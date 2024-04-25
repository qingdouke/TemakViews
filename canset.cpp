#include "canset.h"
#include "ui_canset.h"

#include <QFile>
#include <QButtonGroup>
#include <QTextStream>
#include <QTime>

CANSET::CANSET(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CANSET)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint); //设置为无边框
    this->move(0,0); // 窗口移动到屏幕的左上角位置(0,0)

    //Header背景颜色
    ui->Header->setStyleSheet("QWidget#Header{background-color:rgb(72,129,52)}");
    //标题颜色
    ui->title->setStyleSheet("QLabel#title{color:white}");
    //logo颜色
    ui->logo->setStyleSheet("QLabel#logo{background-image:url(:/Image/85/1.bmp)}");

    //Main背景颜色渐变
    ui->Main->setStyleSheet("QWidget#Main{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 white,stop:1 rgb(177,203,166))}");

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->previous_page_pbtn->setStyleSheet("QPushButton#previous_page_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");

    ui->baudrate_label->setStyleSheet("QLabel#baudrate_label{color:rgb(72,129,52)}");

    QFile file(":/qss/CANSET.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    QButtonGroup* baudrate_group = new QButtonGroup(this);
    baudrate_group->setExclusive(true);
    baudrate_group->addButton(ui->baudrate_1000k_checkBox,1);
    baudrate_group->addButton(ui->baudrate_800k_checkBox,2);
    baudrate_group->addButton(ui->baudrate_500k_checkBox,3);
    baudrate_group->addButton(ui->baudrate_250k_checkBox,4);
    baudrate_group->addButton(ui->baudrate_125k_checkBox,5);
    baudrate_group->addButton(ui->baudrate_100k_checkBox,6);
    baudrate_group->addButton(ui->baudrate_50k_checkBox,7);
    baudrate_group->addButton(ui->baudrate_20k_checkBox,8);
    baudrate_group->addButton(ui->baudrate_10k_checkBox,9);
    baudrate_group->addButton(ui->baudrate_5k_checkBox,10);
    baudrate_group->addButton(ui->baudrate_2k_checkBox,11);

    ui->period_label->setStyleSheet("QLabel#period_label{color:rgb(72,129,52)}");
    ui->period_line->setStyleSheet("QLabel#period_line{background-color:rgb(72,129,52)}");
    ui->send_form_line_1->setStyleSheet("QLabel#send_form_line_1{background-color:rgb(72,129,52)}");
    ui->send_form_line_2->setStyleSheet("QLabel#send_form_line_2{background-color:rgb(72,129,52)}");
    ui->send_form_line_3->setStyleSheet("QLabel#send_form_line_3{background-color:rgb(72,129,52)}");
    ui->send_form_line_4->setStyleSheet("QLabel#send_form_line_4{background-color:rgb(72,129,52)}");
    ui->send_form_line_5->setStyleSheet("QLabel#send_form_line_5{background-color:rgb(72,129,52)}");
    ui->send_form_line_6->setStyleSheet("QLabel#send_form_line_6{background-color:rgb(72,129,52)}");
    ui->send_form_line_7->setStyleSheet("QLabel#send_form_line_7{background-color:rgb(72,129,52)}");
    ui->set_form_line_1->setStyleSheet("QLabel#set_form_line_1{background-color:rgb(72,129,52)}");
    ui->set_form_line_2->setStyleSheet("QLabel#set_form_line_2{background-color:rgb(72,129,52)}");
    ui->set_form_line_3->setStyleSheet("QLabel#set_form_line_3{background-color:rgb(72,129,52)}");
    ui->set_form_line_4->setStyleSheet("QLabel#set_form_line_4{background-color:rgb(72,129,52)}");
    ui->set_form_line_5->setStyleSheet("QLabel#set_form_line_5{background-color:rgb(72,129,52)}");

    //页面跳转
    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&CANSET::canset_sendTo_mainWindow);
    connect(ui->previous_page_pbtn,&QPushButton::clicked,this,&CANSET::canset_sendTo_parameterSetting);
}

CANSET::~CANSET()
{
    delete ui;
}

void CANSET::canset_sendTo_mainWindow()
{
    emit canset_to_mainWindow();
}

void CANSET::canset_sendTo_parameterSetting()
{
    emit canset_to_parameterSetting();
}

//void CANSET::freezeOneSec()
//{
//    ui->baudrate_2k_checkBox->setEnabled(false);
//    ui->baudrate_5k_checkBox->setEnabled(false);
//    ui->baudrate_10k_checkBox->setEnabled(false);
//    ui->baudrate_20k_checkBox->setEnabled(false);
//    ui->baudrate_50k_checkBox->setEnabled(false);
//    ui->baudrate_100k_checkBox->setEnabled(false);
//    ui->baudrate_125k_checkBox->setEnabled(false);
//    ui->baudrate_250k_checkBox->setEnabled(false);
//    ui->baudrate_500k_checkBox->setEnabled(false);
//    ui->baudrate_800k_checkBox->setEnabled(false);
//    ui->baudrate_1000k_checkBox->setEnabled(false);
//    ui->previous_page_pbtn->setEnabled(false);
//    ui->font_page_pbtn->setEnabled(false);
//    QTime dieTime = QTime::currentTime().addMSecs(1000);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
//    ui->baudrate_2k_checkBox->setEnabled(true);
//    ui->baudrate_5k_checkBox->setEnabled(true);
//    ui->baudrate_10k_checkBox->setEnabled(true);
//    ui->baudrate_20k_checkBox->setEnabled(true);
//    ui->baudrate_50k_checkBox->setEnabled(true);
//    ui->baudrate_100k_checkBox->setEnabled(true);
//    ui->baudrate_125k_checkBox->setEnabled(true);
//    ui->baudrate_250k_checkBox->setEnabled(true);
//    ui->baudrate_500k_checkBox->setEnabled(true);
//    ui->baudrate_800k_checkBox->setEnabled(true);
//    ui->baudrate_1000k_checkBox->setEnabled(true);
//    ui->previous_page_pbtn->setEnabled(true);
//    ui->font_page_pbtn->setEnabled(true);
//}

//优化以上代码
void CANSET::freezeOneSec()
{
    /*
    QList<QWidget*> widgetList = {ui->baudrate_1000k_checkBox, ui->baudrate_800k_checkBox, ui->baudrate_500k_checkBox,
                                   ui->baudrate_250k_checkBox, ui->baudrate_125k_checkBox, ui->baudrate_100k_checkBox,
                                   ui->baudrate_50k_checkBox, ui->baudrate_20k_checkBox, ui->baudrate_10k_checkBox,
                                   ui->baudrate_5k_checkBox, ui->baudrate_2k_checkBox, ui->previous_page_pbtn,
                                   ui->font_page_pbtn};

    for (auto& widget : widgetList) {
        widget->setEnabled(false);
    }
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    for (auto& widget : widgetList) {
        widget->setEnabled(true);
    }*/
}
void CANSET::addrSetCanInterfaceData(int addr_num, QString set_value){

    QString covert_data;
    switch(addr_num)
    {
    case addr_onepoint_test_temperature:
        covert_data = convertToDecimalString(set_value,2);
        setTemperatureText(covert_data);
        break;
    case addr_onepoint_test_humidity :
        covert_data = convertToDecimalString(set_value,1);
        setHumidityText(covert_data);
        break;
    case addr_onepoint_ramptime_hour:
        setSlopeTimeHText(set_value);
        break;
    case addr_onepoint_ramptime_min:
        setSlopeTimeMText(set_value);
        break;
    case addr_onepoint_ramptime_sec:
        setSlopeTimeSText(set_value);
        break;
    case addr_onepoint_constime_hour:
        setconstantTempHText(set_value);
        break;
    case addr_onepoint_constime_min:
        setconstantTempMText(set_value);
        break;
    case addr_onepoint_constime_sec:
        setconstantTempSText(set_value);
        break;
    case addr_onepoint_timesignal_1:
        setTS1Text(set_value);
        break;
    case addr_onepoint_timesignal_2:
        setTS2Text(set_value);
        break;
    case addr_onepoint_timesignal_3:
        setTS3Text(set_value);
        break;
    case addr_onepoint_wait:
        setWaitText(set_value);
        break;
    default:
        break;
    }
}
