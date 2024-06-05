#include "program_editing.h"
#include "ui_program_editing.h"
#include "general_tools.h"
#include "mainwindow.h"
#include "address_data_show.h"
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


    //添加事件过滤器
    ui->choose_program_edit->installEventFilter(this);
    ui->program_name_edit->installEventFilter(this);
    ui->pgm_table_temp_edit_1->installEventFilter(this);
    ui->pgm_table_temp_edit_2->installEventFilter(this);
    ui->pgm_table_temp_edit_3->installEventFilter(this);
    ui->pgm_table_temp_edit_4->installEventFilter(this);
    ui->pgm_table_humi_edit_1->installEventFilter(this);
    ui->pgm_table_humi_edit_2->installEventFilter(this);
    ui->pgm_table_humi_edit_3->installEventFilter(this);
    ui->pgm_table_humi_edit_4->installEventFilter(this);
    ui->pgm_table_hour_edit_1->installEventFilter(this);
    ui->pgm_table_hour_edit_2->installEventFilter(this);
    ui->pgm_table_hour_edit_3->installEventFilter(this);
    ui->pgm_table_hour_edit_4->installEventFilter(this);
    ui->pgm_table_min_edit_1->installEventFilter(this);
    ui->pgm_table_min_edit_2->installEventFilter(this);
    ui->pgm_table_min_edit_3->installEventFilter(this);
    ui->pgm_table_min_edit_4->installEventFilter(this);
    ui->pgm_table_sec_edit_1->installEventFilter(this);
    ui->pgm_table_sec_edit_2->installEventFilter(this);
    ui->pgm_table_sec_edit_3->installEventFilter(this);
    ui->pgm_table_sec_edit_4->installEventFilter(this);
    ui->pgm_table_ts1_edit_1->installEventFilter(this);
    ui->pgm_table_ts1_edit_2->installEventFilter(this);
    ui->pgm_table_ts1_edit_3->installEventFilter(this);
    ui->pgm_table_ts1_edit_4->installEventFilter(this);
    ui->pgm_table_ts2_edit_1->installEventFilter(this);
    ui->pgm_table_ts2_edit_2->installEventFilter(this);
    ui->pgm_table_ts2_edit_3->installEventFilter(this);
    ui->pgm_table_ts2_edit_4->installEventFilter(this);
    ui->pgm_table_ts3_edit_1->installEventFilter(this);
    ui->pgm_table_ts3_edit_2->installEventFilter(this);
    ui->pgm_table_ts3_edit_3->installEventFilter(this);
    ui->pgm_table_ts3_edit_4->installEventFilter(this);
    //ui->pgm_table_wt_edit_1->installEventFilter(this);
    ui->pgm_table_wt_edit_2->installEventFilter(this);
    //ui->pgm_table_wt_edit_3->installEventFilter(this);
    ui->pgm_table_wt_edit_4->installEventFilter(this);



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
    ui->pgm_table_step_edit_1->setText(edit_pgm_list_step[0]);
    ui->pgm_table_step_edit_2->setText(edit_pgm_list_step[1]);
    ui->pgm_table_step_edit_3->setText(edit_pgm_list_step[2]);
    ui->pgm_table_step_edit_4->setText(edit_pgm_list_step[3]);


    //表格标题设置

    ui->label_step->setStyleSheet("QLabel#label_step{color:rgb(53,87,54);border:1px solid rgb(200,200,200)}");
    ui->label_temp->setStyleSheet("QLabel#label_temp{color:rgb(53,87,54);border:1px solid rgb(200,200,200)}");
    ui->label_humi->setStyleSheet("QLabel#label_humi{color:rgb(53,87,54);border:1px solid rgb(200,200,200)}");
    ui->label_hms->setStyleSheet("QLabel#label_hms{color:rgb(53,87,54);border:1px solid rgb(200,200,200)}");
    ui->label_ts1->setStyleSheet("QLabel#label_ts1{color:rgb(53,87,54);border:1px solid rgb(200,200,200)}");
    ui->label_ts2->setStyleSheet("QLabel#label_ts2{color:rgb(53,87,54);border:1px solid rgb(200,200,200)}");
    ui->label_ts3->setStyleSheet("QLabel#label_ts3{color:rgb(53,87,54);border:1px solid rgb(200,200,200)}");
    ui->label_wt->setStyleSheet("QLabel#label_wt{color:rgb(53,87,54);border:1px solid rgb(200,200,200)}");

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

    ui->delete_program_pbtn->setStyleSheet("QPushButton#delete_program_pbtn{background:transparent;"
                                           "border:2px solid rgb(71,129,52)}");
    ui->insert_pbtn->setStyleSheet("QPushButton#insert_pbtn{background:transparent;"
                                           "border:2px solid rgb(71,129,52)}");
    ui->delete_program->setStyleSheet("QPushButton#delete_program{background:transparent;"
                                           "border:2px solid rgb(71,129,52)}");

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
   /* ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
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
                                                   "color:rgb(74,122,60)}");*/
    //QCustomPlot
    ui->CurveWidget->yAxis2->setVisible(true);
    ui->CurveWidget->setBackground(QBrush(Qt::black));
    ui->CurveWidget->axisRect()->setBackground(QBrush(Qt::black));
    ui->CurveWidget->xAxis->setBasePen(QPen(Qt::white,1));
    ui->CurveWidget->yAxis->setBasePen(QPen(Qt::white,1));
    ui->CurveWidget->yAxis2->setBasePen(QPen(Qt::white,1));
    ui->CurveWidget->xAxis->grid()->setPen(QPen(QColor(180,180,180),1,Qt::PenStyle::DashLine));
    ui->CurveWidget->yAxis->grid()->setPen(QPen(QColor(180,180,180),1,Qt::PenStyle::DashLine));
    ui->CurveWidget->yAxis2->grid()->setPen(QPen(QColor(180,180,180),1,Qt::PenStyle::DashLine));
    ui->CurveWidget->xAxis->grid()->setSubGridVisible(false);
    ui->CurveWidget->yAxis->grid()->setSubGridVisible(false);
    ui->CurveWidget->yAxis2->grid()->setSubGridVisible(false);
    QPen xM;
    xM.setColor(Qt::white);
    xM.setWidth(1);
    ui->CurveWidget->xAxis->setTickPen(xM);
    ui->CurveWidget->yAxis->setTickPen(xM);
    ui->CurveWidget->yAxis2->setTickPen(xM);
    QPen xS;
    xS.setColor(Qt::white);
    ui->CurveWidget->xAxis->setSubTickPen(xS);
    ui->CurveWidget->yAxis->setSubTickPen(xS);
    ui->CurveWidget->yAxis2->setSubTickPen(xS);
    QFont xFont;
    xFont.setPixelSize(14);
    ui->CurveWidget->xAxis->setLabelColor(Qt::white);
    ui->CurveWidget->yAxis->setLabelColor(Qt::white);
    ui->CurveWidget->yAxis2->setLabelColor(Qt::white);
    ui->CurveWidget->xAxis->setLabelFont(xFont);
    ui->CurveWidget->yAxis->setLabelFont(xFont);
    ui->CurveWidget->yAxis2->setLabelFont(xFont);
    ui->CurveWidget->xAxis->setTickLabelColor(Qt::transparent);
    ui->CurveWidget->yAxis->setTickLabelColor(Qt::white);
    ui->CurveWidget->yAxis2->setTickLabelColor(Qt::white);
    ui->CurveWidget->xAxis->setTickLabelFont(xFont);
    ui->CurveWidget->yAxis->setTickLabelFont(xFont);
    ui->CurveWidget->yAxis2->setTickLabelFont(xFont);
    ui->CurveWidget->xAxis->setRange(0,100);
    ui->CurveWidget->xAxis->ticker()->setTickCount(11);
    //    ui->CurveWidget->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
    ui->CurveWidget->yAxis->setRange(-75,175);
    ui->CurveWidget->yAxis->ticker()->setTickCount(11);
    ui->CurveWidget->yAxis2->setRange(0,100);
    ui->CurveWidget->yAxis2->ticker()->setTickCount(11);

    //测试曲线
    size = 660;
    xdata.resize(curve_numb);
    ydata.resize(curve_numb);
    for(int i=0 ; i<curve_numb ; i++)
    {
        xdata[i].resize(size);
        ydata[i].resize(size);
    }
    startTime = "2023-3-28 08:42:44";
    dataInfoSize = curve_numb*2+3;
    dataInfo = new double[dataInfoSize];
    dataInfo[0] = 1;
    dataInfo[1] = 0;
    dataInfo[2] = 660;
    dataInfo[3] = -75;
    dataInfo[4] = 180;
    dataInfo[5] = 0;
    dataInfo[6] = 100;
    axisInfo = new QString[curve_numb];
    axisInfo[0] = "Temperature(°C)";
    axisInfo[1] = "Humidity(%)";
    status=1;
    endSize = 0;
    for(int i=0 ; i<curve_numb ; i++)
    {
        xdata[i].clear();
        ydata[i].clear();
        curve_data_num[i] = 0;
    }
    this->draw(curve_numb,size,xdata,ydata,startTime,dataInfo,axisInfo,status);
    curveTimer = new QTimer(this);
    curveTimer->start(200);

    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&Program_Editing::currentTime);

    //页面跳转
    //connect(ui->font_page_pbtn,&QPushButton::clicked,this,&Program_Editing::programEditing_sendTo_mainWindow);

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
    emit touch_InterfaceDataSignal(addr_touch_edit_pgm_lastpage,"1");
}

/*
 * time: 2022-11-4
 * type: public slots
 * effect: 下一页按钮
 * influence: ui->nextPage_pbtn clicked
*/
void Program_Editing::on_nextPage_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(addr_touch_edit_pgm_nextpage,"2");

}

/*
 * time: 2022-11-4
 * type: public slots
 * effect: 第一页按钮
 * influence: ui->firstPage_pbtn clicked
*/
void Program_Editing::on_firstPage_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(addr_touch_edit_pgm_firstpage,"3");
}

/*
 * time: 2022-11-4
 * type: public slots
 * effect: 最后一页按钮
 * influence: ui->endPage_pbtn clicked
*/
void Program_Editing::on_endPage_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(addr_touch_edit_pgm_endpage,"4");
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

            if(ui->choose_program_edit->hasFocus()){
                ui->choose_program_edit->clearFocus();
            }
            else if(ui->program_name_edit->hasFocus()){
                ui->program_name_edit->clearFocus();
            }else if(ui->pgm_table_temp_edit_1->hasFocus()){
                ui->pgm_table_temp_edit_1->clearFocus();
            }else if(ui->pgm_table_temp_edit_2->hasFocus()){
                ui->pgm_table_temp_edit_2->clearFocus();
            }else if(ui->pgm_table_temp_edit_3->hasFocus()){
                ui->pgm_table_temp_edit_3->clearFocus();
            }else if(ui->pgm_table_temp_edit_4->hasFocus()){
                ui->pgm_table_temp_edit_4->clearFocus();
            }
        }
    }
    if(watched == ui->program_name_edit)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Keyboard_Signal(addr_touch_pgm_edit_pgm_name);
            ui->program_name_edit->setFocus();
        }
    }else if(watched == ui->choose_program_edit){
        if(event->type() == QEvent::MouseButtonPress){
            emit touch_InterfaceDataSignal(addr_touch_pgm_edit_pgm_number, "0");
            ui->choose_program_edit->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_temp_edit_1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_value1_row1);
            ui->pgm_table_temp_edit_1->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_temp_edit_2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_value1_row2);
            ui->pgm_table_temp_edit_2->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_temp_edit_3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_value1_row3);
            ui->pgm_table_temp_edit_3->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_temp_edit_4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_value1_row4);
            ui->pgm_table_temp_edit_4->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_humi_edit_1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_value2_row1);
            ui->pgm_table_humi_edit_1->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_humi_edit_2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_value2_row2);
            ui->pgm_table_humi_edit_2->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_humi_edit_3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_value2_row3);
            ui->pgm_table_humi_edit_3->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_humi_edit_4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_value2_row4);
            ui->pgm_table_humi_edit_4->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_hour_edit_1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_hour_row1);
            ui->pgm_table_hour_edit_1->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_hour_edit_2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_hour_row2);
            ui->pgm_table_hour_edit_2->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_hour_edit_3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_hour_row3);
            ui->pgm_table_hour_edit_3->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_hour_edit_4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_hour_row4);
            ui->pgm_table_hour_edit_4->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_min_edit_1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_min_row1);
            ui->pgm_table_min_edit_1->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_min_edit_2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_min_row2);
            ui->pgm_table_min_edit_2->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_min_edit_3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_min_row3);
            ui->pgm_table_min_edit_3->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_min_edit_4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_min_row4);
            ui->pgm_table_min_edit_4->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_sec_edit_1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_sec_row1);
            ui->pgm_table_sec_edit_1->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_sec_edit_2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_sec_row2);
            ui->pgm_table_sec_edit_2->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_sec_edit_3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_sec_row3);
            ui->pgm_table_sec_edit_3->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_sec_edit_4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_sec_row4);
            ui->pgm_table_sec_edit_4->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts1_edit_1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts1_row1);
            ui->pgm_table_ts1_edit_1->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts1_edit_2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts1_row2);
            ui->pgm_table_ts1_edit_2->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts1_edit_3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts1_row3);
            ui->pgm_table_ts1_edit_3->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts1_edit_4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts1_row4);
            ui->pgm_table_ts1_edit_4->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts2_edit_1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts2_row1);
            ui->pgm_table_ts2_edit_1->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts2_edit_2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts2_row2);
            ui->pgm_table_ts2_edit_2->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts2_edit_3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts2_row3);
            ui->pgm_table_ts2_edit_3->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts2_edit_4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts2_row4);
            ui->pgm_table_ts2_edit_4->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts3_edit_1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts3_row1);
            ui->pgm_table_ts3_edit_1->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts3_edit_2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts3_row2);
            ui->pgm_table_ts3_edit_2->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts3_edit_3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts3_row3);
            ui->pgm_table_ts3_edit_3->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_ts3_edit_4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_ts3_row4);
            ui->pgm_table_ts3_edit_4->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_wt_edit_1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_wt_row1);
            ui->pgm_table_wt_edit_1->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_wt_edit_2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_wt_row2);
            ui->pgm_table_wt_edit_2->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_wt_edit_3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_wt_row3);
            ui->pgm_table_wt_edit_3->setFocus();   //lineEdit聚焦
        }
    }else if(watched == ui->pgm_table_wt_edit_4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_edit_pgm_wt_row4);
            ui->pgm_table_wt_edit_4->setFocus();   //lineEdit聚焦
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




void Program_Editing::on_saving_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(addr_touch_edit_pgm_save,"1");
}


void Program_Editing::on_loop_setting_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(addr_touch_edit_pgm_save,"1");
}

void Program_Editing::on_new_program_pbtn_clicked()
{
    //popUpWindow04.setStatus(1);
    //int num = popUpWindow04.getMapIndex();
    //ui->choose_program_edit->setText(QString::number(num));
    emit touch_InterfaceDataSignal(addr_touch_edit_pgm_newpgm,"0");
}



void Program_Editing::on_delete_program_pbtn_clicked()
{
    //popUpWindow04.setStatus(2);
    emit touch_InterfaceDataSignal(addr_touch_edit_pgm_delpgm,"0");
}


void Program_Editing::freezeOneSec()
{
    /*
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
    ui->loop_setting_pbtn->setEnabled(true);*/
}


/*
 * Param:
 * curve_numb 曲线条数
 * size 数据数量
 * xdata x轴数据 xdata[a][b] a为曲线index b为数据位
 * ydata y轴数据 ydata[a][b] a为曲线index b为数据位
 * startTime 格式为yy-MM-dd hh:mm:ss的起始时间
 * dataInfo 大小为curve_numb+3 存储了间隔时间 x轴 y轴范围 固定[0]为间隔时间 后每两个存储空间为轴范围 顺序为 x轴 y1轴 y2轴.....
 * axisInfo 大小为curve_numb 轴信息 依次对应y1轴 y2轴
 * status 曲线状态 1为静态 2为动态
 */
void Program_Editing::draw(int num,int size,QVector<QVector<double>> xdata,QVector<QVector<double>> ydata,QString startTime,double* dataInfo,QString* axisInfo,int status)
{
    startTime = startTime;
    axisInfo = axisInfo;
    size = size;

    switch (status) {
    case 1:
    {
        //qDebug() << "dataInfo[1]"<< dataInfo[1];
        //qDebug() << "dataInfo[2]"<< dataInfo[2];
        ui->CurveWidget->xAxis->setRange(dataInfo[1],dataInfo[2]);
        ui->CurveWidget->yAxis->setRange(dataInfo[3],dataInfo[4]);
        ui->CurveWidget->yAxis2->setRange(dataInfo[5],dataInfo[6]);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis2);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis2);

        QPen graphPen;
        for(int i=0 ; i<num; i++)
        {
            graphPen.setColor(color[i]);
            graphPen.setWidth(2);
            ui->CurveWidget->graph(i)->setPen(graphPen);
            ui->CurveWidget->graph(i)->setAntialiasedFill(true);
            ui->CurveWidget->graph(i)->setData(xdata[i],ydata[i]);
        }

        ui->CurveWidget->replot();
        break;
    }
    default:
        break;
    }
}

void Program_Editing::addrSetPgmEditInterfaceData(int addr_num, QString set_value){

    qDebug() << QString("addrSetMonitorInterfaceData addr_num: %1").arg(addr_num);
    QString covert_data;
    int for_i;
    switch(addr_num)
    {
    case 0xEB:
        if(0x55 == set_value.toInt())
        {
            for(for_i = 0; for_i < curve_numb; ++for_i)
            {
                xdata[for_i].clear();
                ydata[for_i].clear();
                curve_data_num[for_i] = 0;
            }
            ui->CurveWidget->clearGraphs();
            ui->CurveWidget->replot();
        }else
        if(0x5A == set_value.toInt())
        {
            xdata[0].clear();
            ydata[0].clear();
            curve_data_num[0] = 0;
        }else
            if(0x5B == set_value.toInt())
            {
                xdata[1].clear();
                ydata[1].clear();
                curve_data_num[1] = 0;
            }
        break;
    case 0x2385: // curve 5
        covert_data = convertToDecimalString(set_value,1);
        xdata[0].append(curve_data_num[0]++);
        qDebug() << "new data is" << covert_data.toFloat();
        ydata[0].append(covert_data.toFloat());
        break;
    case 0x2386: // curve 6
        covert_data = convertToDecimalString(set_value,1);
        xdata[1].append(curve_data_num[1]++);
        qDebug() << "new data is" << covert_data.toFloat();
        ydata[1].append(covert_data.toFloat());
        break;
    case addr_pgm_edit_pgm_number:
        setChooseProgram(set_value);
        break;
    case addr_pgm_edit_pgm_name:
        setProgramName(set_value);
        break;
    case addr_pgm_edit_hilimit:
        covert_data = convertToDecimalString(set_value,2);
        setHighTempProtect(covert_data);
        break;
    case addr_pgm_edit_lolimit:
        covert_data = convertToDecimalString(set_value,2);
        setLowTempProtect(covert_data);
        break;
    case addr_edit_pgm_step_row1:
        edit_pgm_list_step[0] = set_value;
        ui->pgm_table_step_edit_1->setText(set_value);
        break;
    case addr_edit_pgm_step_row2:
        edit_pgm_list_step[1] = set_value;
        ui->pgm_table_step_edit_2->setText(set_value);
        break;
    case addr_edit_pgm_step_row3:
        edit_pgm_list_step[2] = set_value;
        ui->pgm_table_step_edit_3->setText(set_value);
        break;
    case addr_edit_pgm_step_row4:
        edit_pgm_list_step[3] = set_value;
        ui->pgm_table_step_edit_4->setText(set_value);
        break;
    case addr_edit_pgm_value1_row1:
        covert_data = convertToDecimalString(set_value,2);
        edit_pgm_list_temp[0] = covert_data;
        ui->pgm_table_temp_edit_1->setText(covert_data);
        break;
    case addr_edit_pgm_value1_row2:
        covert_data = convertToDecimalString(set_value,2);
        edit_pgm_list_temp[1] = covert_data;
        ui->pgm_table_temp_edit_2->setText(covert_data);
        break;
    case addr_edit_pgm_value1_row3:
        covert_data = convertToDecimalString(set_value,2);
        edit_pgm_list_temp[2] = covert_data;
        ui->pgm_table_temp_edit_3->setText(covert_data);
        break;
    case addr_edit_pgm_value1_row4:
        covert_data = convertToDecimalString(set_value,2);
        edit_pgm_list_temp[3] = covert_data;
        ui->pgm_table_temp_edit_4->setText(covert_data);
        break;
    case addr_edit_pgm_value2_row1:
        covert_data = convertToDecimalString(set_value,1);
        edit_pgm_list_humi[0] = covert_data;
        ui->pgm_table_humi_edit_1->setText(covert_data);
        break;
    case addr_edit_pgm_value2_row2:
        covert_data = convertToDecimalString(set_value,1);
        edit_pgm_list_humi[1] = covert_data;
        ui->pgm_table_humi_edit_2->setText(covert_data);
        break;
    case addr_edit_pgm_value2_row3:
        covert_data = convertToDecimalString(set_value,1);
        edit_pgm_list_humi[2] = covert_data;
        ui->pgm_table_humi_edit_3->setText(covert_data);
        break;
    case addr_edit_pgm_value2_row4:
        covert_data = convertToDecimalString(set_value,1);
        edit_pgm_list_humi[3] = covert_data;
        ui->pgm_table_humi_edit_4->setText(covert_data);
        break;
    case addr_edit_pgm_hour_row1:
        edit_pgm_list_hour[0] = set_value;
        ui->pgm_table_hour_edit_1->setText(set_value);
        break;
    case addr_edit_pgm_hour_row2:
        edit_pgm_list_hour[1] = set_value;
        ui->pgm_table_hour_edit_2->setText(set_value);
        break;
    case addr_edit_pgm_hour_row3:
        edit_pgm_list_hour[2] = set_value;
        ui->pgm_table_hour_edit_3->setText(set_value);
        break;
    case addr_edit_pgm_hour_row4:
        edit_pgm_list_hour[3] = set_value;
        ui->pgm_table_hour_edit_4->setText(set_value);
        break;
    case addr_edit_pgm_min_row1:
        edit_pgm_list_min[0] = set_value;
        ui->pgm_table_min_edit_1->setText(set_value);
        break;
    case addr_edit_pgm_min_row2:
        edit_pgm_list_min[1] = set_value;
        ui->pgm_table_min_edit_2->setText(set_value);
        break;
    case addr_edit_pgm_min_row3:
        edit_pgm_list_min[2] = set_value;
        ui->pgm_table_min_edit_3->setText(set_value);
        break;
    case addr_edit_pgm_min_row4:
        edit_pgm_list_min[3] = set_value;
        ui->pgm_table_min_edit_4->setText(set_value);
        break;
    case addr_edit_pgm_sec_row1:
        edit_pgm_list_sec[0] = set_value;
        ui->pgm_table_sec_edit_1->setText(set_value);
        break;
    case addr_edit_pgm_sec_row2:
        edit_pgm_list_sec[1] = set_value;
        ui->pgm_table_sec_edit_2->setText(set_value);
        break;
    case addr_edit_pgm_sec_row3:
        edit_pgm_list_sec[2] = set_value;
        ui->pgm_table_sec_edit_3->setText(set_value);
        break;
    case addr_edit_pgm_sec_row4:
        edit_pgm_list_sec[3] = set_value;
        ui->pgm_table_sec_edit_4->setText(set_value);
        break;
    case addr_edit_pgm_ts1_row1:
        edit_pgm_list_ts1[0] = set_value;
        ui->pgm_table_ts1_edit_1->setText(set_value);
        break;
    case addr_edit_pgm_ts1_row2:
        edit_pgm_list_ts1[1] = set_value;
        ui->pgm_table_ts1_edit_2->setText(set_value);
        break;
    case addr_edit_pgm_ts1_row3:
        edit_pgm_list_ts1[2] = set_value;
        ui->pgm_table_ts1_edit_3->setText(set_value);
        break;
    case addr_edit_pgm_ts1_row4:
        edit_pgm_list_ts1[3] = set_value;
        ui->pgm_table_ts1_edit_4->setText(set_value);
        break;
    case addr_edit_pgm_ts2_row1:
        edit_pgm_list_ts2[0] = set_value;
        ui->pgm_table_ts2_edit_1->setText(set_value);
        break;
    case addr_edit_pgm_ts2_row2:
        edit_pgm_list_ts2[1] = set_value;
        ui->pgm_table_ts2_edit_2->setText(set_value);
        break;
    case addr_edit_pgm_ts2_row3:
        edit_pgm_list_ts2[2] = set_value;
        ui->pgm_table_ts2_edit_3->setText(set_value);
        break;
    case addr_edit_pgm_ts2_row4:
        edit_pgm_list_ts2[3] = set_value;
        ui->pgm_table_ts2_edit_4->setText(set_value);
        break;
    case addr_edit_pgm_ts3_row1:
        edit_pgm_list_ts3[0] = set_value;
        ui->pgm_table_ts3_edit_1->setText(set_value);
        break;
    case addr_edit_pgm_ts3_row2:
        edit_pgm_list_ts3[1] = set_value;
        ui->pgm_table_ts3_edit_2->setText(set_value);
        break;
    case addr_edit_pgm_ts3_row3:
        edit_pgm_list_ts3[2] = set_value;
        ui->pgm_table_ts3_edit_3->setText(set_value);
        break;
    case addr_edit_pgm_ts3_row4:
        edit_pgm_list_ts3[3] = set_value;
        ui->pgm_table_ts3_edit_4->setText(set_value);
        break;
    case addr_edit_pgm_wt_row1:
        edit_pgm_list_wt[0] = set_value;
        ui->pgm_table_wt_edit_1->setText(set_value);
        break;
    case addr_edit_pgm_wt_row2:
        edit_pgm_list_wt[1] = set_value;
        ui->pgm_table_wt_edit_2->setText(set_value);
        break;
    case addr_edit_pgm_wt_row3:
        edit_pgm_list_wt[2] = set_value;
        ui->pgm_table_wt_edit_3->setText(set_value);
        break;
    case addr_edit_pgm_wt_row4:
        edit_pgm_list_wt[3] = set_value;
        ui->pgm_table_wt_edit_4->setText(set_value);
        break;

    default:break;
    }
}

void Program_Editing::on_insert_pbtn_clicked()
{
    emit Request_Use_Keyboard_Signal(addr_touch_edit_pgm_insertsgm);

}

void Program_Editing::on_delete_program_clicked()
{
    emit Request_Use_Keyboard_Signal(addr_touch_edit_pgm_delsgm);

}

void Program_Editing::on_font_page_pbtn_clicked()
{
    emit programEditing_to_mainWindow();
}
void Program_Editing::refreshPgmEditInterfaceData()
{
    this->draw(curve_numb,size,xdata,ydata,startTime,dataInfo,axisInfo,status);
    setChooseProgram(chooseProgram);
    setProgramName(programName);
    setHighTempProtect(highTempProtect);
    setLowTempProtect(lowTempProtect);
    ui->pgm_table_step_edit_1->setText(edit_pgm_list_step[0]);
    ui->pgm_table_step_edit_2->setText(edit_pgm_list_step[1]);
    ui->pgm_table_step_edit_3->setText(edit_pgm_list_step[2]);
    ui->pgm_table_step_edit_4->setText(edit_pgm_list_step[3]);
    ui->pgm_table_temp_edit_1->setText(edit_pgm_list_temp[0]);
    ui->pgm_table_temp_edit_2->setText(edit_pgm_list_temp[1]);
    ui->pgm_table_temp_edit_3->setText(edit_pgm_list_temp[2]);
    ui->pgm_table_temp_edit_4->setText(edit_pgm_list_temp[3]);
    ui->pgm_table_humi_edit_1->setText(edit_pgm_list_humi[0]);
    ui->pgm_table_humi_edit_2->setText(edit_pgm_list_humi[1]);
    ui->pgm_table_humi_edit_3->setText(edit_pgm_list_humi[2]);
    ui->pgm_table_humi_edit_4->setText(edit_pgm_list_humi[3]);
    ui->pgm_table_hour_edit_1->setText( edit_pgm_list_hour[0]);
    ui->pgm_table_hour_edit_2->setText(edit_pgm_list_hour[1]);
    ui->pgm_table_hour_edit_3->setText(edit_pgm_list_hour[2]);
    ui->pgm_table_hour_edit_4->setText(edit_pgm_list_hour[3]);
    ui->pgm_table_min_edit_1->setText(edit_pgm_list_min[0]);
    ui->pgm_table_min_edit_2->setText(edit_pgm_list_min[1]);
    ui->pgm_table_min_edit_3->setText(edit_pgm_list_min[2]);
    ui->pgm_table_min_edit_4->setText(edit_pgm_list_min[3]);
    ui->pgm_table_sec_edit_1->setText(edit_pgm_list_sec[0]);
    ui->pgm_table_sec_edit_2->setText(edit_pgm_list_sec[1]);
    ui->pgm_table_sec_edit_3->setText(edit_pgm_list_sec[2]);
    ui->pgm_table_sec_edit_4->setText(edit_pgm_list_sec[3]);
    ui->pgm_table_ts1_edit_1->setText(edit_pgm_list_ts1[0]);
    ui->pgm_table_ts1_edit_2->setText(edit_pgm_list_ts1[1]);
    ui->pgm_table_ts1_edit_3->setText(edit_pgm_list_ts1[2]);
    ui->pgm_table_ts1_edit_4->setText(edit_pgm_list_ts1[3]);
    ui->pgm_table_ts2_edit_1->setText(edit_pgm_list_ts2[0]);
    ui->pgm_table_ts2_edit_2->setText(edit_pgm_list_ts2[1]);
    ui->pgm_table_ts2_edit_3->setText(edit_pgm_list_ts2[2]);
    ui->pgm_table_ts2_edit_4->setText(edit_pgm_list_ts2[3]);
    ui->pgm_table_ts3_edit_1->setText(edit_pgm_list_ts3[0]);
    ui->pgm_table_ts3_edit_2->setText(edit_pgm_list_ts3[1]);
    ui->pgm_table_ts3_edit_3->setText(edit_pgm_list_ts3[2]);
    ui->pgm_table_ts3_edit_4->setText(edit_pgm_list_ts3[3]);
    ui->pgm_table_wt_edit_1->setText(edit_pgm_list_wt[0]);
    ui->pgm_table_wt_edit_2->setText(edit_pgm_list_wt[1]);
    ui->pgm_table_wt_edit_3->setText(edit_pgm_list_wt[2]);
    ui->pgm_table_wt_edit_4->setText(edit_pgm_list_wt[3]);

    ui->status_text->setText(sys_info.run_sta_string);
    if(sys_info.run_sta_color == 0) // green
    {
        ui->status_text->setStyleSheet("QLabel#status_text{color:rgb(72,129,52)}");
    }else
        if(sys_info.run_sta_color == 1) //red
        {
            ui->status_text->setStyleSheet("QLabel#status_text{color:rgb(253,0,0)}");
        }else
            if(sys_info.run_sta_color == 2) // black
            {
                ui->status_text->setStyleSheet("QLabel#status_text{color:rgb(253,0,0)}");
            }else
                if(sys_info.run_sta_color == 3) //orange
                {
                    ui->status_text->setStyleSheet("QLabel#status_text{color:rgb(255, 170, 0)}");
                }
    if(sys_info.sd_flag)
    {
        ui->status_1->setStyleSheet("QLabel#status_1{background-image:url(:/Image/24/62.bmp)}");
    }else{
        ui->status_1->setStyleSheet("QLabel#status_1{background-image:url(:/Image/24/61.bmp)}");
    }
    if(sys_info.usb_flag)
    {
        ui->status_2->setStyleSheet("QLabel#status_2{background-image:url(:/Image/24/64.bmp)}");
    }else{
        ui->status_2->setStyleSheet("QLabel#status_2{background-image:url(:/Image/24/63.bmp)}");
    }
    if(sys_info.burn_flag)
    {
        ui->status_3->setStyleSheet("QLabel#status_3{background-image:url(:/Image/24/66.bmp)}");
    }else{
        ui->status_3->setStyleSheet("QLabel#status_3{background-image:url(:/Image/24/65.bmp)}");
    }
    if(sys_info.wifi_flag)
    {
        ui->status_4->setStyleSheet("QLabel#status_4{background-image:url(:/Image/24/68.bmp)}");
    }else{
        ui->status_4->setStyleSheet("QLabel#status_4{background-image:url(:/Image/24/67.bmp)}");
    }
    if(sys_info.host_mode)
    {
        ui->status_5->setStyleSheet("QLabel#status_5{background-image:url(:/Image/24/70.bmp)}");
    }else{
        ui->status_5->setStyleSheet("QLabel#status_5{background-image:url(:/Image/24/69.bmp)}");
    }
    if(sys_info.abnormal_flag)
    {
        ui->status_6->setStyleSheet("QLabel#status_6{background-image:url(:/Image/24/72.bmp)}");
    }else{
        ui->status_6->setStyleSheet("QLabel#status_6{background-image:url(:/Image/24/71.bmp)}");
    }

}
