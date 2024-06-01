#include "fixed_value_setting.h"
#include "ui_fixed_value_setting.h"
#include "sql_generic_data.h"
#include "general_tools.h"
#include "mainwindow.h"
#include "address_data_show.h"

#include <QTimer>
#include <QDateTime>
#include <QDebug>

Fixed_Value_Setting::Fixed_Value_Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fixed_Value_Setting)
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

    //form
    ui->form->setStyleSheet("QWidget#form{border:2px solid rgb(117,150,107)}");
    ui->wait_label->setStyleSheet("QLabel#wait_label{border:1px solid rgb(200,200,200);"
                                  "color:rgb(31,55,39);"
                                  "background-color:white}");
    ui->program_label->setStyleSheet("QLabel#program_label{border:1px solid rgb(200,200,200);"
                                     "background-color:white}");
    ui->constant_temperature_label->setStyleSheet("QLabel#constant_temperature_label{border:1px solid rgb(200,200,200);"
                                                  "background-color:white}");
    ui->temperature_label->setStyleSheet("QLabel#temperature_label{border:1px solid rgb(200,200,200);"
                                         "background-color:white}");
    ui->humidity_label->setStyleSheet("QLabel#humidity_label{border:1px solid rgb(200,200,200);"
                                      "background-color:white}");
    ui->sequence_label->setStyleSheet("QLabel#sequence_label{border:1px solid rgb(200,200,200);"
                                      "background-color:white}");
    ui->slope_time_label->setStyleSheet("QLabel#slope_time_label{border:1px solid rgb(200,200,200);"
                                        "background-color:white}");
    ui->t1->setStyleSheet("QLabel#t1{background-color:white;"
                          "border:1px solid rgb(200,200,200);"
                          "color:orange}");
    ui->t2->setStyleSheet("QLabel#t2{background-color:white;"
                          "border:1px solid rgb(200,200,200);"
                          "color:orange}");
    ui->t3->setStyleSheet("QLabel#t3{background-color:white;"
                          "border:1px solid rgb(200,200,200);"
                          "color:orange}");
    ui->t4->setStyleSheet("QLabel#t4{background-color:white;"
                          "border:1px solid rgb(200,200,200);"
                          "color:orange}");
    ui->t5->setStyleSheet("QLabel#t5{background-color:white;"
                          "border:1px solid rgb(200,200,200);"
                          "color:orange}");
    ui->t6->setStyleSheet("QLabel#t6{background-color:white;"
                          "border:1px solid rgb(200,200,200);"
                          "color:orange}");
    ui->t7->setStyleSheet("QLabel#t7{background-color:white;"
                          "border:1px solid rgb(200,200,200);"
                          "color:orange}");
    ui->border_left->setStyleSheet("QLabel#border_left{background-color:rgb(117,150,107)}");
    ui->border_right->setStyleSheet("QLabel#border_right{background-color:rgb(117,150,107)}");
    ui->border_buttom->setStyleSheet("QLabel#border_buttom{background-color:rgb(117,150,107)}");
    ui->border_top->setStyleSheet("QLabel#border_top{background-color:rgb(117,150,107)}");
    ui->temperature_lineEdit->setStyleSheet("QLineEdit#temperature_lineEdit{background:transparent;"
                                            "border:none}");
    ui->temperature_lineEdit->setInputMask("000.00");
    ui->temperature_lineEdit->setText(temperatureText);
    ui->humidity_lineEdit->setStyleSheet("QLineEdit#humidity_lineEdit{background:transparent;"
                                         "border:none}");
    ui->humidity_lineEdit->setInputMask("00.0");
    ui->humidity_lineEdit->setText(humidityText);
    ui->slopeTime_H_lineEdit->setStyleSheet("QLineEdit#slopeTime_H_lineEdit{background:transparent;"
                                            "border:none}");
    ui->slopeTime_H_lineEdit->setInputMask("0000");
    ui->slopeTime_H_lineEdit->setText(slopeTimeHText);
    ui->slopeTime_M_lineEdit->setStyleSheet("QLineEdit#slopeTime_M_lineEdit{background:transparent;"
                                            "border:none}");
    ui->slopeTime_M_lineEdit->setInputMask("00");
    ui->slopeTime_M_lineEdit->setText(slopeTimeMText);
    ui->slopeTime_S_lineEdit->setStyleSheet("QLineEdit#slopeTime_S_lineEdit{background:transparent;"
                                            "border:none}");
    ui->slopeTime_S_lineEdit->setInputMask("00");
    ui->slopeTime_S_lineEdit->setText(slopeTimeSText);
    ui->constantTemp_H_lineEdit->setStyleSheet("QLineEdit#constantTemp_H_lineEdit{background:transparent;"
                                               "border:none}");
    ui->constantTemp_H_lineEdit->setInputMask("0000");
    ui->constantTemp_H_lineEdit->setText(constantTempHText);
    ui->constantTemp_M_lineEdit->setStyleSheet("QLineEdit#constantTemp_M_lineEdit{background:transparent;"
                                               "border:none}");
    ui->constantTemp_M_lineEdit->setInputMask("00");
    ui->constantTemp_M_lineEdit->setText(constantTempMText);
    ui->constantTemp_S_lineEdit->setStyleSheet("QLineEdit#constantTemp_S_lineEdit{background:transparent;"
                                               "border:none}");
    ui->constantTemp_S_lineEdit->setInputMask("00");
    ui->constantTemp_S_lineEdit->setText(constantTempSText);
    ui->TS1_lineEdit->setStyleSheet("QLineEdit#TS1_lineEdit{background:transparent;"
                                    "border:none}");
    ui->TS1_lineEdit->setInputMask("0");
    ui->TS1_lineEdit->setText(TS1Text);
    ui->TS2_lineEdit->setStyleSheet("QLineEdit#TS2_lineEdit{background:transparent;"
                                    "border:none}");
    ui->TS2_lineEdit->setInputMask("0");
    ui->TS2_lineEdit->setText(TS2Text);
    ui->TS3_lineEdit->setStyleSheet("QLineEdit#TS3_lineEdit{background:transparent;"
                                    "border:none}");
    ui->TS3_lineEdit->setInputMask("0");
    ui->TS3_lineEdit->setText(TS3Text);
    ui->Wait_lineEdit->setStyleSheet("QLineEdit#Wait_lineEdit{background:transparent;"
                                     "border:none}");
    ui->Wait_lineEdit->setInputMask("0");
    ui->Wait_lineEdit->setText(waitText);

    //添加事件过滤器
    ui->temperature_lineEdit->installEventFilter(this);
    ui->humidity_lineEdit->installEventFilter(this);
    ui->slopeTime_H_lineEdit->installEventFilter(this);
    ui->slopeTime_M_lineEdit->installEventFilter(this);
    ui->slopeTime_S_lineEdit->installEventFilter(this);
    ui->constantTemp_H_lineEdit->installEventFilter(this);
    ui->constantTemp_M_lineEdit->installEventFilter(this);
    ui->constantTemp_S_lineEdit->installEventFilter(this);
    ui->TS1_lineEdit->installEventFilter(this);
    ui->TS2_lineEdit->installEventFilter(this);
    ui->TS3_lineEdit->installEventFilter(this);
    ui->Wait_lineEdit->installEventFilter(this);
    this->installEventFilter(this);

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    /*ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->previous_page_pbtn->setStyleSheet("QPushButton#previous_page_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");
    ui->saving_pbtn->setStyleSheet("QPushButton#saving_pbtn{border:2px solid rgb(74,122,60);"
                                                   "background-color:rgb(173,199,160);"
                                                   "border-radius:8px;"
                                                   "color:rgb(74,122,60)}");*/
    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&Fixed_Value_Setting::currentTime);

    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&Fixed_Value_Setting::fixedValueSetting_sendTo_mainWindow);
    connect(ui->previous_page_pbtn,&QPushButton::clicked,this,&Fixed_Value_Setting::fixedValueSetting_sendTo_programLoop);
    connect(ui->saving_pbtn,&QPushButton::clicked,this,&Fixed_Value_Setting::OnepointSavePgm);
}

Fixed_Value_Setting::~Fixed_Value_Setting()
{
    delete ui;
}

/*
 * time: 2022-11-15
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void Fixed_Value_Setting::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

/*
 * time: 2022-11-15
 * type: System EventFilter
 * effect: 事件过滤器
 * influence: this
*/
bool Fixed_Value_Setting::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type()==QEvent::MouseButtonPress){
            if(ui->temperature_lineEdit->hasFocus()){
                ui->temperature_lineEdit->clearFocus();
            }
            else if(ui->humidity_lineEdit->hasFocus()){
                ui->humidity_lineEdit->clearFocus();
            }
            else if(ui->slopeTime_H_lineEdit->hasFocus()){
                ui->slopeTime_H_lineEdit->clearFocus();
            }
            else if(ui->slopeTime_M_lineEdit->hasFocus()){
                ui->slopeTime_M_lineEdit->clearFocus();
            }
            else if(ui->slopeTime_S_lineEdit->hasFocus()){
                ui->slopeTime_S_lineEdit->clearFocus();
            }
            else if(ui->constantTemp_H_lineEdit->hasFocus()){
                ui->constantTemp_H_lineEdit->clearFocus();
            }
            else if(ui->constantTemp_M_lineEdit->hasFocus()){
                ui->constantTemp_M_lineEdit->clearFocus();
            }
            else if(ui->constantTemp_S_lineEdit->hasFocus()){
                ui->constantTemp_S_lineEdit->clearFocus();
            }
            else if(ui->TS1_lineEdit->hasFocus()){
                ui->TS1_lineEdit->clearFocus();
            }
            else if(ui->TS2_lineEdit->hasFocus()){
                ui->TS2_lineEdit->clearFocus();
            }
            else if(ui->TS3_lineEdit->hasFocus()){
                ui->TS3_lineEdit->clearFocus();
            }
            else if(ui->Wait_lineEdit->hasFocus()){
                ui->Wait_lineEdit->clearFocus();
            }
        }
    }

    if(watched == ui->temperature_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_test_temperature);
            ui->temperature_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->humidity_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_test_humidity);
            ui->humidity_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->slopeTime_H_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_ramptime_hour);
            ui->slopeTime_H_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->slopeTime_M_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_ramptime_min);
            ui->slopeTime_M_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->slopeTime_S_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_ramptime_sec);
            ui->slopeTime_S_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->constantTemp_H_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_constime_hour);
            ui->constantTemp_H_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->constantTemp_M_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_constime_min);
            ui->constantTemp_M_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->constantTemp_S_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_constime_sec);
            ui->constantTemp_S_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->TS1_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_timesignal_1);
            ui->TS1_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->TS2_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_timesignal_2);
            ui->TS2_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->TS3_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_timesignal_3);
            ui->TS3_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->Wait_lineEdit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(addr_touch_onepoint_wait);
            ui->Wait_lineEdit->setFocus();   //lineEdit聚焦
        }
    }
    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}

/*
 * time: 2022-11-17
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Fixed_Value_Setting::fixedValueSetting_sendTo_mainWindow(){
    emit fixedValueSetting_to_mainWindow();
    //emit touch_InterfaceDataSignal(addr_touch_pageturn_pbtn, QString::number(PGM_CYCLE));

}

/*
 * time: 2022-11-17
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Fixed_Value_Setting::fixedValueSetting_sendTo_programLoop(){
    emit fixedValueSetting_to_programLoop();
    //emit touch_InterfaceDataSignal(addr_touch_pageturn_pbtn, QString::number(MAIN_PAGE));
}

void Fixed_Value_Setting::OnepointSavePgm(){
    emit touch_InterfaceDataSignal(addr_onepoint_save_pgm, "0");
}
/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: temperatureText
*/
QString Fixed_Value_Setting::getTemperatureText(){
    return temperatureText;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: humidityText
*/
QString Fixed_Value_Setting::getHumidityText(){
    return humidityText;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: slopeTimeHText
*/
QString Fixed_Value_Setting::getSlopeTimeHText(){
    return slopeTimeHText;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: slopeTimeMText
*/
QString Fixed_Value_Setting::getSlopeTimeMText(){
    return slopeTimeMText;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: slopeTimeSText
*/
QString Fixed_Value_Setting::getSlopeTimeSText(){
    return slopeTimeSText;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: slopeconstantTempHText
*/
QString Fixed_Value_Setting::getconstantTempHText(){
    return constantTempHText;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: slopeconstantTempMText
*/
QString Fixed_Value_Setting::getconstantTempMText(){
    return constantTempMText;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: slopeconstantTempSText
*/
QString Fixed_Value_Setting::getconstantTempSText(){
    return constantTempSText;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: TS1Text
*/
QString Fixed_Value_Setting::getTS1Text(){
    return TS1Text;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: TS2Text
*/
QString Fixed_Value_Setting::getTS2Text(){
    return TS2Text;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: TS3Text
*/
QString Fixed_Value_Setting::getTS3Text(){
    return TS3Text;
}

/*
 * time: 2022-11-17
 * type: Get
 * effect: Get函数
 * influence: waitText
*/
QString Fixed_Value_Setting::getWaitText(){
    return waitText;
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: temperatureText
*/
void Fixed_Value_Setting::setTemperatureText(QString strs){
    temperatureText = strs;
    ui->temperature_lineEdit->setText(temperatureText);
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: humidityText
*/
void Fixed_Value_Setting::setHumidityText(QString strs){
    humidityText = strs;
    ui->humidity_lineEdit->setText(humidityText);
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: slopeTimeHText
*/
void Fixed_Value_Setting::setSlopeTimeHText(QString strs){
    slopeTimeHText = strs;
    ui->slopeTime_H_lineEdit->setText(slopeTimeHText);
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: slopeTimeMText
*/
void Fixed_Value_Setting::setSlopeTimeMText(QString strs){
    slopeTimeMText = strs;
    ui->slopeTime_M_lineEdit->setText(slopeTimeMText);
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: slopeTimeSText
*/
void Fixed_Value_Setting::setSlopeTimeSText(QString strs){
    slopeTimeSText = strs;
    ui->slopeTime_S_lineEdit->setText(slopeTimeSText);
}


/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: constantTempHText
*/
void Fixed_Value_Setting::setconstantTempHText(QString strs){
    constantTempHText = strs;
    ui->constantTemp_H_lineEdit->setText(constantTempHText);
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: constantTempMText
*/
void Fixed_Value_Setting::setconstantTempMText(QString strs){
    constantTempMText = strs;
    ui->constantTemp_M_lineEdit->setText(constantTempMText);
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: constantTempSText
*/
void Fixed_Value_Setting::setconstantTempSText(QString strs){
    constantTempSText = strs;
    ui->constantTemp_S_lineEdit->setText(constantTempSText);
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: TS1Text
*/
void Fixed_Value_Setting::setTS1Text(QString strs){
    TS1Text = strs;
    ui->TS1_lineEdit->setText(TS1Text);
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: TS2Text
*/
void Fixed_Value_Setting::setTS2Text(QString strs){
    TS2Text = strs;
    ui->TS2_lineEdit->setText(TS2Text);
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: TS3Text
*/
void Fixed_Value_Setting::setTS3Text(QString strs){
    TS3Text = strs;
    ui->TS3_lineEdit->setText(TS3Text);
}

/*
 * time: 2022-11-17
 * type: Set
 * effect: Set函数
 * influence: waitText
*/
void Fixed_Value_Setting::setWaitText(QString strs){
    waitText = strs;
    ui->Wait_lineEdit->setText(waitText);
}

void Fixed_Value_Setting::freezeOneSec()
{/*
    ui->font_page_pbtn->setEnabled(false);
    ui->previous_page_pbtn->setEnabled(false);
    ui->saving_pbtn->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    ui->font_page_pbtn->setEnabled(true);
    ui->previous_page_pbtn->setEnabled(true);
    ui->saving_pbtn->setEnabled(true);*/
}

void Fixed_Value_Setting::addrSetOnepointInterfaceData(int addr_num, QString set_value){

    QString covert_data;
    switch(addr_num)
    {
    case addr_onepoint_test_temperature:
        covert_data = convertToDecimalString(set_value,2);
        temperatureText = covert_data;
        setTemperatureText(temperatureText);
        break;
    case addr_onepoint_test_humidity :
        covert_data = convertToDecimalString(set_value,1);
        humidityText = covert_data;
        setHumidityText(humidityText);
        break;
    case addr_onepoint_ramptime_hour:
        slopeTimeHText = set_value;
        setSlopeTimeHText(slopeTimeHText);
        break;
    case addr_onepoint_ramptime_min:
        slopeTimeMText = set_value;
        setSlopeTimeMText(slopeTimeMText);
        break;
    case addr_onepoint_ramptime_sec:
        slopeTimeSText = set_value;
        setSlopeTimeSText(slopeTimeSText);
        break;
    case addr_onepoint_constime_hour:
        constantTempHText = set_value;
        setconstantTempHText(set_value);
        break;
    case addr_onepoint_constime_min:
        constantTempMText = set_value;
        setconstantTempMText(set_value);
        break;
    case addr_onepoint_constime_sec:
        constantTempSText = set_value;
        setconstantTempSText(set_value);
        break;
    case addr_onepoint_timesignal_1:
        TS1Text = set_value;
        setTS1Text(set_value);
        break;
    case addr_onepoint_timesignal_2:
        TS2Text = set_value;
        setTS2Text(set_value);
        break;
    case addr_onepoint_timesignal_3:
        TS3Text = set_value;
        setTS3Text(set_value);
        break;
    case addr_onepoint_wait:
        waitText = set_value;
        setWaitText(set_value);
        break;
    default:
        break;
    }
}

void Fixed_Value_Setting::refreshOnePointInterfaceData()
{
    setTemperatureText(temperatureText);
    setHumidityText(humidityText);
    setSlopeTimeHText(slopeTimeHText);
    setSlopeTimeMText(slopeTimeMText);
    setSlopeTimeSText(slopeTimeSText);
    setconstantTempHText(constantTempHText);
    setconstantTempMText(constantTempMText);
    setconstantTempSText(constantTempSText);
    setTS1Text(TS1Text);
    setTS2Text(TS2Text);
    setTS3Text(TS3Text);
    setWaitText(waitText);
}
