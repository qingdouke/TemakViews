#include "popupwindow_saveEnd.h"
#include "ui_popupwindow_saveEnd.h"

PopupWindow_SaveEnd::PopupWindow_SaveEnd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopupWindow_SaveEnd)
{
    ui->setupUi(this);    
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::ApplicationModal);

    ui->widget ->setStyleSheet("QWidget#widget{background-color:white;"
                              "border:3px solid rgb(74,122,60)}");

    ui->pBtn_OK->setStyleSheet("QPushButton#pBtn_OK{background-color:rgb(72,129,52);"
                               "color:white;"
                               "border:none}");
}

PopupWindow_SaveEnd::~PopupWindow_SaveEnd()
{
    delete ui;
}
void PopupWindow_SaveEnd::centerShow(int WIDTH,int HEIGHT){
    this->move((WIDTH-this->width())/2,(HEIGHT-this->height())/2);
    this->show();
}

void PopupWindow_SaveEnd::setChinese(QString strs)
{
    ui->textEdit_ch->setText(strs);
}

void PopupWindow_SaveEnd::setEnglish(QString strs)
{
    ui->textEdit_en->setText(strs);
}

void PopupWindow_SaveEnd::setPopupWindowAddr(int addr)
{
    pbtn_ok_addr = addr;
}

void PopupWindow_SaveEnd::on_pBtn_OK_clicked()
{
    if(pbtn_ok_addr > 0)
    {
        emit touch_InterfaceDataSignal(pbtn_ok_addr,pbtn_ok_code);
        pbtn_ok_addr = 0;
    }
    this->close();
}
