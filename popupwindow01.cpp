#include "popupwindow01.h"
#include "ui_popupwindow01.h"
// 是否运行弹出窗口
PopUpWindow01::PopUpWindow01(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpWindow01)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);
    ui->widget->setStyleSheet("QWidget#widget{background-color:white;"
                              "border:3px solid rgb(74,122,60)}");
    ui->pBtn_OK->setStyleSheet("QPushButton#pBtn_OK{background-color:rgb(72,129,52);"
                               "color:white;"
                               "border:none}");
    ui->pBtn_Cancel->setStyleSheet("QPushButton#pBtn_Cancel{background-color:rgb(238,117,0);"
                                   "color:white;"
                                   "border:none}");

    //connect(ui->pBtn_OK,&QPushButton::clicked,this,&PopUpWindow01::on_pBtn_OK_clicked);
}

PopUpWindow01::~PopUpWindow01()
{
    delete ui;
}

void PopUpWindow01::on_pBtn_OK_clicked()
{
    emit popWindow01PushButtonOKClickedSignal();
}


void PopUpWindow01::on_pBtn_Cancel_clicked()
{
    this->close();
}

