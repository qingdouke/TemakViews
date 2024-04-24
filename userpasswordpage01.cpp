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
    ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->next_page_pbtn->setStyleSheet("QPushButton#next_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");

    QFile file(":/qss/UserPasswordPage01.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    ui->password_change_lineEdit->installEventFilter(this);
    this->installEventFilter(this);

    QButtonGroup* temperature_calorifier_group = new QButtonGroup(this);
    temperature_calorifier_group->setExclusive(true);
    temperature_calorifier_group->addButton(ui->temperature_calorifier_checkBox_1,1);
    temperature_calorifier_group->addButton(ui->temperature_calorifier_checkBox_2,2);
    temperature_calorifier_group->addButton(ui->temperature_calorifier_checkBox_3,3);
    temperature_calorifier_group->addButton(ui->temperature_calorifier_checkBox_4,4);

    QButtonGroup* humidity_calorifier_group = new QButtonGroup(this);
    humidity_calorifier_group->setExclusive(true);
    humidity_calorifier_group->addButton(ui->humidity_calorifier_checkBox_1,1);
    humidity_calorifier_group->addButton(ui->humidity_calorifier_checkBox_2,2);
    humidity_calorifier_group->addButton(ui->humidity_calorifier_checkBox_3,3);
    humidity_calorifier_group->addButton(ui->humidity_calorifier_checkBox_4,4);

    QButtonGroup* c1_group = new QButtonGroup(this);
    c1_group->setExclusive(true);
    c1_group->addButton(ui->c1_checkBox_1,1);
    c1_group->addButton(ui->c1_checkBox_2,2);
    c1_group->addButton(ui->c1_checkBox_3,3);

    QButtonGroup* server_group = new QButtonGroup(this);
    server_group->setExclusive(true);
    server_group->addButton(ui->server_checkBox_1,1);
    server_group->addButton(ui->server_checkBox_2,2);
    server_group->addButton(ui->server_checkBox_3,3);
    server_group->addButton(ui->server_checkBox_4,4);

    ui->password_change_lineEdit->setStyleSheet("QLineEdit#password_change_lineEdit{border:2px solid rgb(203,230,200);"
                                                "background-color:white}");
    ui->confirm_pushButton->setStyleSheet("QPushButton#confirm_pushButton{border:2px solid rgb(74,122,60);"
                                          "background-color:rgb(173,199,160);"
                                          "color:rgb(74,122,60)}");
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
    if(watched == ui->password_change_lineEdit)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Keyboard_Signal(1);
            ui->password_change_lineEdit->setFocus();
        }
    }
    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}

void UserPasswordPage01::setConfirmPassword(QString strs)
{
    confirmPassword = strs;
}

void UserPasswordPage01::setCurrentPassword(QString strs)
{
    currentPassword = strs;
}

void UserPasswordPage01::setTempPassword(QString strs)
{
    tempPassword = strs;
}

void UserPasswordPage01::setPasswordLineEdit(QString strs)
{
    ui->password_change_lineEdit->setText(strs);
}

QString UserPasswordPage01::getTempPassword(){
    return tempPassword;
}

QString UserPasswordPage01::getConfirmPassword(){
    return confirmPassword;
}

QString UserPasswordPage01::getCurrentPassword(){
    return currentPassword;
}

QString UserPasswordPage01::getPasswordLineEdit(){
    return ui->password_change_lineEdit->text();
}

void UserPasswordPage01::on_confirm_pushButton_clicked()
{
    if(isChangingPassword==false)
    {
        if(this->getPasswordLineEdit()!="")
        {
            isChangingPassword=true;
            ui->password_change_label->setText("请再输入一次");
            this->setTempPassword(this->getPasswordLineEdit());
            this->setPasswordLineEdit("");
        }
        else
        {
            popUpWindow07.setChinese("输入为空！");
            popUpWindow07.setEnglish("Input Empty!");
            popUpWindow07.centerShow(this->width(),this->height());
        }
    }
    else
    {
        if(this->getPasswordLineEdit()!="")
        {
            this->setConfirmPassword(this->getPasswordLineEdit());
            this->setPasswordLineEdit("");
            if(confirmPassword == tempPassword)
            {
                popUpWindow07.setChinese("修改成功!");
                popUpWindow07.setEnglish("Change Successfully!");
                popUpWindow07.centerShow(this->width(),this->height());
                currentPassword = confirmPassword;
                confirmPassword = "";
                tempPassword = "";
                isChangingPassword = false;
                ui->password_change_label->setText("请输入新密码");
            }
            else
            {
                popUpWindow07.setChinese("输入不一致！");
                popUpWindow07.setEnglish("Inconsistent input!");
                popUpWindow07.centerShow(this->width(),this->height());
                isChangingPassword=false;
                this->setPasswordLineEdit("");
                ui->password_change_label->setText("请输入新密码");
            }
        }
        else
        {
            popUpWindow07.setChinese("输入为空！");
            popUpWindow07.setEnglish("Input Empty!");
            popUpWindow07.centerShow(this->width(),this->height());
            isChangingPassword=false;
            this->setPasswordLineEdit("");
            ui->password_change_label->setText("请输入新密码");
        }
    }
    qDebug()<<currentPassword;
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

