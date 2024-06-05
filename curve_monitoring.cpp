#include "curve_monitoring.h"
#include "ui_curve_monitoring.h"
#include "address_data_show.h"
#include "mainwindow.h"
#include "general_tools.h"

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
    //添加事件过滤器
    ui->curve_list_page->installEventFilter(this);
    ui->storage_frequency_lineEdit ->installEventFilter(this);
    ui->temperature_pv_label->installEventFilter(this);
    ui->temperature_sv_label->installEventFilter(this);
    ui->humidity_pv_label->installEventFilter(this);
    ui->humidity_sv_label->installEventFilter(this);
    //status_box
    ui->status_box->setStyleSheet("QWidget#status_box{border:2px solid rgb(72,129,52);"
                                  "border-radius:10px;"
                                  "background-color:white}");
    ui->status_box_line->setStyleSheet("QLabel#status_box_line{background-color:rgb(127,127,127)}");   

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

    //存储频率、存储空间、光标时间
    ui->storage_frequency_line->setStyleSheet("QLabel#storage_frequency_line{background-color:rgb(72,129,52)}");
    ui->storage_frequency_lineEdit->setStyleSheet("QLineEdit#storage_frequency_lineEdit{border:none;"
                                                  "background:transparent}");
    ui->storage_frequency_lineEdit->setText(storage_frequency+"s");

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
    ui->CurveWidget->xAxis->setTickLabelColor(Qt::transparent);
    ui->CurveWidget->yAxis->setTickLabelColor(Qt::white);
    ui->CurveWidget->yAxis2->setTickLabelColor(Qt::white);
    ui->CurveWidget->xAxis->setTickLabelFont(xFont);
    ui->CurveWidget->yAxis->setTickLabelFont(xFont);
    ui->CurveWidget->yAxis2->setTickLabelFont(xFont);
    ui->CurveWidget->xAxis->setRange(0,100);
    ui->CurveWidget->xAxis->ticker()->setTickCount(11);
    //    ui->CurveWidget->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
    ui->CurveWidget->yAxis->setRange(-90,210);
    ui->CurveWidget->yAxis->ticker()->setTickCount(11);
    ui->CurveWidget->yAxis2->setRange(0,100);
    ui->CurveWidget->yAxis2->ticker()->setTickCount(11);

    //测试曲线
    size = 360;
    xdata.resize(curve_numb);
    ydata.resize(curve_numb);
    for(int i=0 ; i<curve_numb ; i++)
    {
        xdata[i].resize(size);
        ydata[i].resize(size);
    }
    startTime = "2023-3-28 08:42:44";
    dataInfoSize = curve_numb*2+3;
    dataInfo = new double[dataInfoSize];
    dataInfo[0] = 1;
    dataInfo[1] = 0;
    dataInfo[2] = 360;
    dataInfo[3] = -90;
    dataInfo[4] = 210;
    dataInfo[5] = 0;
    dataInfo[6] = 100;
    axisInfo = new QString[curve_numb];
    axisInfo[0] = "Temperature(°C)";
    axisInfo[1] = "Humidity(%)";
    status=1;
    endSize = 0;
    for(int i=0 ; i<curve_numb ; i++)
    {
        xdata[i].clear();
        ydata[i].clear();
        curve_data_num_1 = 0;
        curve_data_num_2 = 0;
        curve_data_num_3 = 0;
        curve_data_num_4 = 0;
    }
    this->draw(curve_numb,size,xdata,ydata,startTime,dataInfo,axisInfo,status);
    curveTimer = new QTimer(this);
    curveTimer->start(200);

    //事件注册
    this->installEventFilter(this);
    ui->storage_frequency_lineEdit->installEventFilter(this);

    // 游标追踪器变量初始化
    tracer_curve_1 = new QCPItemTracer(ui->CurveWidget);        //设置部件的父类
    tracer_curve_1->setStyle(QCPItemTracer::tsCircle);        //标记点的类型设置为圆形
    tracer_curve_1->setPen(QPen(Qt::white, 1, Qt::SolidLine));  //标记点颜色、粗细、线型
    tracer_curve_1->setBrush(Qt::SolidPattern);               //画刷
    tracer_curve_1->position->setType(QCPItemPosition::ptPlotCoords);//在曲线上显示
    tracer_curve_1->setSize(1);//标记点大小
    tracer_curve_1->setGraph(ui->CurveWidget->graph(0));    //标记点绑定曲线

    tracer_curve_2 = new QCPItemTracer(ui->CurveWidget);//设置部件的父类
    tracer_curve_2->setStyle(QCPItemTracer::tsCircle);   //标记点的类型设置为圆形
    tracer_curve_2->setPen(QPen(Qt::white, 1, Qt::SolidLine));  //标记点颜色、粗细、线型
    tracer_curve_2->setBrush(Qt::SolidPattern);         //画刷
    tracer_curve_2->position->setType(QCPItemPosition::ptPlotCoords);//在曲线上显示
    tracer_curve_2->setSize(1);    //标记点大小
    tracer_curve_2->setGraph(ui->CurveWidget->graph(1));//标记点绑定曲线

    tracer_curve_3 = new QCPItemTracer(ui->CurveWidget);//设置部件的父类
    tracer_curve_3->setStyle(QCPItemTracer::tsCircle);   //标记点的类型设置为圆形
    tracer_curve_3->setPen(QPen(Qt::white, 1, Qt::SolidLine));  //标记点颜色、粗细、线型
    tracer_curve_3->setBrush(Qt::SolidPattern);         //画刷
    tracer_curve_3->position->setType(QCPItemPosition::ptPlotCoords);//在曲线上显示
    tracer_curve_3->setSize(1);    //标记点大小
    tracer_curve_3->setGraph(ui->CurveWidget->graph(2));//标记点绑定曲线

    tracer_curve_4 = new QCPItemTracer(ui->CurveWidget);//设置部件的父类
    tracer_curve_4->setStyle(QCPItemTracer::tsCircle);   //标记点的类型设置为圆形
    tracer_curve_4->setPen(QPen(Qt::white, 1, Qt::SolidLine));  //标记点颜色、粗细、线型
    tracer_curve_4->setBrush(Qt::SolidPattern);         //画刷
    tracer_curve_4->position->setType(QCPItemPosition::ptPlotCoords);//在曲线上显示
    tracer_curve_4->setSize(1);    //标记点大小
    tracer_curve_4->setGraph(ui->CurveWidget->graph(3));//标记点绑定曲线

    cur_Label_curve_1 = new QCPItemText(ui->CurveWidget);//文本框父类设置
    //cur_Label_curve_1->setPadding(QMargins(3, 3, 3, 3));    //这个根据需求设置，我这不需要
    //cur_Label_curve_1->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    //cur_Label_curve_1->setBrush(Qt::NoBrush);

    //设置标签显示位置跟随锚点的位置
    cur_Label_curve_1->position->setParentAnchor(tracer_curve_1->position);
    cur_Label_curve_1->setFont(QFont(qApp->font().family(), 12));      //设置字体大小
    cur_Label_curve_1->setColor(Qt::white);                            //设置字体颜色
    cur_Label_curve_1->setText("");

    cur_Label_curve_2 = new QCPItemText(ui->CurveWidget);//文本框父类设置
    //设置标签显示位置跟随锚点的位置
    cur_Label_curve_2->position->setParentAnchor(tracer_curve_2->position);
    cur_Label_curve_2->setFont(QFont(qApp->font().family(), 12));
    cur_Label_curve_2->setColor(Qt::white);
    cur_Label_curve_2->setText("");

    cur_Label_curve_3 = new QCPItemText(ui->CurveWidget);//文本框父类设置
    //设置标签显示位置跟随锚点的位置
    cur_Label_curve_3->position->setParentAnchor(tracer_curve_3->position);
    cur_Label_curve_3->setFont(QFont(qApp->font().family(), 12));
    cur_Label_curve_3->setColor(Qt::white);
    cur_Label_curve_3->setText("");

    cur_Label_curve_4 = new QCPItemText(ui->CurveWidget);//文本框父类设置
    //设置标签显示位置跟随锚点的位置
    cur_Label_curve_4->position->setParentAnchor(tracer_curve_4->position);
    cur_Label_curve_4->setFont(QFont(qApp->font().family(), 12));
    cur_Label_curve_4->setColor(Qt::white);
    cur_Label_curve_4->setText("");

    //设置标签对齐方式
    cur_Label_curve_1->setPositionAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    cur_Label_curve_2->setPositionAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    cur_Label_curve_3->setPositionAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    cur_Label_curve_4->setPositionAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    m_refer_lineV = new QCPItemStraightLine(ui->CurveWidget);
    m_refer_lineV->setPen(QPen(QColor(255,255,255)));
    m_refer_lineV->point1->setCoords(0, 0);               //设置点1的值
    m_refer_lineV->point2->setCoords(0, 100);              //设置点2的值
    //关联鼠标事件槽函数
    connect(ui->CurveWidget, SIGNAL(mouseRelease(QMouseEvent *)), this, SLOT(slot_mouseRelease(QMouseEvent *)));

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
                ui->storage_frequency_lineEdit->clearFocus(); //如果点击屏幕任意位置则取消对应lineEdit的聚焦
            }
        }
    }

    //监听lineEdit
    if(watched == ui->storage_frequency_lineEdit)
    {
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x33C);
            ui->storage_frequency_lineEdit->setFocus();
        }
    }else
        if(watched == ui->temperature_pv_label)
        {
            if(event->type() == QEvent::MouseButtonPress){
                curve_swi_1 = !curve_swi_1;
                ui->CurveWidget->graph(0)->setVisible(curve_swi_1);
                ui->temperature_pv_label->setFocus();
            }
        }else
            if(watched == ui->temperature_sv_label)
            {
                if(event->type() == QEvent::MouseButtonPress){
                    curve_swi_2 = !curve_swi_2;
                    ui->CurveWidget->graph(1)->setVisible(curve_swi_2);
                    //emit touch_InterfaceDataSignal(0x312,"0");
                    ui->temperature_sv_label->setFocus();
                }
            }else
                if(watched == ui->humidity_pv_label)
                {
                    if(event->type() == QEvent::MouseButtonPress){
                        curve_swi_3 = !curve_swi_3;
                        ui->CurveWidget->graph(2)->setVisible(curve_swi_3);
                        ui->humidity_pv_label->setFocus();
                    }
                }else
                    if(watched == ui->humidity_sv_label)
                    {
                        if(event->type() == QEvent::MouseButtonPress){
                            curve_swi_4 = !curve_swi_4;
                            ui->CurveWidget->graph(3)->setVisible(curve_swi_4);
                            ui->humidity_sv_label->setFocus();
                        }
                    }else
                        if(watched == ui->curve_list_page)
                        {
                            if(event->type() == QEvent::MouseButtonPress){
                                if(true == sys_info.sys_sta)
                                {
                                    // pop up dialog box about can't edit storage frequent when system is runnning
                                }else
                                {
                                    emit Request_Use_Calculate_Signal(0x31);
                                    ui->curve_list_page->setFocus();
                                }
                            }
                        }

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
    //refreshCurveInterfaceData();
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
void Curve_Monitoring::on_curve_pbtn_1_clicked()
{
    emit touch_InterfaceDataSignal(0x330, "2");
}
void Curve_Monitoring::on_curve_pbtn_2_clicked()
{
    emit touch_InterfaceDataSignal(0x330, "3");
}
void Curve_Monitoring::on_curve_pbtn_3_clicked()
{
    emit touch_InterfaceDataSignal(0x330, "4");
}
void Curve_Monitoring::on_curve_pbtn_4_clicked()
{
    emit touch_InterfaceDataSignal(0x330, "5");
}
void Curve_Monitoring::on_curve_pbtn_5_clicked()
{
    emit touch_InterfaceDataSignal(0x330, "6");
}
void Curve_Monitoring::on_curve_pbtn_6_clicked()
{
    emit touch_InterfaceDataSignal(0x330, "7");
}
void Curve_Monitoring::on_curve_pbtn_7_clicked()
{
    emit touch_InterfaceDataSignal(0x330, "8");
}
void Curve_Monitoring::on_curve_pbtn_8_clicked()
{
    emit touch_InterfaceDataSignal(0x330, "9");
}
void Curve_Monitoring::on_curve_pbtn_9_clicked()
{
    emit touch_InterfaceDataSignal(0x330, "10");
}
void Curve_Monitoring::on_curve_pbtn_10_clicked()
{
    emit touch_InterfaceDataSignal(0x330, "11");
}

void Curve_Monitoring::on_curve_lastpage_pbtn_clicked()
{
   emit touch_InterfaceDataSignal(0x33D, "0");
}

void Curve_Monitoring::on_curve_nextpage_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(0x33A, "0");
}

void Curve_Monitoring::on_pushButton_0_clicked()
{
    emit touch_InterfaceDataSignal(0x331, "0");
}

void Curve_Monitoring::on_pushButton_1_clicked()
{
    emit touch_InterfaceDataSignal(0x332, "0");
}

void Curve_Monitoring::on_pushButton_2_clicked()
{
    emit touch_InterfaceDataSignal(0x333, "0");
}

void Curve_Monitoring::on_pushButton_3_clicked()
{
    emit touch_InterfaceDataSignal(0x334, "0");
}

void Curve_Monitoring::on_pushButton_4_clicked()
{
    emit touch_InterfaceDataSignal(0x335, "0");
}

void Curve_Monitoring::on_pushButton_5_clicked()
{
    emit touch_InterfaceDataSignal(0x336, "0");
}

void Curve_Monitoring::on_pushButton_6_clicked()
{
    //emit touch_InterfaceDataSignal(0x337, "0");
    --cur_x;
}

void Curve_Monitoring::on_pushButton_7_clicked()
{
    //emit touch_InterfaceDataSignal(0x338, "0");
    ++cur_x;
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

void Curve_Monitoring::on_real_time_pbtn_clicked()
{
   /* qDebug() <<"isconnect" << isconnect;
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
    }*/
    emit touch_InterfaceDataSignal(0x330, "0");
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


void Curve_Monitoring::deal_PopUpWindow06PushButtonClickedSignals(int storage_frequency_num)
{
    storage_frequency = QString::number(storage_frequency_num);
    ui->storage_frequency_lineEdit->setText(storage_frequency+'S');
    popUpWindow06.close();
}

void Curve_Monitoring::freezeOneSec()
{
   /* ui->pushButton_0->setEnabled(false);
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
    ui->saving_pbtn->setEnabled(true);*/
}

/*
 * Param:
 * curve_numb 曲线条数
 * size 数据数量
 * xdata x轴数据 xdata[a][b] a为曲线index b为数据位
 * ydata y轴数据 ydata[a][b] a为曲线index b为数据位
 * startTime 格式为yy-MM-dd hh:mm:ss的起始时间
 * dataInfo 大小为curve_numb+3 存储了间隔时间 x轴 y轴范围 固定[0]为间隔时间 后每两个存储空间为轴范围 顺序为 x轴 y1轴 y2轴.....
 * axisInfo 大小为curve_numb 轴信息 依次对应y1轴 y2轴
 * status 曲线状态 1为静态 2为动态
 */
void Curve_Monitoring::draw(int num,int size,QVector<QVector<double>> xdata,QVector<QVector<double>> ydata,QString startTime,double* dataInfo,QString* axisInfo,int status)
{
    startTime = startTime;
    axisInfo = axisInfo;
    size = size;

    switch (status) {
    case 1:
    {
        //qDebug() << "dataInfo[1]"<< dataInfo[1];
        //qDebug() << "dataInfo[2]"<< dataInfo[2];
        ui->CurveWidget->xAxis->setRange(dataInfo[1],dataInfo[2]);
        ui->CurveWidget->yAxis->setRange(dataInfo[3],dataInfo[4]);
        ui->CurveWidget->yAxis2->setRange(dataInfo[5],dataInfo[6]);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis2);
        ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis2);

        //ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        //ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        //ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        //ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        //ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis2);
        //ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis2);
        //ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        //ui->CurveWidget->addGraph(ui->CurveWidget->xAxis,ui->CurveWidget->yAxis);
        QPen graphPen;
        for(int i=0 ; i<num; i++)
        {
            graphPen.setColor(color[i]);
            graphPen.setWidth(2);
            ui->CurveWidget->graph(i)->setPen(graphPen);
            ui->CurveWidget->graph(i)->setAntialiasedFill(true);
            ui->CurveWidget->graph(i)->setData(xdata[i],ydata[i]);
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

    endSize++;
    xdata[0].append(endSize);
    xdata[1].append(endSize);
    xdata[2].append(endSize);
    xdata[3].append(endSize);
    ydata[0].append(endSize-75);
    ydata[1].append(180 - endSize);
    ydata[2].append(endSize + 1);
    ydata[3].append(99 - endSize);
    if(endSize < 100)
        dataInfo[1] = 0;
    else
        dataInfo[1] = endSize - 360;
    dataInfo[2] = dataInfo[1] + 360;
    this->draw(curve_numb,size,xdata,ydata,startTime,dataInfo,axisInfo,status);
}
void Curve_Monitoring::addrSetCurveInterfaceData(int addr_num, QString set_value){

    QString covert_data;
    int for_i;
    switch(addr_num)
    {
    case 0xEB:
        if(0x55 == set_value.toInt())
        {
            for(for_i = 0; for_i < curve_numb; ++for_i)
            {
                xdata[for_i].clear();
                ydata[for_i].clear();
                curve_data_num_1 = 0;
                curve_data_num_2 = 0;
                curve_data_num_3 = 0;
                curve_data_num_4 = 0;
            }
            ui->CurveWidget->clearGraphs();
            ui->CurveWidget->replot();
        }
        break;
    case 0x301:  // temperature pv
        covert_data = convertToDecimalString(set_value,2);
        setTemperaturePV(covert_data);
        break;
    case 0x302:    // temperature sv
        covert_data = convertToDecimalString(set_value,2);
        setTemperatureSV(covert_data);
        break;
    case 0x303 :    //humidity pv
        covert_data = convertToDecimalString(set_value,1);
        setHumidityPV(covert_data);
        break;
    case 0x304 :
        covert_data = convertToDecimalString(set_value,1);
        setHumiditySV(covert_data);
        break;   
    case 0x33B:
        ui->curve_list_page->setText(set_value);
        break;
    case 0x351:
        ui->Y_axis_time_1->setText(set_value);
        break;
    case 0x353:
        ui->Y_axis_time_2->setText(set_value);
        break;
    case 0x355:
        ui->Y_axis_time_3->setText(set_value);
        break;
    case 0x357:
        ui->Y_axis_time_4->setText(set_value);
        break;
    case 0x359:
        ui->Y_axis_time_5->setText(set_value);
        break;
    case 0x35B:
        ui->Y_axis_time_6->setText(set_value);
        break;
    case 0x35D:
        ui->Y_axis_time_7->setText(set_value);
        break;
    case 0x361:
        dataInfo[3] = set_value.toDouble() / 10;
        break;
    case 0x36B:
        dataInfo[4] = set_value.toDouble() / 10;
        break;
    case 0x341:
        dataInfo[5] = set_value.toDouble() / 10;
        break;
    case 0x34B:
        dataInfo[6] = set_value.toDouble() / 10;
        break;
    case 0x371: //sample rate
        setStroageFrequency(set_value);
        break;
    case 0x370:  // storage space
        covert_data = convertToDecimalString(set_value,2);
        setStorageSpacing(covert_data);
        break;
    case 0x373:     // cursor time
        setCursorTime(set_value);
        break;
    case 0x2381: // curve 1
        covert_data = convertToDecimalString(set_value,2);
        xdata[0].append(curve_data_num_1++);
        qDebug() << "new data is" << covert_data.toFloat();
        ydata[0].append(covert_data.toFloat());
        break;
    case 0x2382: // curve 2
        covert_data = convertToDecimalString(set_value,2);
        xdata[1].append(curve_data_num_2++);
        qDebug() << "new data is" << covert_data.toFloat();
        ydata[1].append(covert_data.toFloat());
        break;
    case 0x2383: // curve 3
        covert_data = convertToDecimalString(set_value,1);
        xdata[2].append(curve_data_num_3++);
        qDebug() << "new data is" << covert_data.toFloat();
        ydata[2].append(covert_data.toFloat());
        break;
    case 0x2384: // curve 4
        covert_data = convertToDecimalString(set_value,1);
        xdata[3].append(curve_data_num_4++);
        qDebug() << "new data is" << covert_data.toFloat();
        ydata[3].append(covert_data.toFloat());
        break;
    case 0x396:
        ui->curve_pbtn_1->setText(set_value);
        break;
    case 0x3A0:
        ui->curve_pbtn_2->setText(set_value);
        break;
    case 0x3AA:
        ui->curve_pbtn_3->setText(set_value);
        break;
    case 0x3B4:
        ui->curve_pbtn_4->setText(set_value);
        break;
    case 0x3BE:
        ui->curve_pbtn_5->setText(set_value);
        break;
    case 0x3C8:
        ui->curve_pbtn_6->setText(set_value);
        break;
    case 0x3D2:
        ui->curve_pbtn_7->setText(set_value);
        break;
    case 0x3DC:
        ui->curve_pbtn_8->setText(set_value);
        break;
    case 0x3E6:
        ui->curve_pbtn_9->setText(set_value);
        break;
    case 0x3F0:
        ui->curve_pbtn_10->setText(set_value);
        break;
    default:
        break;
    }
}
void Curve_Monitoring::on_temperature_pv_checkbox_clicked()
{
    curve_swi_1 = !curve_swi_1;
    ui->CurveWidget->graph(0)->setVisible(curve_swi_1);
}

void Curve_Monitoring::on_temperature_sv_checkbox_clicked()
{
    curve_swi_2 = !curve_swi_2;
    ui->CurveWidget->graph(1)->setVisible(curve_swi_2);
}

void Curve_Monitoring::on_humidity_pv_checkbox_clicked()
{
    curve_swi_3 = !curve_swi_3;
    ui->CurveWidget->graph(2)->setVisible(curve_swi_3);
}

void Curve_Monitoring::on_humidity_sv_checkbox_clicked()
{
    curve_swi_4 = !curve_swi_4;
    ui->CurveWidget->graph(3)->setVisible(curve_swi_4);
}
void Curve_Monitoring::refreshCurveInterfaceData()
{
    ui->temperature_pv_checkbox->setChecked(curve_swi_1);
    ui->temperature_sv_checkbox->setChecked(curve_swi_2);
    ui->humidity_pv_checkbox->setChecked(curve_swi_3);
    ui->humidity_sv_checkbox->setChecked(curve_swi_4);
    showTraceData(cur_x);
    this->draw(curve_numb,size,xdata,ydata,startTime,dataInfo,axisInfo,status);
    ui->status_text->setText(sys_info.run_sta_string);
    if(sys_info.run_sta_color == 0) // green
    {
        ui->status_text->setStyleSheet("QLabel#status_text{color:rgb(72,129,52)}");
    }else
        if(sys_info.run_sta_color == 1) //red
        {
            ui->status_text->setStyleSheet("QLabel#status_text{color:rgb(253,0,0)}");
        }else
            if(sys_info.run_sta_color == 2) // black
            {
                ui->status_text->setStyleSheet("QLabel#status_text{color:rgb(253,0,0)}");
            }else
                if(sys_info.run_sta_color == 3) //orange
                {
                    ui->status_text->setStyleSheet("QLabel#status_text{color:rgb(255, 170, 0)}");
                }
    if(sys_info.sd_flag)
    {
        ui->status_1->setStyleSheet("QLabel#status_1{background-image:url(:/Image/24/62.bmp)}");
    }else{
        ui->status_1->setStyleSheet("QLabel#status_1{background-image:url(:/Image/24/61.bmp)}");
    }
    if(sys_info.usb_flag)
    {
        ui->status_2->setStyleSheet("QLabel#status_2{background-image:url(:/Image/24/64.bmp)}");
    }else{
        ui->status_2->setStyleSheet("QLabel#status_2{background-image:url(:/Image/24/63.bmp)}");
    }
    if(sys_info.burn_flag)
    {
        ui->status_3->setStyleSheet("QLabel#status_3{background-image:url(:/Image/24/66.bmp)}");
    }else{
        ui->status_3->setStyleSheet("QLabel#status_3{background-image:url(:/Image/24/65.bmp)}");
    }
    if(sys_info.wifi_flag)
    {
        ui->status_4->setStyleSheet("QLabel#status_4{background-image:url(:/Image/24/68.bmp)}");
    }else{
        ui->status_4->setStyleSheet("QLabel#status_4{background-image:url(:/Image/24/67.bmp)}");
    }
    if(sys_info.host_mode)
    {
        ui->status_5->setStyleSheet("QLabel#status_5{background-image:url(:/Image/24/70.bmp)}");
    }else{
        ui->status_5->setStyleSheet("QLabel#status_5{background-image:url(:/Image/24/69.bmp)}");
    }
    if(sys_info.abnormal_flag)
    {
        ui->status_6->setStyleSheet("QLabel#status_6{background-image:url(:/Image/24/72.bmp)}");
    }else{
        ui->status_6->setStyleSheet("QLabel#status_6{background-image:url(:/Image/24/71.bmp)}");
    }

}

void Curve_Monitoring::slot_mouseRelease(QMouseEvent *event)
{
    //点击坐标
    QPointF CPoint = event->pos();

    //鼠标点击的后屏幕位置转换到下坐标轴对应坐标
    cur_x = ui->CurveWidget->xAxis->pixelToCoord(CPoint.x());
}

void Curve_Monitoring::showTraceData(int cur_x)
{
    qDebug() << "cur_x = "<<cur_x;
    double y_value1 = 0;
    double y_value2 = 0;
    double y_value3 = 0;
    double y_value4 = 0;
    QString y_value1_text = "";
    QString y_value2_text = "";
    QString y_value3_text = "";
    QString y_value4_text = "";
   //标记点和标签
    if(cur_x < 0)
    {
        cur_x = 0;
    }else
    {
        if((cur_x < ydata[0].size()))
        {
            y_value1 = ydata[0].at(cur_x);                     //获取曲线在X轴位置的Y值
            y_value1_text = QString::number(y_value1, 'f', 2);
        }
        if((cur_x < ydata[1].size()))
        {
            y_value2 = ydata[1].at(cur_x);
            y_value2_text = QString::number(y_value2, 'f', 2);
        }
        if((cur_x < ydata[2].size()))
        {
            y_value3 = ydata[2].at(cur_x);
            y_value3_text = QString::number(y_value3, 'f', 2);
        }
        if((cur_x < ydata[3].size()))
        {
            y_value4 = ydata[3].at(cur_x);
            y_value4_text = QString::number(y_value4, 'f', 2);
        }
    }

    tracer_curve_1->setGraphKey(cur_x);                              //设置标记点X轴的位置
    tracer_curve_1->position->setCoords(cur_x, y_value1);             //设置标记点在位置
    cur_Label_curve_1->position->setCoords(0, 10);                   //设置标签显示偏移位置
    cur_Label_curve_1->setText(y_value1_text);    //设置标签的值

    tracer_curve_2->setGraphKey(cur_x);
    tracer_curve_2->position->setCoords(cur_x, y_value2);
    cur_Label_curve_2->position->setCoords(0, 10);
    cur_Label_curve_2->setText(y_value2_text);

    tracer_curve_3->setGraphKey(cur_x);
    tracer_curve_3->position->setCoords(cur_x, y_value3);
    cur_Label_curve_3->position->setCoords(0, 10);
    cur_Label_curve_3->setText(y_value3_text);

    tracer_curve_4->setGraphKey(cur_x);
    tracer_curve_4->position->setCoords(cur_x, y_value4);
    cur_Label_curve_4->position->setCoords(0, 10);
    cur_Label_curve_4->setText(y_value4_text);

    //垂直参考线，就是两点一线
    m_refer_lineV->point1->setCoords(cur_x, 0);               //设置点1的值
    m_refer_lineV->point2->setCoords(cur_x, 100);              //设置点2的值
    //ui->CurveWidget->replot();
}
