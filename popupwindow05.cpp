#include "popupwindow05.h"
#include "ui_popupwindow05.h"

PopUpWindow05::PopUpWindow05(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpWindow05)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);

    ui->widget->setStyleSheet("QWidget#widget{background-color:white;"
                              "border:3px solid rgb(74,122,60)}");

    ui->pBtn_OK->setStyleSheet("QPushButton#pBtn_OK{background-color:rgb(72,129,52);"
                               "color:white;"
                               "border:none}");
}

PopUpWindow05::~PopUpWindow05()
{
    delete ui;
}

void PopUpWindow05::on_pBtn_OK_clicked()
{
    this->close();
}

void PopUpWindow05::centerShow(int WIDTH,int HEIGHT){
    this->move((WIDTH-this->width())/2,(HEIGHT-this->height())/2);
    this->show();
}
