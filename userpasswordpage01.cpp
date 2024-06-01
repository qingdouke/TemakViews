#include "userpasswordpage01.h"
#include "ui_userpasswordpage01.h"


#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QButtonGroup>

UserPasswordPage01::UserPasswordPage01(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPasswordPage01)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);

    //Header背景颜色
    ui->Header->setStyleSheet("QWidget#Header{background-color:rgb(72,129,52)}");
    //标题颜色
    ui->title->setStyleSheet("QLabel#title{color:white}");
    //logo颜色
    ui->logo->setStyleSheet("QLabel#logo{background-image:url(:/Image/85/1.bmp)}");

    //Main背景颜色渐变
    ui->Main->setStyleSheet("QWidget#Main{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 white,stop:1 rgb(177,203,166))}");

    //Header时间label初始化
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
    ui->current_time->setStyleSheet("QLabel#current_time{color:white}");
    //设置定时器 每一秒更新一次Header的时间label
    QTimer* timer = new QTimer(this);
    timer->start(1000);

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    /*ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->next_page_pbtn->setStyleSheet("QPushButton#next_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");*/

    QFile file(":/qss/UserPasswordPage01.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    ui->on_display_label_2->installEventFilter(this);
    ui->on_display_label_3->installEventFilter(this);
    ui->on_display_label_4->installEventFilter(this);
    ui->on_display_label_5->installEventFilter(this);
    ui->on_display_label_6->installEventFilter(this);
    ui->on_display_label_7->installEventFilter(this);
    ui->on_display_label_8->installEventFilter(this);
    ui->on_display_label_9->installEventFilter(this);
    ui->off_display_label_2->installEventFilter(this);
    ui->off_display_label_3->installEventFilter(this);
    ui->off_display_label_4->installEventFilter(this);
    ui->off_display_label_5->installEventFilter(this);
    ui->off_display_label_6->installEventFilter(this);
    ui->off_display_label_7->installEventFilter(this);
    ui->off_display_label_8->installEventFilter(this);
    ui->off_display_label_9->installEventFilter(this);

    ui->sgm_pause_label_1->installEventFilter(this);
    ui->sgm_pause_label_2->installEventFilter(this);
    ui->sgm_pause_label_3->installEventFilter(this);
    ui->sgm_pause_label_4->installEventFilter(this);
    ui->cycle_pause_label_1->installEventFilter(this);
    ui->cycle_pause_label_2->installEventFilter(this);
    ui->cycle_pause_label_3->installEventFilter(this);
    ui->cycle_pause_label_4->installEventFilter(this);
    ui->other_pause_laber->installEventFilter(this);

    ui->password_change_lineEdit->installEventFilter(this);
    ui->password_change_lineEdit_2->installEventFilter(this);
    ui->power_display->installEventFilter(this);


    this->installEventFilter(this);



    ui->password_change_lineEdit->setStyleSheet("QLineEdit#password_change_lineEdit{border:2px solid rgb(203,230,200);"
                                                "background-color:white}");

    ui->password_change_lineEdit->setEchoMode(QLineEdit::Password);

    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&UserPasswordPage01::currentTime);

    //页面跳转
    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&UserPasswordPage01::userPasswordPage01_sendTo_mainWindow);
    connect(ui->next_page_pbtn,&QPushButton::clicked,this,&UserPasswordPage01::userPasswordPage01_sendTo_userPasswordPage02);
}

UserPasswordPage01::~UserPasswordPage01()
{
    delete ui;
}

void UserPasswordPage01::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

bool UserPasswordPage01::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(ui->password_change_lineEdit->hasFocus()){
                ui->password_change_lineEdit->clearFocus();
            }
        }
    }
    if(watched == ui->on_display_label_2)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1402);
            ui->on_display_label_2->setFocus();
        }
    }else if(watched == ui->on_display_label_3)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1403);
            ui->on_display_label_3->setFocus();
        }
    }else if(watched == ui->on_display_label_4)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1404);
            ui->on_display_label_4->setFocus();
        }
    }else if(watched == ui->on_display_label_5)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1405);
            ui->on_display_label_5->setFocus();
        }
    }else if(watched == ui->on_display_label_6)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1406);
            ui->on_display_label_6->setFocus();
        }
    }else if(watched == ui->on_display_label_7)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1407);
            ui->on_display_label_7->setFocus();
        }
    }else if(watched == ui->on_display_label_8)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1408);
            ui->on_display_label_8->setFocus();
        }
    }else if(watched == ui->on_display_label_9)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1409);
            ui->on_display_label_9->setFocus();
        }
    }else if(watched == ui->off_display_label_2)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1412);
            ui->off_display_label_2->setFocus();
        }
    }else if(watched == ui->off_display_label_3)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1413);
            ui->off_display_label_3->setFocus();
        }
    }else if(watched == ui->off_display_label_4)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1414);
            ui->off_display_label_4->setFocus();
        }
    }else if(watched == ui->off_display_label_5)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1415);
            ui->off_display_label_5->setFocus();
        }
    }else if(watched == ui->off_display_label_6)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1416);
            ui->off_display_label_6->setFocus();
        }
    }else if(watched == ui->off_display_label_7)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1417);
            ui->off_display_label_7->setFocus();
        }
    }else if(watched == ui->off_display_label_8)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1418);
            ui->off_display_label_8->setFocus();
        }
    }else if(watched == ui->off_display_label_9)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1419);
            ui->off_display_label_9->setFocus();
        }
    }else if(watched == ui->sgm_pause_label_1)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1420);
            ui->sgm_pause_label_1->setFocus();
        }
    }else if(watched == ui->sgm_pause_label_2)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1422);
            ui->sgm_pause_label_2->setFocus();
        }
    }else if(watched == ui->sgm_pause_label_3)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1424);
            ui->sgm_pause_label_3->setFocus();
        }
    }else if(watched == ui->sgm_pause_label_4)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1426);
            ui->sgm_pause_label_4->setFocus();
        }
    }else if(watched == ui->cycle_pause_label_1)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1430);
            ui->cycle_pause_label_1->setFocus();
        }
    }else if(watched == ui->cycle_pause_label_2)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1432);
            ui->cycle_pause_label_2->setFocus();
        }
    }else if(watched == ui->cycle_pause_label_3)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1434);
            ui->cycle_pause_label_3->setFocus();
        }
    }else if(watched == ui->cycle_pause_label_4)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1436);
            ui->cycle_pause_label_4->setFocus();
        }
    }else if(watched == ui->other_pause_laber)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x143E);
            ui->other_pause_laber->setFocus();
        }
    }else if(watched == ui->password_change_lineEdit)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1440);
            ui->password_change_lineEdit->setFocus();
        }
    }else if(watched == ui->password_change_lineEdit_2)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1450);
            ui->password_change_lineEdit->setFocus();
        }
    }else if(watched == ui->power_display)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x1460);
            ui->password_change_lineEdit->setFocus();
        }
    }

    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}



void UserPasswordPage01::userPasswordPage01_sendTo_mainWindow()
{
    emit userPasswordPage01_to_mainWindow();
}

void UserPasswordPage01::userPasswordPage01_sendTo_userPasswordPage02()
{
    emit userPasswordPage01_to_userPasswordPage02();
}

void UserPasswordPage01::freezeOneSec()
{
   /* ui->temperature_calorifier_checkBox_1->setEnabled(false);
    ui->temperature_calorifier_checkBox_2->setEnabled(false);
    ui->temperature_calorifier_checkBox_3->setEnabled(false);
    ui->temperature_calorifier_checkBox_4->setEnabled(false);
    ui->humidity_calorifier_checkBox_1->setEnabled(false);
    ui->humidity_calorifier_checkBox_2->setEnabled(false);
    ui->humidity_calorifier_checkBox_3->setEnabled(false);
    ui->humidity_calorifier_checkBox_4->setEnabled(false);
    ui->font_page_pbtn->setEnabled(false);
    ui->next_page_pbtn->setEnabled(false);
    ui->c1_checkBox_1->setEnabled(false);
    ui->c1_checkBox_2->setEnabled(false);
    ui->c1_checkBox_3->setEnabled(false);
    ui->server_checkBox_1->setEnabled(false);
    ui->server_checkBox_2->setEnabled(false);
    ui->server_checkBox_3->setEnabled(false);
    ui->server_checkBox_4->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    ui->temperature_calorifier_checkBox_1->setEnabled(true);
    ui->temperature_calorifier_checkBox_2->setEnabled(true);
    ui->temperature_calorifier_checkBox_3->setEnabled(true);
    ui->temperature_calorifier_checkBox_4->setEnabled(true);
    ui->humidity_calorifier_checkBox_1->setEnabled(true);
    ui->humidity_calorifier_checkBox_2->setEnabled(true);
    ui->humidity_calorifier_checkBox_3->setEnabled(true);
    ui->humidity_calorifier_checkBox_4->setEnabled(true);
    ui->font_page_pbtn->setEnabled(true);
    ui->next_page_pbtn->setEnabled(true);
    ui->c1_checkBox_1->setEnabled(true);
    ui->c1_checkBox_2->setEnabled(true);
    ui->c1_checkBox_3->setEnabled(true);
    ui->server_checkBox_1->setEnabled(true);
    ui->server_checkBox_2->setEnabled(true);
    ui->server_checkBox_3->setEnabled(true);
    ui->server_checkBox_4->setEnabled(true);*/
}


void UserPasswordPage01::on_monitor_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1470,"1");
}

void UserPasswordPage01::on_pgm_monitor_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1470,"2");
}

void UserPasswordPage01::on_recorder_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1470,"3");
}

void UserPasswordPage01::on_edit_pgm_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1470,"4");
}

void UserPasswordPage01::on_pgm_cycle_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1470,"5");
}

void UserPasswordPage01::on_one_poinit_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1470,"6");
}

void UserPasswordPage01::on_param_set_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1470,"7");
}

void UserPasswordPage01::on_sick_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1470,"8");
}

void UserPasswordPage01::on_continue_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1481,"1");
}

void UserPasswordPage01::on_again_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1481,"2");
}

void UserPasswordPage01::on_stop_checkBox_clicked()
{
    emit touch_InterfaceDataSignal(0x1481,"3");
}
void UserPasswordPage01::addrSetUserPsdInterfaceData(int addr_num, QString set_value){

    QString covert_data;
    switch(addr_num)
    {
    case 0x1402:
        ui->on_display_label_2->setText(set_value);
        break;
    case 0x1403:
        ui->on_display_label_3->setText(set_value);
        break;
    case 0x1404:
        ui->on_display_label_4->setText(set_value);
        break;
    case 0x1405:
        ui->on_display_label_5->setText(set_value);
        break;
    case 0x1406:
        ui->on_display_label_6->setText(set_value);
        break;
    case 0x1407:
        ui->on_display_label_7->setText(set_value);
        break;
    case 0x1408:
        ui->on_display_label_8->setText(set_value);
        break;
    case 0x1409:
        ui->on_display_label_9->setText(set_value);
        break;
    case 0x1412:
        ui->off_display_label_2->setText(set_value);
        break;
    case 0x1413:
        ui->off_display_label_3->setText(set_value);
        break;
    case 0x1414:
        ui->off_display_label_4->setText(set_value);
        break;
    case 0x1415:
        ui->off_display_label_5->setText(set_value);
        break;
    case 0x1416:
        ui->off_display_label_6->setText(set_value);
        break;
    case 0x1417:
        ui->off_display_label_7->setText(set_value);
        break;
    case 0x1418:
        ui->off_display_label_8->setText(set_value);
        break;
    case 0x1419:
        ui->off_display_label_9->setText(set_value);
        break;
    case 0x1421:
        ui->sgm_pause_label_1->setText(set_value);
        break;
    case 0x1423:
        ui->sgm_pause_label_2->setText(set_value);
        break;
    case 0x1425:
        ui->sgm_pause_label_3->setText(set_value);
        break;
    case 0x1427:
        ui->sgm_pause_label_4->setText(set_value);
        break;
    case 0x1431:
        ui->cycle_pause_label_1->setText(set_value);
        break;
    case 0x1433:
        ui->cycle_pause_label_2->setText(set_value);
        break;
    case 0x1435:
        ui->cycle_pause_label_3->setText(set_value);
        break;
    case 0x1437:
        ui->cycle_pause_label_4->setText(set_value);
        break;
    case 0x143F:
        ui->other_pause_laber->setText(set_value);
        break;
    case 0x1440:
        ui->password_change_lineEdit->setText(set_value);
        break;
    case 0x1450:
        ui->password_change_lineEdit_2->setText(set_value);
        break;
    case 0x1460:
        ui->power_display->setText(set_value);
        break;
    case 0x1471:
        ui->monitor_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1472:
        ui->pgm_monitor_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1473:
        ui->recorder_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1474:
        ui->edit_pgm_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1475:
        ui->pgm_cycle_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1476:
        ui->one_poinit_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1477:
        ui->param_set_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1478:
        ui->sick_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1483:
        ui->continue_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1484:
        ui->again_checkBox->setChecked((bool)set_value.toInt());
        break;
    case 0x1482:
        ui->stop_checkBox->setChecked((bool)set_value.toInt());
        break;
    default:
        break;
    }
}
