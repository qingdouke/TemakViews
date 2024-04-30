#include "canset.h"
#include "ui_canset.h"
#include "general_tools.h"
#include "mainwindow.h"
#include "address_data_show.h"

#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
CANSET::CANSET(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CANSET)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint); //设置为无边框
    this->move(0,0); // 窗口移动到屏幕的左上角位置(0,0)
    qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;

    //Header背景颜色
    ui->Header->setStyleSheet("QWidget#Header{background-color:rgb(72,129,52)}");
    //标题颜色
    ui->title->setStyleSheet("QLabel#title{color:white}");
    //logo颜色
    ui->logo->setStyleSheet("QLabel#logo{background-image:url(:/Image/85/1.bmp)}");

    //Main背景颜色渐变
    ui->Main->setStyleSheet("QWidget#Main{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 white,stop:1 rgb(177,203,166))}");

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->previous_page_pbtn->setStyleSheet("QPushButton#previous_page_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");

    ui->baudrate_label->setStyleSheet("QLabel#baudrate_label{color:rgb(72,129,52)}");

    QFile file(":/qss/CANSET.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    //添加事件过滤器
    this->installEventFilter(this);
    ui->period_edit->installEventFilter(this);
    ui->send_sys_value_display_2->installEventFilter(this);
    ui->send_sys_sta_display_2->installEventFilter(this);
    ui->send_pgm_run_time_display_2->installEventFilter(this);
    ui->set_sys_value_display_2->installEventFilter(this);

    QButtonGroup* baudrate_group = new QButtonGroup(this);
    baudrate_group->setExclusive(true);
    baudrate_group->addButton(ui->baudrate_1000k_checkBox,1);
    baudrate_group->addButton(ui->baudrate_800k_checkBox,2);
    baudrate_group->addButton(ui->baudrate_500k_checkBox,3);
    baudrate_group->addButton(ui->baudrate_250k_checkBox,4);
    baudrate_group->addButton(ui->baudrate_125k_checkBox,5);
    baudrate_group->addButton(ui->baudrate_100k_checkBox,6);
    baudrate_group->addButton(ui->baudrate_50k_checkBox,7);
    baudrate_group->addButton(ui->baudrate_20k_checkBox,8);
    baudrate_group->addButton(ui->baudrate_10k_checkBox,9);
    baudrate_group->addButton(ui->baudrate_5k_checkBox,10);
    baudrate_group->addButton(ui->baudrate_2k_checkBox,11);

    ui->period_label->setStyleSheet("QLabel#period_label{color:rgb(72,129,52)}");
    ui->send_form_line_1->setStyleSheet("QLabel#send_form_line_1{background-color:rgb(72,129,52)}");
    ui->send_form_line_2->setStyleSheet("QLabel#send_form_line_2{background-color:rgb(72,129,52)}");
    ui->send_form_line_3->setStyleSheet("QLabel#send_form_line_3{background-color:rgb(72,129,52)}");
    ui->send_form_line_4->setStyleSheet("QLabel#send_form_line_4{background-color:rgb(72,129,52)}");
    ui->send_form_line_5->setStyleSheet("QLabel#send_form_line_5{background-color:rgb(72,129,52)}");
    ui->send_form_line_6->setStyleSheet("QLabel#send_form_line_6{background-color:rgb(72,129,52)}");
    ui->send_form_line_7->setStyleSheet("QLabel#send_form_line_7{background-color:rgb(72,129,52)}");
    ui->set_form_line_1->setStyleSheet("QLabel#set_form_line_1{background-color:rgb(72,129,52)}");
    ui->set_form_line_2->setStyleSheet("QLabel#set_form_line_2{background-color:rgb(72,129,52)}");
    ui->set_form_line_3->setStyleSheet("QLabel#set_form_line_3{background-color:rgb(72,129,52)}");
    ui->set_form_line_4->setStyleSheet("QLabel#set_form_line_4{background-color:rgb(72,129,52)}");
    ui->set_form_line_5->setStyleSheet("QLabel#set_form_line_5{background-color:rgb(72,129,52)}");
    qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;    
}

CANSET::~CANSET()
{
    delete ui;
}


bool CANSET::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(ui->period_edit->hasFocus()){
                ui->period_edit->clearFocus();
            }
        }
    }
    if(watched == ui->period_edit)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x731);
            ui->period_edit->setFocus();
        }
    }else
        if(watched == ui->send_sys_value_display_2)
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit Request_Use_Keyboard_Signal(0x960);
                ui->send_sys_value_display_2->setFocus();
            }
        }else
            if(watched == ui->send_sys_sta_display_2)
            {
                if(event->type() == QEvent::MouseButtonPress){
                    emit Request_Use_Keyboard_Signal(0x970);
                    ui->send_sys_sta_display_2->setFocus();
                }
            }else
                if(watched == ui->send_pgm_run_time_display_2)
                {
                    if(event->type() == QEvent::MouseButtonPress){
                        emit Request_Use_Keyboard_Signal(0x980);
                        ui->send_pgm_run_time_display_2->setFocus();
                    }
                }else
                    if(watched == ui->set_sys_value_display_2)
                    {
                        if(event->type() == QEvent::MouseButtonPress){
                            emit Request_Use_Keyboard_Signal(0x968);
                            ui->set_sys_value_display_2->setFocus();
                        }
                    }

    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}

//优化以上代码
void CANSET::freezeOneSec()
{
    /*
    QList<QWidget*> widgetList = {ui->baudrate_1000k_checkBox, ui->baudrate_800k_checkBox, ui->baudrate_500k_checkBox,
                                   ui->baudrate_250k_checkBox, ui->baudrate_125k_checkBox, ui->baudrate_100k_checkBox,
                                   ui->baudrate_50k_checkBox, ui->baudrate_20k_checkBox, ui->baudrate_10k_checkBox,
                                   ui->baudrate_5k_checkBox, ui->baudrate_2k_checkBox, ui->previous_page_pbtn,
                                   ui->font_page_pbtn};

    for (auto& widget : widgetList) {
        widget->setEnabled(false);
    }
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    for (auto& widget : widgetList) {
        widget->setEnabled(true);
    }*/
}
void CANSET::addrSetCanInterfaceData(int addr_num, QString set_value){

    QString covert_data;
    switch(addr_num)
    {
    case 0x911:
        ui->baudrate_1000k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x912 :
        ui->baudrate_800k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x913 :
        ui->baudrate_500k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x914 :
        ui->baudrate_250k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x915 :
        ui->baudrate_125k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x916 :
        ui->baudrate_100k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x917 :
        ui->baudrate_50k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x918 :
        ui->baudrate_20k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x919 :
        ui->baudrate_10k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x91A :
        ui->baudrate_5k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x91B :
        ui->baudrate_2k_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x932:
        ui->period_edit->setText(set_value);
        break;
    case 0x941:
        ui->send_sys_value_display_1->setText(set_value);
        break;
    case 0x942:
        ui->send_sys_sta_display_1->setText(set_value);
        break;
    case 0x943:
        ui->send_pgm_run_time_display_1->setText(set_value);
        break;
    case 0x960:
        ui->send_sys_value_display_2->setText(set_value);
        break;
    case 0x968:
        ui->set_sys_value_display_2->setText(set_value);
        break;
    case 0x970:
        ui->send_sys_sta_display_2->setText(set_value);
        break;
    case 0x980:
        ui->send_pgm_run_time_display_2->setText(set_value);
        break;
    case 0x7C0:
        ui->comm_text_edit_1->setText(set_value);
        break;
    case 0x7D0:
        ui->comm_text_edit_2->setText(set_value);
        break;
    case 0x7E0:
        ui->comm_text_edit_3->setText(set_value);
        break;
    case 0x7F0:
        ui->comm_text_edit_4->setText(set_value);
        break;
    default:
        break;
    }
}

void CANSET::on_baudrate_1000k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x921,"0");
}

void CANSET::on_baudrate_800k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x922,"0");
}

void CANSET::on_baudrate_500k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x923,"0");
}

void CANSET::on_baudrate_250k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x924,"0");
}

void CANSET::on_baudrate_125k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x925,"0");
}

void CANSET::on_baudrate_100k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x926,"0");
}

void CANSET::on_baudrate_50k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x927,"0");
}

void CANSET::on_baudrate_20k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x928,"0");
}

void CANSET::on_baudrate_10k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x929,"0");
}

void CANSET::on_baudrate_5k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x92A,"0");
}

void CANSET::on_baudrate_2k_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x92B,"0");
}

void CANSET::on_font_page_pbtn_clicked()
{
    emit canset_to_mainWindow();

}

void CANSET::on_previous_page_pbtn_clicked()
{
    emit canset_to_parameterSetting();
}
