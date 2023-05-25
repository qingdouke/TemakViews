#include "curve_monitoring.h"
#include "ui_curve_monitoring.h"

#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDebug>

Curve_Monitoring::Curve_Monitoring(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Curve_Monitoring)
{
    ui->setupUi(this);

    this->setGeometry(0,0,1280,800);
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

    //使用qss
    QFile file(":/qss/Temperature_PV_box.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

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

    //Temperature_PV_box
    ui->Temperature_PV_box->setStyleSheet("QWidget#Temperature_PV_box{background-color:white;"
                                          "border:1px solid rgb(192,192,192)}");
    ui->temperature_pv_checkbox->setStyleSheet("QCheckBox#temperature_pv_checkbox{border-radius:2px;"
                                               "background:transparent}");
    ui->temperature_pv_label->setStyleSheet("QLabel#temperature_pv_label{background-color:rgb(203,153,204)}");
    ui->temperature_pv_lineEdit->setStyleSheet("QLineEdit#temperature_pv_lineEdit{background:transparent;"
                                               "border:none}");
    ui->temperature_pv_company_label->setStyleSheet("QLabel#temperature_pv_company_label{color:rgb(203,153,204)}");

    //Temperature_SV_box
    ui->Temperature_SV_box->setStyleSheet("QWidget#Temperature_SV_box{background-color:white;"
                                          "border:1px solid rgb(192,192,192)}");
    ui->temperature_sv_checkbox->setStyleSheet("QCheckBox#temperature_sv_checkbox{border-radius:2px;"
                                               "background:transparent}");
    ui->temperature_sv_label->setStyleSheet("QLabel#temperature_sv_label{background-color:rgb(253,154,52)}");
    ui->temperature_sv_lineEdit->setStyleSheet("QLineEdit#temperature_sv_lineEdit{background:transparent;"
                                               "border:none}");
    ui->temperature_sv_company_label->setStyleSheet("QLabel#temperature_sv_company_label{color:rgb(253,154,52)}");

    //Humidity_PV_box
    ui->Humidity_PV_box->setStyleSheet("QWidget#Humidity_PV_box{background-color:white;"
                                       "border:1px solid rgb(192,192,192)}");
    ui->humidity_pv_checkbox->setStyleSheet("QCheckBox#humidity_pv_checkbox{border-radius:2px;"
                                            "background:transparent}");
    ui->humidity_pv_label->setStyleSheet("QLabel#humidity_pv_label{background-color:rgb(107,149,255)}");
    ui->humidity_pv_lineEdit->setStyleSheet("QLineEdit#humidity_pv_lineEdit{background:transparent;"
                                            "border:none}");
    ui->humidity_pv_company_label->setStyleSheet("QLabel#humidity_pv_company_label{color:rgb(107,149,255)}");

    //Humidity_SV_box
    ui->Humidity_SV_box->setStyleSheet("QWidget#Humidity_SV_box{background-color:white;"
                                       "border:1px solid rgb(192,192,192)}");
    ui->humidity_sv_checkbox->setStyleSheet("QCheckBox#humidity_sv_checkbox{border-radius:2px;"
                                            "background:transparent}");
    ui->humidity_sv_label->setStyleSheet("QLabel#humidity_sv_label{background-color:rgb(153,204,101)}");
    ui->humidity_sv_lineEdit->setStyleSheet("QLineEdit#humidity_sv_lineEdit{background:transparent;"
                                            "border:none}");
    ui->humidity_sv_company_label->setStyleSheet("QLabel#humidity_sv_company_label{color:rgb(153,204,101)}");

    //pushButton 0~7
    ui->pushButton_0->setStyleSheet("QPushButton#pushButton_0{background-color:rgb(72,129,52);"
                                    "border:none;"
                                    "background-image:url(:/Image/icon/pushButton_0.png);"
                                    "background-repeat:no-repeat;"
                                    "background-position:center}");
    ui->pushButton_1->setStyleSheet("QPushButton#pushButton_1{background-color:rgb(72,129,52);"
                                    "border:none;"
                                    "background-image:url(:/Image/icon/pushButton_1.png);"
                                    "background-repeat:no-repeat;"
                                    "background-position:center}");
    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{background-color:rgb(72,129,52);"
                                    "border:none;"
                                    "background-image:url(:/Image/icon/pushButton_2.png);"
                                    "background-repeat:no-repeat;"
                                    "background-position:center}");
    ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{background-color:rgb(72,129,52);"
                                    "border:none;"
                                    "background-image:url(:/Image/icon/pushButton_3.png);"
                                    "background-repeat:no-repeat;"
                                    "background-position:center}");
    ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4{background-color:rgb(72,129,52);"
                                    "border:none;"
                                    "background-image:url(:/Image/icon/pushButton_4.png);"
                                    "background-repeat:no-repeat;"
                                    "background-position:center}");
    ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5{background-color:rgb(72,129,52);"
                                    "border:none;"
                                    "background-image:url(:/Image/icon/pushButton_5.png);"
                                    "background-repeat:no-repeat;"
                                    "background-position:center}");
    ui->pushButton_6->setStyleSheet("QPushButton#pushButton_6{background-color:rgb(72,129,52);"
                                    "border:none;"
                                    "background-image:url(:/Image/icon/pushButton_6.png);"
                                    "background-repeat:no-repeat;"
                                    "background-position:center}");
    ui->pushButton_7->setStyleSheet("QPushButton#pushButton_7{background-color:rgb(72,129,52);"
                                    "border:none;"
                                    "background-image:url(:/Image/icon/pushButton_7.png);"
                                    "background-repeat:no-repeat;"
                                    "background-position:center}");

    //存储频率、存储空间、光标时间
    ui->storage_frequency_line->setStyleSheet("QLabel#storage_frequency_line{background-color:rgb(72,129,52)}");
    ui->storage_frequency_lineEdit->setStyleSheet("QLineEdit#storage_frequency_lineEdit{border:none;"
                                                  "background:transparent}");
    ui->storage_frequency_lineEdit->setText(storage_frequency+"s");
    ui->storage_frequency_pushButton->setStyleSheet("QPushButton#storage_frequency_pushButton{background-color:transparent;"
                                                    "border:none}");
    ui->storage_spacing_line->setStyleSheet("QLabel#storage_spacing_line{background-color:rgb(72,129,52)}");
    ui->storage_spacing_lineEdit->setStyleSheet("QLineEdit#storage_spacing_lineEdit{border:none;"
                                                "background:transparent}");
    ui->storage_spacing_lineEdit->setText(storage_spacing+"%");
    ui->cursor_time_line->setStyleSheet("QLabel#cursor_time_line{background-color:rgb(72,129,52)}");
    ui->cursor_time_lineEdit->setStyleSheet("QLineEdit#cursor_time_lineEdit{border:none;"
                                            "background:transparent}");
    ui->cursor_time_lineEdit->setText(cursor_time);

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->previous_page_pbth->setStyleSheet("QPushButton#previous_page_pbth{border:2px solid rgb(74,122,60);"
                                          "background-color:rgb(173,199,160);"
                                          "border-radius:8px;"
                                          "color:rgb(74,122,60)}");
    ui->saving_pbtn->setStyleSheet("QPushButton#saving_pbtn{border:2px solid rgb(74,122,60);"
                                   "background-color:rgb(173,199,160);"
                                   "border-radius:8px;"
                                   "color:rgb(74,122,60)}");
    ui->real_time_pbtn->setStyleSheet("QPushButton#real_time_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");

    //QCustomPlot
    ui->CurveWidget->yAxis2->setVisible(true);
    ui->CurveWidget->setBackground(QBrush(Qt::black));
    ui->CurveWidget->axisRect()->setBackground(QBrush(Qt::black));
    ui->CurveWidget->xAxis->setBasePen(QPen(Qt::white,1));
    ui->CurveWidget->yAxis->setBasePen(QPen(Qt::white,1));
    ui->CurveWidget->yAxis2->setBasePen(QPen(Qt::white,1));
    ui->CurveWidget->xAxis->grid()->setPen(QPen(QColor(180,180,180),1,Qt::PenStyle::DashLine));
    ui->CurveWidget->yAxis->grid()->setPen(QPen(QColor(180,180,180),1,Qt::PenStyle::DashLine));
    ui->CurveWidget->yAxis2->grid()->setPen(QPen(QColor(180,180,180),1,Qt::PenStyle::DashLine));
    ui->CurveWidget->xAxis->grid()->setSubGridVisible(false);
    ui->CurveWidget->yAxis->grid()->setSubGridVisible(false);
    ui->CurveWidget->yAxis2->grid()->setSubGridVisible(false);
    QPen xM;
    xM.setColor(Qt::white);
    xM.setWidth(1);
    ui->CurveWidget->xAxis->setTickPen(xM);
    ui->CurveWidget->yAxis->setTickPen(xM);
    ui->CurveWidget->yAxis2->setTickPen(xM);
    QPen xS;
    xS.setColor(Qt::white);
    ui->CurveWidget->xAxis->setSubTickPen(xS);
    ui->CurveWidget->yAxis->setSubTickPen(xS);
    ui->CurveWidget->yAxis2->setSubTickPen(xS);
    QFont xFont;
    xFont.setPixelSize(14);
    ui->CurveWidget->xAxis->setLabelColor(Qt::white);
    ui->CurveWidget->yAxis->setLabelColor(Qt::white);
    ui->CurveWidget->yAxis2->setLabelColor(Qt::white);
    ui->CurveWidget->xAxis->setLabelFont(xFont);
    ui->CurveWidget->yAxis->setLabelFont(xFont);
    ui->CurveWidget->yAxis2->setLabelFont(xFont);
    ui->CurveWidget->xAxis->setTickLabelColor(Qt::white);
    ui->CurveWidget->yAxis->setTickLabelColor(Qt::white);
    ui->CurveWidget->yAxis2->setTickLabelColor(Qt::white);
    ui->CurveWidget->xAxis->setTickLabelFont(xFont);
    ui->CurveWidget->yAxis->setTickLabelFont(xFont);
    ui->CurveWidget->yAxis2->setTickLabelFont(xFont);
    ui->CurveWidget->xAxis->setRange(0,100);
    ui->CurveWidget->xAxis->ticker()->setTickCount(11);
    //    ui->CurveWidget->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
    ui->CurveWidget->yAxis->setRange(-75,175);
    ui->CurveWidget->yAxis->ticker()->setTickCount(11);
    ui->CurveWidget->yAxis2->setRange(0,100);
    ui->CurveWidget->yAxis2->ticker()->setTickCount(11);

    //测试曲线
    num = 12;
    size = 1000;
    xdata.resize(num);
    data.resize(num);
    for(int i=0 ; i<num ; i++)
    {
        xdata[i].resize(size);
        data[i].resize(size);
    }
    startTime = "2023-3-28 08:42:44";
    dataInfoSize = num*2+3;
    dataInfo = new double[dataInfoSize];
    dataInfo[0] = 0.01;
    dataInfo[1] = 0;
    dataInfo[2] = 10;
    dataInfo[3] = -1;
    dataInfo[4] = 1;
    dataInfo[5] = -5;
    dataInfo[6] = 5;
    axisInfo = new QString[num];
    axisInfo[0] = "Temperature(°C)";
    axisInfo[1] = "Humidity(%)";
    status=1;
    endSize = size;
    for(int i=0 ; i<endSize ; i++)
    {
        xdata[0][i] = i*1.0/100*1.0;
        xdata[1][i] = i*1.0/100*1.0;
        xdata[2][i] = i*1.0/100*1.0;
        xdata[3][i] = i*1.0/100*1.0;
        xdata[4][i] = i*1.0/100*1.0;
        xdata[5][i] = i*1.0/100*1.0;
        xdata[6][i] = i*1.0/100*1.0;
        xdata[7][i] = i*1.0/100*1.0;
        xdata[8][i] = i*1.0/100*1.0;
        xdata[9][i] = i*1.0/100*1.0;
        xdata[10][i] = i*1.0/100*1.0;
        xdata[11][i] = i*1.0/100*1.0;
        data[0][i] = sin(i*1.0/100*1.0);
        data[1][i] = cos(i*1.0/100*1.0);
        data[2][i] = asin((i*1.0/100*1.0));
        data[3][i] = acos((i*1.0/100*1.0));
        data[4][i] = tan((i*1.0/100*1.0));
        data[5][i] = atan((i*1.0/100*1.0));
        data[6][i] = sin((i*1.0/100*1.0)+1);
        data[7][i] = cos((i*1.0/100*1.0)+1);
        data[8][i] = asin((i*1.0/100*1.0)+1);
        data[9][i] = acos((i*1.0/100*1.0)+1);
        data[10][i] = tan((i*1.0/100*1.0)+1);
        data[11][i] = atan((i*1.0/100*1.0)+1);
    }
    this->draw(num,size,xdata,data,startTime,dataInfo,axisInfo,status);
    curveTimer = new QTimer(this);
    curveTimer->start(200);

    //事件注册
    this->installEventFilter(this);
    ui->storage_frequency_lineEdit->installEventFilter(this);

    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&Curve_Monitoring::currentTime);

    //页面跳转信号
    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&Curve_Monitoring::curveMonitoring_sendTo_mainWindow);
    connect(ui->previous_page_pbth,&QPushButton::clicked,this,&Curve_Monitoring::curveMonitoring_sendTo_outputMonitoring);

    //弹窗
    connect(&popUpWindow06,&PopUpWindow06::popUpWindow06PushButtonClickedSignals,this,&Curve_Monitoring::deal_PopUpWindow06PushButtonClickedSignals);
}

Curve_Monitoring::~Curve_Monitoring()
{
    delete ui;
}

bool Curve_Monitoring::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(ui->storage_frequency_lineEdit->hasFocus()){
                ui->storage_frequency_lineEdit->clearFocus();//如果点击屏幕任意位置则取消对应lineEdit的聚焦
            }
        }
    }

    //    //监听lineEdit
    //    if(watched == ui->storage_frequency_lineEdit)
    //    {
    //        if(event->type() == QEvent::MouseButtonPress){
    //            emit Request_Use_Keyboard_Signal(3);
    //            ui->storage_frequency_lineEdit->setFocus();
    //        }
    //    }
    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}
/*
 * time: 2022-10-31
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void Curve_Monitoring::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

/*
 * time: 2022-11-3
 * type: get
 * effect: 获取存储频率
 * influence: storage_frequency
*/
QString Curve_Monitoring::getStroageFrequency(){
    return storage_frequency;
}

/*
 * time: 2022-11-3
 * type: get
 * effect: 获取存储空间
 * influence: storage_spacing
*/
QString Curve_Monitoring::getStorageSpacing(){
    return storage_spacing;
}

/*
 * time: 2022-11-3
 * type: get
 * effect: 获取光标时间
 * influence: cursor_time
*/
QString Curve_Monitoring::getCursorTime(){
    return cursor_time;
}

/*
 * time: 2022-11-3
 * type: set
 * effect: 设置存储频率
 * influence: storage_frequency
*/
void Curve_Monitoring::setStroageFrequency(QString strs){
    this->storage_frequency = strs+"s";
    ui->storage_frequency_lineEdit->setText(storage_frequency);
}

/*
 * time: 2022-11-3
 * type: set
 * effect: 设置存储空间
 * influence: storage_spacing
*/
void Curve_Monitoring::setStorageSpacing(QString strs){
    this->storage_spacing = strs+"%";
    ui->storage_spacing_lineEdit->setText(storage_spacing);
}

/*
 * time: 2022-11-3
 * type: set
 * effect: 设置光标时间
 * influence: cursor_time
*/
void Curve_Monitoring::setCursorTime(QString strs){
    this->cursor_time = strs;
    ui->cursor_time_lineEdit->setText(cursor_time);
}

/*
 * time: 2022-11-3
 * type: send signals
 * effect: 请求页面跳转
 * influence: this
*/
void Curve_Monitoring::curveMonitoring_sendTo_mainWindow(){
    emit curveMonitoring_to_mainWindow();
}

/*
 * time: 2022-11-3
 * type: send signals
 * effect: 请求页面跳转
 * influence: this
*/
void Curve_Monitoring::curveMonitoring_sendTo_outputMonitoring(){
    emit curveMonitoring_to_outputMonitoring();
}

void Curve_Monitoring::saving_pBtn_clicked(){
    emit savingClickedSignals();
}

void Curve_Monitoring::real_time_pBtn_clicked(){
    //    emit realTimeClickedSignals();
}

QString Curve_Monitoring::getTemperaturePV(){
    return temperaturePV;
}

QString Curve_Monitoring::getTemperatureSV(){
    return temperatureSV;
}

QString Curve_Monitoring::getHumidityPV(){
    return humidityPV;
}

QString Curve_Monitoring::getHumiditySV(){
    return humiditySV;
}

void Curve_Monitoring::setTemperaturePV(QString strs){
    this->temperaturePV = strs;
    ui->temperature_pv_lineEdit->setText(temperaturePV);
}

void Curve_Monitoring::setTemperatureSV(QString strs){
    this->temperatureSV = strs;
    ui->temperature_sv_lineEdit->setText(temperatureSV);
}

void Curve_Monitoring::setHumidityPV(QString strs){
    this->humidityPV = strs;
    ui->humidity_pv_lineEdit->setText(humidityPV);
}

void Curve_Monitoring::setHumiditySV(QString strs){
    this->humiditySV = strs;
    ui->humidity_sv_lineEdit->setText(humiditySV);
}

void Curve_Monitoring::on_storage_frequency_pushButton_clicked()
{
    popUpWindow06.move(270,250);
    popUpWindow06.show();
}

void Curve_Monitoring::deal_PopUpWindow06PushButtonClickedSignals(int storage_frequency_num)
{
    storage_frequency = QString::number(storage_frequency_num);
    ui->storage_frequency_lineEdit->setText(storage_frequency+'S');
    popUpWindow06.close();
}

void Curve_Monitoring::freezeOneSec()
{
    ui->pushButton_0->setEnabled(false);
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->storage_frequency_pushButton->setEnabled(false);
    ui->font_page_pbtn->setEnabled(false);
    ui->previous_page_pbth->setEnabled(false);
    ui->real_time_pbtn->setEnabled(false);
    ui->saving_pbtn->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    ui->pushButton_0->setEnabled(true);
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_2->setEnabled(true);


    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->storage_frequency_pushButton->setEnabled(true);
    ui->font_page_pbtn->setEnabled(true);
    ui->previous_page_pbth->setEnabled(true);
    ui->real_time_pbtn->setEnabled(true);
    ui->saving_pbtn->setEnabled(true);
}

/*
 * Param:
 * num 曲线条数
 * size 数据数量
 * xdata x轴数据 xdata[a][b] a为曲线index b为数据位
 * data y轴数据 data[a][b] a为曲线index b为数据位
 * startTime 格式为yy-MM-dd hh:mm:ss的起始时间
 * dataInfo 大小为num+3 存储了间隔时间 x轴 y轴范围 固定[0]为间隔时间 后每两个存储空间为轴范围 顺序为 x轴 y1轴 y2轴.....
 * axisInfo 大小为num 轴信息 依次对应y1轴 y2轴
 * status 曲线状态 1为静态 2为动态
 */
void Curve_Monitoring::draw(int num,int size,QVector<QVector<double>> xdata,QVector<QVector<double>> data,QString startTime,double* dataInfo,QString* axisInfo,int status)
{
    switch (status) {
    case 1:
    {
        ui->CurveWidget->xAxis->setRange(dataInfo[1],dataInfo[2]);
        ui->CurveWidget->yAxis->setRange(dataInfo[3],dataInfo[4]);
        ui->CurveWidget->yAxis2->setRange(dataInfo[5],dataInfo[6]);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis2);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis2);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis2);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis2);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        QPen graphPen;
        for(int i=0 ; i<num; i++)
        {
            graphPen.setColor(color[i]);
            graphPen.setWidth(2);
            ui->CurveWidget->graph(i)->setPen(graphPen);
            ui->CurveWidget->graph(i)->setAntialiasedFill(true);
            ui->CurveWidget->graph(i)->addData(xdata[i],data[i]);
        }
        ui->CurveWidget->replot();
        break;
    }
    default:
        break;
    }
}

//动态曲线测试
void Curve_Monitoring::trendDraw()
{
    for(int i=0 ; i<num ; i++)
    {
        xdata[i].removeAt(0);
        data[i].removeAt(0);
    }
    endSize++;
    for(int i=0 ; i<num ; i++)
    {
        xdata[i].append(endSize*1.0/100*1.0);
    }
    data[0].append(sin(endSize*1.0/100*1.0));
    data[1].append(cos(endSize*1.0/100*1.0));
    data[2].append(asin(endSize*1.0/100*1.0));
    data[3].append(acos(endSize*1.0/100*1.0));
    data[4].append(tan(endSize*1.0/100*1.0));
    data[5].append(atan(endSize*1.0/100*1.0));
    data[6].append(sin(endSize*1.0/100*1.0+1));
    data[7].append(cos(endSize*1.0/100*1.0+1));
    data[8].append(asin(endSize*1.0/100*1.0+1));
    data[9].append(acos(endSize*1.0/100*1.0+1));
    data[10].append(tan(endSize*1.0/100*1.0+1));
    data[11].append(atan(endSize*1.0/100*1.0+1));
    double temp = dataInfo[1];
    dataInfo[1] = temp+dataInfo[0];
    dataInfo[2] = endSize*1.0/100*1.0;
    this->draw(num,size,xdata,data,startTime,dataInfo,axisInfo,status);
}


void Curve_Monitoring::on_real_time_pbtn_clicked()
{
    if(isconnect==true)
    {
        disconnect(curveTimer,&QTimer::timeout,this,&Curve_Monitoring::trendDraw);
        isconnect = false;
        ui->real_time_pbtn->setStyleSheet("QPushButton#real_time_pbtn{border:2px solid rgb(74,122,60);"
                                          "background-color:rgb(173,199,160);"
                                          "border-radius:8px;"
                                          "color:rgb(74,122,60)}");
    }
    else{
        connect(curveTimer,&QTimer::timeout,this,&Curve_Monitoring::trendDraw);
        isconnect = true;
        ui->real_time_pbtn->setStyleSheet("QPushButton#real_time_pbtn{border:2px solid rgb(74,122,60);"
                                          "background-color:rgb(74,122,60);"
                                          "border-radius:8px;"
                                          "color:rgb(173,199,160)}");
    }
    //    if(isconnect)
    //    {
    //        isconnect = false;
    //        ui->real_time_pbtn->setStyleSheet("QPushButton#real_time_pbtn{border:2px solid rgb(74,122,60);"
    //                                          "background-color:rgb(173,199,160);"
    //                                          "border-radius:8px;"
    //                                          "color:rgb(74,122,60)}");
    //    }
    //    else
    //    {
    //        isconnect = true;
    //        ui->real_time_pbtn->setStyleSheet("QPushButton#real_time_pbtn{border:2px solid rgb(74,122,60);"
    //                                          "background-color:rgb(74,122,60);"
    //                                          "border-radius:8px;"
    //                                          "color:rgb(173,199,160)}");
    //    }
}
