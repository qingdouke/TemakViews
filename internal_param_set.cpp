#include "internal_param_set.h"
#include "ui_InternalParamSet.h"
#include "address_data_show.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>
InternalParamSet::InternalParamSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InternalParamSet)
{
    ui->setupUi(this);
    qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;

    setWindowFlags(Qt::FramelessWindowHint);
    //Header背景颜色
    ui->Header->setStyleSheet("QWidget#Header{background-color:rgb(72,129,52)}");
     //logo颜色
    ui->logo->setStyleSheet("QLabel#logo{background-image:url(:/Image/85/1.bmp)}");

    //ui->current_time的connect 显示实时时间
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&InternalParamSet::currentTime);
    timer->start(1000);

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->last_page_pbtn->setStyleSheet("QPushButton#last_page_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");
    ui->next_page_pbtn->setStyleSheet("QPushButton#next_page_pbtn{border:2px solid rgb(74,122,60);"
                                                   "background-color:rgb(173,199,160);"
                                                   "border-radius:8px;"
                                                   "color:rgb(74,122,60)}");
    ui->retrun_pbtn->setStyleSheet("QPushButton#retrun_pbtn{border:2px solid rgb(74,122,60);"
                                                   "background-color:rgb(173,199,160);"
                                                   "border-radius:8px;"
                                                   "color:rgb(74,122,60)}");


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

    //Main背景颜色渐变
    ui->Main->setStyleSheet("QWidget#Main{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 white,stop:1 rgb(177,203,166))}");
    //ui->r3c1->setFont({"Monospace"});
    //ui->row1column1->setText("iii wwww");
    ui->title->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row1column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row1column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row1column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row1column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row1column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row1column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row1column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row1column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row2column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row2column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row2column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row2column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row2column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row2column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row2column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row2column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row3column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row3column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row3column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row3column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row3column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row3column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row3column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row3column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row4column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row4column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row4column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row4column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row4column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row4column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row4column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row4column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row5column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row5column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row5column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row5column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row5column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row5column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row5column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row5column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row6column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row6column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row6column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row6column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row6column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row6column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row6column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row6column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row7column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row7column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row7column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row7column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row7column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row7column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row7column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row7column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row8column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row8column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row8column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row8column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row8column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row8column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row8column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row8column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row9column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row9column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row9column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row9column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row9column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row9column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row9column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row9column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row10column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row10column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row10column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row10column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row10column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row10column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row10column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row10column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row11column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row11column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row11column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row11column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row11column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row11column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row11column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row11column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");

    ui->row12column1->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row12column2->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row12column3->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row12column4->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row12column5->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row12column6->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row12column7->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    ui->row12column8->setStyleSheet("font-family:Monospace;font-size:20pt;background:transparent;border-width:0;border-style:outset");
    clearPage();
    qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;

    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&InternalParamSet::internalParamSet_sendTo_mainWindow);

}
/*
 * time: 2022-11-15
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void InternalParamSet::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

InternalParamSet::~InternalParamSet()
{
    delete ui;
}

void InternalParamSet::on_font_page_pbtn_clicked()
{

}
QString InternalParamSet::getViewPassword(){
    return viewPassword;
}
void InternalParamSet::internalParamSet_sendTo_mainWindow()
{
    emit internalParamSet_to_mainWindow();
}
void InternalParamSet::clearPage()
{
    ui->title->setText("");

    ui->row1column1->setText("");
    ui->row1column2->setText("");
    ui->row1column3->setText("");
    ui->row1column4->setText("");
    ui->row1column5->setText("");
    ui->row1column6->setText("");
    ui->row1column7->setText("");
    ui->row1column8->setText("");

    ui->row2column1->setText("");
    ui->row2column2->setText("");
    ui->row2column3->setText("");
    ui->row2column4->setText("");
    ui->row2column5->setText("");
    ui->row2column6->setText("");
    ui->row2column7->setText("");
    ui->row2column8->setText("");

    ui->row3column1->setText("");
    ui->row3column2->setText("");
    ui->row3column3->setText("");
    ui->row3column4->setText("");
    ui->row3column5->setText("");
    ui->row3column6->setText("");
    ui->row3column7->setText("");
    ui->row3column8->setText("");

    ui->row4column1->setText("");
    ui->row4column2->setText("");
    ui->row4column3->setText("");
    ui->row4column4->setText("");
    ui->row4column5->setText("");
    ui->row4column6->setText("");
    ui->row4column7->setText("");
    ui->row4column8->setText("");

    ui->row5column1->setText("");
    ui->row5column2->setText("");
    ui->row5column3->setText("");
    ui->row5column4->setText("");
    ui->row5column5->setText("");
    ui->row5column6->setText("");
    ui->row5column7->setText("");
    ui->row5column8->setText("");

    ui->row6column1->setText("");
    ui->row6column2->setText("");
    ui->row6column3->setText("");
    ui->row6column4->setText("");
    ui->row6column5->setText("");
    ui->row6column6->setText("");
    ui->row6column7->setText("");
    ui->row6column8->setText("");

    ui->row7column1->setText("");
    ui->row7column2->setText("");
    ui->row7column3->setText("");
    ui->row7column4->setText("");
    ui->row7column5->setText("");
    ui->row7column6->setText("");
    ui->row7column7->setText("");
    ui->row7column8->setText("");

    ui->row8column1->setText("");
    ui->row8column2->setText("");
    ui->row8column3->setText("");
    ui->row8column4->setText("");
    ui->row8column5->setText("");
    ui->row8column6->setText("");
    ui->row8column7->setText("");
    ui->row8column8->setText("");

    ui->row9column1->setText("");
    ui->row9column2->setText("");
    ui->row9column3->setText("");
    ui->row9column4->setText("");
    ui->row9column5->setText("");
    ui->row9column6->setText("");
    ui->row9column7->setText("");
    ui->row9column8->setText("");

    ui->row10column1->setText("");
    ui->row10column2->setText("");
    ui->row10column3->setText("");
    ui->row10column4->setText("");
    ui->row10column5->setText("");
    ui->row10column6->setText("");
    ui->row10column7->setText("");
    ui->row10column8->setText("");

    ui->row11column1->setText("");
    ui->row11column2->setText("");
    ui->row11column3->setText("");
    ui->row11column4->setText("");
    ui->row11column5->setText("");
    ui->row11column6->setText("");
    ui->row11column7->setText("");
    ui->row11column8->setText("");

    ui->row12column1->setText("");
    ui->row12column2->setText("");
    ui->row12column3->setText("");
    ui->row12column4->setText("");
    ui->row12column5->setText("");
    ui->row12column6->setText("");
    ui->row12column7->setText("");
    ui->row12column8->setText("");
}
int key_cal = 0;
void InternalParamSet::on_row1column1_clicked()
{
    if(key_cal == 0)
    {
        ui->row1column1->setText("cal");
        emit Request_Use_Calculate_Signal(3);
    }else
    {
        ui->row1column1->setText("key1");
        emit Request_Use_Keyboard_Signal(3);
    }
}

void InternalParamSet::on_row1column2_clicked()
{
    if(key_cal == 0)
    {
        ui->row1column2->setText("key2");
        emit Request_Use_Calculate_Signal(4);
    }else
    {
        ui->row1column2->setText("cal2");
        emit Request_Use_Keyboard_Signal(4);
    }
}

void InternalParamSet::on_row1column3_clicked()
{
    if(key_cal == 0)
    {
        ui->row1column3->setText("key3");
        emit Request_Use_Keyboard_Signal(5);
    }else
    {
        ui->row1column3->setText("cal3");
        emit Request_Use_Calculate_Signal(5);
    }
}


void InternalParamSet::on_row2column1_clicked()
{
    ui->row2column1->setText("swi");
    key_cal = !key_cal;
}
