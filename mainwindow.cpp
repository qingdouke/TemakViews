#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqliteoperator.h"
#include "sql_generic_data.h"
#include "server.h"
#include "general_tools.h"
#include "address_data_show.h"

#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QMutexLocker>
#include <QDataStream>


SYS_INFO_F sys_info;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    //Header背景颜色
   // qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;

    ui->Header->setStyleSheet("QWidget#Header{background-color:rgb(72,129,52)}");
    //标题颜色
    ui->title->setStyleSheet("QLabel#title{color:white}");
    //logo颜色
    ui->logo->setStyleSheet("QLabel#logo{background-image:url(:/Image/85/1.bmp)}");

    //Header时间label初始化
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
    ui->current_time->setStyleSheet("QLabel#current_time{color:white}");
    //设置定时器 每一秒更新一次Header的时间label
    QTimer* timer = new QTimer(this);
    timer->start(1000);
    //Main背景颜色渐变
    ui->Main->setStyleSheet("QWidget#Main{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 white,stop:1 rgb(177,203,166))}");


    //九个image图标
    ui->image_1->setStyleSheet("QLabel#image_1{background-image:url(:/Image/icon/monitoring_interface.png);"
                               "background-repeat:no-repeat;"
                               "background-color:green;"
                               "background-position:center;"
                               "border-radius:10px}");
    ui->image_2->setStyleSheet("QLabel#image_2{background-image:url(:/Image/icon/output_monitoring.png);"
                               "background-repeat:no-repeat;"
                               "background-color:rgb(255,127,39);"
                               "background-position:center;"
                               "border-radius:10px}");
    ui->image_3->setStyleSheet("QLabel#image_3{background-image:url(:/Image/icon/curve_monitoring.png);"
                               "background-repeat:no-repeat;"
                               "background-color:rgb(0,64,0);"
                               "background-position:center;"
                               "border-radius:10px}");
    ui->image_4->setStyleSheet("QLabel#image_4{background-image:url(:/Image/icon/program_editing.png);"
                               "background-repeat:no-repeat;"
                               "background-color:green;"
                               "background-position:center;"
                               "border-radius:10px}");
    ui->image_5->setStyleSheet("QLabel#image_5{background-image:url(:/Image/icon/program_cycle.png);"
                               "background-repeat:no-repeat;"
                               "background-color:rgb(255,127,39);"
                               "background-position:center;"
                               "border-radius:10px}");
    ui->image_6->setStyleSheet("QLabel#image_6{background-image:url(:/Image/icon/constant_value_setting.png);"
                               "background-repeat:no-repeat;"
                               "background-color:rgb(0,64,0);"
                               "background-position:center;"
                               "border-radius:10px}");
    ui->image_7->setStyleSheet("QLabel#image_7{background-image:url(:/Image/icon/parameter_setting.png);"
                               "background-repeat:no-repeat;"
                               "background-color:green;"
                               "background-position:center;"
                               "border-radius:10px}");
    ui->image_8->setStyleSheet("QLabel#image_8{background-image:url(:/Image/icon/failure_record.png);"
                               "background-repeat:no-repeat;"
                               "background-color:rgb(255,127,39);"
                               "background-position:center;"
                               "border-radius:10px}");
    ui->image_9->setStyleSheet("QLabel#image_9{background-image:url(:/Image/icon/fault_description.png);"
                               "background-repeat:no-repeat;"
                               "background-color:rgb(0,64,0);"
                               "background-position:center;"
                               "border-radius:10px}");

    //九个pushbutton  // 改用样式表完成
   /* ui->pBtn_1->setStyleSheet("QPushButton#pBtn_1{background-color:rgba(255,255,255,0);"
                              "border:none}");
    ui->pBtn_2->setStyleSheet("QPushButton#pBtn_2{background-color:rgba(255,255,255,0);"
                              "border:none}");
    ui->pBtn_3->setStyleSheet("QPushButton#pBtn_3{background-color:rgba(255,255,255,0);"
                              "border:none}");
    ui->pBtn_4->setStyleSheet("QPushButton#pBtn_4{background-color:rgba(255,255,255,0);"
                              "border:none}");
    ui->pBtn_5->setStyleSheet("QPushButton#pBtn_5{background-color:rgba(255,255,255,0);"
                              "border:none}");
    ui->pBtn_6->setStyleSheet("QPushButton#pBtn_6{background-color:rgba(255,255,255,0);"
                              "border:none}");
    ui->pBtn_7->setStyleSheet("QPushButton#pBtn_7{background-color:rgba(255,255,255,0);"
                              "border:none}");
    ui->pBtn_8->setStyleSheet("QPushButton#pBtn_8{background-color:rgba(255,255,255,0);"
                              "border:none}");
    ui->pBtn_9->setStyleSheet("QPushButton#pBtn_9{background-color:rgba(255,255,255,0);"
                              "border:none}");*/

    //login pbtn
    ui->login->setStyleSheet("QPushButton#login{background:transparent;"
                             "border:none}");
    qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;

    //数据线程初始化
    readData01 = new Data;
    readData02 = new Data;
    dataReadThread = new QThread;
    readData01->isRunning = false;
    readData02->isRunning = false;
    readData01->moveToThread(dataReadThread);
    readData02->moveToThread(dataReadThread);
    dataReadThread->start();

    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&MainWindow::currentTime);
    //页面跳转信号槽
    connect(&monitoring_interface_page,&Monitoring_Interface::monitoring_interface_to_mainwindow,this,&MainWindow::deal_monitoring_interface_to_mainwindow);
    connect(&monitoring_interface_page,&Monitoring_Interface::monitoringInterface_to_outputMonitoring,this,&MainWindow::deal_monitoringInterface_to_outputMonitoring);
    connect(&output_monitoring_page,&Output_Monitoring::outputMonitoring_to_mainWindow,this,&MainWindow::deal_outputMonitoring_to_mainWindow);
    connect(&output_monitoring_page,&Output_Monitoring::outputMonitoring_to_monitoringInterface,this,&MainWindow::deal_outputMonitoring_to_monitoringInterface);
    connect(&output_monitoring_page,&Output_Monitoring::outputMonitoring_to_curveMonitoring,this,&MainWindow::deal_outputMonitoring_to_curveMonitoring);
    connect(&curve_monitoring_page,&Curve_Monitoring::curveMonitoring_to_mainWindow,this,&MainWindow::deal_curveMonitoring_to_mainWindow);
    connect(&curve_monitoring_page,&Curve_Monitoring::curveMonitoring_to_outputMonitoring,this,&MainWindow::deal_curveMonitoring_to_outputMonitoring);
    connect(&program_editing_page,&Program_Editing::programEditing_to_mainWindow,this,&MainWindow::deal_programEditing_to_mainWindow);
    connect(&program_loop_page,&Program_Loop::programLoop_to_mainWindow,this,&MainWindow::deal_programLoop_to_mainWindow);
    connect(&program_loop_page,&Program_Loop::programLoop_to_programEditing,this,&MainWindow::deal_programLoop_to_programEditing);
    connect(&program_loop_page,&Program_Loop::programLoop_to_fixedValueSetting,this,&MainWindow::deal_programLoop_to_fixedValueSetting);
    connect(&fixed_value_setting_page,&Fixed_Value_Setting::fixedValueSetting_to_mainWindow,this,&MainWindow::deal_fixedValueSetting_to_mainWindow);
    connect(&fixed_value_setting_page,&Fixed_Value_Setting::fixedValueSetting_to_programLoop,this,&MainWindow::deal_fixedValueSetting_to_programLoop);
    connect(&error_log_page,&Error_Log::errorLog_to_mainWindow,this,&MainWindow::deal_errorLog_to_mainWindow);
    connect(&keyboard,&Keyboard::pushButton_Enter_clicked,this,&MainWindow::deal_KeyboardEnter);
    connect(&keyboard,&Keyboard::pushButton_Esc_clicked,this,&MainWindow::deal_KeyboardEsc);
    connect(&calculate,&Calculate::pushButton_OK_clicked,this,&MainWindow::deal_CalculateOk);
    connect(&parameter_setting_page,&Parameter_Setting::parameterSetting_to_mainWindow,this,&MainWindow::deal_parameterSetting_to_mainWindow);
    connect(&parameter_setting_page,&Parameter_Setting::parameterSetting_to_CANSET,this,&MainWindow::deal_parameterSetting_to_CANSET);
    connect(&userPasswordPage01,&UserPasswordPage01::userPasswordPage01_to_mainWindow,this,&MainWindow::deal_userPasswordPage01_to_mainWindow);
    connect(&userPasswordPage01,&UserPasswordPage01::userPasswordPage01_to_userPasswordPage02,this,&MainWindow::deal_userPasswordPage01_to_userPasswordPage02);
    connect(&userPasswordPage02,&UserPasswordPage02::userPasswordPage02_to_mainWindow,this,&MainWindow::deal_userPasswordPage02_to_mainWindow);
    connect(&userPasswordPage02,&UserPasswordPage02::userPasswordPage02_to_userPasswordPage01,this,&MainWindow::deal_userPasswordPage02_to_userPasswordPage01);
    connect(&userPasswordPage02,&UserPasswordPage02::userPasswordPage02_to_userPasswordPage03,this,&MainWindow::deal_userPasswordPage02_to_userPasswordPage03);
    connect(&userPasswordPage03,&UserPasswordPage03::userPasswordPage03_to_mainWindow,this,&MainWindow::deal_userPasswordPage03_to_mainWindow);
    connect(&userPasswordPage03,&UserPasswordPage03::userPasswordPage03_to_userPasswordPage02,this,&MainWindow::deal_userPasswordPage03_to_userPasswordPage02);

    connect(&canset_page,&CANSET::canset_to_mainWindow,this,&MainWindow::deal_canset_to_mainWindow);
    connect(&canset_page,&CANSET::canset_to_parameterSetting,this,&MainWindow::deal_canset_to_parameterSetting);
    connect(&internal_param_set_page,&InternalParamSet::internalParamSet_to_mainWindow,this,&MainWindow::deal_internalParamSet_to_mainWindow);

    //请求使用数字键盘
    connect(&monitoring_interface_page,&Monitoring_Interface::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&output_monitoring_page,&Output_Monitoring::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&curve_monitoring_page,&Curve_Monitoring::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&program_editing_page,&Program_Editing::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&program_loop_page,&Program_Loop::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&fixed_value_setting_page,&Fixed_Value_Setting::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&error_log_page,&Error_Log::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&userPasswordPage01,&UserPasswordPage01::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&userPasswordPage02,&UserPasswordPage02::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&userPasswordPage03,&UserPasswordPage03::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&internal_param_set_page,&InternalParamSet::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);

    //请求使用虚拟全键盘
    connect(&monitoring_interface_page,&Monitoring_Interface::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&output_monitoring_page,&Output_Monitoring::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&curve_monitoring_page,&Curve_Monitoring::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&program_editing_page,&Program_Editing::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&program_loop_page,&Program_Loop::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&fixed_value_setting_page,&Fixed_Value_Setting::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&error_log_page,&Error_Log::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&userPasswordPage01,&UserPasswordPage01::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&userPasswordPage02,&UserPasswordPage02::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&userPasswordPage03,&UserPasswordPage03::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&internal_param_set_page,&InternalParamSet::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);

    // 按键信号处理
    connect(&monitoring_interface_page,&Monitoring_Interface::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&output_monitoring_page,&Output_Monitoring::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&curve_monitoring_page,&Curve_Monitoring::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&program_editing_page,&Program_Editing::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&program_loop_page,&Program_Loop::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&fixed_value_setting_page,&Fixed_Value_Setting::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&error_log_page,&Error_Log::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&userPasswordPage01,&UserPasswordPage01::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&userPasswordPage02,&UserPasswordPage02::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&userPasswordPage03,&UserPasswordPage03::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&internal_param_set_page,&InternalParamSet::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    //connect(&popUpWindow01,&PopUpWindow01::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    //connect(&popUpWindow02,&PopUpWindow02::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
   // connect(&popUpWindow03,&PopUpWindow03::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&popUpWindow04,&PopUpWindow04::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
   // connect(&popUpWindow05,&PopUpWindow05::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    //connect(&popUpWindow06,&PopUpWindow06::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    //connect(&popUpWindow07,&PopUpWindow07::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);
    connect(&popUpWindow08,&PopupWindow_SaveEnd::touch_InterfaceDataSignal,this,&MainWindow::deal_TouchInterfaceDataSignal);

    //线程处理
    connect(this,&MainWindow::InitDataThread01,readData01,&Data::dataFunction);
   // connect(this,&MainWindow::InitDataThread02,readData02,&Data::dataFunction);
    //connect(readData01,&Data::updateInterfaceNumberSignal,this,&MainWindow::deal_updateInterfaceNumber);
    //connect(readData02,&Data::updateInterfaceNumberSignal,this,&MainWindow::deal_updateInterfaceNumber);

    //connect(readData01,&Data::sql_updateMonitorInterfaceDataSignal,this,&MainWindow::deal_SQLInterfaceData_update);
    //connect(readData02,&Data::sql_updateMonitorInterfaceDataSignal,this,&MainWindow::deal_SQLInterfaceData_update);
    //connect(&serverTask,&Server::comm_updateInterfaceDataSignal,this,&MainWindow::deal_CommInterfaceData_update);
    connect(&tcpServerTask,&tcpServer::comm_updateInterfaceDataSignal,this,&MainWindow::deal_CommInterfaceData_update);
    connect(readData01,&Data::updateInterfaceDataSignal,this,&MainWindow::deal_updateInterfaceDataSignal);
    //connect(readData02,&Data::updateCurve,this,&MainWindow::deal_curveData_update);
    //qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;


}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * time: 2022-10-24
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void MainWindow::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

/*
 * time: 2022-10-31
 * type: private slots
 * effect: 跳转至监视界面
 * influence: this
*/
void MainWindow::on_pBtn_1_clicked()
{
    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(STATE_MONITOR));
    }else
    {
        last_page = current_Page;
        current_Page = STATE_MONITOR;
        QMutexLocker locker(&page_mutex);
        monitoring_interface_page.move(0,0);
        monitoring_interface_page.show();
        //线程启动
        this->dataThreadInit(current_Page);
        monitoring_interface_page.freezeOneSec();
        qDebug() <<"on_pBtn_1_clicked end";
        this->hide();
    }
}
void MainWindow:: on_pBtn_1_pressed()
{

}

/*
 * time: 2022-11-1
 * type: public void
 * effect: 处理监视界面的跳转信号
 * influence: this
*/
void MainWindow::deal_monitoring_interface_to_mainwindow(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->move(0,0);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        qDebug() <<"deal_monitoring_interface_to_mainwindow end";
        monitoring_interface_page.hide();
    }
}

/*
 * time: 2022-11-1
 * type: private slots
 * effect: 跳转至输出界面
 * influence: this
*/
void MainWindow::on_pBtn_2_clicked()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(OUTPUT_MONITOR));
    }else
    {
        last_page = current_Page;
        current_Page = OUTPUT_MONITOR;
        QMutexLocker locker(&page_mutex);
        output_monitoring_page.move(0,0);
        output_monitoring_page.show();
        this->dataThreadInit(current_Page);
        output_monitoring_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        this->hide();
    }

}

/*
 * time: 2022-11-2
 * type: public void
 * effect: 处理输出界面的跳转信号
 * influence: this
*/
void MainWindow::deal_outputMonitoring_to_mainWindow(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->move(0,0);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        output_monitoring_page.hide();
    }
}

/*
 * time: 2022-11-2
 * type: public void
 * effect: 处理输出界面的跳转信号
 * influence: this
*/
void MainWindow::deal_outputMonitoring_to_monitoringInterface(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(STATE_MONITOR));
    }else
    {
        last_page = current_Page;
        current_Page = STATE_MONITOR;
        QMutexLocker locker(&page_mutex);
        monitoring_interface_page.move(0,0);
        monitoring_interface_page.show();
        this->dataThreadInit(current_Page);
        monitoring_interface_page.freezeOneSec();
        output_monitoring_page.hide();
    }
}

/*
 * time: 2022-11-2
 * type: public void
 * effect: 处理输出界面的跳转信号
 * influence: this
*/
void MainWindow::deal_monitoringInterface_to_outputMonitoring(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(OUTPUT_MONITOR));
    }else
    {
        last_page = current_Page;
        current_Page = OUTPUT_MONITOR;
        QMutexLocker locker(&page_mutex);
        output_monitoring_page.move(0,0);
        output_monitoring_page.show();
        output_monitoring_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        monitoring_interface_page.hide();
    }
}

/*
 * time: 2022-11-2
 * type: private slots
 * effect: 跳转至输出界面
 * influence: this
*/
void MainWindow::on_pBtn_3_clicked()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(CURE_SHOW));
    }else
    {
        last_page = current_Page;
        current_Page = CURE_SHOW;
        QMutexLocker locker(&page_mutex);
        curve_monitoring_page.move(0,0);
        curve_monitoring_page.show();
        this->dataThreadInit(current_Page);
        curve_monitoring_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        this->hide();
    }
}


/*
 * time: 2022-11-3
 * type: private slots
 * effect: 处理曲线监视的跳转信号
 * influence: this
*/
void MainWindow::deal_curveMonitoring_to_mainWindow(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->move(0,0);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        curve_monitoring_page.hide();
    }

}

/*
 * time: 2022-11-3
 * type: private slots
 * effect: 处理曲线监视的跳转信号
 * influence: this
*/
void MainWindow::deal_curveMonitoring_to_outputMonitoring(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(OUTPUT_MONITOR));
    }else
    {
        last_page = current_Page;
        current_Page = OUTPUT_MONITOR;
        QMutexLocker locker(&page_mutex);
        output_monitoring_page.move(0,0);
        output_monitoring_page.show();
        this->dataThreadInit(current_Page);
        output_monitoring_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        curve_monitoring_page.hide();
    }
}

/*
 * time: 2022-11-3
 * type: private slots
 * effect: 处理曲线监视的跳转信号
 * influence: this
*/
void MainWindow::deal_outputMonitoring_to_curveMonitoring(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(CURE_SHOW));
    }else
    {
        last_page = current_Page;
        current_Page = CURE_SHOW;
        QMutexLocker locker(&page_mutex);
        curve_monitoring_page.move(0,0);
        curve_monitoring_page.show();
        this->dataThreadInit(current_Page);
        curve_monitoring_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        output_monitoring_page.hide();
    }
}

/*
 * time: 2022-11-2
 * type: private slots
 * effect: 跳转至程式编辑
 * influence: this
*/
void MainWindow::on_pBtn_4_clicked()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(PGM_EDIT));
    }else
    {
        last_page = current_Page;
        current_Page = PGM_EDIT;
        QMutexLocker locker(&page_mutex);
        program_editing_page.move(0,0);
        program_editing_page.show();
        this->dataThreadInit(current_Page);
        program_editing_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        this->hide();
    }
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 处理程式编辑的跳转信号
 * influence: this
*/
void MainWindow::deal_programEditing_to_mainWindow(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->move(0,0);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        program_editing_page.hide();
    }
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 跳转至程式循环
 * influence: this
*/
void MainWindow::on_pBtn_5_clicked()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(PGM_CYCLE));
    }else
    {
        last_page = current_Page;
        current_Page = PGM_CYCLE;
        QMutexLocker locker(&page_mutex);
        program_loop_page.move(0,0);
        program_loop_page.show();
        this->dataThreadInit(current_Page);
        program_loop_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        this->hide();
    }
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 处理程式循环的跳转信号
 * influence: this
*/
void MainWindow::deal_programLoop_to_mainWindow(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->move(0,0);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        program_loop_page.hide();
    }
}

/*
 * time: 2022-11-15
 * type: private slots
 * effect: 处理程式循环的跳转信号
 * influence: this
*/
void MainWindow::deal_programLoop_to_programEditing(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(PGM_EDIT));
    }else
    {
        last_page = current_Page;
        current_Page = PGM_EDIT;
        QMutexLocker locker(&page_mutex);
        program_editing_page.move(0,0);
        program_editing_page.show();
        this->dataThreadInit(current_Page);
        program_editing_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        program_loop_page.hide();
    }
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 跳转至定值设置
 * influence: this
*/
void MainWindow::on_pBtn_6_clicked()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(FIXED_FUN));
    }else
    {
        last_page = current_Page;
        current_Page = FIXED_FUN;
        QMutexLocker locker(&page_mutex);
        fixed_value_setting_page.move(0,0);
        fixed_value_setting_page.show();
        this->dataThreadInit(current_Page);
        fixed_value_setting_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        this->hide();
    }
}

/*
 * time: 2022-11-17
 * type: private slots
 * effect: 处理定值设置的跳转信号
 * influence: this
*/
void MainWindow::deal_fixedValueSetting_to_mainWindow(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        fixed_value_setting_page.hide();
        this->move(0,0);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
    }
}

/*
 * time: 2022-11-17
 * type: private slots
 * effect: 处理定值设置的跳转信号
 * influence: this
*/
void MainWindow::deal_fixedValueSetting_to_programLoop(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(PGM_CYCLE));
    }else
    {
        last_page = current_Page;
        current_Page = PGM_CYCLE;
        QMutexLocker locker(&page_mutex);
        program_loop_page.move(0,0);
        program_loop_page.show();
        this->dataThreadInit(current_Page);
        program_loop_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        fixed_value_setting_page.hide();
    }
}

/*
 * time: 2022-11-17
 * type: private slots
 * effect: 处理程式循环的跳转信号
 * influence: this
*/
void MainWindow::deal_programLoop_to_fixedValueSetting(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(FIXED_FUN));
    }else
    {
        last_page = current_Page;
        current_Page = FIXED_FUN;
        QMutexLocker locker(&page_mutex);
        fixed_value_setting_page.move(0,0);
        fixed_value_setting_page.show();
        this->dataThreadInit(current_Page);
        fixed_value_setting_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        program_loop_page.hide();
    }
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 跳转至参数设置
 * influence: this
*/
void MainWindow::on_pBtn_7_clicked()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(PARAM_SET));
    }else
    {
        last_page = current_Page;
        current_Page = PARAM_SET;
        QMutexLocker locker(&page_mutex);
        parameter_setting_page.move(0,0);
        parameter_setting_page.show();
        this->dataThreadInit(current_Page);
        parameter_setting_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        this->hide();
    }
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 跳转至故障记录
 * influence: this
*/
void MainWindow::on_pBtn_8_clicked()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(ERR_LOG_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = ERR_LOG_PAGE;
        QMutexLocker locker(&page_mutex);
        error_log_page.move(0,0);
        error_log_page.show();
        this->dataThreadInit(current_Page);
        this->hide();
    }
}

/*
 * time: 2022-11-17
 * type: private slots
 * effect: 处理故障记录的跳转信号
 * influence: this
*/
void MainWindow::deal_errorLog_to_mainWindow(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->move(0,0);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
        //    }
        error_log_page.hide();
    }
}

/*
 * time: 2022-11-22
 * type: private slots
 * effect: 主页密码登录
 * influence: this
*/
void MainWindow::on_login_clicked()
{    
    keyboard.Clean_Keyboard_CapsLock();
    keyboard.Clean_Keyboard_LineEdit();
   /*eyboard.hide();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }*/
    keyboard.move((this->width()-keyboard.width())/2,(this->height()-keyboard.height())/2);
    keyboard.show();
    current_ID = 0xF00;
}


/*
 * time: 2022-11-24
 * type: private slots
 * effect: 处理参数设置的跳转信号
 * influence: this
*/
void MainWindow::deal_parameterSetting_to_mainWindow(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->move(0,0);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        parameter_setting_page.hide();
    }
}

/*
 * time: 2022-11-24
 * type: private slots
 * effect: 处理参数设置的跳转信号
 * influence: this
*/
void MainWindow::deal_parameterSetting_to_CANSET(){
    //last_page = current_Page;
    //current_Page = PARAM_SET;
    /*if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(current_Page));
    }else*/
    {
        QMutexLocker locker(&page_mutex);
        canset_page.move(0,0);
        canset_page.show();
        //this->dataThreadInit(current_Page);
        canset_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        parameter_setting_page.hide();
    }
}

void MainWindow::deal_RequestUseKeyBoardSignal(int ID){
    QMutexLocker locker(&page_mutex);
    keyboard.Clean_Keyboard_CapsLock();
    keyboard.Clean_Keyboard_LineEdit();
    keyboard.hide();
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    keyboard.move((this->width()-keyboard.width())/2,(this->height()-keyboard.height())/2);
    keyboard.show();
    printf("string key id is %d\n",ID);
    current_ID = ID;
}

void MainWindow::deal_RequestUseCalculateSignal(int ID){
    QMutexLocker locker(&page_mutex);
    calculate.Clean_Calculater_LineEdit();
    calculate.hide();
    /*QTime dieTime = QTime::currentTime().addMSecs(100);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }*/
    calculate.move((this->width()-calculate.width())/2,(this->height()-calculate.height())/2);
    calculate.show();
    Qt::WindowFlags flags = windowFlags();
    flags &= ~Qt::WindowStaysOnTopHint;
    calculate.setWindowFlags(flags);
    printf("calculate key id is %d\n",ID);
    calculate_ID = ID;
}



void MainWindow::deal_userPasswordPage01_to_mainWindow(){

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        userPasswordPage01.hide();
    }
}

void MainWindow::deal_userPasswordPage01_to_userPasswordPage02()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(USER_PSD_PAGE2));
    }else
    {
        last_page = current_Page;
        current_Page = USER_PSD_PAGE2;
        QMutexLocker locker(&page_mutex);
        userPasswordPage02.show();
        this->dataThreadInit(current_Page);
        userPasswordPage02.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        userPasswordPage01.hide();
    }
}

void MainWindow::deal_userPasswordPage02_to_mainWindow()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        userPasswordPage02.hide();
    }
}

void MainWindow::deal_userPasswordPage02_to_userPasswordPage01()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(USER_PSD_PAGE1));
    }else
    {
        last_page = current_Page;
        current_Page = USER_PSD_PAGE1;
        QMutexLocker locker(&page_mutex);
        userPasswordPage01.show();
        this->dataThreadInit(current_Page);
        userPasswordPage01.freezeOneSec();       
        userPasswordPage02.hide();
    }
}

void MainWindow::deal_userPasswordPage02_to_userPasswordPage03()
{

    /*if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(USER_PSD_PAGE3));
    }else
    {
        last_page = current_Page;
        current_Page = USER_PSD_PAGE3;*/
        QMutexLocker locker(&page_mutex);
        userPasswordPage03.show();
        this->dataThreadInit(current_Page);
        userPasswordPage03.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        userPasswordPage02.hide();
    //}
}

void MainWindow::deal_userPasswordPage03_to_mainWindow()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        userPasswordPage03.hide();
    }
}

void MainWindow::deal_userPasswordPage03_to_userPasswordPage02()
{

    /*if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(USER_PSD_PAGE2));
    }else
    {
        last_page = current_Page;
        current_Page = USER_PSD_PAGE2;*/
        QMutexLocker locker(&page_mutex);
        userPasswordPage02.show();
        this->dataThreadInit(current_Page);
        userPasswordPage02.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        userPasswordPage03.hide();
    //}
}

void MainWindow::deal_canset_to_mainWindow()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        canset_page.hide();
    }
}

void MainWindow::deal_canset_to_parameterSetting()
{
    //last_page = current_Page;
    //current_Page = PARAM_SET;
    /*if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(current_Page));
    }else*/
    {
        QMutexLocker locker(&page_mutex);
        parameter_setting_page.show();
       // this->dataThreadInit(current_Page);
        parameter_setting_page.freezeOneSec();
        //    QTime dieTime = QTime::currentTime().addMSecs(100);
        //    while(QTime::currentTime()<dieTime){
        //        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        //    }
        canset_page.hide();
    }
}

void MainWindow::deal_internalParamSet_to_mainWindow()
{

    if(0 == page_debug_state)
    {
        tcpServerTask.sendData(addr_touch_pageturn_pbtn,QString::number(MAIN_PAGE));
    }else
    {
        last_page = current_Page;
        current_Page = MAIN_PAGE;
        QMutexLocker locker(&page_mutex);
        this->show();
        this->dataThreadInit(current_Page);
        this->freezeOneSec();
        internal_param_set_page.hide();
    }
}

void MainWindow:: dataThreadInit(int page_num)
{
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(page_num);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(page_num);
    }
}

void MainWindow::freezeOneSec()
{
    /*ui->pBtn_1->setEnabled(false);
    ui->pBtn_2->setEnabled(false);
    ui->pBtn_3->setEnabled(false);
    ui->pBtn_4->setEnabled(false);
    ui->pBtn_5->setEnabled(false);
    ui->pBtn_6->setEnabled(false);
    ui->pBtn_7->setEnabled(false);
    ui->pBtn_8->setEnabled(false);
    ui->pBtn_9->setEnabled(false);
    ui->login->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    ui->login->setEnabled(false);
    ui->pBtn_1->setEnabled(true);
    ui->pBtn_2->setEnabled(true);
    ui->pBtn_3->setEnabled(true);
    ui->pBtn_4->setEnabled(true);
    ui->pBtn_5->setEnabled(true);
    ui->pBtn_6->setEnabled(true);
    ui->pBtn_7->setEnabled(true);
    ui->pBtn_8->setEnabled(true);
    ui->pBtn_9->setEnabled(true);*/
}

void MainWindow::deal_updateInterfaceNumber(int addr,QString strs)
{
    serverTask.sendData(addr,strs);
}

/*
 * time: 2022-11-22
 * type: private slots
 * effect: 处理虚拟键盘信号
 * influence: keyboard
*/
void MainWindow::deal_KeyboardEsc(){
    keyboard.hide();
    keyboard.Clean_Keyboard_LineEdit();
    keyboard.Clean_Keyboard_CapsLock();
}

/*
 * time: 2022-11-22
 * type: private slots
 * effect: 处理虚拟键盘信号
 * influence: keyboard
*/
void MainWindow::deal_KeyboardEnter(){
    keyboardStrs = keyboard.get_strs();    
    if(0 == page_debug_state)
    {
        tcpServerTask.sendText(current_ID,keyboardStrs);
    }else
    {
        if(keyboardStrs=="3337")
        {
            QMutexLocker locker(&page_mutex);
            userPasswordPage01.move(0,0);
            userPasswordPage01.show();
            last_page = current_Page;
            current_Page = USER_PSD_PAGE1;
            this->dataThreadInit(current_Page);
            userPasswordPage01.freezeOneSec();            
            this->hide();
        }
        else
            if(keyboardStrs == internal_param_set_page.getViewPassword())
            {
                QMutexLocker locker(&page_mutex);
                internal_param_set_page.move(0,0);
                internal_param_set_page.show();
                last_page = current_Page;
                current_Page = TAB_PARAM_PAGE;
                this->dataThreadInit(current_Page);
                this->hide();
            }
            else{
                popUpWindow07.setChinese("密码错误！");
                popUpWindow07.setEnglish("Password Error!");
                popUpWindow07.centerShow(this->width(),this->height());
            }
    }
}

void MainWindow::deal_CalculateOk(){
    calculateStrs = calculate.get_strs();
    int number = calculateStrs.toInt();
    writeTouchDBData(1, 1,calculate_ID,number,calculateStrs, 1,"null",0,"null","null","null");
    switch (calculate_ID) {
    case addr_touch_test_temperature_sv:
    case addr_touch_onepoint_test_temperature:
    case addr_touch_edit_pgm_value1_row1:
    case addr_touch_edit_pgm_value1_row2:
    case addr_touch_edit_pgm_value1_row3:
    case addr_touch_edit_pgm_value1_row4:
    case 0x1413:
    case 0x1416:
    case 0x1417:
    case 0x1426:
    case 0x1427:
    case 0x1428:
        tcpServerTask.sendData(calculate_ID,convertToIntegerString(calculateStrs,2));
        monitoring_interface_page.setFocus();
        break;
    case addr_touch_humidity_sv:
    case addr_touch_onepoint_test_humidity:
    case addr_touch_edit_pgm_value2_row1:
    case addr_touch_edit_pgm_value2_row2:
    case addr_touch_edit_pgm_value2_row3:
    case addr_touch_edit_pgm_value2_row4:
        tcpServerTask.sendData(calculate_ID,convertToIntegerString(calculateStrs,1));
        monitoring_interface_page.setFocus();
        break;
    default:
        tcpServerTask.sendData(calculate_ID,calculateStrs);
        monitoring_interface_page.setFocus();
        break;
    }
}
void MainWindow::deal_TouchInterfaceDataSignal(int addr,QString strs)
{
    qDebug() << QString("addr_num: %1 %2").arg(addr).arg(strs);
    tcpServerTask.sendData(addr,strs);
}

QString MainWindow::getRunStateString(int run_state){
    QString runsta_string = "定值运行";
    switch(run_state)
    {
        case 0: runsta_string = "定值运行";break;
        case 1: runsta_string = "定值運行";break;
        case 2: runsta_string = "POINT RUN";break;
        case 10: runsta_string = "程式运行";break;
        case 11: runsta_string = "程式運行";break;
        case 12: runsta_string = "PGM RUN";break;
        case 20: runsta_string = "停机回常温";break;
        case 21: runsta_string = "停機回常溫";break;
        case 22: runsta_string = "BACK ROOM";break;
        case 30: runsta_string = "系统停止";break;
        case 31: runsta_string = "系統停止";break;
        case 32: runsta_string = "SYS STOP";break;
        case 40: runsta_string = "系统运行";break;
        case 41: runsta_string = "系統運行";break;
        case 42: runsta_string = "SYS RUNING";break;
        case 50: runsta_string = "系统故障";break;
        case 51: runsta_string = "系統故障";break;
        case 52: runsta_string = "SYS ERROR";break;
        case 60: runsta_string = "预约运行";break;
        case 61: runsta_string = "預約運行";break;
        case 62: runsta_string = "APPT RUN";break;
        case 70: runsta_string = "系统调试";break;
        case 71: runsta_string = "系統調試";break;
        case 72: runsta_string = "SYS DEBUG";break;
        case 80: runsta_string = "系统警告";break;
        case 81: runsta_string = "系統警告";break;
        case 82: runsta_string = "SYS ALARM";break;
        case 90: runsta_string = "除霜中";break;
        case 91: runsta_string = "除霜中";break;
        case 92: runsta_string = "DEFROST";break;
        case 100: runsta_string = "高温冲击";break;
        case 101: runsta_string = "高溫衝擊";break;
        case 102: runsta_string = "HI SHOCK";break;
        case 110: runsta_string = "低温冲击";break;
        case 111: runsta_string = "低溫衝擊";break;
        case 112: runsta_string = "LOW SHOCK";break;
        case 120: runsta_string = "恒温状态";break;
        case 121: runsta_string = "恆溫狀態";break;
        case 122: runsta_string = "TEMP CONS";break;
        case 130: runsta_string = "低温恒温";break;
        case 131: runsta_string = "低溫恆溫";break;
        case 132: runsta_string = "LOWT CONS";break;
        case 140: runsta_string = "等待预冷";break;
        case 141: runsta_string = "等待預冷";break;
        case 142: runsta_string = "COOL WAIT";break;
        case 150: runsta_string = "湿度上升";break;
        case 151: runsta_string = "溼度上升";break;
        case 152: runsta_string = "H RAISE";break;
        case 160: runsta_string = "常温状态";break;
        case 161: runsta_string = "常溫狀態";break;
        case 162: runsta_string = "ROOM TEMP";break;
        case 170: runsta_string = "恒湿状态";break;
        case 171: runsta_string = "恆溼狀態";break;
        case 172: runsta_string = "HUMI CONS";break;
        case 180: runsta_string = "高温状态";break;
        case 181: runsta_string = "高溫狀態";break;
        case 182: runsta_string = "HIGH TEMP";break;
        case 190: runsta_string = "湿度下降";break;
        case 191: runsta_string = "溼度下降";break;
        case 192: runsta_string = "HUMI DROP";break;
        case 200: runsta_string = "低温状态";break;
        case 201: runsta_string = "低溫狀態";break;
        case 202: runsta_string = "LOW TEMP";break;
        case 210: runsta_string = "超低温状态";break;
        case 211: runsta_string = "超低溫狀態";break;
        case 212: runsta_string = "ULTRA LOWT";break;
        case 220: runsta_string = "高湿状态";break;
        case 221: runsta_string = "高溼狀態";break;
        case 222: runsta_string = "HIGT HUMI";break;
        case 230: runsta_string = "样品预热";break;
        case 231: runsta_string = "樣品預熱";break;
        case 232: runsta_string = "SAMP PREH";break;
        case 240: runsta_string = "";break;
        case 241: runsta_string = "";break;
        case 242: runsta_string = "";break;
        case 250: runsta_string = "暂停运行";break;
        case 251: runsta_string = "暫停運行";break;
        case 252: runsta_string = "RUN PAUSE";break;
    default:break;
    }
    return runsta_string;
}

int MainWindow::getRunStatecolor(int run_state){
    int runsta_color = 0;
    switch(run_state)
    {
        case 50:
        case 51:
        case 52:
        case 80:
        case 81:
        case 82: runsta_color = 1;break;
        case 30:
        case 31:
        case 32:
        case 40:
        case 41:
        case 42:
        case 60:
        case 61:
        case 62: runsta_color = 2;break;
        case 250:
        case 251:
        case 252: runsta_color = 3;break;
    default:
        break;
    }
    return runsta_color;
}

void MainWindow::deal_SQLInterfaceData_update(int id_num,QString data_strs)
{
    switch(current_Page)
    {
    case STATE_MONITOR:     monitoring_interface_page.idSetMonitorInterfaceData(id_num , data_strs);   break;
    case OUTPUT_MONITOR:    output_monitoring_page.idSetOutputInterfaceData(id_num , data_strs);         break;
    case CURE_SHOW:         break;
    case PGM_EDIT:          break;
    case PGM_CYCLE:         break;
    case FIXED_FUN:         break;
    case PARAM_SET:         break;
    case ERR_LOG_PAGE:      break;
    case PGM_SLT_PAGE:      break;
    case CLT_DATA_PAGE:     break;
    case USER_PSD_PAGE1:    break;
    case USER_PSD_PAGE2:    break;
    case USER_PSD_PAGE3:    break;
    case TAB_PARAM_PAGE:    break;
    default: break;
    }
}



void MainWindow::deal_CommInterfaceData_update(int addr_num,QString data_strs)
{
    qDebug() << QString("addr_num: %1").arg(addr_num);
   // qDebug() << QString("data_strs: %1").arg(data_strs);
    //qDebug() << QString("current_Page:%1").arg(current_Page);
    if(0x4F == addr_num)        // pop up window
    {

        int data_key = data_strs.toInt();
        usePopupWindow(data_key);
    }
    if(0x03 == addr_num)       // interface switch
    {
        oldPageHide(current_Page);
        newPageShow(data_strs.toInt());
        //oldPageHide(last_page);
    }else
    {
        this->addrSetSystemData(addr_num , data_strs);
       // switch(current_Page)
        {
        //case STATE_MONITOR:
            monitoring_interface_page.addrSetMonitorInterfaceData(addr_num , data_strs);
         //   break;
        //case OUTPUT_MONITOR:
            output_monitoring_page.addrSetOutputInterfaceData(addr_num , data_strs);
            //break;
        //case CURE_SHOW:
            curve_monitoring_page.addrSetCurveInterfaceData(addr_num , data_strs);
         //   break;
       // case PGM_EDIT:
            program_editing_page.addrSetPgmEditInterfaceData(addr_num , data_strs);
            //break;
       // case PGM_CYCLE:
            program_loop_page.addrSetPgmLoopInterfaceData(addr_num , data_strs);
       //    break;
       // case FIXED_FUN:
            fixed_value_setting_page.addrSetOnepointInterfaceData(addr_num,data_strs);
        //    break;
       // case PARAM_SET:
            parameter_setting_page.addrSetParamSetInterfaceData(addr_num , data_strs);
            canset_page.addrSetCanInterfaceData(addr_num , data_strs);
        //    break;
        //case ERR_LOG_PAGE:
            error_log_page.addrSetErrLogInterfaceData(addr_num , data_strs);
        //    break;
        //case PGM_SLT_PAGE:
            popUpWindow04.addrSetPgmListInterfaceData(addr_num,data_strs);
         //   break;
       // case CLT_DATA_PAGE:
        //     break;
       // case USER_PSD_PAGE1:
            userPasswordPage01.addrSetUserPsdInterfaceData(addr_num,data_strs);
        //    break;
       //case USER_PSD_PAGE2:
       // case USER_PSD_PAGE3:
            userPasswordPage02.addrSetUserPsdInterfaceData(addr_num,data_strs);
            userPasswordPage03.addrSetUserPsdInterfaceData(addr_num,data_strs);
        //   break;
       // case TAB_PARAM_PAGE:
            internal_param_set_page.addrInternalParamInterfaceData(addr_num,data_strs);
        //    break;
        //default: break;
        }
    }
}


void MainWindow::deal_updateInterfaceDataSignal(void)
{
    switch(current_Page)
    {
    case STATE_MONITOR:     monitoring_interface_page.refreshMonitorInterfaceData();   break;
    case OUTPUT_MONITOR:    output_monitoring_page.refreshOutPutInterfaceData();   break;
    case CURE_SHOW:         curve_monitoring_page.refreshCurveInterfaceData();   break;
    case PGM_EDIT:          program_editing_page.refreshPgmEditInterfaceData();   break;
    case PGM_CYCLE:         program_loop_page.refreshPgmLoopInterfaceData();   break;
    case FIXED_FUN:         fixed_value_setting_page.refreshOnePointInterfaceData();  break;
    case PGM_SLT_PAGE:      popUpWindow04.refreshOutPutInterfaceData();break;
    case PARAM_SET:         parameter_setting_page.refreshParamSetInterfaceData();      break;
    case ERR_LOG_PAGE:      error_log_page.refreshErrorLogInterfaceData();   break;
    case CLT_DATA_PAGE:     break;
   /* case USER_PSD_PAGE1:    userPasswordPage01.addrSetUserPsdInterfaceData(addr_num,data_strs);  break;
    //case CLT_DATA_PAGE:     break;
    case USER_PSD_PAGE2:
    case USER_PSD_PAGE3:
        userPasswordPage02.addrSetUserPsdInterfaceData(addr_num,data_strs);
        userPasswordPage03.addrSetUserPsdInterfaceData(addr_num,data_strs);
        break;*/
    case TAB_PARAM_PAGE:    internal_param_set_page.refreshInternalSetInterface();  break;

    default: break;
    }
}




void MainWindow::newPageShow(int page_num)
{
    QMutexLocker locker(&page_mutex);
    last_page = current_Page;
    current_Page = page_num;
    this->dataThreadInit(current_Page);

    switch(current_Page)
    {
    case MAIN_PAGE:
        this->move(0,0);
        this->show();
        this->freezeOneSec();
        break;
    case STATE_MONITOR:
        monitoring_interface_page.move(0,0);
        monitoring_interface_page.show();
        monitoring_interface_page.freezeOneSec();
        break;
    case OUTPUT_MONITOR:
        output_monitoring_page.move(0,0);
        output_monitoring_page.show();
        output_monitoring_page.freezeOneSec();
        break;
    case CURE_SHOW:
        curve_monitoring_page.move(0,0);
        curve_monitoring_page.show();
        curve_monitoring_page.freezeOneSec();
        break;
    case PGM_EDIT:
        program_editing_page.move(0,0);
        program_editing_page.show();
        program_editing_page.freezeOneSec();
        break;
    case PGM_CYCLE:
        program_loop_page.move(0,0);
        program_loop_page.show();
        program_loop_page.freezeOneSec();
        break;
    case FIXED_FUN:
        fixed_value_setting_page.move(0,0);
        fixed_value_setting_page.show();
        fixed_value_setting_page.freezeOneSec();
        break;
    case PARAM_SET:
        parameter_setting_page.move(0,0);
        parameter_setting_page.show();
        parameter_setting_page.freezeOneSec();
        break;
    case ERR_LOG_PAGE:
        error_log_page.move(0,0);
        error_log_page.show();
        break;
    case PGM_SLT_PAGE:
        popUpWindow04.move(0,0);
        popUpWindow04.show();
        break;
    case CLT_DATA_PAGE:
        break;
    case USER_PSD_PAGE1:
        userPasswordPage01.move(0,0);
        userPasswordPage01.show();
        break;
    case USER_PSD_PAGE2:
        userPasswordPage02.move(0,0);
        userPasswordPage02.show();
        break;
    case USER_PSD_PAGE3:
        userPasswordPage03.move(0,0);
        userPasswordPage03.show();
        break;
    case TAB_PARAM_PAGE:
        internal_param_set_page.move(0,0);
        internal_param_set_page.show();
        break;
    default: break;
    }
}

void MainWindow::oldPageHide(int page_num)
{
    switch(page_num)
    {
    case MAIN_PAGE:
        this->hide();
        break;
    case STATE_MONITOR:
        monitoring_interface_page.hide();
        break;
    case OUTPUT_MONITOR:
        output_monitoring_page.hide();
        break;
    case CURE_SHOW:
        curve_monitoring_page.hide();
        break;
    case PGM_EDIT:
        program_editing_page.hide();
        break;
    case PGM_CYCLE:
        program_loop_page.hide();
        break;
    case FIXED_FUN:
        fixed_value_setting_page.hide();
        break;
    case PARAM_SET:
        parameter_setting_page.hide();
        canset_page.hide();
        break;
    case ERR_LOG_PAGE:
        error_log_page.hide();
        break;
    case PGM_SLT_PAGE:
        popUpWindow04.hide();
        break;
    case CLT_DATA_PAGE:
        break;
    case USER_PSD_PAGE1:
        userPasswordPage01.hide();
        break;
    case USER_PSD_PAGE2:
        userPasswordPage02.hide();
        break;
    case USER_PSD_PAGE3:
        userPasswordPage03.hide();
        break;
    case TAB_PARAM_PAGE:
        internal_param_set_page.hide();
        break;
    default: break;
    }
}


void MainWindow::usePopupWindow(int key_code)
{
    switch(key_code)
    {
    case SAVE_SUC_KEY:
        popUpWindow07.setChinese("存储成功");
        popUpWindow07.setEnglish("Saved successfully");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case PWD_CHANGE_SUC_KEY:
        popUpWindow07.setChinese("密码修改成功");
        popUpWindow07.setEnglish("Password be changed");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case SAVEING_KEY:
        popUpWindow07.setChinese("存储中请稍后");
        popUpWindow07.setEnglish("Please wait storing");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case N0_PGM_LOAD_KEY:
        popUpWindow07.setChinese("运行中不可载入程式");
        popUpWindow07.setEnglish("Can't load pgm when system is running");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case NO_PGM_JUMP_KEY:
        popUpWindow07.setChinese("程式未运行不可跳段");
        popUpWindow07.setEnglish("Pgm is't running,can't jump sgm");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case THE_NUM_KEY:  //跳段使用数字键盘输入目标段
        deal_RequestUseCalculateSignal(0x361);
        break;
    case NO_THIS_SGM:
        popUpWindow07.setChinese("无效段");
        popUpWindow07.setEnglish("Have no this sgm");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case PGM_TIME_ZERO_KEY:
        popUpWindow07.setChinese("程式时间不能为0");
        popUpWindow07.setEnglish("Pgm time can't set to 0");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case RUN_NOT_SAVE_KEY:
        popUpWindow07.setChinese("运行时不可编辑");
        popUpWindow07.setEnglish("Can't edit when system is running");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case NO_PGM_RUN_KEY:
        popUpWindow07.setChinese("程式未载入，请先加载程式");
        popUpWindow07.setEnglish("Please load pgm");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case SAVE_FAL_KEY:
        popUpWindow07.setChinese("保存失败");
        popUpWindow07.setEnglish("Save failure");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case SYS_RUN_KEY:
        break;
    case SYS_STOP_KEY:
        break;
    case NO_THIS_FUNCTIION:
        popUpWindow07.setChinese("本版本暂不支持此功能");
        popUpWindow07.setEnglish("This version haven't this function");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case PLEASE_ENTER_USB:
        popUpWindow07.setChinese("请插入U盘");
        popUpWindow07.setEnglish("Please enter USB");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case PLEASE_ENTER_SD:
        popUpWindow07.setChinese("请插入SD卡");
        popUpWindow07.setEnglish("Please enter SD");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case NO_ACCESS_KEY:
        popUpWindow07.setChinese("暂无权限进行此操作");
        popUpWindow07.setEnglish("Have no permission to perform this operation");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case ENTER_ASCII_KEY:
        deal_RequestUseKeyBoardSignal(0x1D0);
        break;
    case SYSTEM_STOP_KEY:
        popUpWindow07.setChinese("设备已停机，请取放样品");
        popUpWindow07.setEnglish("The system is stop,please take the sample");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case NUM_NO_DEC_KEY:
        deal_RequestUseCalculateSignal(0x3010);
        break;
    case NUM_ONE_DEC_KEY:
        deal_RequestUseCalculateSignal(0x3011);
        break;
    case NUM_TWO_DEC_KEY:
        deal_RequestUseCalculateSignal(0x3012);
        break;
    case NUM_THR_DEC_KEY:
        deal_RequestUseCalculateSignal(0x3013);
        break;
    case STR_DEC_KEY:
        deal_RequestUseKeyBoardSignal(0x30F0);
        break;
    case THE_PASSWORD_ERR:
        popUpWindow07.setChinese("密码错误");
        popUpWindow07.setEnglish("Password Error");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case PGMNAME_CANT_DEFT:
        popUpWindow07.setChinese("程式名称不能为空");
        popUpWindow07.setEnglish("Pgm must have name");
        popUpWindow07.centerShow(this->width(),this->height());
        break;
    case PGM_PAUSE_KEY:
        popUpWindow08.setChinese("是否暂停?");
        popUpWindow08.setEnglish("Pause running?");
        popUpWindow08.setPopupWindowAddr(0x74);
        popUpWindow08.centerShow(this->width(),this->height());
        break;
    case ENTER_KEY:
        popUpWindow08.hide();
        popUpWindow07.hide();
        break;
    default:
        break;
    }

}

void MainWindow::addrSetSystemData(int addr_num, QString set_value){

    //QString covert_data;
    switch(addr_num)
    {

    case addr_run_stop_pbtn_state:
        sys_info.sys_sta = (bool)set_value.toInt();
        break;
    case addr_run_flag_state:
        sys_info.run_sta = set_value.toInt();
        sys_info.run_sta_string = getRunStateString(sys_info.run_sta);
        sys_info.run_sta_color = getRunStatecolor(sys_info.run_sta);
        break;
    case addr_sys_usb_state:
        sys_info.usb_flag = (bool)set_value.toInt();
        break;
    case addr_sys_sd_state:
        sys_info.sd_flag = (bool)set_value.toInt();
        break;
    case addr_sys_comm_state:
        sys_info.host_mode = (bool)set_value.toInt();
        break;
    case addr_sys_burn_state:
        sys_info.burn_flag = (bool)set_value.toInt();
        break;
    case addr_sys_wifi_state:
        sys_info.wifi_flag = (bool)set_value.toInt();
        break;
    case addr_sys_abnormal_state:
        sys_info.abnormal_flag = (bool)set_value.toInt();
        break;
    default:break;
    }
}
