#include "userpasswordpage02.h"
#include "ui_userpasswordpage02.h"

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

void UserPasswordPage02::freezeOneSec()
{
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
}
