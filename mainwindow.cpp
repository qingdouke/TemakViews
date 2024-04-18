#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqliteoperator.h"
#include "sql_generic_data.h"
#include "server.h"

#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QMutexLocker>
#include <QDataStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    //Header背景颜色
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

    //九个pushbutton
    ui->pBtn_1->setStyleSheet("QPushButton#pBtn_1{background-color:rgba(255,255,255,0);"
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
                              "border:none}");

    //login pbtn
    ui->login->setStyleSheet("QPushButton#login{background:transparent;"
                             "border:none}");

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
    connect(&internal_param_set_page,&internal_param_set::internalParamSet_to_mainWindow,this,&MainWindow::deal_internalParamSet_to_mainWindow);

    //请求使用虚拟键盘
    printf("use calculate  key\n");
    connect(&monitoring_interface_page,&Monitoring_Interface::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&program_editing_page,&Program_Editing::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&userPasswordPage01,&UserPasswordPage01::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);
    connect(&internal_param_set_page,&internal_param_set::Request_Use_Calculate_Signal,this,&MainWindow::deal_RequestUseCalculateSignal);
    connect(&internal_param_set_page,&internal_param_set::Request_Use_Keyboard_Signal,this,&MainWindow::deal_RequestUseKeyBoardSignal);

    //数据处理
    connect(&monitoring_interface_page,&Monitoring_Interface::monitoring_interface_choose_program,this,&MainWindow::deal_ChooseProgramSignals);
    connect(&output_monitoring_page,&Output_Monitoring::outputMonitoringChooseProgramSignals,this,&MainWindow::deal_ChooseProgramSignals);
    connect(&program_editing_page,&Program_Editing::programEditingChooseProgramSignals,this,&MainWindow::deal_ChooseProgramSignals);

    //线程处理
    connect(this,&MainWindow::InitDataThread01,readData01,&Data::dataFunction);
    connect(this,&MainWindow::InitDataThread02,readData02,&Data::dataFunction);
    connect(readData01,&Data::updateInterfaceNumberSignal,this,&MainWindow::deal_updateInterfaceNumber);
    connect(readData02,&Data::updateInterfaceNumberSignal,this,&MainWindow::deal_updateInterfaceNumber);

    //connect(readData01,&Data::sql_updateMonitorInterfaceDataSignal,this,&MainWindow::deal_SQLInterfaceData_update);
    //connect(readData02,&Data::sql_updateMonitorInterfaceDataSignal,this,&MainWindow::deal_SQLInterfaceData_update);
    connect(&serverTask,&Server::comm_updateInterfaceDataSignal,this,&MainWindow::deal_CommInterfaceData_update);
    connect(&tcpServerTask,&tcpServer::comm_updateInterfaceDataSignal,this,&MainWindow::deal_CommInterfaceData_update);

    connect(readData01,&Data::updateCurve,this,&MainWindow::deal_curveData_update);
    connect(readData02,&Data::updateCurve,this,&MainWindow::deal_curveData_update);
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
    QMutexLocker locker(&page_mutex);
    monitoring_interface_page.move(0,0);
    monitoring_interface_page.show();
    current_Page=1;
    //线程启动
    if(readData01->isRunning==false)
    {
        readData01->isRunning = true;
        readData02->isRunning = false;        
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    monitoring_interface_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    qDebug() <<"on_pBtn_1_clicked end";
    this->hide();
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
    QMutexLocker locker(&page_mutex);
    this->move(0,0);
    this->show();
    current_Page=0;
    if(readData01->isRunning==false)
    {
        readData01->isRunning = true;
        readData02->isRunning = false;        
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    qDebug() <<"deal_monitoring_interface_to_mainwindow end";
    monitoring_interface_page.hide();
}

/*
 * time: 2022-11-1
 * type: private slots
 * effect: 跳转至输出界面
 * influence: this
*/
void MainWindow::on_pBtn_2_clicked()
{
    QMutexLocker locker(&page_mutex);
    output_monitoring_page.move(0,0);
    output_monitoring_page.show();
    current_Page=2;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    output_monitoring_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    this->hide();

}

/*
 * time: 2022-11-2
 * type: public void
 * effect: 处理输出界面的跳转信号
 * influence: this
*/
void MainWindow::deal_outputMonitoring_to_mainWindow(){
    QMutexLocker locker(&page_mutex);
    this->move(0,0);
    this->show();
    current_Page = 0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    output_monitoring_page.hide();
}

/*
 * time: 2022-11-2
 * type: public void
 * effect: 处理输出界面的跳转信号
 * influence: this
*/
void MainWindow::deal_outputMonitoring_to_monitoringInterface(){
    QMutexLocker locker(&page_mutex);
    monitoring_interface_page.move(0,0);
    monitoring_interface_page.show();
    current_Page = 1;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    monitoring_interface_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    output_monitoring_page.hide();
}

/*
 * time: 2022-11-2
 * type: public void
 * effect: 处理输出界面的跳转信号
 * influence: this
*/
void MainWindow::deal_monitoringInterface_to_outputMonitoring(){
    QMutexLocker locker(&page_mutex);
    output_monitoring_page.move(0,0);
    output_monitoring_page.show();
    current_Page=2;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    output_monitoring_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    monitoring_interface_page.hide();
}

/*
 * time: 2022-11-2
 * type: private slots
 * effect: 跳转至输出界面
 * influence: this
*/
void MainWindow::on_pBtn_3_clicked()
{
    QMutexLocker locker(&page_mutex);
    curve_monitoring_page.move(0,0);
    curve_monitoring_page.show();
    current_Page=3;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    curve_monitoring_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    this->hide();
}

/*
 * time: 2022-11-3
 * type: private slots
 * effect: 处理曲线监视的跳转信号
 * influence: this
*/
void MainWindow::deal_curveMonitoring_to_mainWindow(){
    QMutexLocker locker(&page_mutex);
    this->move(0,0);
    this->show();
    current_Page = 0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    curve_monitoring_page.hide();
}

/*
 * time: 2022-11-3
 * type: private slots
 * effect: 处理曲线监视的跳转信号
 * influence: this
*/
void MainWindow::deal_curveMonitoring_to_outputMonitoring(){
    QMutexLocker locker(&page_mutex);
    output_monitoring_page.move(0,0);
    output_monitoring_page.show();
    current_Page = 2;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    output_monitoring_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    curve_monitoring_page.hide();
}

/*
 * time: 2022-11-3
 * type: private slots
 * effect: 处理曲线监视的跳转信号
 * influence: this
*/
void MainWindow::deal_outputMonitoring_to_curveMonitoring(){
    QMutexLocker locker(&page_mutex);
    curve_monitoring_page.move(0,0);
    curve_monitoring_page.show();
    current_Page = 3;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    curve_monitoring_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    output_monitoring_page.hide();
}

/*
 * time: 2022-11-2
 * type: private slots
 * effect: 跳转至程式编辑
 * influence: this
*/
void MainWindow::on_pBtn_4_clicked()
{
    QMutexLocker locker(&page_mutex);
    program_editing_page.move(0,0);
    program_editing_page.show();
    current_Page=4;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    program_editing_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    this->hide();
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 处理程式编辑的跳转信号
 * influence: this
*/
void MainWindow::deal_programEditing_to_mainWindow(){
    QMutexLocker locker(&page_mutex);
    this->move(0,0);
    this->show();
    current_Page = 0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    program_editing_page.hide();
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 跳转至程式循环
 * influence: this
*/
void MainWindow::on_pBtn_5_clicked()
{
    QMutexLocker locker(&page_mutex);
    program_loop_page.move(0,0);
    program_loop_page.show();
    current_Page=5;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    program_loop_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    this->hide();
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 处理程式循环的跳转信号
 * influence: this
*/
void MainWindow::deal_programLoop_to_mainWindow(){
    QMutexLocker locker(&page_mutex);
    this->move(0,0);
    this->show();
    current_Page=0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    program_loop_page.hide();
}

/*
 * time: 2022-11-15
 * type: private slots
 * effect: 处理程式循环的跳转信号
 * influence: this
*/
void MainWindow::deal_programLoop_to_programEditing(){
    QMutexLocker locker(&page_mutex);
    program_editing_page.move(0,0);
    program_editing_page.show();
    current_Page = 4;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    program_editing_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    program_loop_page.hide();
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 跳转至定值设置
 * influence: this
*/
void MainWindow::on_pBtn_6_clicked()
{
    QMutexLocker locker(&page_mutex);
    fixed_value_setting_page.move(0,0);
    fixed_value_setting_page.show();
    current_Page=6;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    fixed_value_setting_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    this->hide();
}

/*
 * time: 2022-11-17
 * type: private slots
 * effect: 处理定值设置的跳转信号
 * influence: this
*/
void MainWindow::deal_fixedValueSetting_to_mainWindow(){
    QMutexLocker locker(&page_mutex);
    this->move(0,0);
    this->show();
    current_Page = 0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    fixed_value_setting_page.hide();
}

/*
 * time: 2022-11-17
 * type: private slots
 * effect: 处理定值设置的跳转信号
 * influence: this
*/
void MainWindow::deal_fixedValueSetting_to_programLoop(){
    QMutexLocker locker(&page_mutex);
    program_loop_page.move(0,0);
    program_loop_page.show();
    current_Page=5;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    program_loop_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    fixed_value_setting_page.hide();
}

/*
 * time: 2022-11-17
 * type: private slots
 * effect: 处理程式循环的跳转信号
 * influence: this
*/
void MainWindow::deal_programLoop_to_fixedValueSetting(){
    QMutexLocker locker(&page_mutex);
    fixed_value_setting_page.move(0,0);
    fixed_value_setting_page.show();
    current_Page = 6;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    fixed_value_setting_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    program_loop_page.hide();
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 跳转至参数设置
 * influence: this
*/
void MainWindow::on_pBtn_7_clicked()
{
    QMutexLocker locker(&page_mutex);
    parameter_setting_page.move(0,0);
    parameter_setting_page.show();
    current_Page=7;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    parameter_setting_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    this->hide();
}

/*
 * time: 2022-11-14
 * type: private slots
 * effect: 跳转至故障记录
 * influence: this
*/
void MainWindow::on_pBtn_8_clicked()
{
    QMutexLocker locker(&page_mutex);
    error_log_page.move(0,0);
    error_log_page.show();
    current_Page=8;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    this->hide();
}

/*
 * time: 2022-11-17
 * type: private slots
 * effect: 处理故障记录的跳转信号
 * influence: this
*/
void MainWindow::deal_errorLog_to_mainWindow(){
    QMutexLocker locker(&page_mutex);
    this->move(0,0);
    this->show();
    current_Page=0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
//    }
    error_log_page.hide();
}

/*
 * time: 2022-11-22
 * type: private slots
 * effect: 主页密码登录
 * influence: this
*/
void MainWindow::on_login_clicked()
{
    keyboard.hide();
    keyboard.move((this->width()-keyboard.width())/2,(this->height()-keyboard.height())/2);
    keyboard.Clean_Keyboard_LineEdit();
    keyboard.Clean_Keyboard_CapsLock();
    keyboard.show();
    current_ID = -1;
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
    //    double number = keyboardStrs.toDouble();
    switch (current_ID) {
    case -1:
    {
        if(keyboardStrs==userPasswordPage01.getCurrentPassword())
        {
            QMutexLocker locker(&page_mutex);
            userPasswordPage01.move(0,0);
            userPasswordPage01.show();
            current_Page = 11;
            if(readData01->isRunning==false)
            {
                readData02->isRunning = false;
                readData01->isRunning = true;
                emit InitDataThread01(current_Page);
            }
            else
            {
                readData01->isRunning = false;
                readData02->isRunning = true;
                emit InitDataThread02(current_Page);
            }
            userPasswordPage01.freezeOneSec();
//            QTime dieTime = QTime::currentTime().addMSecs(100);
//            while(QTime::currentTime()<dieTime){
//                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//            }
            this->hide();
        }
        else
            if(keyboardStrs == internal_param_set_page.getViewPassword())
            {
                QMutexLocker locker(&page_mutex);
                internal_param_set_page.move(0,0);
                internal_param_set_page.show();
                current_Page = 21;
                if(readData01->isRunning==false)
                {
                    readData02->isRunning = false;
                    readData01->isRunning = true;
                    emit InitDataThread01(current_Page);
                }
                else
                {
                    readData01->isRunning = false;
                    readData02->isRunning = true;
                    emit InitDataThread02(current_Page);
                }
                this->hide();
            }
        else{
            popUpWindow07.setChinese("密码错误！");
            popUpWindow07.setEnglish("Password Error!");
            popUpWindow07.centerShow(this->width(),this->height());
        }
        break;
    }
    case 0:
    {
        if(keyboardStrs ==""){
            popUpWindow07.setChinese("输入为空!");
            popUpWindow07.setEnglish("Input Empty!");
            popUpWindow07.centerShow(this->width(),this->height());
        }
        else{
            program_editing_page.inset(keyboardStrs);
            program_editing_page.setProgramName(keyboardStrs);
            program_editing_page.setFocus();
        }
    }
    case 1:
    {
        userPasswordPage01.setPasswordLineEdit(keyboardStrs);
        userPasswordPage01.setFocus();
        break;
    }
    }
}

void MainWindow::deal_CalculateOk(){
    calculateStrs = calculate.get_strs();
    int number = calculateStrs.toInt();
    writeTouchDBData(1, 1,calculate_ID,number,calculateStrs, 1,"null",0,"null","null","null");
    tcpServerTask.sendData(calculate_ID,calculateStrs);
    switch (calculate_ID) {
    case 258:
    {
        if(number >= -1000 && number <= 30000)
        {
            //monitoring_interface_page.setTestTemperatureSV(calculateStrs);
            monitoring_interface_page.setFocus();
        }
        else{
            monitoring_interface_page.setFocus();
        }
        break;
    }
    case 262:
    {
        if(number >= -10000 && number <= 30000)
        {
            //monitoring_interface_page.setHumiditySV(calculateStrs);
            monitoring_interface_page.setFocus();
        }
        else{
            monitoring_interface_page.setFocus();
        }
        break;
    }
    default:
        break;
    }
}


/*
 * time: 2022-11-24
 * type: private slots
 * effect: 处理参数设置的跳转信号
 * influence: this
*/
void MainWindow::deal_parameterSetting_to_mainWindow(){
    QMutexLocker locker(&page_mutex);
    this->move(0,0);
    this->show();
    current_Page = 0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    parameter_setting_page.hide();
}

/*
 * time: 2022-11-24
 * type: private slots
 * effect: 处理参数设置的跳转信号
 * influence: this
*/
void MainWindow::deal_parameterSetting_to_CANSET(){
    QMutexLocker locker(&page_mutex);
    canset_page.move(0,0);
    canset_page.show();
    current_Page = 10;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    canset_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    parameter_setting_page.hide();
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
    QTime dieTime = QTime::currentTime().addMSecs(100);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    calculate.move((this->width()-calculate.width())/2,(this->height()-calculate.height())/2);
    calculate.show();
    printf("calculate key id is %d\n",ID);
    calculate_ID = ID;
}

void MainWindow::deal_ChooseProgramSignals(int ID,QString Name)
{
    monitoring_interface_page.InitProgram(ID,Name);
    output_monitoring_page.InitProgram(ID,Name);
    program_editing_page.InitProgram(ID,Name);
}

void MainWindow::deal_userPasswordPage01_to_mainWindow(){
    QMutexLocker locker(&page_mutex);
    this->show();
    current_Page = 0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    userPasswordPage01.hide();
}

void MainWindow::deal_userPasswordPage01_to_userPasswordPage02()
{
    QMutexLocker locker(&page_mutex);
    userPasswordPage02.show();
    current_Page = 12;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    userPasswordPage02.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    userPasswordPage01.hide();
}

void MainWindow::deal_userPasswordPage02_to_mainWindow()
{
    QMutexLocker locker(&page_mutex);
    this->show();
    current_Page = 0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    userPasswordPage02.hide();
}

void MainWindow::deal_userPasswordPage02_to_userPasswordPage01()
{
    QMutexLocker locker(&page_mutex);
    userPasswordPage01.show();
    current_Page = 11;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    userPasswordPage01.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    userPasswordPage02.hide();
}

void MainWindow::deal_userPasswordPage02_to_userPasswordPage03()
{
    QMutexLocker locker(&page_mutex);
    userPasswordPage03.show();
    current_Page = 13;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    userPasswordPage03.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    userPasswordPage02.hide();
}

void MainWindow::deal_userPasswordPage03_to_mainWindow()
{
    QMutexLocker locker(&page_mutex);
    this->show();
    current_Page = 0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    userPasswordPage03.hide();
}

void MainWindow::deal_userPasswordPage03_to_userPasswordPage02()
{
    QMutexLocker locker(&page_mutex);
    userPasswordPage02.show();
    current_Page = 12;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    userPasswordPage02.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    userPasswordPage03.hide();
}

void MainWindow::deal_canset_to_mainWindow()
{
    QMutexLocker locker(&page_mutex);
    this->show();
    current_Page = 0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    canset_page.hide();
}

void MainWindow::deal_canset_to_parameterSetting()
{
    QMutexLocker locker(&page_mutex);
    parameter_setting_page.show();
    current_Page = 7;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    parameter_setting_page.freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    canset_page.hide();
}

void MainWindow::deal_internalParamSet_to_mainWindow()
{
    QMutexLocker locker(&page_mutex);
    this->show();
    current_Page = 0;
    if(readData01->isRunning==false)
    {
        readData02->isRunning = false;
        readData01->isRunning = true;
        emit InitDataThread01(current_Page);
    }
    else
    {
        readData01->isRunning = false;
        readData02->isRunning = true;
        emit InitDataThread02(current_Page);
    }
    this->freezeOneSec();
//    QTime dieTime = QTime::currentTime().addMSecs(100);
//    while(QTime::currentTime()<dieTime){
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
//    }
    internal_param_set_page.hide();
}
////鼠标按下
//void MainWindow::mousePressEvent(QMouseEvent *event)
//{
//    mOffset =  event->globalPosition().toPoint() - this->pos();
//}

////鼠标移动
//void MainWindow::mouseMoveEvent(QMouseEvent *event)
//{
//    this->move(event->globalPosition().toPoint()-mOffset);
//}

void MainWindow::freezeOneSec()
{
    ui->pBtn_1->setEnabled(false);
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
    ui->pBtn_9->setEnabled(true);
}


void MainWindow::deal_updateInterfaceNumber(int addr,QString strs)
{
    serverTask.sendData(addr,strs);
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
    qDebug() << QString("data_strs: %1").arg(data_strs);
    qDebug() << QString("current_Page:%1").arg(current_Page);
    switch(current_Page)
    {
    case STATE_MONITOR:     monitoring_interface_page.addrSetMonitorInterfaceData(addr_num , data_strs);   break;
    case OUTPUT_MONITOR:    break;
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



void MainWindow::deal_curveData_update(int num, int size, QVector<QVector<double> > xdata, QVector<QVector<double> > data, QString startTime, double *dataInfo, QString *axisInfo, int status)
{
    curve_monitoring_page.draw(num,size,xdata,data,startTime,dataInfo,axisInfo,status);
}
