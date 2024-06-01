#include "popupwindow06.h"
#include "ui_popupwindow06.h"

PopUpWindow06::PopUpWindow06(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpWindow06)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->widget->setStyleSheet("QWidget#widget{background-color:white;"
                              "border:3px solid rgb(74,122,60)}");

    ui->line_1->setStyleSheet("QLabel#line_1{background-color:rgb(74,122,60)}");
    ui->line_2->setStyleSheet("QLabel#line_2{background-color:rgb(74,122,60)}");
    ui->line_3->setStyleSheet("QLabel#line_3{background-color:rgb(74,122,60)}");
    ui->line_4->setStyleSheet("QLabel#line_4{background-color:rgb(74,122,60)}");
    ui->line_5->setStyleSheet("QLabel#line_5{background-color:rgb(74,122,60)}");
    ui->line_6->setStyleSheet("QLabel#line_6{background-color:rgb(74,122,60)}");
    ui->line_7->setStyleSheet("QLabel#line_7{background-color:rgb(74,122,60)}");
    ui->line_8->setStyleSheet("QLabel#line_8{background-color:rgb(74,122,60)}");

    ui->pushButton_3S->setStyleSheet("QPushButton#pushButton_3S{background-color:transparent;"
                                     "border:none}");
    ui->pushButton_5S->setStyleSheet("QPushButton#pushButton_5S{background-color:transparent;"
                                     "border:none}");
    ui->pushButton_6S->setStyleSheet("QPushButton#pushButton_6S{background-color:transparent;"
                                     "border:none}");
    ui->pushButton_10S->setStyleSheet("QPushButton#pushButton_10S{background-color:transparent;"
                                     "border:none}");
    ui->pushButton_15S->setStyleSheet("QPushButton#pushButton_15S{background-color:transparent;"
                                     "border:none}");
    ui->pushButton_30S->setStyleSheet("QPushButton#pushButton_30S{background-color:transparent;"
                                     "border:none}");
    ui->pushButton_60S->setStyleSheet("QPushButton#pushButton_60S{background-color:transparent;"
                                     "border:none}");
    ui->pushButton_120S->setStyleSheet("QPushButton#pushButton_120S{background-color:transparent;"
                                     "border:none}");
    ui->pushButton_300S->setStyleSheet("QPushButton#pushButton_300S{background-color:transparent;"
                                     "border:none}");
}

PopUpWindow06::~PopUpWindow06()
{
    delete ui;
}

void PopUpWindow06::on_pushButton_3S_clicked()
{
    emit popUpWindow06PushButtonClickedSignals(3);
}


void PopUpWindow06::on_pushButton_5S_clicked()
{
    emit popUpWindow06PushButtonClickedSignals(5);
}


void PopUpWindow06::on_pushButton_6S_clicked()
{
    emit popUpWindow06PushButtonClickedSignals(6);
}


void PopUpWindow06::on_pushButton_10S_clicked()
{
    emit popUpWindow06PushButtonClickedSignals(10);
}


void PopUpWindow06::on_pushButton_15S_clicked()
{
    emit popUpWindow06PushButtonClickedSignals(15);
}


void PopUpWindow06::on_pushButton_30S_clicked()
{
    emit popUpWindow06PushButtonClickedSignals(30);
}


void PopUpWindow06::on_pushButton_60S_clicked()
{
    emit popUpWindow06PushButtonClickedSignals(60);
}


void PopUpWindow06::on_pushButton_120S_clicked()
{
    emit popUpWindow06PushButtonClickedSignals(120);
}


void PopUpWindow06::on_pushButton_300S_clicked()
{
    emit popUpWindow06PushButtonClickedSignals(300);
}

