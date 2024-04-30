#include "internal_param_set.h"
#include "ui_InternalParamSet.h"
#include "ui_internal_param_set.h"

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
void InternalParamSet::on_row1column1_clicked()
{
    emit touch_InterfaceDataSignal(0x3020,"0");
}

void InternalParamSet::on_row1column2_clicked()
{
    emit touch_InterfaceDataSignal(0x3021,"0");
}

void InternalParamSet::on_row1column3_clicked()
{
    emit touch_InterfaceDataSignal(0x3022,"0");
}

void InternalParamSet::on_row1column4_clicked()
{
    emit touch_InterfaceDataSignal(0x3023,"0");
}
void InternalParamSet::on_row1column5_clicked()
{
    emit touch_InterfaceDataSignal(0x3024,"0");
}
void InternalParamSet::on_row1column6_clicked()
{
    emit touch_InterfaceDataSignal(0x3025,"0");
}
void InternalParamSet::on_row1column7_clicked()
{
    emit touch_InterfaceDataSignal(0x3026,"0");
}
void InternalParamSet::on_row1column8_clicked()
{
    emit touch_InterfaceDataSignal(0x3027,"0");
}
void InternalParamSet::on_row2column1_clicked()
{
    emit touch_InterfaceDataSignal(0x3030,"0");
}

void InternalParamSet::on_row2column2_clicked()
{
    emit touch_InterfaceDataSignal(0x3031,"0");
}


void InternalParamSet::on_row2column3_clicked()
{
    emit touch_InterfaceDataSignal(0x3032,"0");
}

void InternalParamSet::on_row2column4_clicked()
{
    emit touch_InterfaceDataSignal(0x3033,"0");
}

void InternalParamSet::on_row2column5_clicked()
{
    emit touch_InterfaceDataSignal(0x3034,"0");
}

void InternalParamSet::on_row2column6_clicked()
{
    emit touch_InterfaceDataSignal(0x3035,"0");
}

void InternalParamSet::on_row2column7_clicked()
{
    emit touch_InterfaceDataSignal(0x3036,"0");
}

void InternalParamSet::on_row2column8_clicked()
{
    emit touch_InterfaceDataSignal(0x3037,"0");
}

void InternalParamSet::on_row3column1_clicked()
{
    emit touch_InterfaceDataSignal(0x3040,"0");
}

void InternalParamSet::on_row3column2_clicked()
{
    emit touch_InterfaceDataSignal(0x3041,"0");
}

void InternalParamSet::on_row3column3_clicked()
{
    emit touch_InterfaceDataSignal(0x3042,"0");
}

void InternalParamSet::on_row3column4_clicked()
{
    emit touch_InterfaceDataSignal(0x3043,"0");
}

void InternalParamSet::on_row3column5_clicked()
{
    emit touch_InterfaceDataSignal(0x3044,"0");
}

void InternalParamSet::on_row3column6_clicked()
{
    emit touch_InterfaceDataSignal(0x3045,"0");
}

void InternalParamSet::on_row3column7_clicked()
{
    emit touch_InterfaceDataSignal(0x3046,"0");
}

void InternalParamSet::on_row3column8_clicked()
{
    emit touch_InterfaceDataSignal(0x3047,"0");
}

void InternalParamSet::on_row4column1_clicked()
{
    emit touch_InterfaceDataSignal(0x3050,"0");
}

void InternalParamSet::on_row4column2_clicked()
{
    emit touch_InterfaceDataSignal(0x3051,"0");
}

void InternalParamSet::on_row4column3_clicked()
{
   emit touch_InterfaceDataSignal(0x3052,"0");
}

void InternalParamSet::on_row4column4_clicked()
{
   emit touch_InterfaceDataSignal(0x3053,"0");
}

void InternalParamSet::on_row4column5_clicked()
{
   emit touch_InterfaceDataSignal(0x3054,"0");
}

void InternalParamSet::on_row4column6_clicked()
{
   emit touch_InterfaceDataSignal(0x3055,"0");
}

void InternalParamSet::on_row4column7_clicked()
{
   emit touch_InterfaceDataSignal(0x3056,"0");
}

void InternalParamSet::on_row4column8_clicked()
{
   emit touch_InterfaceDataSignal(0x3057,"0");
}

void InternalParamSet::on_row5column1_clicked()
{
    emit touch_InterfaceDataSignal(0x3060,"0");
}

void InternalParamSet::on_row5column2_clicked()
{
    emit touch_InterfaceDataSignal(0x3061,"0");
}

void InternalParamSet::on_row5column3_clicked()
{
    emit touch_InterfaceDataSignal(0x3062,"0");
}

void InternalParamSet::on_row5column4_clicked()
{
    emit touch_InterfaceDataSignal(0x3063,"0");
}

void InternalParamSet::on_row5column5_clicked()
{
    emit touch_InterfaceDataSignal(0x3064,"0");
}

void InternalParamSet::on_row5column6_clicked()
{
    emit touch_InterfaceDataSignal(0x3065,"0");
}

void InternalParamSet::on_row5column7_clicked()
{
    emit touch_InterfaceDataSignal(0x3066,"0");
}

void InternalParamSet::on_row5column8_clicked()
{
    emit touch_InterfaceDataSignal(0x3067,"0");
}

void InternalParamSet::on_row6column1_clicked()
{
    emit touch_InterfaceDataSignal(0x3070,"0");
}

void InternalParamSet::on_row6column2_clicked()
{
    emit touch_InterfaceDataSignal(0x3071,"0");
}

void InternalParamSet::on_row6column3_clicked()
{
    emit touch_InterfaceDataSignal(0x3072,"0");
}

void InternalParamSet::on_row6column4_clicked()
{
    emit touch_InterfaceDataSignal(0x3073,"0");
}

void InternalParamSet::on_row6column5_clicked()
{
    emit touch_InterfaceDataSignal(0x3074,"0");
}

void InternalParamSet::on_row6column6_clicked()
{
    emit touch_InterfaceDataSignal(0x3075,"0");
}

void InternalParamSet::on_row6column7_clicked()
{
    emit touch_InterfaceDataSignal(0x3076,"0");
}

void InternalParamSet::on_row6column8_clicked()
{
    emit touch_InterfaceDataSignal(0x3077,"0");
}

void InternalParamSet::on_row7column1_clicked()
{
    emit touch_InterfaceDataSignal(0x3080,"0");
}

void InternalParamSet::on_row7column2_clicked()
{
    emit touch_InterfaceDataSignal(0x3081,"0");
}

void InternalParamSet::on_row7column3_clicked()
{
    emit touch_InterfaceDataSignal(0x3082,"0");
}

void InternalParamSet::on_row7column4_clicked()
{
    emit touch_InterfaceDataSignal(0x3083,"0");
}

void InternalParamSet::on_row7column5_clicked()
{
    emit touch_InterfaceDataSignal(0x3084,"0");
}

void InternalParamSet::on_row7column6_clicked()
{
    emit touch_InterfaceDataSignal(0x3085,"0");
}

void InternalParamSet::on_row7column7_clicked()
{
    emit touch_InterfaceDataSignal(0x3086,"0");
}

void InternalParamSet::on_row7column8_clicked()
{
    emit touch_InterfaceDataSignal(0x3087,"0");
}

void InternalParamSet::on_row8column1_clicked()
{
    emit touch_InterfaceDataSignal(0x3090,"0");
}

void InternalParamSet::on_row8column2_clicked()
{
    emit touch_InterfaceDataSignal(0x3091,"0");
}

void InternalParamSet::on_row8column3_clicked()
{
    emit touch_InterfaceDataSignal(0x3092,"0");
}

void InternalParamSet::on_row8column4_clicked()
{
    emit touch_InterfaceDataSignal(0x3093,"0");
}

void InternalParamSet::on_row8column5_clicked()
{
    emit touch_InterfaceDataSignal(0x3094,"0");
}

void InternalParamSet::on_row8column6_clicked()
{
    emit touch_InterfaceDataSignal(0x3095,"0");
}

void InternalParamSet::on_row8column7_clicked()
{
    emit touch_InterfaceDataSignal(0x3096,"0");
}

void InternalParamSet::on_row8column8_clicked()
{
    emit touch_InterfaceDataSignal(0x3097,"0");
}

void InternalParamSet::on_row9column1_clicked()
{
    emit touch_InterfaceDataSignal(0x30A0,"0");
}

void InternalParamSet::on_row9column2_clicked()
{
    emit touch_InterfaceDataSignal(0x30A1,"0");
}

void InternalParamSet::on_row9column3_clicked()
{
    emit touch_InterfaceDataSignal(0x30A2,"0");
}

void InternalParamSet::on_row9column4_clicked()
{
    emit touch_InterfaceDataSignal(0x30A3,"0");
}

void InternalParamSet::on_row9column5_clicked()
{
    emit touch_InterfaceDataSignal(0x30A4,"0");
}

void InternalParamSet::on_row9column6_clicked()
{
    emit touch_InterfaceDataSignal(0x30A5,"0");
}

void InternalParamSet::on_row9column7_clicked()
{
    emit touch_InterfaceDataSignal(0x30A6,"0");
}

void InternalParamSet::on_row9column8_clicked()
{
    emit touch_InterfaceDataSignal(0x30A7,"0");
}

void InternalParamSet::on_row10column1_clicked()
{
    emit touch_InterfaceDataSignal(0x30B0,"0");
}

void InternalParamSet::on_row10column2_clicked()
{
    emit touch_InterfaceDataSignal(0x30B1,"0");
}

void InternalParamSet::on_row10column3_clicked()
{
    emit touch_InterfaceDataSignal(0x30B2,"0");
}

void InternalParamSet::on_row10column4_clicked()
{
    emit touch_InterfaceDataSignal(0x30B3,"0");
}

void InternalParamSet::on_row10column5_clicked()
{
    emit touch_InterfaceDataSignal(0x30B4,"0");
}

void InternalParamSet::on_row10column6_clicked()
{
    emit touch_InterfaceDataSignal(0x30B5,"0");
}

void InternalParamSet::on_row10column7_clicked()
{
    emit touch_InterfaceDataSignal(0x30B6,"0");
}

void InternalParamSet::on_row10column8_clicked()
{
    emit touch_InterfaceDataSignal(0x30B7,"0");
}

void InternalParamSet::on_row11column1_clicked()
{
    emit touch_InterfaceDataSignal(0x30C0,"0");
}

void InternalParamSet::on_row11column2_clicked()
{
    emit touch_InterfaceDataSignal(0x30C1,"0");
}

void InternalParamSet::on_row11column3_clicked()
{
    emit touch_InterfaceDataSignal(0x30C2,"0");
}

void InternalParamSet::on_row11column4_clicked()
{
    emit touch_InterfaceDataSignal(0x30C3,"0");
}

void InternalParamSet::on_row11column5_clicked()
{
    emit touch_InterfaceDataSignal(0x30C4,"0");
}

void InternalParamSet::on_row11column6_clicked()
{
    emit touch_InterfaceDataSignal(0x30C5,"0");
}

void InternalParamSet::on_row11column7_clicked()
{
    emit touch_InterfaceDataSignal(0x30C6,"0");
}

void InternalParamSet::on_row11column8_clicked()
{
    emit touch_InterfaceDataSignal(0x30C7,"0");
}

void InternalParamSet::on_row12column1_clicked()
{
    emit touch_InterfaceDataSignal(0x30D0,"0");
}

void InternalParamSet::on_row12column2_clicked()
{
    emit touch_InterfaceDataSignal(0x30D1,"0");
}

void InternalParamSet::on_row12column3_clicked()
{
    emit touch_InterfaceDataSignal(0x30D2,"0");
}

void InternalParamSet::on_row12column4_clicked()
{
    emit touch_InterfaceDataSignal(0x30D3,"0");
}

void InternalParamSet::on_row12column5_clicked()
{
    emit touch_InterfaceDataSignal(0x30D4,"0");
}

void InternalParamSet::on_row12column6_clicked()
{
    emit touch_InterfaceDataSignal(0x30D5,"0");
}

void InternalParamSet::on_row12column7_clicked()
{
    emit touch_InterfaceDataSignal(0x30D6,"0");
}

void InternalParamSet::on_row12column8_clicked()
{
    emit touch_InterfaceDataSignal(0x30D7,"0");
}

void InternalParamSet::on_last_page_pbtn_clicked()
{
    clearPage();
    emit touch_InterfaceDataSignal(0x3001,"0");
}

void InternalParamSet::on_next_page_pbtn_clicked()
{
    clearPage();
    emit touch_InterfaceDataSignal(0x3002,"0");
}

void InternalParamSet::on_retrun_pbtn_clicked()
{
    clearPage();
    emit touch_InterfaceDataSignal(0x3003,"0");
}


void InternalParamSet::addrInternalParamInterfaceData(int addr_num, QString set_value){

    switch(addr_num)
    {
    case 0x3100:
        table_title_1 = set_value;
        table_title = table_title_1 + table_title_2 + table_title_3 + table_title_4 + table_title_5;
        ui->title->setText(table_title);
        break;
    case 0x3110:
        table_title_2 = set_value;
        table_title = table_title_1 + table_title_2 + table_title_3 + table_title_4 + table_title_5;
        ui->title->setText(table_title);
        break;
    case 0x3120:
        table_title_3 = set_value;
        table_title = table_title_1 + table_title_2 + table_title_3 + table_title_4 + table_title_5;
        ui->title->setText(table_title);
        break;
    case 0x3130:
        table_title_4 = set_value;
        table_title = table_title_1 + table_title_2 + table_title_3 + table_title_4 + table_title_5;
        ui->title->setText(table_title);
        break;
    case 0x3140:
        table_title_5 = set_value;
        table_title = table_title_1 + table_title_2 + table_title_3 + table_title_4 + table_title_5;
        ui->title->setText(table_title);
        break;
    case 0x3200:
        ui->row1column1->setText(set_value);
        break;
    case 0x3210:
        ui->row1column2->setText(set_value);
        break;
    case 0x3220:
        ui->row1column3->setText(set_value);
        break;
    case 0x3230:
        ui->row1column4->setText(set_value);
        break;
    case 0x3240:
        ui->row1column5->setText(set_value);
        break;
    case 0x3250:
        ui->row1column6->setText(set_value);
        break;
    case 0x3260:
        ui->row1column7->setText(set_value);
        break;
    case 0x3270:
        ui->row1column8->setText(set_value);
        break;
    case 0x3300:
        ui->row2column1->setText(set_value);
        break;
    case 0x3310:
        ui->row2column2->setText(set_value);
        break;
    case 0x3320:
        ui->row2column3->setText(set_value);
        break;
    case 0x3330:
        ui->row2column4->setText(set_value);
        break;
    case 0x3340:
        ui->row2column5->setText(set_value);
        break;
    case 0x3350:
        ui->row2column6->setText(set_value);
        break;
    case 0x3360:
        ui->row2column7->setText(set_value);
        break;
    case 0x3370:
        ui->row2column8->setText(set_value);
        break;

    case 0x3400:
        ui->row3column1->setText(set_value);
        break;
    case 0x3410:
        ui->row3column2->setText(set_value);
        break;
    case 0x3420:
        ui->row3column3->setText(set_value);
        break;
    case 0x3430:
        ui->row3column4->setText(set_value);
        break;
    case 0x3440:
        ui->row3column5->setText(set_value);
        break;
    case 0x3450:
        ui->row3column6->setText(set_value);
        break;
    case 0x3460:
        ui->row3column7->setText(set_value);
        break;
    case 0x3470:
        ui->row3column8->setText(set_value);
        break;

    case 0x3500:
        ui->row4column1->setText(set_value);
        break;
    case 0x3510:
        ui->row4column2->setText(set_value);
        break;
    case 0x3520:
        ui->row4column3->setText(set_value);
        break;
    case 0x3530:
        ui->row4column4->setText(set_value);
        break;
    case 0x3540:
        ui->row4column5->setText(set_value);
        break;
    case 0x3550:
        ui->row4column6->setText(set_value);
        break;
    case 0x3560:
        ui->row4column7->setText(set_value);
        break;
    case 0x3570:
        ui->row4column8->setText(set_value);
        break;

    case 0x3600:
        ui->row5column1->setText(set_value);
        break;
    case 0x3610:
        ui->row5column2->setText(set_value);
        break;
    case 0x3620:
        ui->row5column3->setText(set_value);
        break;
    case 0x3630:
        ui->row5column4->setText(set_value);
        break;
    case 0x3640:
        ui->row5column5->setText(set_value);
        break;
    case 0x3650:
        ui->row5column6->setText(set_value);
        break;
    case 0x3660:
        ui->row5column7->setText(set_value);
        break;
    case 0x3670:
        ui->row5column8->setText(set_value);
        break;

    case 0x3700:
        ui->row6column1->setText(set_value);
        break;
    case 0x3710:
        ui->row6column2->setText(set_value);
        break;
    case 0x3720:
        ui->row6column3->setText(set_value);
        break;
    case 0x3730:
        ui->row6column4->setText(set_value);
        break;
    case 0x3740:
        ui->row6column5->setText(set_value);
        break;
    case 0x3750:
        ui->row6column6->setText(set_value);
        break;
    case 0x3760:
        ui->row6column7->setText(set_value);
        break;
    case 0x3770:
        ui->row6column8->setText(set_value);
        break;

    case 0x3800:
        ui->row7column1->setText(set_value);
        break;
    case 0x3810:
        ui->row7column2->setText(set_value);
        break;
    case 0x3820:
        ui->row7column3->setText(set_value);
        break;
    case 0x3830:
        ui->row7column4->setText(set_value);
        break;
    case 0x3840:
        ui->row7column5->setText(set_value);
        break;
    case 0x3850:
        ui->row7column6->setText(set_value);
        break;
    case 0x3860:
        ui->row7column7->setText(set_value);
        break;
    case 0x3870:
        ui->row7column8->setText(set_value);
        break;

    case 0x3900:
        ui->row8column1->setText(set_value);
        break;
    case 0x3910:
        ui->row8column2->setText(set_value);
        break;
    case 0x3920:
        ui->row8column3->setText(set_value);
        break;
    case 0x3930:
        ui->row8column4->setText(set_value);
        break;
    case 0x3940:
        ui->row8column5->setText(set_value);
        break;
    case 0x3950:
        ui->row8column6->setText(set_value);
        break;
    case 0x3960:
        ui->row8column7->setText(set_value);
        break;
    case 0x3970:
        ui->row8column8->setText(set_value);
        break;

    case 0x3A00:
        ui->row9column1->setText(set_value);
        break;
    case 0x3A10:
        ui->row9column2->setText(set_value);
        break;
    case 0x3A20:
        ui->row9column3->setText(set_value);
        break;
    case 0x3A30:
        ui->row9column4->setText(set_value);
        break;
    case 0x3A40:
        ui->row9column5->setText(set_value);
        break;
    case 0x3A50:
        ui->row9column6->setText(set_value);
        break;
    case 0x3A60:
        ui->row9column7->setText(set_value);
        break;
    case 0x3A70:
        ui->row9column8->setText(set_value);
        break;

    case 0x3B00:
        ui->row10column1->setText(set_value);
        break;
    case 0x3B10:
        ui->row10column2->setText(set_value);
        break;
    case 0x3B20:
        ui->row10column3->setText(set_value);
        break;
    case 0x3B30:
        ui->row10column4->setText(set_value);
        break;
    case 0x3B40:
        ui->row10column5->setText(set_value);
        break;
    case 0x3B50:
        ui->row10column6->setText(set_value);
        break;
    case 0x3B60:
        ui->row10column7->setText(set_value);
        break;
    case 0x3B70:
        ui->row10column8->setText(set_value);
        break;

    case 0x3C00:
        ui->row11column1->setText(set_value);
        break;
    case 0x3C10:
        ui->row11column2->setText(set_value);
        break;
    case 0x3C20:
        ui->row11column3->setText(set_value);
        break;
    case 0x3C30:
        ui->row11column4->setText(set_value);
        break;
    case 0x3C40:
        ui->row11column5->setText(set_value);
        break;
    case 0x3C50:
        ui->row11column6->setText(set_value);
        break;
    case 0x3C60:
        ui->row11column7->setText(set_value);
        break;
    case 0x3C70:
        ui->row11column8->setText(set_value);
        break;

    case 0x3D00:
        ui->row12column1->setText(set_value);
        break;
    case 0x3D10:
        ui->row12column2->setText(set_value);
        break;
    case 0x3D20:
        ui->row12column3->setText(set_value);
        break;
    case 0x3D30:
        ui->row12column4->setText(set_value);
        break;
    case 0x3D40:
        ui->row12column5->setText(set_value);
        break;
    case 0x3D50:
        ui->row12column6->setText(set_value);
        break;
    case 0x3D60:
        ui->row12column7->setText(set_value);
        break;
    case 0x3D70:
        ui->row12column8->setText(set_value);
        break;


       default:
        break;
    }
}
