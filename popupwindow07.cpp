#include "popupwindow07.h"
#include "ui_popupwindow07.h"
#include <QDebug>
PopUpWindow07::PopUpWindow07(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpWindow07)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);
    //qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;


    ui->widget->setStyleSheet("QWidget#widget{background-color:white;"
                              "border:3px solid rgb(74,122,60)}");
    ui->textEdit_cn->setStyleSheet("QTextEdit#textEdit_cn{color:black;border:none;background:transparent}");
    ui->textEdit_en->setStyleSheet("QTextEdit#textEdit_en{color:black;border:none;background:transparent}");

    ui->pBtn_OK->setStyleSheet("QPushButton#pBtn_OK{background-color:rgb(72,129,52);"
                               "color:white;"
                               "border:none}");
    //qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;

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
    ui->textEdit_cn->setText(strs);
}

void PopUpWindow07::setEnglish(QString strs)
{
    ui->textEdit_en->setText(strs);
}
