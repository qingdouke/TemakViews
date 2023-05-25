#include "output_monitoring.h"
#include "ui_output_monitoring.h"

#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QHeaderView>
#include <QTextStream>
#include <QDebug>

Output_Monitoring::Output_Monitoring(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Output_Monitoring)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    //Header背景颜色
    ui->Header->setStyleSheet("QWidget#Header{background-color:rgb(72,129,52)}");
    //标题颜色
    ui->title->setStyleSheet("QLabel#title{color:white}");
    //logo颜色
    ui->logo->setStyleSheet("QLabel#logo{background-image:url(:/Image/85/1.bmp)}");

    //Main背景颜色渐变
    ui->Main->setStyleSheet("QWidget#Main{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 white,stop:1 rgb(177,203,166))}");

    //Header时间label初始化
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
    ui->current_time->setStyleSheet("QLabel#current_time{color:white}");
    //设置定时器 每一秒更新一次Header的时间label
    QTimer* timer = new QTimer(this);
    timer->start(1000);

    //status_box
    ui->status_box->setStyleSheet("QWidget#status_box{border:2px solid rgb(72,129,52);"
                                  "border-radius:10px;"
                                  "background-color:white}");
    ui->status_box_line->setStyleSheet("QLabel#status_box_line{background-color:rgb(127,127,127)}");
    ui->status_1->setStyleSheet("QLabel#status_1{background-image:url(:/Image/24/61.bmp)}");
    ui->status_2->setStyleSheet("QLabel#status_2{background-image:url(:/Image/24/63.bmp)}");
    ui->status_3->setStyleSheet("QLabel#status_3{background-image:url(:/Image/24/65.bmp)}");
    ui->status_4->setStyleSheet("QLabel#status_4{background-image:url(:/Image/24/67.bmp)}");
    ui->status_5->setStyleSheet("QLabel#status_5{background-image:url(:/Image/24/69.bmp)}");
    ui->status_6->setStyleSheet("QLabel#status_6{background-image:url(:/Image/24/71.bmp)}");

    //添加事件过滤器
    ui->temperature_sv_edit->installEventFilter(this);
    ui->temperature_pv_edit->installEventFilter(this);
    ui->humidity_sv_edit->installEventFilter(this);
    ui->humidity_pv_edit->installEventFilter(this);
    this->installEventFilter(this);

    //temperature_box
    ui->Temperature_box->setStyleSheet("QWidget#Temperature_box{border:2px solid rgb(203,230,200);"
                                       "background-color:white}");

    //humidity_box
    ui->Humidity_box->setStyleSheet("QWidget#Humidity_box{background-color:white;"
                                    "border:2px solid rgb(203,230,200)}");

    //Temperature_image
    ui->temperature_image->setStyleSheet("QLabel#temperature_image{background-image:url(:/Image/icon/temperature.png)}");

    //Temperature_sv
    ui->temperature_sv_company->setStyleSheet("QLabel#temperature_sv_company{color:rgb(255,201,14)}");
    ui->temperature_sv_edit->setStyleSheet("QLineEdit#temperature_sv_edit{border:none;background:transparent}");
    ui->temperature_sv_edit->setInputMask("00.00");
    ui->temperature_sv_edit->setText("12.12");

    //Temperature_pv
    ui->temperature_pv_company->setStyleSheet("QLabel#temperature_pv_company{color:rgb(255,201,14)}");
    ui->temperature_pv_edit->setStyleSheet("QLineEdit#temperature_pv_edit{border:none;background:transparent;color:red}");
    ui->temperature_pv_edit->setInputMask("00.00");
    ui->temperature_pv_edit->setText("12.12");

    //Humdity_image
    ui->humidity_image->setStyleSheet("QLabel#humidity_image{background-image:url(:/Image/icon/humidity.png)}");

    //Humidity_sv
    ui->humidity_sv_company->setStyleSheet("QLabel#humidity_sv_company{color:rgb(255,201,14)}");
    ui->humidity_sv_edit->setStyleSheet("QLineEdit#humidity_sv_edit{border:none;background:transparent}");
    ui->humidity_sv_edit->setInputMask("00.00");
    ui->humidity_sv_edit->setText("12.12");

    //Humidity_pv
    ui->humidity_pv_company->setStyleSheet("QLabel#humidity_pv_company{color:rgb(255,201,14)}");
    ui->humidity_pv_edit->setStyleSheet("QLineEdit#humidity_pv_edit{border:none;background:transparent;color:blue}");
    ui->humidity_pv_edit->setInputMask("00.00");
    ui->humidity_pv_edit->setText("12.12");

    //使用qss设定Signal_box checkbox样式
    QFile file(":/qss/Signal_box.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    //Signal_box
    ui->Signal_box->setStyleSheet("QWidget#Signal_box{border:2px solid rgb(203,230,200)"
                                  "background-color:white}");

    //Step_box
    ui->Step_box->setStyleSheet("QWidget#Step_box{border:2px solid rgb(117,138,107)}");

    //创建Step组，共100组
    for(int i=0 ;i<100 ;i++){
        num.append(i+1);
    }
    //创建初始化页面（共4个Step）
    table.append(new QTableWidget(this));
    //设置行数列数和表格大小
    table[0]->setRowCount(4);
    table[0]->setColumnCount(8);
    table[0]->resize(886,150);
    //隐藏标题栏
    QHeaderView* headerview_Vertical = table[0]->verticalHeader();
    headerview_Vertical->setHidden(true);
    QHeaderView* headerview_Horizontal = table[0]->horizontalHeader();
    headerview_Horizontal->setHidden(true);
    //设置Step
    for(int i=0 ;i<4 ;i++){
        table[0]->setItem(i,0,new QTableWidgetItem(QString::number(num[count++])));
    }
    //设置其余每列内容
    for(int i=0 ;i<4 ;i++){
        table[0]->setItem(i,1,new QTableWidgetItem("0.00"));
    }
    for(int i=0 ;i<4 ;i++){
        table[0]->setItem(i,2,new QTableWidgetItem("0.0"));
    }
    for(int i=0 ;i<4 ;i++){
        table[0]->setItem(i,3,new QTableWidgetItem("0:0:0"));
    }
    for(int i=0 ;i<4 ;i++){
        table[0]->setItem(i,4,new QTableWidgetItem("0"));
    }
    for(int i=0 ;i<4 ;i++){
        table[0]->setItem(i,5,new QTableWidgetItem("0"));
    }
    for(int i=0 ;i<4 ;i++){
        table[0]->setItem(i,6,new QTableWidgetItem("0"));
    }
    for(int i=0 ;i<4 ;i++){
        table[0]->setItem(i,7,new QTableWidgetItem("0"));
    }
    //设置Step不可修改
    for(int i=0 ;i<table[0]->rowCount() ;i++){
        table[0]->item(i,0)->setFlags(Qt::NoItemFlags);
    }
    table[0]->setSelectionBehavior(QAbstractItemView::SelectRows);
    table[0]->setFocusPolicy(Qt::ClickFocus);
    table[0]->viewport()->installEventFilter(this);
    table[0]->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    //设置item不可修改
    for(int i=0 ;i<table[0]->rowCount() ;i++){
        table[0]->item(i,1)->setFlags(Qt::NoItemFlags);
    }
    for(int i=0 ;i<table[0]->rowCount() ;i++){
        table[0]->item(i,2)->setFlags(Qt::NoItemFlags);
    }
    for(int i=0 ;i<table[0]->rowCount() ;i++){
        table[0]->item(i,3)->setFlags(Qt::NoItemFlags);
    }
    for(int i=0 ;i<table[0]->rowCount() ;i++){
        table[0]->item(i,4)->setFlags(Qt::NoItemFlags);
    }
    for(int i=0 ;i<table[0]->rowCount() ;i++){
        table[0]->item(i,5)->setFlags(Qt::NoItemFlags);
    }
    for(int i=0 ;i<table[0]->rowCount() ;i++){
        table[0]->item(i,6)->setFlags(Qt::NoItemFlags);
    }
    for(int i=0 ;i<table[0]->rowCount() ;i++){
        table[0]->item(i,7)->setFlags(Qt::NoItemFlags);
    }
    //设置表格文字格式居中
    for(int i=0 ;i<4 ;i++){
        for(int j=0 ;j<8 ;j++){
            table[0]->item(i,j)->setTextAlignment(Qt::AlignCenter);
            QFont font_tabel = table[0]->item(i,j)->font();
            font_tabel.setPointSize(18);
            font_tabel.setFamily("Micorsoft UI light");
            table[0]->item(i,j)->setFont(font_tabel);
        }
    }
    //控制表格格式
    table[0]->setColumnWidth(0,77);
    table[0]->setColumnWidth(1,155);
    table[0]->setColumnWidth(2,118);
    table[0]->setColumnWidth(3,257);
    table[0]->setColumnWidth(4,70);
    table[0]->setColumnWidth(5,70);
    table[0]->setColumnWidth(6,70);
    table[0]->setColumnWidth(7,70);
    table[0]->setRowHeight(0,38);
    table[0]->setRowHeight(1,37);
    table[0]->setRowHeight(2,37);
    table[0]->setRowHeight(3,38);
    table[0]->setStyleSheet("QTableWidget::item{border-top:1px solid rgba(0,0,0,0.4);color:black}"
                            "QTableWidget{border:none;font-size:14}");
    //将表格加入StackedWidge页面
    page = new QStackedWidget(this);
    page->addWidget(table[0]);
    page->setGeometry(39,360,887,150);
    //表格标题设置
    ui->line_step->setStyleSheet("QLabel#line_step{background-color:rgb(200,200,200);border:none}");
    ui->line_temp->setStyleSheet("QLabel#line_temp{background-color:rgb(200,200,200);border:none}");
    ui->line_humi->setStyleSheet("QLabel#line_humi{background-color:rgb(200,200,200);border:none}");
    ui->line_hms->setStyleSheet("QLabel#line_hms{background-color:rgb(200,200,200);border:none}");
    ui->line_ts1->setStyleSheet("QLabel#line_ts1{background-color:rgb(200,200,200);border:none}");
    ui->line_ts2->setStyleSheet("QLabel#line_ts2{background-color:rgb(200,200,200);border:none}");
    ui->line_ts3->setStyleSheet("QLabel#line_ts3{background-color:rgb(200,200,200);border:none}");
    ui->label_step->setStyleSheet("QLabel#label_step{color:rgb(53,87,54)}");
    ui->label_temp->setStyleSheet("QLabel#label_temp{color:rgb(53,87,54)}");
    ui->label_humi->setStyleSheet("QLabel#label_humi{color:rgb(53,87,54)}");
    ui->label_hms->setStyleSheet("QLabel#label_hms{color:rgb(53,87,54)}");
    ui->label_ts1->setStyleSheet("QLabel#label_ts1{color:rgb(53,87,54)}");
    ui->label_ts2->setStyleSheet("QLabel#label_ts2{color:rgb(53,87,54)}");
    ui->label_ts3->setStyleSheet("QLabel#label_ts3{color:rgb(53,87,54)}");
    ui->label_wt->setStyleSheet("QLabel#label_wt{color:rgb(53,87,54)}");

    //高低温保护 单位
    ui->company_temp_label_1->setStyleSheet("QLabel#company_temp_label_1{color:rgb(255,201,14)}");
    ui->company_temp_label_2->setStyleSheet("QLabel#company_temp_label_2{color:rgb(255,201,14)}");

    //高低温保护 各种输出的 edit
    ui->highTemp_protect_edit->setStyleSheet("QLineEdit#highTemp_protect_edit{border-radius:4px;"
                                             "border:2px solid rgb(203,230,200)}");
    ui->highTemp_protect_edit->setText("20.20");
    ui->lowTemp_protect_edit->setStyleSheet("QLineEdit#lowTemp_protect_edit{border-radius:4px;"
                                             "border:2px solid rgb(203,230,200)}");
    ui->lowTemp_protect_edit->setText("-20.20");
    ui->temp_output_edit->setStyleSheet("QLineEdit#temp_output_edit{border-radius:4px;"
                                        "border:2px solid rgb(203,230,200)}");
    ui->temp_output_edit->setText("2.02");
    ui->humi_output_edit->setStyleSheet("QLineEdit#humi_output_edit{border-radius:4px;"
                                        "border:2px solid rgb(203,230,200)}");
    ui->humi_output_edit->setText("2.02");
    ui->servo_output_edit->setStyleSheet("QLineEdit#servo_output_edit{border-radius:4px;"
                                        "border:2px solid rgb(203,230,200)}");
    ui->servo_output_edit->setText("2.02");

    //StackWidget 上一页 下一页 编辑 跳段
    ui->previousPage_pbtn->setStyleSheet("QPushButton#previousPage_pbtn{color:white;"
                                         "background-color:rgb(7,75,34);"
                                         "border:none;"
                                         "border-radius:3px}");
    ui->nextPage_pbtn->setStyleSheet("QPushButton#nextPage_pbtn{color:white;"
                                     "background-color:rgb(7,75,34);"
                                     "border:none;"
                                     "border-radius:3px}");
    ui->edit_pbtn->setStyleSheet("QPushButton#edit_pbtn{color:white;"
                                 "background-color:rgb(7,75,34);"
                                 "border:none;"
                                 "border-radius:3px}");
    ui->jumpping_pbtn->setStyleSheet("QPushButton#jumpping_pbtn{color:white;"
                                 "background-color:rgb(7,75,34);"
                                 "border:none;"
                                 "border-radius:3px}");

    //program_box
    ui->Program_box->setStyleSheet("QWidget#Program_box{background-color:white;"
                                   "border:2px solid rgb(117,150,107);"
                                   "border-radius:10px}");
    ui->program_line->setStyleSheet("QLabel#program_line{background-color:rgb(117,150,107)}");

    //progrem_name部分
    ui->program_name_edit->setStyleSheet("QLineEdit#program_name_edit{background:transparent;border:none}");
    ui->program_name_edit->setText(program_name);

    //program_time部分
    ui->program_time_edit->setStyleSheet("QLineEdit#program_time_edit{background:transparent;border:none}");
    ui->program_time_edit->setInputMask("0000:00:00/0000:00:00");
    ui->program_time_edit->setText(program_time);

    //period_time部分
    ui->period_time_edit->setStyleSheet("QLineEdit#period_time_edit{background:transparent;border:none}");
    ui->period_time_edit->setInputMask("0000:00:00/0000:00:00");
    ui->period_time_edit->setText(period_time);

    //estimate_time 部分
    ui->estimate_time_edit->setStyleSheet("QLineEdit#estimate_time_edit{background:transparent;border:none}");
    ui->estimate_time_edit->setInputMask("0000-00-00 00:00:00");
    ui->estimate_time_edit->setText(estimate_time);

    //program_cycle部分
    ui->program_cycle_edit->setStyleSheet("QLineEdit#program_cycle_edit{background:transparent;border:none}");
    ui->program_cycle_edit->setInputMask("0000/0000");
    ui->program_cycle_edit->setText(program_cycle);

    //program_run_period部分
    ui->program_run_period_edit->setStyleSheet("QLineEdit#program_run_period_edit{background:transparent;border:none}");
    ui->program_run_period_edit->setInputMask("000");
    ui->program_run_period_edit->setText(program_run_period);

    //program_link部分
    ui->program_link_edit->setStyleSheet("QLineEdit#program_link_edit{background:transparent;border:none}");
    ui->program_link_edit->setInputMask("000/000");
    ui->program_link_edit->setText(program_link);

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->previous_page_pbth->setStyleSheet("QPushButton#previous_page_pbth{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");
    ui->constant_value_running_pbtn->setStyleSheet("QPushButton#constant_value_running_pbtn{border:2px solid rgb(74,122,60);"
                                                   "background-color:rgb(173,199,160);"
                                                   "border-radius:8px;"
                                                   "color:rgb(74,122,60)}");
    ui->next_page_pbtn->setStyleSheet("QPushButton#next_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");

    //运行、加载
    ui->running_pbtn->setStyleSheet("QPushButton#running_pbtn{border:none;"
                                    "background-color:rgb(71,129,52);"
                                    "color:white;"
                                    "border-radius:8px}");
    ui->loading_pbtn->setStyleSheet("QPushButton#loading_pbtn{border:none;"
                                    "background-color:rgb(238,117,0);"
                                    "color:white;"
                                    "border-radius:8px}");

    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&Output_Monitoring::currentTime);
    //页面跳转信号发送
    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&Output_Monitoring::outputMonitoring_sendTo_mainWindow);
    connect(ui->previous_page_pbth,&QPushButton::clicked,this,&Output_Monitoring::outputMonitoring_sendTo_monitoringInterface);
    connect(ui->next_page_pbtn,&QPushButton::clicked,this,&Output_Monitoring::outputMonitoring_sendTo_curveMonitoring);

    //弹窗
    connect(&popUpWindow01,&PopUpWindow01::popWindow01PushButtonOKClickedSignal,this,&Output_Monitoring::deal_popUpWindow01PushButtonOKClickedSignal);
    connect(&popUpWindow02,&PopUpWindow02::popWindow02PushButtonOKClickedSignal,this,&Output_Monitoring::deal_popUpWindow02PushButtonOKClickedSignal);
    connect(&popUpWindow03,&PopUpWindow03::popWindow03PushButtonYESClickedSignal,this,&Output_Monitoring::deal_popUpWindow03PushButtonYESClickedSignal);
    connect(&popUpWindow04,&PopUpWindow04::popUpWindow04WithoutDataSignals,this,&Output_Monitoring::deal_popUpWindow04WithoutDataSignals);

    //数据处理
    connect(&popUpWindow04,&PopUpWindow04::popUpWindow04ButtonClickedSignals,this,&Output_Monitoring::deal_popUpWindow04PushButtonClickedSignals);
}

Output_Monitoring::~Output_Monitoring()
{
    delete ui;
}

/*
 * time: 2022-10-31
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void Output_Monitoring::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

/*
 * time: 2022-11-1
 * type: System EventFilter
 * effect: 事件过滤器
 * influence: this
*/
bool Output_Monitoring::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(ui->temperature_sv_edit->hasFocus())
                ui->temperature_sv_edit->clearFocus();
            else if(ui->temperature_pv_edit->hasFocus())
                ui->temperature_pv_edit->clearFocus();
            else if(ui->humidity_sv_edit->hasFocus())
                ui->humidity_sv_edit->clearFocus();
            else if(ui->humidity_pv_edit->hasFocus())
                ui->humidity_pv_edit->clearFocus();
            else if (table[nindex]->currentItem())
                table[nindex]->setCurrentItem(nullptr);
        }
    }

//    //监听lineEdit
//    if(watched == ui->temperature_sv_edit)
//    {
//        if(event->type() == QEvent::MouseButtonPress){
//            //            ID = 1;                                     //为lineEdit设置ID
//            //            emit Request_Use_Calculater_Signal();       //发送请求使用计算器的信号
//            ui->temperature_sv_edit->setFocus();   //清除lineEdit聚焦
//        }
//    }
//    else if(watched == ui->temperature_pv_edit){
//        if(event->type() == QEvent::MouseButtonPress){
//            ui->temperature_pv_edit->setFocus();
//        }
//    }
//    else if(watched == ui->humidity_pv_edit){
//        if(event->type() == QEvent::MouseButtonPress){
//            ui->humidity_pv_edit->setFocus();
//        }
//    }
//    else if(watched == ui->humidity_pv_edit){
//        if(event->type() == QEvent::MouseButtonPress){
//            ui->humidity_pv_edit->setFocus();
//        }
//    }
    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}

/*
 * time: 2022-11-2
 * type: slots
 * effect: 表格跳转上一页
 * influence: table
*/
void Output_Monitoring::on_previousPage_pbtn_clicked()
{
    nindex--;
    if(nindex>=0){
        page->setCurrentIndex(nindex);
    }
    else{
        nindex = index;
        page->setCurrentIndex(nindex);
    }
    emit tablePreviousPageClickedSignals();
}

/*
 * time: 2022-11-2
 * type: slots
 * effect: 表格跳转下一页
 * influence: table
*/
void Output_Monitoring::on_nextPage_pbtn_clicked()
{
    nindex++;
    if(nindex>index&&nindex<=24){
        table.append(new QTableWidget(this));
        table[++index]->setRowCount(4);
        table[index]->setColumnCount(8);
        QHeaderView* headerview_Vertical = table[index]->verticalHeader();
        headerview_Vertical->setHidden(true);
        QHeaderView* headerview_Horizontal = table[index]->horizontalHeader();
        headerview_Horizontal->setHidden(true);
        for(int i=0 ;i<4 ;i++){
            table[index]->setItem(i,0,new QTableWidgetItem(QString::number(num[count++])));
        }
        for(int i=0 ;i<4 ;i++){
            table[index]->setItem(i,1,new QTableWidgetItem("0.00"));
        }
        for(int i=0 ;i<4 ;i++){
            table[index]->setItem(i,2,new QTableWidgetItem("0.0"));
        }
        for(int i=0 ;i<4 ;i++){
            table[index]->setItem(i,3,new QTableWidgetItem("0:0:0"));
        }
        for(int i=0 ;i<4 ;i++){
            table[index]->setItem(i,4,new QTableWidgetItem("0"));
        }
        for(int i=0 ;i<4 ;i++){
            table[index]->setItem(i,5,new QTableWidgetItem("0"));
        }
        for(int i=0 ;i<4 ;i++){
            table[index]->setItem(i,6,new QTableWidgetItem("0"));
        }
        for(int i=0 ;i<4 ;i++){
            table[index]->setItem(i,7,new QTableWidgetItem("0"));
        }
        for(int i=0 ;i<table[index]->rowCount() ;i++){
            table[index]->item(i,0)->setFlags(Qt::NoItemFlags);
            table[index]->setStyleSheet("color:black");
        }
        for(int i=0 ;i<4 ;i++){
            for(int j=0 ;j<8 ;j++){
                table[index]->item(i,j)->setTextAlignment(Qt::AlignCenter);
                QFont font_tabel = table[index]->item(i,j)->font();
                font_tabel.setPointSize(18);
                font_tabel.setFamily("Micorsoft UI light");
                table[index]->item(i,j)->setFont(font_tabel);
            }
        }
        table[index]->setColumnWidth(0,77);
        table[index]->setColumnWidth(1,155);
        table[index]->setColumnWidth(2,118);
        table[index]->setColumnWidth(3,257);
        table[index]->setColumnWidth(4,70);
        table[index]->setColumnWidth(5,70);
        table[index]->setColumnWidth(6,70);
        table[index]->setColumnWidth(7,70);
        table[index]->setRowHeight(0,38);
        table[index]->setRowHeight(1,37);
        table[index]->setRowHeight(2,37);
        table[index]->setRowHeight(3,38);
        //设置item不可修改
        for(int i=0 ;i<table[0]->rowCount() ;i++){
            table[index]->item(i,1)->setFlags(Qt::NoItemFlags);
        }
        for(int i=0 ;i<table[0]->rowCount() ;i++){
            table[index]->item(i,2)->setFlags(Qt::NoItemFlags);
        }
        for(int i=0 ;i<table[0]->rowCount() ;i++){
            table[index]->item(i,3)->setFlags(Qt::NoItemFlags);
        }
        for(int i=0 ;i<table[0]->rowCount() ;i++){
            table[index]->item(i,4)->setFlags(Qt::NoItemFlags);
        }
        for(int i=0 ;i<table[0]->rowCount() ;i++){
            table[index]->item(i,5)->setFlags(Qt::NoItemFlags);
        }
        for(int i=0 ;i<table[0]->rowCount() ;i++){
            table[index]->item(i,6)->setFlags(Qt::NoItemFlags);
        }
        for(int i=0 ;i<table[0]->rowCount() ;i++){
            table[index]->item(i,7)->setFlags(Qt::NoItemFlags);
        }
        table[index]->setSelectionBehavior(QAbstractItemView::SelectRows);
        table[index]->setFocusPolicy(Qt::ClickFocus);
        table[index]->viewport()->installEventFilter(this);
        table[index]->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
        table[index]->setStyleSheet("QTableWidget::item{border-top:1px solid rgba(0,0,0,0.4);color:black}"
                                "QTableWidget{border:none;font-size:14}");
        page->addWidget(table[index]);
    }
    if(nindex<=24)
    {
        page->setCurrentIndex(nindex);
    }
    else
    {
        nindex = 0;
        page->setCurrentIndex(nindex);
    }
    emit tableNextPageClickedSignals();
}

/*
 * time: 2022-11-2
 * type: Get
 * effect: 获取程式名称
 * influence: QString program_name
*/
QString Output_Monitoring::getProgramName(){
    return program_name;
}

/*
 * time: 2022-11-2
 * type: Set
 * effect: 设定程式名称
 * influence: QString program_name
*/
void Output_Monitoring::setProgramName(QString strs){
    this->program_name = strs;
    ui->program_name_edit->setText(program_name);
}

/*
 * time: 2022-11-2
 * type: Get
 * effect: 获取程式时间
 * influence: QString program_time
*/
QString Output_Monitoring::getProgramTime(){
    return program_time;
}

/*
 * time: 2022-11-2
 * type: Get
 * effect: 获取段时间
 * influence: QString period_time
*/
QString Output_Monitoring::getPeriodTime(){
    return period_time;
}

/*
 * time: 2022-11-2
 * type: Get
 * effect: 获取预完成时间
 * influence: QString estimate_time
*/
QString Output_Monitoring::getEstimateTime(){
    return estimate_time;
}

/*
 * time: 2022-11-2
 * type: Get
 * effect: 获取循环
 * influence: QString program_cycle
*/
QString Output_Monitoring::getProgramCycle(){
    return program_cycle;
}

/*
 * time: 2022-11-2
 * type: Get
 * effect: 获取运行段
 * influence: QString program_run_period
*/
QString Output_Monitoring::getProgramRunPeriod(){
    return program_run_period;
}

/*
 * time: 2022-11-2
 * type: Get
 * effect: 获取链接
 * influence: QString program_link
*/
QString Output_Monitoring::getProgramLink(){
    return program_link;
}

/*
 * time: 2022-11-2
 * type: Set
 * effect: 设置段时间
 * influence: QString period_time
*/
void Output_Monitoring::setPeriodTime(QString A,QString B){
    this->period_time_A = A;
    this->period_time_B = B;
    ui->period_time_edit->setText(period_time);
}

void Output_Monitoring::setPeriodTime_A(QString A){
    this->period_time_A = A;
    ui->period_time_edit->setText(period_time);
}

void Output_Monitoring::setPeriodTime_B(QString B){
    this->period_time_B = B;
    ui->period_time_edit->setText(period_time);
}

/*
 * time: 2022-11-2
 * type: Set
 * effect: 设置程序时间
 * influence: QString program_time
*/
void Output_Monitoring::setProgramTime(QString A,QString B){
    this->program_time_A = A;
    this->program_time_B = B;
    ui->program_time_edit->setText(program_time);
}
void Output_Monitoring::setProgramTime_A(QString A){
    this->program_time_A = A;
    ui->program_time_edit->setText(program_time);
}
void Output_Monitoring::setProgramTime_B(QString B){
    this->program_time_B = B;
    ui->program_time_edit->setText(program_time);
}

/*
 * time: 2022-11-2
 * type: Set
 * effect: 设置预完成时间
 * influence: QString estimate_time
*/
void Output_Monitoring::setEstimateTime(QString strs){
    this->estimate_time = strs;
    ui->estimate_time_edit->setText(estimate_time);
}

/*
 * time: 2022-11-2
 * type: Set
 * effect: 设置循环
 * influence: QString program_cycle
*/
void Output_Monitoring::setProgramCycle(QString strs){
    this->program_cycle = strs;
    ui->program_cycle_edit->setText(program_cycle);
}

/*
 * time: 2022-11-2
 * type: Set
 * effect: 设置运行段
 * influence: QString program_run_period
*/
void Output_Monitoring::setProgramRunPeriod(QString strs){
    this->program_run_period = strs;
    ui->program_run_period_edit->setText(program_run_period);
}

/*
 * time: 2022-11-2
 * type: Set
 * effect: 设置链接
 * influence: QString program_link
*/
void Output_Monitoring::setProgramLink(QString strs){
    this->program_link = strs;
    ui->program_link_edit->setText(program_link);
}

void Output_Monitoring::setTableItem(int index,int row,int col,QString strs){
    table[index]->setItem(row,col,new QTableWidgetItem(strs));
}

/*
 * time: 2022-11-2
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Output_Monitoring::outputMonitoring_sendTo_mainWindow(){
    emit outputMonitoring_to_mainWindow();
}

/*
 * time: 2022-11-2
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Output_Monitoring::outputMonitoring_sendTo_monitoringInterface(){
    emit outputMonitoring_to_monitoringInterface();
}

/*
 * time: 2022-11-3
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Output_Monitoring::outputMonitoring_sendTo_curveMonitoring(){
    emit outputMonitoring_to_curveMonitoring();
}

QString Output_Monitoring::getTemperturePV(){
    return temperaturePV;
}

QString Output_Monitoring::getTempertureSV(){
    return temperatureSV;
}

QString Output_Monitoring::getHumidityPV(){
    return humidityPV;
}

QString Output_Monitoring::getHumiditySV(){
    return humiditySV;
}

void Output_Monitoring::setTemperaturePV(QString strs){
    this->temperaturePV = strs;
    ui->temperature_pv_edit->setText(temperaturePV);
}

void Output_Monitoring::setTemperatureSV(QString strs){
    this->temperatureSV = strs;
    ui->temperature_sv_edit->setText(temperatureSV);
}

void Output_Monitoring::setHumidityPV(QString strs){
    this->humidityPV = strs;
    ui->humidity_pv_edit->setText(humidityPV);
}

void Output_Monitoring::setHumiditySV(QString strs){
    this->humiditySV = strs;
    ui->humidity_sv_edit->setText(humiditySV);
}

QString Output_Monitoring::getHighTempProtect(){
    return highTempProtect;
}

QString Output_Monitoring::getLowTempProtect(){
    return lowTempProtect;
}

QString Output_Monitoring::getTemperatureOutput(){
    return temperatureOutput;
}

QString Output_Monitoring::getHumidityOutput(){
    return humidityOutput;
}

QString Output_Monitoring::getServoOutput(){
    return servoOutput;
}

void Output_Monitoring::setHighTempProtect(QString strs){
    this->highTempProtect = strs;
    ui->highTemp_protect_edit->setText(highTempProtect);
}

void Output_Monitoring::setLowTempProtect(QString strs){
    this->lowTempProtect = strs;
    ui->lowTemp_protect_edit->setText(lowTempProtect);
}

void Output_Monitoring::setTemperatureOutput(QString strs){
    this->temperatureOutput = strs;
    ui->temp_output_edit->setText(temperatureOutput);
}

void Output_Monitoring::setHumidityOutput(QString strs){
    this->humidityOutput = strs;
    ui->humi_output_edit->setText(humidityOutput);
}

void Output_Monitoring::setServoOutput(QString strs){
    this->servoOutput = strs;
    ui->servo_output_edit->setText(servoOutput);
}

void Output_Monitoring::on_edit_pbtn_clicked()
{
    emit tableEditClickedSignals();
}


void Output_Monitoring::on_jumpping_pbtn_clicked()
{
    emit tabelJumppingClickedSignals();
}


void Output_Monitoring::on_running_pbtn_clicked()
{
    emit running_pBtn_clickedSignals();
    if(isRunning==false){
        popUpWindow01.move((this->width()-popUpWindow01.width())/2,(this->height()-popUpWindow01.height())/2);
        popUpWindow01.show();
    }
    else
    {
        popUpWindow03.move((this->width()-popUpWindow03.width())/2,(this->height()-popUpWindow03.height())/2);
        popUpWindow03.show();
    }
}


void Output_Monitoring::on_loading_pbtn_clicked()
{
    emit loading_pBtn_clickedSignals();
    popUpWindow04.move(0,0);
    popUpWindow04.show();
}

void Output_Monitoring::on_constant_value_running_pbtn_clicked()
{
    emit constantValueRunning_pBtn_clickedSignals();
}

void Output_Monitoring::deal_popUpWindow01PushButtonOKClickedSignal(){
    popUpWindow01.close();
    popUpWindow02.move((this->width()-popUpWindow02.width())/2,(this->height()-popUpWindow02.height())/2);
    popUpWindow02.show();
}

void Output_Monitoring::deal_popUpWindow02PushButtonOKClickedSignal(){
    popUpWindow02.close();
    ui->running_pbtn->setStyleSheet("QPushButton#running_pbtn{background-color:red;"
                                    "color:black;"
                                    "border:none;"
                                    "border-radius:10px}");
    ui->running_pbtn->setText(tr("停  止"));
    isRunning = true;
}

void Output_Monitoring::deal_popUpWindow03PushButtonYESClickedSignal(){
    popUpWindow03.close();
    isRunning=false;
    ui->running_pbtn->setStyleSheet("QPushButton#running_pbtn{background-color:rgb(72,129,52);"
                                    "color:white;"
                                    "border:none;"
                                    "border-radius:10px}");
    ui->running_pbtn->setText(tr("运  行"));
}

void Output_Monitoring::deal_popUpWindow04WithoutDataSignals(int WIDTH,int HEIGHT){
    popUpWindow05.centerShow(WIDTH,HEIGHT);
}

void Output_Monitoring::InitProgram(int ID,QString Name)
{
    ui->program_name_edit->setText(Name);
}

void Output_Monitoring::deal_popUpWindow04PushButtonClickedSignals(int ID,QString Name)
{
    emit outputMonitoringChooseProgramSignals(ID,Name);
}

void Output_Monitoring::freezeOneSec()
{
    ui->font_page_pbtn->setEnabled(false);
    ui->nextPage_pbtn->setEnabled(false);
    ui->previousPage_pbtn->setEnabled(false);
    ui->next_page_pbtn->setEnabled(false);
    ui->previous_page_pbth->setEnabled(false);
    ui->constant_value_running_pbtn->setEnabled(false);
    ui->running_pbtn->setEnabled(false);
    ui->edit_pbtn->setEnabled(false);
    ui->loading_pbtn->setEnabled(false);
    ui->jumpping_pbtn->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    ui->font_page_pbtn->setEnabled(true);
    ui->nextPage_pbtn->setEnabled(true);
    ui->previousPage_pbtn->setEnabled(true);
    ui->next_page_pbtn->setEnabled(true);
    ui->previous_page_pbth->setEnabled(true);
    ui->constant_value_running_pbtn->setEnabled(true);
    ui->running_pbtn->setEnabled(true);
    ui->edit_pbtn->setEnabled(true);
    ui->loading_pbtn->setEnabled(true);
    ui->jumpping_pbtn->setEnabled(true);
}
