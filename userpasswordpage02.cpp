#include "userpasswordpage02.h"
#include "ui_userpasswordpage02.h"
#include "general_tools.h"

#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QButtonGroup>

UserPasswordPage02::UserPasswordPage02(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPasswordPage02)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    this->move(0,0);

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

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->next_page_pbtn->setStyleSheet("QPushButton#next_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->previous_page_pbtn->setStyleSheet("QPushButton#previous_page_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");

    QFile file(":/qss/Userpasswordpage02.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    ui->define_temperture_display->installEventFilter(this);
    ui->high_temperature_range_display->installEventFilter(this);
    ui->define_time_display_H->installEventFilter(this);
    ui->define_time_display_M->installEventFilter(this);
    ui->low_temperature_range_display->installEventFilter(this);

    ui->ultrasonic_humidification_temperature_low_display->installEventFilter(this);
    ui->ultrasonic_humidification_temperature_high_display->installEventFilter(this);
    ui->ultrasonic_humidification_humidity_display->installEventFilter(this);

    this->installEventFilter(this);


    QButtonGroup *group = new QButtonGroup(this);
    group->setExclusive(true);
    group->addButton(ui->record_naming_method_checkBox_1,1);
    group->addButton(ui->record_naming_method_checkBox_2,2);

    ui->common_programs_pushButton->setStyleSheet("QPushButton#common_programs_pushButton{border:2px solid rgb(74,122,60);"
                                                  "background-color:rgb(173,199,160);"
                                                  "color:rgb(74,122,60)}");

    //ui->current_time的connect 显示previous_page_pbtn实时时间
    connect(timer,&QTimer::timeout,this,&UserPasswordPage02::currentTime);

    //页面跳转
    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&UserPasswordPage02::userPasswordPage02_sendTo_mainWindow);
    connect(ui->previous_page_pbtn,&QPushButton::clicked,this,&UserPasswordPage02::userPasswordPage02_sendTo_userPasswordPage01);
    connect(ui->next_page_pbtn,&QPushButton::clicked,this,&UserPasswordPage02::userPasswordPage02_sendTo_userPasswordPage03);
}

UserPasswordPage02::~UserPasswordPage02()
{
    delete ui;
}

void UserPasswordPage02::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}


void UserPasswordPage02::userPasswordPage02_sendTo_userPasswordPage01(){
    emit userPasswordPage02_to_userPasswordPage01();
}

void UserPasswordPage02::userPasswordPage02_sendTo_mainWindow(){
    emit userPasswordPage02_to_mainWindow();
}

void UserPasswordPage02::userPasswordPage02_sendTo_userPasswordPage03(){
    emit userPasswordPage02_to_userPasswordPage03();
}

bool UserPasswordPage02::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(ui->define_temperture_display->hasFocus()){
                ui->define_temperture_display->clearFocus();
            }
        }
    }
    if(watched == ui->define_temperture_display)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1413);
            ui->define_temperture_display->setFocus();
        }
    }else if(watched == ui->define_time_display_H)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1414);
            ui->define_time_display_H->setFocus();
        }
    }else if(watched == ui->define_time_display_M)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1415);
            ui->define_time_display_M->setFocus();
        }
    }else if(watched == ui->high_temperature_range_display)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1416);
            ui->high_temperature_range_display->setFocus();
        }
    }else if(watched == ui->low_temperature_range_display)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1417);
            ui->low_temperature_range_display->setFocus();
        }
    }else if(watched == ui->ultrasonic_humidification_temperature_low_display)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1426);
            ui->ultrasonic_humidification_temperature_low_display->setFocus();
        }
    }else if(watched == ui->ultrasonic_humidification_temperature_high_display)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1427);
            ui->ultrasonic_humidification_temperature_low_display->setFocus();
        }
    }else if(watched == ui->ultrasonic_humidification_humidity_display)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1428);
            ui->ultrasonic_humidification_temperature_low_display->setFocus();
        }
    }




    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}


void UserPasswordPage02::freezeOneSec()
{
    /*
    ui->record_naming_method_checkBox_1->setEnabled(false);
    ui->record_naming_method_checkBox_2->setEnabled(false);
    ui->auto_temperature_protected_locked->setEnabled(false);
    ui->shutdown_protected_locked->setEnabled(false);
    ui->nitrogen_function_checkBox->setEnabled(false);
    ui->ultrasonic_humidification_locked->setEnabled(false);
    ui->ultra_low_humidity_locked->setEnabled(false);
    ui->wind_speed_locked->setEnabled(false);
    ui->test_article_protection_locked->setEnabled(false);
    ui->remote_recording_locked->setEnabled(false);
    ui->culmulative_time_locked->setEnabled(false);
    ui->history_curve_list_display_locked->setEnabled(false);
    ui->font_page_pbtn->setEnabled(false);
    ui->next_page_pbtn->setEnabled(false);
    ui->previous_page_pbtn->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    ui->record_naming_method_checkBox_1->setEnabled(true);
    ui->record_naming_method_checkBox_2->setEnabled(true);
    ui->auto_temperature_protected_locked->setEnabled(true);
    ui->shutdown_protected_locked->setEnabled(true);
    ui->nitrogen_function_checkBox->setEnabled(true);
    ui->ultrasonic_humidification_locked->setEnabled(true);
    ui->ultra_low_humidity_locked->setEnabled(true);
    ui->wind_speed_locked->setEnabled(true);
    ui->test_article_protection_locked->setEnabled(true);
    ui->remote_recording_locked->setEnabled(true);
    ui->culmulative_time_locked->setEnabled(true);
    ui->history_curve_list_display_locked->setEnabled(true);
    ui->font_page_pbtn->setEnabled(true);
    ui->next_page_pbtn->setEnabled(true);
    ui->previous_page_pbtn->setEnabled(true);
    */
}


void UserPasswordPage02::on_common_programs_pushButton_clicked()
{
    emit touch_InterfaceDataSignal(0x1401,"0");
}

void UserPasswordPage02::on_record_naming_method_checkBox_1_clicked()
{
    emit touch_InterfaceDataSignal(0x1402,"0");
}

void UserPasswordPage02::on_record_naming_method_checkBox_2_clicked()
{
    emit touch_InterfaceDataSignal(0x1402,"1");
}

void UserPasswordPage02::on_auto_temperature_protected_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1406,"0");
}

void UserPasswordPage02::on_shutdown_protected_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1412,"0");
}

void UserPasswordPage02::on_nitrogen_function_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1422,"0");
}

void UserPasswordPage02::on_ultrasonic_humidification_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1424,"0");
}

void UserPasswordPage02::on_wind_speed_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1431,"0");
}

void UserPasswordPage02::on_ultra_low_humidity_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1432,"0");
}

void UserPasswordPage02::on_test_article_protection_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1433,"0");
}

void UserPasswordPage02::on_culmulative_time_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1434,"0");
}

void UserPasswordPage02::on_remote_recording_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1435,"0");
}

void UserPasswordPage02::on_history_curve_list_display_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1436,"0");
}

void UserPasswordPage02::addrSetUserPsdInterfaceData(int addr_num, QString set_value){

    QString covert_data;
    switch(addr_num)
    {
    case 0x1403:
        ui->record_naming_method_checkBox_1->setChecked((bool)set_value.toInt());
        break;
    case 0x1404:
        ui->record_naming_method_checkBox_2->setChecked((bool)set_value.toInt());
        break;
    case 0x1405:
        ui->auto_temperature_protected_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1411:
        ui->shutdown_protected_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1413:
        covert_data = convertToDecimalString(set_value,2);
        ui->define_temperture_display->setText(covert_data);
        break;
    case 0x1414:
        ui->define_time_display_H->setText(set_value);
        break;
    case 0x1415:
        ui->define_time_display_M->setText(set_value);
        break;
    case 0x1416:
        covert_data = convertToDecimalString(set_value,2);
        ui->high_temperature_range_display->setText(covert_data);
        break;
    case 0x1417:
        covert_data = convertToDecimalString(set_value,2);
        ui->low_temperature_range_display->setText(covert_data);
        break;
    case 0x1421:
        ui->nitrogen_function_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1425:
        ui->ultrasonic_humidification_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1426:
        covert_data = convertToDecimalString(set_value,2);
        ui->ultrasonic_humidification_temperature_low_display->setText(covert_data);
        break;
    case 0x1427:
        covert_data = convertToDecimalString(set_value,2);
        ui->ultrasonic_humidification_temperature_high_display->setText(covert_data);
        break;
    case 0x1428:
        covert_data = convertToDecimalString(set_value,2);
        ui->ultrasonic_humidification_humidity_display->setText(covert_data);
        break;
    case 0x1431:
        ui->wind_speed_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1432:
        ui->ultra_low_humidity_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1433:
        ui->test_article_protection_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1434:
        ui->culmulative_time_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1435:
        ui->remote_recording_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1436:
        ui->history_curve_list_display_locked->setChecked((bool)set_value.toInt());
        break;
    default:
        break;
    }
}
