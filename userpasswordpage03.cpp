#include "userpasswordpage03.h"
#include "ui_userpasswordpage03.h"

#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QButtonGroup>

UserPasswordPage03::UserPasswordPage03(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPasswordPage03)
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
    ui->previous_page_pbtn->setStyleSheet("QPushButton#previous_page_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");

    QFile file(":/qss/Userpasswordpage03.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    ui->water_level_warning_display->installEventFilter(this);
    ui->water_replenishment_mode_display->installEventFilter(this);
    ui->water_level_warning_M->installEventFilter(this);
    this->installEventFilter(this);
    //ui->current_time的connect 显示previous_page_pbtn实时时间
    connect(timer,&QTimer::timeout,this,&UserPasswordPage03::currentTime);

    //页面跳转
    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&UserPasswordPage03::userPasswordPage03_sendTo_mainWindow);
    connect(ui->previous_page_pbtn,&QPushButton::clicked,this,&UserPasswordPage03::userPasswordPage03_sendTo_userPasswordPage02);
}

UserPasswordPage03::~UserPasswordPage03()
{
    delete ui;
}

void UserPasswordPage03::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

void UserPasswordPage03::userPasswordPage03_sendTo_mainWindow(){
    emit userPasswordPage03_to_mainWindow();
}

void UserPasswordPage03::userPasswordPage03_sendTo_userPasswordPage02(){
    emit userPasswordPage03_to_userPasswordPage02();
}
bool UserPasswordPage03::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(ui->water_level_warning_M->hasFocus()){
                ui->water_level_warning_M->clearFocus();
            }
        }
    }
    if(watched == ui->water_level_warning_M)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1413);
            ui->water_level_warning_M->setFocus();
        }
    }else if(watched == ui->water_level_warning_display)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit touch_InterfaceDataSignal(0x1451,"0");
            ui->water_level_warning_display->setFocus();
        }
    }else if(watched == ui->water_replenishment_mode_display)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit touch_InterfaceDataSignal(0x1452,"0");
            ui->water_replenishment_mode_display->setFocus();
        }
    }
    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}
void UserPasswordPage03::freezeOneSec()
{
    /*
    ui->turn_off_humidity_function_locked->setEnabled(false);
    ui->automatic_defrosting_locked->setEnabled(false);
    ui->remote_recording_locked->setEnabled(false);
    ui->excessive_warning_locked->setEnabled(false);
    ui->text_messaging_locked->setEnabled(false);
    ui->temperature_control_checkBox_1->setEnabled(false);
    ui->temperature_control_checkBox_2->setEnabled(false);
    ui->font_page_pbtn->setEnabled(false);
    ui->previous_page_pbtn->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    ui->turn_off_humidity_function_locked->setEnabled(true);
    ui->automatic_defrosting_locked->setEnabled(true);
    ui->remote_recording_locked->setEnabled(true);
    ui->excessive_warning_locked->setEnabled(true);
    ui->text_messaging_locked->setEnabled(true);
    ui->temperature_control_checkBox_1->setEnabled(true);
    ui->temperature_control_checkBox_2->setEnabled(true);
    ui->font_page_pbtn->setEnabled(true);
    ui->previous_page_pbtn->setEnabled(true);
    */
}

void UserPasswordPage03::on_turn_off_humidity_function_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1441,"0");
}

void UserPasswordPage03::on_automatic_defrosting_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1442,"0");
}

void UserPasswordPage03::on_remote_recording_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1443,"0");
}


void UserPasswordPage03::on_excessive_warning_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1444,"0");
}

void UserPasswordPage03::on_text_messaging_locked_clicked()
{
    emit touch_InterfaceDataSignal(0x1446,"0");
}

void UserPasswordPage03::on_program_downloading_clicked()
{
    emit touch_InterfaceDataSignal(0x1447,"0");
}

void UserPasswordPage03::on_program_uploading_clicked()
{
    emit touch_InterfaceDataSignal(0x1448,"0");
}
void UserPasswordPage03::addrSetUserPsdInterfaceData(int addr_num, QString set_value){

    switch(addr_num)
    {
    case 0x1441:
        ui->turn_off_humidity_function_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1442:
        ui->automatic_defrosting_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1443:
        ui->remote_recording_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1444:
        ui->excessive_warning_locked->setChecked((bool)set_value.toInt());
        break;
    case 0x1451:
        ui->water_replenishment_mode_display->setText(set_value);
        break;
    case 0x1452:
        ui->water_level_warning_display->setText(set_value);
        break;
    case 0x1453:
        ui->water_level_warning_M->setText(set_value);
        break;
    case 0x1446:
        ui->text_messaging_locked->setChecked((bool)set_value.toInt());
        break;

    default:
        break;
    }
}
