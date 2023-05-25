#include "error_log.h"
#include "ui_error_log.h"

#include <QTimer>
#include <QDateTime>

Error_Log::Error_Log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Error_Log)
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

    //line
    ui->line_1->setStyleSheet("QLabel#line_1{background-color:rgb(150,150,150)}");
    ui->line_2->setStyleSheet("QLabel#line_2{background-color:rgb(150,150,150)}");
    ui->line_3->setStyleSheet("QLabel#line_3{background-color:rgb(150,150,150)}");
    ui->line_4->setStyleSheet("QLabel#line_4{background-color:rgb(150,150,150)}");
    ui->line_5->setStyleSheet("QLabel#line_5{background-color:rgb(150,150,150)}");
    ui->line_6->setStyleSheet("QLabel#line_6{background-color:rgb(150,150,150)}");
    ui->line_7->setStyleSheet("QLabel#line_7{background-color:rgb(150,150,150)}");
    ui->line_8->setStyleSheet("QLabel#line_8{background-color:rgb(150,150,150)}");
    ui->line_9->setStyleSheet("QLabel#line_9{background-color:rgb(150,150,150)}");

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->clear_log_pbtn->setStyleSheet("QPushButton#clear_log_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");
    ui->saving_pbtn->setStyleSheet("QPushButton#saving_pbtn{border:2px solid rgb(74,122,60);"
                                                   "background-color:rgb(173,199,160);"
                                                   "border-radius:8px;"
                                                   "color:rgb(74,122,60)}");


    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&Error_Log::currentTime);

    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&Error_Log::errorLog_sendTo_mainWindow);

}

Error_Log::~Error_Log()
{
    delete ui;
}

/*
 * time: 2022-11-21
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void Error_Log::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

/*
 * time: 2022-11-21
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Error_Log::errorLog_sendTo_mainWindow(){
    emit errorLog_to_mainWindow();
}
