#include "monitoring_interface.h"
#include "ui_monitoring_interface.h"
#include "sql_generic_data.h"
#include "sqliteoperator.h"
//#include "qtimer.h"

#include<QTimer>
#include<QDateTime>
#include <QDebug>


Monitoring_Interface::Monitoring_Interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Monitoring_Interface)
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
    //Header标题label初始化
    //ui->title->setText(tr("Monitor"));
    //Header时间label初始化
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
    ui->current_time->setStyleSheet("QLabel#current_time{color:white}");
    //设置定时器 每一秒更新一次Header的时间label
    QTimer* timer = new QTimer(this);
    timer->start(1000);

    //显示Temperature_box和Humidity_box
    ui->Humidity_box->setStyleSheet("QWidget#Humidity_box{background-color:white;"
                                    "border-radius:20px;"
                                    "border:1px solid rgb(127,127,127)}");
    ui->Temperature_box->setStyleSheet("QWidget#Temperature_box{background-color:white;"
                                       "border-radius:20px;"
                                       "border:1px solid rgb(127,127,127)}");
    //temperature PV部分
    ui->temperature_company_pv->setStyleSheet("QLabel#temperature_company_pv{color:rgb(255,201,14)}");
    ui->temperature_edit_pv->setStyleSheet("QLineEdit#temperature_edit_pv{color:red;border:none;background:transparent}");
    ui->temperature_edit_pv->setInputMask("xxxxxx");
    ui->temperature_edit_pv->setText(test_temperature_pv);
    //temperature SV部分
    ui->temperature_edit_sv->setStyleSheet("QLineEdit#temperature_edit_sv{border:none;background:transparent}");
    ui->temperature_edit_sv->setInputMask("xxxxxx");
    ui->temperature_edit_sv->setText(test_temperature_sv);
    //temperature 百分比部分
    ui->temperature_image->setStyleSheet("QLabel#temperature_image{background-image:url(:/Image/icon/temperature.png)}");
    ui->temperature_edit_percent->setStyleSheet("QLineEdit#temperature_edit_percent{border:none;background:transparent}");
    ui->temperature_edit_percent->setInputMask("xxxxxx");
    ui->temperature_edit_percent->setText(test_temperature_heat_percent);
    //humidity PV部分
    ui->humidity_company_pv->setStyleSheet("QLabel#humidity_company_pv{color:rgb(255,201,14)}");
    ui->humidity_edit_pv->setStyleSheet("QLineEdit#humidity_edit_pv{color:blue;border:none;background:transparent}");
    ui->humidity_edit_pv->setInputMask("xxxxxx");
    ui->humidity_edit_pv->setText(humidity_pv);
    //humidity SV部分
    ui->humidity_edit_sv->setStyleSheet("QLineEdit#humidity_edit_sv{border:none;background:transparent}");
    ui->humidity_edit_sv->setInputMask("xxxxxx");
    ui->humidity_edit_sv->setText(humidity_sv);
    //humidity 百分比部分
    ui->humidity_image->setStyleSheet("QLabel#humidity_image{background-image:url(:/Image/icon/humidity.png)}");
    ui->humidity_edit_percent->setStyleSheet("QLineEdit#humidity_edit_percent{border:none;background:transparent}");
    ui->humidity_edit_percent->setInputMask("xxxxxx");
    ui->humidity_edit_percent->setText(humidity_heat_percent);
    //temperature_check_icon
    //ui->temperature_check_icon->setStyleSheet("QLabel#temperature_check_icon{background-image:url(:/Image/24/42.bmp)}");

    //添加事件过滤器 处理焦点和光标
    ui->temperature_edit_pv->installEventFilter(this);
    ui->temperature_edit_sv->installEventFilter(this);
    ui->temperature_company_percent->installEventFilter(this);
    ui->humidity_edit_pv->installEventFilter(this);
    ui->humidity_edit_sv->installEventFilter(this);
    ui->humidity_edit_percent->installEventFilter(this);
    this->installEventFilter(this);

    //显示Program_box
    ui->Program_box->setStyleSheet("QWidget#Program_box{background-color:white;"
                                   "border: 1px solid rgb(127,127,127);"
                                   "border-radius:20px}");
    //progrem_name部分
    ui->program_name_edit->setStyleSheet("QLineEdit#program_name_edit{background:transparent;border:none}");
    ui->program_name_edit->setText(run_program_name);
    //program_time部分
    ui->program_time_edit->setStyleSheet("QLineEdit#program_time_edit{background:transparent;border:none}");
    ui->program_time_edit->setInputMask("xxxx:xx:xx/xxxx:xx:xx");
    ui->program_time_edit->setText(program_time);
    //period_time部分
    ui->period_time_edit->setStyleSheet("QLineEdit#period_time_edit{background:transparent;border:none}");
    ui->period_time_edit->setInputMask("xxxx:xx:xx/xxxx:xx:xx");
    ui->period_time_edit->setText(segment_time);
    //estimate_time 部分
    ui->estimate_time_edit->setStyleSheet("QLineEdit#estimate_time_edit{background:transparent;border:none}");
    ui->estimate_time_edit->setInputMask("xxxx-xx-xx xx:xx:xx");
    ui->estimate_time_edit->setText(estimate_end_time);
    //program_cycle部分
    ui->program_cycle_edit->setStyleSheet("QLineEdit#program_cycle_edit{background:transparent;border:none}");
    ui->program_cycle_edit->setInputMask("xxxx/xxxx");
    ui->program_cycle_edit->setText(program_cycle);
    //program_run_period部分
    ui->program_run_period_edit->setStyleSheet("QLineEdit#program_run_period_edit{background:transparent;border:none}");
    ui->program_run_period_edit->setInputMask("xxx");
    ui->program_run_period_edit->setText(program_run_segment);
    //program_link部分
    ui->program_link_edit->setStyleSheet("QLineEdit#program_link_edit{background:transparent;border:none}");
    ui->program_link_edit->setInputMask("xxx/xxx");
    ui->program_link_edit->setText(program_link);
    //run_gif部分
    ui->run_gif->setStyleSheet("QLabel#run_gif{background-image:url(:/Image/24/10.bmp)}");
//    QTimer* gifTimer = new QTimer(this);
//    gifTimer->start(500);


    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->LED_pbtn->setStyleSheet("QPushButton#LED_pbtn{border:2px solid rgb(74,122,60);"
                                "background-color:rgb(173,199,160);"
                                "border-radius:8px;"
                                "color:rgb(74,122,60)}");
    ui->reset_pbth->setStyleSheet("QPushButton#reset_pbth{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");
    ui->constant_value_running_pbtn->setStyleSheet("QPushButton#constant_value_running_pbtn{border:2px solid rgb(74,122,60);"
                                                   "background-color:rgb(173,199,160);"
                                                   "border-radius:8px;"
                                                   "color:rgb(74,122,60)}");
    ui->next_page_pbtn->setStyleSheet("QPushButton#next_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");

    //运行 加载
    ui->running_pBtn->setStyleSheet("QPushButton#running_pBtn{background-color:rgb(72,129,52);"
                                    "color:white;"
                                    "border:none;"
                                    "border-radius:10px}");
    ui->loading_pBtn->setStyleSheet("QPushButton#loading_pBtn{background-color:rgb(238,117,0);"
                                    "color:white;"
                                    "border:none;"
                                    "border-radius:10px}");

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


    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&Monitoring_Interface::currentTime);
    connect(timer,&QTimer::timeout,this,&Monitoring_Interface::start_run_gif);
    //跳转至目录 发送信号
    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&Monitoring_Interface::monitoring_interface_sendTo_mainwindow);
    connect(ui->next_page_pbtn,&QPushButton::clicked,this,&Monitoring_Interface::monitoringInterface_sendTo_outputMonitoring);
    connect(ui->LED_pbtn,&QPushButton::clicked,this,&Monitoring_Interface::LED_pBtn_clicked);
    connect(ui->running_pBtn,&QPushButton::clicked,this,&Monitoring_Interface::running_pBtn_clicked);
    connect(ui->loading_pBtn,&QPushButton::clicked,this,&Monitoring_Interface::loading_pBtn_clicked);

    //弹窗
    connect(&popUpWindow01,&PopUpWindow01::popWindow01PushButtonOKClickedSignal,this,&Monitoring_Interface::deal_popUpWindow01PushButtonOKClickedSignal);
    connect(&popUpWindow02,&PopUpWindow02::popWindow02PushButtonOKClickedSignal,this,&Monitoring_Interface::deal_popUpWindow02PushButtonOKClickedSignal);
    connect(&popUpWindow03,&PopUpWindow03::popWindow03PushButtonYESClickedSignal,this,&Monitoring_Interface::deal_popUpWindow03PushButtonYESClickedSignal);
    connect(&popUpWindow04,&PopUpWindow04::popUpWindow04WithoutDataSignals,this,&Monitoring_Interface::deal_popUpWindow04WithoutDataSignals);

    //数据处理
    connect(&popUpWindow04,&PopUpWindow04::popUpWindow04ButtonClickedSignals,this,&Monitoring_Interface::deal_popUpWindow04PushButtonClickedSignals);


}


Monitoring_Interface::~Monitoring_Interface()
{
    delete ui;
}

/*
 * time: 2022-10-24
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void Monitoring_Interface::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

/*
 * time: 2022-10-28
 * type: System EventFilter
 * effect: 事件过滤器
 * influence: this
*/
bool Monitoring_Interface::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(ui->temperature_edit_pv->hasFocus()){
                ui->temperature_edit_pv->clearFocus();//如果点击屏幕任意位置则取消对应lineEdit的聚焦
            }
            else if(ui->temperature_edit_sv->hasFocus()){
                ui->temperature_edit_sv->clearFocus();
            }
            else if(ui->temperature_edit_percent->hasFocus()){
                ui->temperature_edit_percent->clearFocus();
            }
            else if(ui->humidity_edit_pv->hasFocus()){
                ui->humidity_edit_pv->clearFocus();
            }
            else if(ui->humidity_edit_sv->hasFocus()){
                ui->humidity_edit_sv->clearFocus();
            }
            else if(ui->humidity_edit_percent->hasFocus()){
                ui->humidity_edit_percent->clearFocus();
            }
        }
    }

    //监听lineEdit


    if(watched == ui->temperature_edit_sv)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(258);
            ui->temperature_edit_sv->setFocus();
        }
    }
    else if(watched == ui->humidity_edit_sv)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(262);
            ui->humidity_edit_sv->setFocus();
        }
    }
    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取温度PV
 * influence: QString test_temperature_pv
*/
QString Monitoring_Interface::getTestTemperaturePV(){
   return test_temperature_pv;
}
/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置温度PV
 * influence: QString test_temperature_pv
*/
void Monitoring_Interface::setTestTemperaturePV(QString strs){
    this->test_temperature_pv = strs;
    ui->temperature_edit_pv->setText(test_temperature_pv);
}
/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取温度SV
 * influence: QString temperature_sv
*/
QString Monitoring_Interface::getTestTemperatureSV(){
    return test_temperature_sv;
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取温度百分比
 * influence: QString test_temperature_heat_percent
*/
QString Monitoring_Interface::getTestTemperaturePercent(){
    return test_temperature_heat_percent;
}



/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置温度SV
 * influence: QString temperature_sv
*/
void Monitoring_Interface::setTestTemperatureSV(QString strs){
    this->test_temperature_sv = strs;
    ui->temperature_edit_sv->setText(strs);
}

/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置温度百分比
 * influence: QString temperature_percent
*/
void Monitoring_Interface::setTestTemperaturePercent(QString strs){
    this->test_temperature_heat_percent = strs;
    ui->temperature_edit_percent->setText(test_temperature_heat_percent);
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取湿度PV
 * influence: QString humidity_pv
*/
QString Monitoring_Interface::getHumidityPV(){
    return humidity_pv;
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取湿度SV
 * influence: QString humidity_sv
*/
QString Monitoring_Interface::getHumiditySV(){
    return humidity_sv;
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取湿度百分比
 * influence: QString humidity_percent
*/
QString Monitoring_Interface::getHumidityPercent(){
    return humidity_heat_percent;
}

/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置湿度PV
 * influence: QString humidity_pv
*/
void Monitoring_Interface::setHumidityPV(QString strs){
    this->humidity_pv = strs;
    ui->humidity_edit_pv->setText(humidity_pv);
}

/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置湿度SV
 * influence: QString humidity_sv
*/
void Monitoring_Interface::setHumiditySV(QString strs){
    this->humidity_sv = strs;
    ui->humidity_edit_sv->setText(humidity_sv);
}

/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置湿度百分比
 * influence: QString humidity_percent
*/
void Monitoring_Interface::setHumidityPercent(QString strs){
    this->humidity_heat_percent = strs;
    ui->humidity_edit_percent->setText(humidity_heat_percent);
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取程式名称
 * influence: QString run_program_name
*/
QString Monitoring_Interface::getProgramName(){
    return run_program_name;
}

/*
 * time: 2022-10-28
 * type: Set
 * effect: 设定程式名称
 * influence: QString run_program_name
*/
void Monitoring_Interface::setProgramName(QString strs){
    this->run_program_name = strs;
    ui->program_name_edit->setText(run_program_name);
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取程式时间
 * influence: QString program_time
*/
QString Monitoring_Interface::getProgramTime(){
    return program_time;
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取段时间
 * influence: QString period_time
*/
QString Monitoring_Interface::getSegmentTime(){
    return segment_time;
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取预完成时间
 * influence: QString estimate_time
*/
QString Monitoring_Interface::getEstimateTime(){
    return estimate_end_time;
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取循环
 * influence: QString program_cycle
*/
QString Monitoring_Interface::getProgramCycle(){
    return program_cycle;
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取运行段
 * influence: QString program_run_period
*/
QString Monitoring_Interface::getProgramRunSegment(){
    return program_run_segment;
}

/*
 * time: 2022-10-28
 * type: Get
 * effect: 获取链接
 * influence: QString program_link
*/
QString Monitoring_Interface::getProgramLink(){
    return program_link;
}

/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置段时间
 * influence: QString period_time
*/
void Monitoring_Interface::setSegmentTime(QString A,QString B){
    this->segment_run_time = A;
    this->segment_free_time = B;
    ui->period_time_edit->setText(segment_time);
}
void Monitoring_Interface::setSegmentRunTime(QString A){
    this->segment_run_time = A;
    ui->period_time_edit->setText(segment_run_time);
}
void Monitoring_Interface::setSegmentFreeTime(QString B){
    this->segment_free_time = B;
    ui->period_time_edit->setText(segment_free_time);
}
/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置程序时间
 * influence: QString program_time
*/
void Monitoring_Interface::setProgramTime(QString A,QString B){
    this->program_run_time = A;
    this->program_free_time = B;
    ui->program_time_edit->setText(program_time);
}
void Monitoring_Interface::setProgramRunTime(QString A){
    this->program_run_time = A;
    ui->program_time_edit->setText(program_run_time);
}
void Monitoring_Interface::setProgramFreeTime(QString B){
    this->program_free_time = B;
    ui->program_time_edit->setText(program_free_time);
}

/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置预完成时间
 * influence: QString estimate_time
*/
void Monitoring_Interface::setEstimateEndTime(QString strs){
    this->estimate_end_time = strs;
    ui->estimate_time_edit->setText(estimate_end_time);
}

/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置循环
 * influence: QString program_cycle
*/
void Monitoring_Interface::setProgramCycle(QString strs){
    this->program_cycle = strs;
    ui->program_cycle_edit->setText(program_cycle);
}

/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置运行段
 * influence: QString program_run_period
*/
void Monitoring_Interface::setProgramRunSegment(QString strs){
    this->program_run_segment = strs;
    ui->program_run_period_edit->setText(program_run_segment);
}

/*
 * time: 2022-10-28
 * type: Set
 * effect: 设置链接
 * influence: QString program_link
*/
void Monitoring_Interface::setProgramLink(QString strs){
    this->program_link = strs;
    ui->program_link_edit->setText(program_link);
}

/*
 * time: 2022-10-31
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Monitoring_Interface::monitoring_interface_sendTo_mainwindow(){
    emit monitoring_interface_to_mainwindow();
}

/*
 * time: 2022-10-31
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Monitoring_Interface::monitoringInterface_sendTo_outputMonitoring(){
    emit monitoringInterface_to_outputMonitoring();
}

/*
 * time: 2022-10-31
 * type: send Signals
 * effect: 信号发送函数 照明按钮被按下
 * influence: this
*/
void Monitoring_Interface::LED_pBtn_clicked(){
    emit LED_pBtn_clickedSignals();
    isLEDChecked = !isLEDChecked;
    if(isLEDChecked==true){
        ui->LED_pbtn->setStyleSheet("QPushButton#LED_pbtn{border:2px solid rgb(74,122,60);"
                                    "background-color:rgb(74,122,60);"
                                    "border-radius:8px;"
                                    "color:rgb(173,199,160)}");
    }
    else{
        ui->LED_pbtn->setStyleSheet("QPushButton#LED_pbtn{border:2px solid rgb(74,122,60);"
                                    "background-color:rgb(173,199,160);"
                                    "border-radius:8px;"
                                    "color:rgb(74,122,60)}");
    }
}

void Monitoring_Interface::running_pBtn_clicked(){
    emit running_pBtn_clickedSignals();
    if(isRunning==false){
        popUpWindow01.move((this->width()-popUpWindow01.width())/2,(this->height()-popUpWindow01.height())/2);
        popUpWindow01.show();
    }
    else
    {
        popUpWindow03.move((this->width()-popUpWindow03.width())/2,(this->height()-popUpWindow03.height())/2);
        popUpWindow03.show();
    }
}

void Monitoring_Interface::loading_pBtn_clicked(){
    emit loading_pBtn_clickedSignals();
    popUpWindow04.move(0,0);
    popUpWindow04.setStatus(0);
    popUpWindow04.show();
}

void Monitoring_Interface::start_run_gif(){
    if(isStart==true){
        QString URL = ":/Image/24/"+QString::number(run_gif_currentBmp)+".bmp";
        ui->run_gif->setStyleSheet("QLabel#run_gif{background-image:url("+URL+")}");
        if(run_gif_currentBmp==13)
            run_gif_currentBmp = 11;
        else
            run_gif_currentBmp++;
    }
    else
        ui->run_gif->setStyleSheet("QLabel#run_gif{background-image:url(:/Image/24/10.bmp)}");
}

void Monitoring_Interface::deal_popUpWindow01PushButtonOKClickedSignal(){
    popUpWindow01.close();
    popUpWindow02.move((this->width()-popUpWindow02.width())/2,(this->height()-popUpWindow02.height())/2);
    popUpWindow02.show();
}

void Monitoring_Interface::deal_popUpWindow02PushButtonOKClickedSignal(){
    popUpWindow02.close();
    ui->running_pBtn->setStyleSheet("QPushButton#running_pBtn{background-color:red;"
                                    "color:black;"
                                    "border:none;"
                                    "border-radius:10px}");
    ui->running_pBtn->setText(tr("停  止"));
    isRunning = true;
    isStart = true;
}

void Monitoring_Interface::deal_popUpWindow03PushButtonYESClickedSignal(){
    popUpWindow03.close();
    isRunning=false;
    ui->running_pBtn->setStyleSheet("QPushButton#running_pBtn{background-color:rgb(72,129,52);"
                                    "color:white;"
                                    "border:none;"
                                    "border-radius:10px}");
    ui->running_pBtn->setText(tr("运  行"));
    isStart = false;
}

void Monitoring_Interface::deal_popUpWindow04WithoutDataSignals(int WIDTH,int HEIGHT){
    popUpWindow05.centerShow(WIDTH,HEIGHT);
}

void Monitoring_Interface::InitProgram(int ID,QString Name)
{
    printf("—————Monitoring_Interface———————InitProgram——————%d/n",ID);

    ui->program_name_edit->setText(Name);
}

/*
 *转发给父页面MainWindow以影响其他页面
 */
void Monitoring_Interface::deal_popUpWindow04PushButtonClickedSignals(int ID,QString Name)
{
    emit monitoring_interface_choose_program(ID,Name);
}

void Monitoring_Interface::freezeOneSec()
{
    ui->font_page_pbtn->setEnabled(false);
    ui->next_page_pbtn->setEnabled(false);
    ui->LED_pbtn->setEnabled(false);
    ui->loading_pBtn->setEnabled(false);
    ui->constant_value_running_pbtn->setEnabled(false);
    ui->running_pBtn->setEnabled(false);
    ui->reset_pbth->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    dieTime = dieTime;
   // while(QTime::currentTime()<dieTime){  //此处会引发死循环，从而宕机
     //   QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
   // }
    ui->font_page_pbtn->setEnabled(true);
    ui->next_page_pbtn->setEnabled(true);
    ui->LED_pbtn->setEnabled(true);
    ui->loading_pBtn->setEnabled(true);
    ui->constant_value_running_pbtn->setEnabled(true);
    ui->running_pBtn->setEnabled(true);
    ui->reset_pbth->setEnabled(true);
}

void Monitoring_Interface::idSetMonitorInterfaceData(int id_num, QString data_string){
    id_num = id_num;
    data_string = data_string;
    QVector<lcd_show_data_f> lcd_show_data;
    readComDBData(lcd_show_data);
    //qDebug()<<"lcd_show_data :"<<lcd_show_data[101].str;
    if (id_test_temperature_pv < lcd_show_data.size())
    {
        test_temperature_pv = lcd_show_data[id_test_temperature_pv].str;
        ui->temperature_edit_pv->setText(test_temperature_pv);
    }
    if (id_test_temperature_sv < lcd_show_data.size())
    {
        test_temperature_sv = lcd_show_data[id_test_temperature_sv].str;
        ui->temperature_edit_sv->setText(test_temperature_sv);
    }
    if (id_humidity_pv < lcd_show_data.size())
    {
        humidity_pv = lcd_show_data[id_humidity_pv].str;
        ui->humidity_edit_pv->setText((humidity_pv));
    }
    if (id_humidity_sv < lcd_show_data.size())
    {
        humidity_sv = lcd_show_data[id_humidity_sv].str;
        ui->humidity_edit_sv->setText((humidity_sv));
    }
    if (id_test_temperature_heat_percent < lcd_show_data.size())
    {
        test_temperature_heat_percent = lcd_show_data[id_test_temperature_heat_percent].str;
        ui->temperature_edit_percent->setText(test_temperature_heat_percent);
    }
    if (id_humidity_heat_percent < lcd_show_data.size())
    {
        humidity_heat_percent = lcd_show_data[id_humidity_heat_percent].str;
        ui->humidity_edit_percent->setText(humidity_heat_percent);
    }
    if (id_run_program_name < lcd_show_data.size())
    {
        run_program_name = lcd_show_data[id_run_program_name].str;
        ui->program_name_edit->setText(run_program_name);
    }
    if (id_program_time < lcd_show_data.size())
    {
        program_time = lcd_show_data[id_program_time].str;
        ui->program_time_edit->setText(program_time);
    }
    if (id_segment_time < lcd_show_data.size())
    {
        segment_time = lcd_show_data[id_segment_time].str;
        ui->period_time_edit->setText(segment_time);
    }
    if (id_estimate_end_time < lcd_show_data.size())
    {
        estimate_end_time = lcd_show_data[id_estimate_end_time].str;
        ui->estimate_time_edit->setText(estimate_end_time);
    }
    if (id_program_cycle < lcd_show_data.size())
    {
        program_cycle = lcd_show_data[id_program_cycle].str;
        ui->program_cycle_edit->setText(program_cycle);
    }
    if (id_program_run_segment < lcd_show_data.size())
    {
        program_run_segment = lcd_show_data[id_program_run_segment].str;
        ui->program_run_period_label->setText(program_run_segment);
    }
    if (id_program_link < lcd_show_data.size())
    {
        program_link = lcd_show_data[id_program_link].str;
        ui->program_link_edit->setText(program_link);
    }
}

void Monitoring_Interface::addrSetMonitorInterfaceData(int addr_num, QString pv_or_sv){


    qDebug() << QString("addrSetMonitorInterfaceData addr_num: %1").arg(addr_num);

    if (addr_test_temperature_pv == addr_num)
    {
         qDebug() << QString("pv_or_sv: %1").arg(pv_or_sv);
        test_temperature_pv = pv_or_sv;
        ui->temperature_edit_pv->setText(test_temperature_pv);
    }
    if (addr_test_temperature_sv == addr_num)
    {
        test_temperature_sv = pv_or_sv;
        ui->temperature_edit_sv->setText(test_temperature_sv);
    }
    if (addr_humidity_pv == addr_num)
    {
        humidity_pv = pv_or_sv;
        ui->humidity_edit_pv->setText((humidity_pv));
    }
    if (addr_humidity_sv == addr_num)
    {
        humidity_sv = pv_or_sv;
        ui->humidity_edit_sv->setText((humidity_sv));
    }
    if (addr_test_temperature_heat_percent == addr_num)
    {
        test_temperature_heat_percent = pv_or_sv;
        ui->temperature_edit_percent->setText(test_temperature_heat_percent);
    }
    if (addr_humidity_heat_percent == addr_num)
    {
        humidity_heat_percent = pv_or_sv;
        ui->humidity_edit_percent->setText(humidity_heat_percent);
    }
    if (addr_run_program_name == addr_num)
    {
        run_program_name = pv_or_sv;
        ui->program_name_edit->setText(run_program_name);
    }
    if (addr_program_time == addr_num)
    {
        program_time = pv_or_sv;
        ui->program_time_edit->setText(program_time);
    }
    if (addr_segment_time == addr_num)
    {
        segment_time = pv_or_sv;
        ui->period_time_edit->setText(segment_time);
    }
    if (addr_estimate_end_time == addr_num)
    {
        estimate_end_time = pv_or_sv;
        ui->estimate_time_edit->setText(estimate_end_time);
    }
    if (addr_program_cycle == addr_num)
    {
        program_cycle = pv_or_sv;
        ui->program_cycle_edit->setText(program_cycle);
    }
    if (addr_program_run_segment == addr_num)
    {
        program_run_segment = pv_or_sv;
        ui->program_run_period_label->setText(program_run_segment);
    }
    if (addr_program_link == addr_num)
    {
        program_link = pv_or_sv;
        ui->program_link_edit->setText(program_link);
    }
}