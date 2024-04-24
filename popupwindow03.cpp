#include "popupwindow03.h"
#include "ui_popupwindow03.h"
// 停机确认弹出窗口
PopUpWindow03::PopUpWindow03(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpWindow03)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);

    ui->pBtn_YES->setStyleSheet("QPushButton#pBtn_YES{background-color:rgb(72,129,52);"
                               "color:white;"
                               "border:none}");
    ui->pBtn_NO->setStyleSheet("QPushButton#pBtn_NO{background-color:rgb(238,117,0);"
                                   "color:white;"
                                   "border:none}");

    connect(ui->pBtn_YES,&QPushButton::clicked,this,&PopUpWindow03::on_pBtn_YES_clicked);
}

PopUpWindow03::~PopUpWindow03()
{
    delete ui;
}

void PopUpWindow03::on_pBtn_YES_clicked()
{
    emit popWindow03PushButtonYESClickedSignal();
}


void PopUpWindow03::on_pBtn_NO_clicked()
{
    this->close();

}

