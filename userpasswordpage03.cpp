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

void UserPasswordPage03::freezeOneSec()
{
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
}
