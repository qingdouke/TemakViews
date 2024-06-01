#include "parameter_setting.h"
#include "ui_parameter_setting.h"
#include "general_tools.h"
#include "mainwindow.h"
#include "address_data_show.h"

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
    //qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;
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
    ui->auto_static_pbtn->setStyleSheet("QPushButton#auto_static_pbtn{color:white;"
                                         "background-color:rgb(7,75,34);"
                                         "border:none;"
                                         "border-radius:3px}");
    ui->save_ip_pbtn->setStyleSheet("QPushButton#save_ip_pbtn{color:white;"
                                     "background-color:rgb(7,75,34);"
                                     "border:none;"
                                     "border-radius:3px}");
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
    /*ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->next_page_pbtn->setStyleSheet("QPushButton#next_page_pbtn{border:2px solid rgb(74,122,60);"
                                                   "background-color:rgb(173,199,160);"
                                                   "border-radius:8px;"
                                                   "color:rgb(74,122,60)}");*/
    //qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;
    //添加事件过滤器
    this->installEventFilter(this);
    ui->passwordChange_lineEdit->installEventFilter(this);
    ui->backLightingTime_lineEdit->installEventFilter(this);
    ui->programPrepared_lineEdit->installEventFilter(this);
    ui->programPrepared_lineEdit_2->installEventFilter(this);
    ui->programPrepared_lineEdit_3->installEventFilter(this);
    ui->programPrepared_lineEdit_4->installEventFilter(this);
    ui->programPrepared_lineEdit_5->installEventFilter(this);
    ui->chooseProgram_lineEdit->installEventFilter(this);
    ui->communicationAddress485_lineEdit->installEventFilter(this);
    ui->ipAddress_lineEdit->installEventFilter(this);
    ui->ipAddress_lineEdit_2->installEventFilter(this);
    ui->ipAddress_lineEdit_3->installEventFilter(this);
    ui->ipAddress_lineEdit_4->installEventFilter(this);
    ui->subnetMask_lineEdit->installEventFilter(this);
    ui->subnetMask_lineEdit_2->installEventFilter(this);
    ui->subnetMask_lineEdit_3->installEventFilter(this);
    ui->subnetMask_lineEdit_4->installEventFilter(this);
    ui->defaultGateway_lineEdit->installEventFilter(this);
    ui->defaultGateway_lineEdit_2->installEventFilter(this);
    ui->defaultGateway_lineEdit_3->installEventFilter(this);
    ui->defaultGateway_lineEdit_4->installEventFilter(this);
    ui->port_lineEdit->installEventFilter(this);

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
    if(watched == ui->passwordChange_lineEdit)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Keyboard_Signal(0x712);
            ui->passwordChange_lineEdit->setFocus();
        }
    }else
        if(watched == ui->backLightingTime_lineEdit)
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit Request_Use_Calculate_Signal(0x745);
                ui->backLightingTime_lineEdit->setFocus();
            }
        }else
            if(watched == ui->programPrepared_lineEdit)
            {
                if(event->type() == QEvent::MouseButtonPress){
                    emit Request_Use_Calculate_Signal(0x720);
                    ui->programPrepared_lineEdit->setFocus();
                }
            }else
                if(watched == ui->programPrepared_lineEdit_2)
                {
                    if(event->type() == QEvent::MouseButtonPress){
                        emit Request_Use_Calculate_Signal(0x721);
                        ui->programPrepared_lineEdit_2->setFocus();
                    }
                }else
                    if(watched == ui->programPrepared_lineEdit_3)
                    {
                        if(event->type() == QEvent::MouseButtonPress){
                            emit Request_Use_Calculate_Signal(0x722);
                            ui->programPrepared_lineEdit_3->setFocus();
                        }
                    }else
                        if(watched == ui->programPrepared_lineEdit_4)
                        {
                            if(event->type() == QEvent::MouseButtonPress){
                                emit Request_Use_Calculate_Signal(0x723);
                                ui->programPrepared_lineEdit_4->setFocus();
                            }
                        }else
                            if(watched == ui->programPrepared_lineEdit_5)
                            {
                                if(event->type() == QEvent::MouseButtonPress){
                                    emit Request_Use_Calculate_Signal(0x724);
                                    ui->programPrepared_lineEdit_5->setFocus();
                                }
                            }else
                                if(watched == ui->communicationAddress485_lineEdit)
                                {
                                    if(event->type() == QEvent::MouseButtonPress){
                                        emit Request_Use_Keyboard_Signal(0x760);
                                        ui->communicationAddress485_lineEdit->setFocus();
                                    }
                                }else
                                    if(watched == ui->ipAddress_lineEdit)
                                    {
                                        if(event->type() == QEvent::MouseButtonPress){
                                            emit Request_Use_Keyboard_Signal(0x780);
                                            ui->ipAddress_lineEdit->setFocus();
                                        }
                                    }else
                                        if(watched == ui->ipAddress_lineEdit_2)
                                        {
                                            if(event->type() == QEvent::MouseButtonPress){
                                                emit Request_Use_Keyboard_Signal(0x781);
                                                ui->ipAddress_lineEdit_2->setFocus();
                                            }
                                        }else
                                            if(watched == ui->ipAddress_lineEdit_3)
                                            {
                                                if(event->type() == QEvent::MouseButtonPress){
                                                    emit Request_Use_Keyboard_Signal(0x782);
                                                    ui->ipAddress_lineEdit_3->setFocus();
                                                }
                                            }else
                                                if(watched == ui->ipAddress_lineEdit_4)
                                                {
                                                    if(event->type() == QEvent::MouseButtonPress){
                                                        emit Request_Use_Keyboard_Signal(0x783);
                                                        ui->ipAddress_lineEdit_4->setFocus();
                                                    }
                                                }else
                                                    if(watched == ui->subnetMask_lineEdit)
                                                    {
                                                        if(event->type() == QEvent::MouseButtonPress){
                                                            emit Request_Use_Keyboard_Signal(0x790);
                                                            ui->subnetMask_lineEdit->setFocus();
                                                        }
                                                    }else
                                                        if(watched == ui->subnetMask_lineEdit_2)
                                                        {
                                                            if(event->type() == QEvent::MouseButtonPress){
                                                                emit Request_Use_Keyboard_Signal(0x791);
                                                                ui->subnetMask_lineEdit_2->setFocus();
                                                            }
                                                        }else
                                                            if(watched == ui->subnetMask_lineEdit_3)
                                                            {
                                                                if(event->type() == QEvent::MouseButtonPress){
                                                                    emit Request_Use_Keyboard_Signal(0x792);
                                                                    ui->subnetMask_lineEdit_3->setFocus();
                                                                }
                                                            }else
                                                                if(watched == ui->subnetMask_lineEdit_4)
                                                                {
                                                                    if(event->type() == QEvent::MouseButtonPress){
                                                                        emit Request_Use_Keyboard_Signal(0x793);
                                                                        ui->subnetMask_lineEdit_4->setFocus();
                                                                    }
                                                                }else
                                                                    if(watched == ui->defaultGateway_lineEdit)
                                                                    {
                                                                        if(event->type() == QEvent::MouseButtonPress){
                                                                            emit Request_Use_Keyboard_Signal(0x7A0);
                                                                            ui->defaultGateway_lineEdit->setFocus();
                                                                        }
                                                                    }else
                                                                        if(watched == ui->defaultGateway_lineEdit_2)
                                                                        {
                                                                            if(event->type() == QEvent::MouseButtonPress){
                                                                                emit Request_Use_Keyboard_Signal(0x7A1);
                                                                                ui->defaultGateway_lineEdit_2->setFocus();
                                                                            }
                                                                        }else
                                                                            if(watched == ui->defaultGateway_lineEdit_3)
                                                                            {
                                                                                if(event->type() == QEvent::MouseButtonPress){
                                                                                    emit Request_Use_Keyboard_Signal(0x7A2);
                                                                                    ui->defaultGateway_lineEdit_3->setFocus();
                                                                                }
                                                                            }else
                                                                                if(watched == ui->defaultGateway_lineEdit_4)
                                                                                {
                                                                                    if(event->type() == QEvent::MouseButtonPress){
                                                                                        emit Request_Use_Keyboard_Signal(0x7A3);
                                                                                        ui->defaultGateway_lineEdit_4->setFocus();
                                                                                    }
                                                                                }

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
    programPrepared = getprogramPrepared();
    ui->programPrepared_lineEdit->setText(strs);
}

void Parameter_Setting::setprogramPrepared2(QString strs){
    this->programPrepared_2 = strs;
    programPrepared = getprogramPrepared();
    ui->programPrepared_lineEdit_2->setText(strs);
}

void Parameter_Setting::setprogramPrepared3(QString strs){
    this->programPrepared_3 = strs;
    programPrepared = getprogramPrepared();
    ui->programPrepared_lineEdit_3->setText(strs);
}

void Parameter_Setting::setprogramPrepared4(QString strs){
    this->programPrepared_4 = strs;
    programPrepared = getprogramPrepared();
    ui->programPrepared_lineEdit_4->setText(strs);
}

void Parameter_Setting::setprogramPrepared5(QString strs){
    this->programPrepared_5 = strs;
    programPrepared = getprogramPrepared();
    ui->programPrepared_lineEdit_5->setText(strs);
}

QString Parameter_Setting::getprogramPrepared(){
    QString repgmpre = programPrepared_1 + "/" + programPrepared_2 + "/" + programPrepared_3 + "   "
            + programPrepared_4 + ":" + programPrepared_5;
    return repgmpre;
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
    getIpAddress();
    ui->ipAddress_lineEdit->setText(strs);
}

void Parameter_Setting::setIpAddress2(QString strs){
    this->ipAddress_2 = strs;
    getIpAddress();
    ui->ipAddress_lineEdit_2->setText(strs);
}

void Parameter_Setting::setIpAddress3(QString strs){
    this->ipAddress_3 = strs;
    getIpAddress();
    ui->ipAddress_lineEdit_3->setText(strs);
}

void Parameter_Setting::setIpAddress4(QString strs){
    this->ipAddress_4 = strs;
    getIpAddress();
    ui->ipAddress_lineEdit_4->setText(strs);
}

QString Parameter_Setting::getIpAddress(){
    ipAddress = ipAddress_1 + "." + ipAddress_2 +"." + ipAddress_3 + "." + ipAddress_4;
    return ipAddress;
}

void Parameter_Setting::setSubnetMask1(QString strs){
    this->subnetMask_1 = strs;
    getSubnetMask();
    ui->subnetMask_lineEdit->setText(strs);
}

void Parameter_Setting::setSubnetMask2(QString strs){
    this->subnetMask_2 = strs;
    getSubnetMask();
    ui->subnetMask_lineEdit_2->setText(strs);
}

void Parameter_Setting::setSubnetMask3(QString strs){
    this->subnetMask_3 = strs;
    getSubnetMask();
    ui->subnetMask_lineEdit_3->setText(strs);
}

void Parameter_Setting::setSubnetMask4(QString strs){
    this->subnetMask_4 = strs;
    getSubnetMask();
    ui->subnetMask_lineEdit_4->setText(strs);
}

QString Parameter_Setting::getSubnetMask(){
    subnetMask = subnetMask_1 + "." + subnetMask_2 +"." + subnetMask_3 + "." + subnetMask_4;
    return subnetMask;
}

void Parameter_Setting::setDefaultGateway1(QString strs){
    this->defaultGateway_1 = strs;
    getDefaultGateway();
    ui->defaultGateway_lineEdit->setText(strs);
}

void Parameter_Setting::setDefaultGateway2(QString strs){
    this->defaultGateway_2 = strs;
    getDefaultGateway();
    ui->defaultGateway_lineEdit_2->setText(strs);
}

void Parameter_Setting::setDefaultGateway3(QString strs){
    this->defaultGateway_3 = strs;
    getDefaultGateway();
    ui->defaultGateway_lineEdit_3->setText(strs);
}

void Parameter_Setting::setDefaultGateway4(QString strs){
    this->defaultGateway_4 = strs;
    getDefaultGateway();
    ui->defaultGateway_lineEdit_4->setText(strs);
}

QString Parameter_Setting::getDefaultGateway(){
    defaultGateway = defaultGateway_1 + "." + defaultGateway_2 +"." + defaultGateway_3 + "." + defaultGateway_4;
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
    emit touch_InterfaceDataSignal(0x711,QString::number(screenLocked));
}

void Parameter_Setting::freezeOneSec()
{/*
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
    ui->next_page_pbtn->setEnabled(true);*/
}

void Parameter_Setting::addrSetParamSetInterfaceData(int addr_num, QString set_value){


    switch(addr_num)
    {
    case 0x70B:
        ui->languageChinese_pBtn->setChecked(true);
        break;
    case 0x70C:
        ui->languageTraditionalChinese_pBtn->setChecked(true);
        break;
    case 0x70D:
        ui->languageEnglish_pBtn->setChecked(true);
        break;
    case 0x711:
        ui->checkBox_Screen_Lock->setChecked((bool)set_value.toInt());
        break;
    case 0x712:
        setPassword(set_value);
        break;
    case 0x745: //  screen light time
        setBackLightingTime(set_value);
        break;
    case 0x746:
        ui->checkBox_Screen_Sleep->setChecked((bool)set_value.toInt());
        break;
    case 0x720:  // appointment program time year
        setprogramPrepared1(set_value);
        break;
    case 0x721:  // appointment program time mon
        setprogramPrepared2(set_value);
        break;
    case 0x722:  // appointment program time day
        setprogramPrepared3(set_value);
        break;
    case 0x723:  // appointment program hour
        setprogramPrepared4(set_value);
        break;
    case 0x724: // appointment program min
        setprogramPrepared5(set_value);
        break;
    case 0x725: // appointment program number
        setChooseProgram(set_value);
        break;
    case 0x755: //
        ui->PCLINK_radioButton->setChecked((bool)set_value.toInt());
        break;
    case 0x756: //
        ui->PCLINK_SUM_radioButton->setChecked((bool)set_value.toInt());
        break;
    case 0x757: //
        ui->MODBUS_RTU_radioButton->setChecked((bool)set_value.toInt());
        break;
    case 0x761://
        setCommunicationAddress485(set_value);
        break;
    case 0x776://
        ui->baudRate9600_radioButton->setChecked((bool)set_value.toInt());
        break;
    case 0x777://
        ui->baudRate19200_radioButton->setChecked((bool)set_value.toInt());
        break;
    case 0x778://
        ui->baudRate38400_radioButton->setChecked((bool)set_value.toInt());
        break;
    case 0x779://
        ui->baudRate57600_radioButton->setChecked((bool)set_value.toInt());
        break;
    case 0x77A://
        ui->baudRate115200_radioButton->setChecked((bool)set_value.toInt());
        break;
    case 0x786:
        setIpAddress1(set_value);
        break;
    case 0x787:
        setIpAddress2(set_value);
        break;
    case 0x788:
        setIpAddress3(set_value);
        break;
    case 0x789:
        setIpAddress4(set_value);
        break;
    case 0x796:
        setSubnetMask1(set_value);
        break;
    case 0x797:
        setSubnetMask2(set_value);
        break;
    case 0x798:
        setSubnetMask3(set_value);
        break;
    case 0x799:
        setSubnetMask4(set_value);
        break;
    case 0x7A6:
        setDefaultGateway1(set_value);
        break;
    case 0x7A7:
        setDefaultGateway2(set_value);
        break;
    case 0x7A8:
        setDefaultGateway3(set_value);
        break;
    case 0x7A9:
        setDefaultGateway4(set_value);
        break;
    case 0x7A5:
        setPort(set_value);
        break;
    case 0x7B7:
        if(set_value.toInt() < 10 )
        {
            ui->auto_static_pbtn->setText(tr("Auto IP"));
        }else
        {
            ui->auto_static_pbtn->setText(tr("Static IP"));
        }
        break;
    default:break;
    }
}


void Parameter_Setting::on_languageChinese_pBtn_clicked()
{
    emit touch_InterfaceDataSignal(0x709, "0");
}

void Parameter_Setting::on_languageEnglish_pBtn_clicked()
{
    emit touch_InterfaceDataSignal(0x709, "2");
}

void Parameter_Setting::on_languageTraditionalChinese_pBtn_clicked()
{
    emit touch_InterfaceDataSignal(0x709, "1");
}

void Parameter_Setting::on_PCLINK_radioButton_clicked()
{
    emit touch_InterfaceDataSignal(0x750, "0");
}

void Parameter_Setting::on_PCLINK_SUM_radioButton_clicked()
{
    emit touch_InterfaceDataSignal(0x751, "0");
}

void Parameter_Setting::on_MODBUS_RTU_radioButton_clicked()
{
    emit touch_InterfaceDataSignal(0x752, "0");
}

void Parameter_Setting::on_baudRate9600_radioButton_clicked()
{
    emit touch_InterfaceDataSignal(0x770, "0");
}

void Parameter_Setting::on_baudRate19200_radioButton_clicked()
{
    emit touch_InterfaceDataSignal(0x771, "0");
}

void Parameter_Setting::on_baudRate38400_radioButton_clicked()
{
    emit touch_InterfaceDataSignal(0x772, "0");
}

void Parameter_Setting::on_baudRate57600_radioButton_clicked()
{
    emit touch_InterfaceDataSignal(0x773, "0");
}

void Parameter_Setting::on_baudRate115200_radioButton_clicked()
{
    emit touch_InterfaceDataSignal(0x774, "0");
}

void Parameter_Setting::on_auto_static_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(0x7B6, "0");
}

void Parameter_Setting::on_save_ip_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(0x7B0, "0");
}
