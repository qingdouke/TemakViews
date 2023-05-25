#include "popupwindow07.h"
#include "ui_popupwindow07.h"

PopUpWindow07::PopUpWindow07(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpWindow07)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);

    ui->widget->setStyleSheet("QWidget#widget{background-color:white;"
                              "border:3px solid rgb(74,122,60)}");

    ui->pBtn_OK->setStyleSheet("QPushButton#pBtn_OK{background-color:rgb(72,129,52);"
                               "color:white;"
                               "border:none}");
}

PopUpWindow07::~PopUpWindow07()
{
    delete ui;
}

void PopUpWindow07::centerShow(int WIDTH,int HEIGHT){
    this->move((WIDTH-this->width())/2,(HEIGHT-this->height())/2);
    this->show();
}

void PopUpWindow07::on_pBtn_OK_clicked()
{
    this->close();
}

void PopUpWindow07::setChinese(QString strs)
{
    ui->label->setText(strs);
}

void PopUpWindow07::setEnglish(QString strs)
{
    ui->label_2->setText(strs);
}
