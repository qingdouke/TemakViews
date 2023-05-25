#include "parameter_setting.h"
#include "ui_parameter_setting.h"

#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Parameter_Setting::Parameter_Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Parameter_Setting)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    QFile file(":/qss/Parameter_Setting_qss.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

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
    ui->systemTimeSetting_lineEdit->setText(datetimestrs);
    ui->current_time->setStyleSheet("QLabel#current_time{color:white}");
    //设置定时器 每一秒更新一次Header的时间label
    QTimer* timer = new QTimer(this);
    timer->start(1000);

    //status_box
    ui->status_box->setStyleSheet("QWidget#status_box{border:2px solid rgb(72,129,52);"
                                  "border-radius:10px;"
                                  "background-color:white}");
    ui->status_box_line->setStyleSheet("QLabel#status_box_line{background-color:rgb(127,127,127)}");
    ui->status_1->setStyleSheet("QLabel#status_1{background-image:url(:/Image/24/61.bmp)}");
    ui->status_2->setStyleSheet("QLabel#status_2{background-image:url(:/Image/24/63.bmp)}");
    ui->status_3->setStyleSheet("QLabel#status_3{background-image:url(:/Image/24/65.bmp)}");
    ui->status_4->setStyleSheet("QLabel#status_4{background-image:url(:/Image/24/67.bmp)}");
    ui->status_5->setStyleSheet("QLabel#status_5{background-image:url(:/Image/24/69.bmp)}");
    ui->status_6->setStyleSheet("QLabel#status_6{background-image:url(:/Image/24/71.bmp)}");

    //设置亮度调节slider
    ui->horizontalSlider_light->setMinimum(0);
    ui->horizontalSlider_light->setMaximum(100);
    ui->horizontalSlider_light->setSingleStep(10);
    ui->horizontalSlider_light->setValue(Light_Value);

    //设置亮度调节高低按钮
    ui->pBtn_Light_Adjustment_Low->setStyleSheet("QPushButton#pBtn_Light_Adjustment_Low{background-color:rgb(73,126,54);"
                                                 "border:none;"
                                                 "background-image:url(:/Image/icon/pushButton_4.png)}");
    ui->pBtn_Light_Adjustment_High->setStyleSheet("QPushButton#pBtn_Light_Adjustment_High{background-color:rgb(73,126,54);"
                                                  "border:none;"
                                                  "background-image:url(:/Image/icon/pushButton_5.png)}");

    //lineEdit
    ui->port_lineEdit->setStyleSheet("QLineEdit#port_lineEdit{background:transparent;"
                                     "border:2px solid rgb(117,150,107)}");
    ui->chooseProgram_lineEdit->setStyleSheet("QLineEdit#chooseProgram_lineEdit{background:transparent;"
                                              "border:2px solid rgb(117,150,107)}");
    ui->programPrepared_lineEdit->setStyleSheet("QLineEdit#programPrepared_lineEdit{background:transparent;"
                                                "border:2px solid rgb(117,150,107)}");
    ui->communicationAddress485_lineEdit->setStyleSheet("QLineEdit#communicationAddress485_lineEdit{background:transparent;"
                                                        "border:2px solid rgb(117,150,107)}");
    ui->defaultGateway_lineEdit->setStyleSheet("QLineEdit#defaultGateway_lineEdit{background:transparent;"
                                               "border:2px solid rgb(117,150,107)}");
    ui->ipAddress_lineEdit->setStyleSheet("QLineEdit#ipAddress_lineEdit{background:transparent;"
                                          "border:2px solid rgb(117,150,107)}");
    ui->passwordChange_lineEdit->setStyleSheet("QLineEdit#passwordChange_lineEdit{background:transparent;"
                                               "border:2px solid rgb(117,150,107)}");
    ui->subnetMask_lineEdit->setStyleSheet("QLineEdit#subnetMask_lineEdit{background:transparent;"
                                           "border:2px solid rgb(117,150,107)}");
    ui->systemTimeSetting_lineEdit->setStyleSheet("QLineEdit#systemTimeSetting_lineEdit{background:transparent;"
                                                  "border:2px solid rgb(117,150,107)}");
    ui->backLightingTime_lineEdit->setStyleSheet("QLineEdit#backLightingTime_lineEdit{background:transparent;"
                                                 "border:2px solid rgb(117,150,107)}");
    //pushButton
    ui->languageChinese_pBtn->setStyleSheet("QPushButton#languageChinese_pBtn{background-color:rgb(238,117,0);"
                                            "border:none;"
                                            "color:white}");
    ui->languageTraditionalChinese_pBtn->setStyleSheet("QPushButton#languageTraditionalChinese_pBtn{background-color:rgb(238,117,0);"
                                                       "border:none;"
                                                       "color:white}");
    ui->languageEnglish_pBtn->setStyleSheet("QPushButton#languageEnglish_pBtn{background-color:rgb(69,130,50);"
                                            "border:none;"
                                            "color:white}");

    //设置单选按钮组
    box1 = new QButtonGroup(this);
    box2 = new QButtonGroup(this);
    box1->addButton(ui->PCLINK_radioButton,0);
    box1->addButton(ui->PCLINK_SUM_radioButton,1);
    box1->addButton(ui->MODBUS_RTU_radioButton,2);
    box2->addButton(ui->baudRate9600_radioButton,0);
    box2->addButton(ui->baudRate19200_radioButton,1);
    box2->addButton(ui->baudRate38400_radioButton,2);
    box2->addButton(ui->baudRate57600_radioButton,3);
    box2->addButton(ui->baudRate115200_radioButton,4);
    ui->PCLINK_radioButton->setChecked(true);
    ui->baudRate9600_radioButton->setChecked(true);

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

    //添加事件过滤器
    this->installEventFilter(this);
    ui->passwordChange_lineEdit->installEventFilter(this);

    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&Parameter_Setting::currentTime);

    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&Parameter_Setting::parameterSetting_sendTo_mainWindow);
    connect(ui->next_page_pbtn,&QPushButton::clicked,this,&Parameter_Setting::parameterSetting_to_CANSET);

}

Parameter_Setting::~Parameter_Setting()
{
    delete ui;
}


bool Parameter_Setting::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(ui->passwordChange_lineEdit->hasFocus()){
                ui->passwordChange_lineEdit->clearFocus();
            }
        }
    }
//    if(watched == ui->passwordChange_lineEdit)
//    {
//        if(event->type() == QEvent::MouseButtonPress){
//            emit Request_Use_Keyboard_Signal(30);
//            ui->passwordChange_lineEdit->setFocus();
//        }
//    }
    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}
/*
 * time: 2022-11-18
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void Parameter_Setting::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
    ui->systemTimeSetting_lineEdit->setText(datetimestrs);
}

/*
 * time: 2022-11-29
 * type: public slots
 * effect: 滑块移动时数值改变
 * influence: Light_Value
*/
void Parameter_Setting::on_pBtn_Light_Adjustment_Low_clicked()
{
    if(Light_Value>0){
        Light_Value -= 10;
        ui->horizontalSlider_light->setValue(Light_Value);
    }
}

/*
 * time: 2022-11-29
 * type: public slots
 * effect: 滑块移动时数值改变
 * influence: Light_Value
*/
void Parameter_Setting::on_pBtn_Light_Adjustment_High_clicked()
{
    if(Light_Value<100){
        Light_Value += 10;
        ui->horizontalSlider_light->setValue(Light_Value);
    }
}

/*
 * time: 2022-11-24
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Parameter_Setting::parameterSetting_sendTo_CANSET(){
    emit parameterSetting_to_CANSET();
}


/*
 * time: 2022-11-24
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Parameter_Setting::parameterSetting_sendTo_mainWindow(){
    emit parameterSetting_to_mainWindow();
}

void Parameter_Setting::setPassword(QString strs){
    this->password = strs;
    ui->passwordChange_lineEdit->setText(strs);
    ui->passwordChange_lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
}

QString Parameter_Setting::getPassword(){
    return password;
}

/*
 * time: 2022-11-29
 * type: public slots
 * effect: 滑块移动时数值改变
 * influence: Light_Value
*/
void Parameter_Setting::on_horizontalSlider_light_valueChanged(int value)
{
    Light_Value = value;
}

void Parameter_Setting::setBackLightingTime(QString strs){
    this->backLightingTime = strs;
    ui->backLightingTime_lineEdit->setText(backLightingTime);
}

QString Parameter_Setting::getBackLightingTime(){
    return backLightingTime;
}

void Parameter_Setting::setprogramPrepared1(QString strs){
    this->programPrepared_1 = strs;
    ui->programPrepared_lineEdit->setText(programPrepared);
}

void Parameter_Setting::setprogramPrepared2(QString strs){
    this->programPrepared_2 = strs;
    ui->programPrepared_lineEdit->setText(programPrepared);
}

void Parameter_Setting::setprogramPrepared3(QString strs){
    this->programPrepared_3 = strs;
    ui->programPrepared_lineEdit->setText(programPrepared);
}

void Parameter_Setting::setprogramPrepared4(QString strs){
    this->programPrepared_4 = strs;
    ui->programPrepared_lineEdit->setText(programPrepared);
}

void Parameter_Setting::setprogramPrepared5(QString strs){
    this->programPrepared_5 = strs;
    ui->programPrepared_lineEdit->setText(programPrepared);
}

QString Parameter_Setting::getprogramPrepared(){
    return programPrepared;
}

void Parameter_Setting::setChooseProgram(QString strs){
    this->chooseProgram = strs;
    ui->chooseProgram_lineEdit->setText(chooseProgram);
}

void Parameter_Setting::setCommunicationAddress485(QString strs){
    this->communicationAddress485 = strs;
    ui->communicationAddress485_lineEdit->setText(communicationAddress485);
}

QString Parameter_Setting::getChooseProgram(){
    return chooseProgram;
}

QString Parameter_Setting::getCommunicationAddress485(){
    return communicationAddress485;
}

void Parameter_Setting::setIpAddress1(QString strs){
    this->ipAddress_1 = strs;
    ui->ipAddress_lineEdit->setText(ipAddress);
}

void Parameter_Setting::setIpAddress2(QString strs){
    this->ipAddress_2 = strs;
    ui->ipAddress_lineEdit->setText(ipAddress);
}

void Parameter_Setting::setIpAddress3(QString strs){
    this->ipAddress_3 = strs;
    ui->ipAddress_lineEdit->setText(ipAddress);
}

void Parameter_Setting::setIpAddress4(QString strs){
    this->ipAddress_4 = strs;
    ui->ipAddress_lineEdit->setText(ipAddress);
}

QString Parameter_Setting::getIpAddress(){
    return ipAddress;
}

void Parameter_Setting::setSubnetMask1(QString strs){
    this->subnetMask_1 = strs;
    ui->subnetMask_lineEdit->setText(subnetMask);
}

void Parameter_Setting::setSubnetMask2(QString strs){
    this->subnetMask_2 = strs;
    ui->subnetMask_lineEdit->setText(subnetMask);
}

void Parameter_Setting::setSubnetMask3(QString strs){
    this->subnetMask_3 = strs;
    ui->subnetMask_lineEdit->setText(subnetMask);
}

void Parameter_Setting::setSubnetMask4(QString strs){
    this->subnetMask_4 = strs;
    ui->subnetMask_lineEdit->setText(subnetMask);
}

QString Parameter_Setting::getSubnetMask(){
    return subnetMask;
}

void Parameter_Setting::setDefaultGateway1(QString strs){
    this->defaultGateway_1 = strs;
    ui->defaultGateway_lineEdit->setText(defaultGateway);
}

void Parameter_Setting::setDefaultGateway2(QString strs){
    this->defaultGateway_2 = strs;
    ui->defaultGateway_lineEdit->setText(defaultGateway);
}

void Parameter_Setting::setDefaultGateway3(QString strs){
    this->defaultGateway_3 = strs;
    ui->defaultGateway_lineEdit->setText(defaultGateway);
}

void Parameter_Setting::setDefaultGateway4(QString strs){
    this->defaultGateway_4 = strs;
    ui->defaultGateway_lineEdit->setText(defaultGateway);
}

QString Parameter_Setting::getDefaultGateway(){
    return defaultGateway;
}

void Parameter_Setting::setPort(QString strs){
    this->port = strs;
    ui->port_lineEdit->setText(port);
}

QString Parameter_Setting::getPort(){
    return port;
}

void Parameter_Setting::on_checkBox_Screen_Lock_clicked()
{
    if(screenLocked==false){
        screenLocked = true;
    }
    else{
        screenLocked = false;
    }
}

void Parameter_Setting::freezeOneSec()
{
    ui->languageChinese_pBtn->setEnabled(false);
    ui->languageTraditionalChinese_pBtn->setEnabled(false);
    ui->languageEnglish_pBtn->setEnabled(false);
    ui->MODBUS_RTU_radioButton->setEnabled(false);
    ui->PCLINK_SUM_radioButton->setEnabled(false);
    ui->PCLINK_radioButton->setEnabled(false);
    ui->baudRate115200_radioButton->setEnabled(false);
    ui->baudRate38400_radioButton->setEnabled(false);
    ui->baudRate19200_radioButton->setEnabled(false);
    ui->baudRate57600_radioButton->setEnabled(false);
    ui->baudRate9600_radioButton->setEnabled(false);
    ui->pBtn_Light_Adjustment_High->setEnabled(false);
    ui->pBtn_Light_Adjustment_Low->setEnabled(false);
    ui->font_page_pbtn->setEnabled(false);
    ui->next_page_pbtn->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    ui->languageChinese_pBtn->setEnabled(true);
    ui->languageTraditionalChinese_pBtn->setEnabled(true);
    ui->languageEnglish_pBtn->setEnabled(true);
    ui->MODBUS_RTU_radioButton->setEnabled(true);
    ui->PCLINK_SUM_radioButton->setEnabled(true);
    ui->PCLINK_radioButton->setEnabled(true);
    ui->baudRate115200_radioButton->setEnabled(true);
    ui->baudRate38400_radioButton->setEnabled(true);
    ui->baudRate19200_radioButton->setEnabled(true);
    ui->baudRate57600_radioButton->setEnabled(true);
    ui->baudRate9600_radioButton->setEnabled(true);
    ui->pBtn_Light_Adjustment_High->setEnabled(true);
    ui->pBtn_Light_Adjustment_Low->setEnabled(true);
    ui->font_page_pbtn->setEnabled(true);
    ui->next_page_pbtn->setEnabled(true);
}
