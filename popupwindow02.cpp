#include "popupwindow02.h"
#include "ui_popupwindow02.h"

PopUpWindow02::PopUpWindow02(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopUpWindow02)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowModality(Qt::ApplicationModal);

    ui->widget->setStyleSheet("QWidget#widget{background-color:white;"
                              "border:3px solid rgb(74,122,60)}");
    ui->label->setStyleSheet("QLabel#label{background-image:url(:/Image/icon/popupwindow02.bmp)}");
    ui->textEdit_CN->setStyleSheet("QTextEdit#textEdit_CN{border:none;"
                                   "background-color:white}");
    ui->textEdit_EN->setStyleSheet("QTextEdit#textEdit_EN{border:none;"
                                   "background-color:white}");
    ui->pBtn_OK->setStyleSheet("QPushButton#pBtn_OK{background-color:rgb(72,129,52);"
                               "color:white;"
                               "border:none}");
    ui->pBtn_Cancel->setStyleSheet("QPushButton#pBtn_Cancel{background-color:rgb(238,117,0);"
                                   "color:white;"
                                   "border:none}");

    connect(ui->pBtn_OK,&QPushButton::clicked,this,&PopUpWindow02::on_pBtn_OK_clicked);
}

PopUpWindow02::~PopUpWindow02()
{
    delete ui;
}

void PopUpWindow02::on_pBtn_Cancel_clicked()
{
    this->close();
}

void PopUpWindow02::on_pBtn_OK_clicked()
{
    emit popWindow02PushButtonOKClickedSignal();
}

