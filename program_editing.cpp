#include "program_editing.h"
#include "ui_program_editing.h"

#include <QTimer>
#include <QDateTime>
#include <QHeaderView>
#include <QTextStream>
#include <QDebug>

Program_Editing::Program_Editing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Program_Editing)
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
    ui->choose_program_edit->installEventFilter(this);
    ui->program_name_edit->installEventFilter(this);
    this->installEventFilter(this);

    //选择程式、程式名称、高低温保护
    ui->choose_program_edit->setStyleSheet("QLineEdit#choose_program_edit{border:2px solid rgb(203,230,200);"
                                           "background-color:white}");
    ui->program_name_edit->setStyleSheet("QLineEdit#program_name_edit{border:2px solid rgb(203,230,200);"
                                           "background-color:white}");
    ui->highTemp_protect_edit->setStyleSheet("QLineEdit#highTemp_protect_edit{border:2px solid rgb(203,230,200);"
                                           "background-color:white}");
    ui->lowTemp_protect_edit->setStyleSheet("QLineEdit#lowTemp_protect_edit{border:2px solid rgb(203,230,200);"
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
    //设置表格文字格式居中
    for(int i=0 ;i<4 ;i++){
        for(int j=0 ;j<8 ;j++){
            table[0]->item(i,j)->setTextAlignment(Qt::AlignCenter);
            QFont font_tabel = table[0]->item(i,j)->font();
            font_tabel.setPointSize(16);
            font_tabel.setFamily("Micorsoft UI light");
            table[0]->item(i,j)->setFont(font_tabel);
        }
    }
    //控制表格格式
    table[0]->setColumnWidth(0,77);
    table[0]->setColumnWidth(1,155);
    table[0]->setColumnWidth(2,156);
    table[0]->setColumnWidth(3,224);
    table[0]->setColumnWidth(4,60);
    table[0]->setColumnWidth(5,61);
    table[0]->setColumnWidth(6,60);
    table[0]->setColumnWidth(7,61);
    table[0]->setRowHeight(0,45);
    table[0]->setRowHeight(1,45);
    table[0]->setRowHeight(2,45);
    table[0]->setRowHeight(3,45);
    table[0]->setStyleSheet("QTableWidget::item{border-top:1px solid rgba(0,0,0,0.4);color:black}"
                            "QTableWidget{border:none;font-size:14}");
    //将表格加入StackedWidge页面
    page = new QStackedWidget(this);
    page->addWidget(table[0]);
    page->setGeometry(37,508,854,180);
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
    //表格翻页按钮
    ui->lastPage_pbtn->setStyleSheet("QPushButton#lastPage_pbtn{border:none;"
                                     "background-color:rgb(71,129,52);"
                                     "background-image:url(:/Image/icon/lastPage.png);"
                                     "background-position:center;"
                                     "background-repeat:no-repeat}");
    ui->nextPage_pbtn->setStyleSheet("QPushButton#nextPage_pbtn{border:none;"
                                     "background-color:rgb(238,117,0);"
                                     "background-image:url(:/Image/icon/nextPage.png);"
                                     "background-position:center;"
                                     "background-repeat:no-repeat}");
    ui->firstPage_pbtn->setStyleSheet("QPushButton#firstPage_pbtn{border:none;"
                                      "background-color:rgb(71,129,52);"
                                      "background-image:url(:/Image/icon/firstPage.png);"
                                      "background-position:center;"
                                      "background-repeat:no-repeat}");
    ui->endPage_pbtn->setStyleSheet("QPushButton#endPage_pbtn{border:none;"
                                    "background-color:rgb(238,117,0);"
                                    "background-image:url(:/Image/icon/endPage.png);"
                                    "background-position:center;"
                                    "background-repeat:no-repeat}");

    //开新程式、删除程式、插入、删除
    ui->new_program_pbtn->setStyleSheet("QPushButton#new_program_pbtn{background:transparent;"
                                        "border:2px solid rgb(71,129,52)}");
    ui->choose_program_pushButton->setStyleSheet("QPushButton#choose_program_pushButton{background:transparent;"
                                                 "border:none}");
    ui->delete_program_pbtn->setStyleSheet("QPushButton#delete_program_pbtn{background:transparent;"
                                           "border:2px solid rgb(71,129,52)}");
    ui->insert_pbtn->setStyleSheet("QPushButton#insert_pbtn{background:transparent;"
                                           "border:2px solid rgb(71,129,52)}");
    ui->delete_program->setStyleSheet("QPushButton#delete_program{background:transparent;"
                                           "border:2px solid rgb(71,129,52)}");

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->loop_setting_pbtn->setStyleSheet("QPushButton#loop_setting_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");
    ui->saving_pbtn->setStyleSheet("QPushButton#saving_pbtn{border:2px solid rgb(74,122,60);"
                                                   "background-color:rgb(173,199,160);"
                                                   "border-radius:8px;"
                                                   "color:rgb(74,122,60)}");

    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&Program_Editing::currentTime);

    //页面跳转
    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&Program_Editing::programEditing_sendTo_mainWindow);

    //数据处理
    connect(&popUpWindow04,&PopUpWindow04::popUpWindow04ButtonClickedSignals,this,&Program_Editing::deal_popUpWindow04PushButtonClickedSignals);
}

Program_Editing::~Program_Editing()
{
    delete ui;
}

/*
 * time: 2022-10-31
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void Program_Editing::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

/*
 * time: 2022-11-4
 * type: public slots
 * effect: 上一页按钮
 * influence: ui->lastPage_pbtn clicked
*/
void Program_Editing::on_lastPage_pbtn_clicked()
{
    nindex--;
    if(nindex>=0){
        page->setCurrentIndex(nindex);
    }
    else{
        nindex = index;
        page->setCurrentIndex(nindex);
    }

}

/*
 * time: 2022-11-4
 * type: public slots
 * effect: 下一页按钮
 * influence: ui->nextPage_pbtn clicked
*/
void Program_Editing::on_nextPage_pbtn_clicked()
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
                font_tabel.setPointSize(16);
                font_tabel.setFamily("Micorsoft UI light");
                table[index]->item(i,j)->setFont(font_tabel);
            }
        }
        table[index]->setColumnWidth(0,77);
        table[index]->setColumnWidth(1,155);
        table[index]->setColumnWidth(2,156);
        table[index]->setColumnWidth(3,224);
        table[index]->setColumnWidth(4,60);
        table[index]->setColumnWidth(5,61);
        table[index]->setColumnWidth(6,60);
        table[index]->setColumnWidth(7,61);
        table[index]->setRowHeight(0,45);
        table[index]->setRowHeight(1,45);
        table[index]->setRowHeight(2,45);
        table[index]->setRowHeight(3,45);
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
}

/*
 * time: 2022-11-4
 * type: public slots
 * effect: 第一页按钮
 * influence: ui->firstPage_pbtn clicked
*/
void Program_Editing::on_firstPage_pbtn_clicked()
{
    nindex = 0;
    page->setCurrentIndex(nindex);
}

/*
 * time: 2022-11-4
 * type: public slots
 * effect: 最后一页按钮
 * influence: ui->endPage_pbtn clicked
*/
void Program_Editing::on_endPage_pbtn_clicked()
{
    nindex = index;
    page->setCurrentIndex(nindex);
}

/*
 * time: 2022-11-14
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Program_Editing::programEditing_sendTo_mainWindow(){
    emit programEditing_to_mainWindow();
}

/*
 * time: 2022-11-1
 * type: System EventFilter
 * effect: 事件过滤器
 * influence: this
*/
bool Program_Editing::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(table[nindex]->currentItem())
                table[nindex]->setCurrentItem(nullptr);
            if(ui->choose_program_edit->hasFocus()){
                ui->choose_program_edit->clearFocus();
            }
            else if(ui->program_name_edit->hasFocus()){
                ui->program_name_edit->clearFocus();
            }
        }
    }
    if(watched == ui->program_name_edit)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Keyboard_Signal(0);
            ui->program_name_edit->setFocus();
        }
    }
    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}

QString Program_Editing::getChooseProgram(){
    return chooseProgram;
}

QString Program_Editing::getProgramName(){
    return programName;
}

QString Program_Editing::getHighTempProtect(){
    return highTempProtect;
}

QString Program_Editing::getLowTempProtect(){
    return lowTempProtect;
}

void Program_Editing::setChooseProgram(QString strs){
    this->chooseProgram = strs;
    ui->choose_program_edit->setText(chooseProgram);
}

void Program_Editing::setProgramName(QString strs){
    this->programName = strs;
    ui->program_name_edit->setText(programName);
}

void Program_Editing::setLowTempProtect(QString strs){
    this->lowTempProtect = strs;
    ui->lowTemp_protect_edit->setText(lowTempProtect);
}

void Program_Editing::setHighTempProtect(QString strs){
    this->highTempProtect = strs;
    ui->highTemp_protect_edit->setText(highTempProtect);
}

void Program_Editing::creatNewProgramClicked(){
    emit creatNewProgramClickedSignals();
}

void Program_Editing::deleteProgramClicked(){
    emit deleteProgramClickedSignals();
}

void Program_Editing::deleteClicked(){
    emit deleteClickedSignals();
}

void Program_Editing::insertClicked(){
    emit insertClickedSignals();
}

void Program_Editing::on_saving_pbtn_clicked()
{
}


void Program_Editing::on_loop_setting_pbtn_clicked()
{
}

void Program_Editing::on_new_program_pbtn_clicked()
{
    popUpWindow04.setStatus(1);
    int num = popUpWindow04.getMapIndex();
    ui->choose_program_edit->setText(QString::number(num));
}


void Program_Editing::on_choose_program_pushButton_clicked()
{
    popUpWindow04.setStatus(0);
    popUpWindow04.move(0,0);
    popUpWindow04.show();
}

void Program_Editing::inset(QString strs)
{
    popUpWindow04.insertMap(strs);
    popUpWindow04.changeLabelID(popUpWindow04.getEndNumber());
}

void Program_Editing::on_delete_program_pbtn_clicked()
{
    popUpWindow04.setStatus(2);
}

void Program_Editing::InitProgram(int ID, QString Name)
{
    ui->program_name_edit->setText(Name);
    ui->choose_program_edit->setText(QString::number(ID));
}

void Program_Editing::deal_popUpWindow04PushButtonClickedSignals(int ID,QString Name)
{
    emit programEditingChooseProgramSignals(ID,Name);
}

void Program_Editing::freezeOneSec()
{
    ui->choose_program_pushButton->setEnabled(false);
    ui->new_program_pbtn->setEnabled(false);
    ui->insert_pbtn->setEnabled(false);
    ui->delete_program->setEnabled(false);
    ui->delete_program_pbtn->setEnabled(false);
    ui->endPage_pbtn->setEnabled(false);
    ui->firstPage_pbtn->setEnabled(false);
    ui->nextPage_pbtn->setEnabled(false);
    ui->lastPage_pbtn->setEnabled(false);
    ui->font_page_pbtn->setEnabled(false);
    ui->saving_pbtn->setEnabled(false);
    ui->loop_setting_pbtn->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    ui->choose_program_pushButton->setEnabled(true);
    ui->new_program_pbtn->setEnabled(true);
    ui->insert_pbtn->setEnabled(true);
    ui->delete_program->setEnabled(true);
    ui->delete_program_pbtn->setEnabled(true);
    ui->endPage_pbtn->setEnabled(true);
    ui->firstPage_pbtn->setEnabled(true);
    ui->nextPage_pbtn->setEnabled(true);
    ui->lastPage_pbtn->setEnabled(true);
    ui->font_page_pbtn->setEnabled(true);
    ui->saving_pbtn->setEnabled(true);
    ui->loop_setting_pbtn->setEnabled(true);
}
