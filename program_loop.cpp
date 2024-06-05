#include "program_loop.h"
#include "ui_program_loop.h"
#include "general_tools.h"
#include "mainwindow.h"
#include "address_data_show.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>

Program_Loop::Program_Loop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Program_Loop)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
   // qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;
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

    //status_box
    ui->status_box->setStyleSheet("QWidget#status_box{border:2px solid rgb(72,129,52);"
                                  "border-radius:10px;"
                                  "background-color:white}");
    ui->status_box_line->setStyleSheet("QLabel#status_box_line{background-color:rgb(127,127,127)}");


    //添加事件过滤器
    this->installEventFilter(this);
    ui->choose_program_edit->installEventFilter(this);
    ui->all_loops_edit->installEventFilter(this);
    ui->link_edit->installEventFilter(this);
    ui->r2h1->installEventFilter(this);
    ui->r2h2->installEventFilter(this);
    ui->r2h3->installEventFilter(this);
    ui->r2h4->installEventFilter(this);
    ui->r3h1->installEventFilter(this);
    ui->r3h2->installEventFilter(this);
    ui->r3h3->installEventFilter(this);
    ui->r3h4->installEventFilter(this);
    ui->r4h1->installEventFilter(this);
    ui->r4h2->installEventFilter(this);
    ui->r4h3->installEventFilter(this);
    ui->r4h4->installEventFilter(this);

    //line
    ui->choose_program_line->setStyleSheet("QLabel#choose_program_line{background-color:rgb(117,150,107)}");
    ui->program_name_line->setStyleSheet("QLabel#program_name_line{background-color:rgb(117,150,107)}");
    ui->link_line->setStyleSheet("QLabel#link_line{background-color:rgb(117,150,107)}");
    ui->all_loops_line->setStyleSheet("QLabel#all_loops_line{background-color:rgb(117,150,107)}");
    //edit
    ui->choose_program_edit->setStyleSheet("QLineEdit#choose_program_edit{background:transparent;"
                                           "border:none}");
    ui->program_name_edit->setStyleSheet("QLineEdit#program_name_edit{background:transparent;"
                                           "border:none}");
    ui->all_loops_edit->setStyleSheet("QLineEdit#all_loops_edit{background:transparent;"
                                           "border:none}");
    ui->link_edit->setStyleSheet("QLineEdit#link_edit{background:transparent;"
                                           "border:none}");

    //table_box
    ui->table_box->setStyleSheet("QWidget#table_box{border:2px solid rgb(117,150,107)}");
    ui->border_left->setStyleSheet("QLabel#border_left{background-color:rgb(117,150,107)}");
    ui->border_top->setStyleSheet("QLabel#border_top{background-color:rgb(117,150,107)}");
    ui->border_right->setStyleSheet("QLabel#border_right{background-color:rgb(117,150,107)}");
    ui->border_buttom->setStyleSheet("QLabel#border_buttom{background-color:rgb(117,150,107)}");
    ui->r1h1->setStyleSheet("QLabel#r1h1{border:1px solid rgb(200,200,200);"
                            "background-color:rgb(173,199,160)}");
    ui->r2h1->setStyleSheet("QLabel#r2h1{border:1px solid rgb(200,200,200);"
                            "background-color:rgb(173,199,160)}");
    ui->r3h1->setStyleSheet("QLabel#r3h1{border:1px solid rgb(200,200,200);"
                            "background-color:rgb(173,199,160)}");
    ui->r4h1->setStyleSheet("QLabel#r4h1{border:1px solid rgb(200,200,200);"
                            "background-color:rgb(173,199,160)}");
    ui->r1h1->setStyleSheet("QLineEdit#r1h1{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:orange}");
    ui->r1h1->setText("1");
    ui->r1h2->setStyleSheet("QLineEdit#r1h2{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:orange}");    
    ui->r1h2->setText("2");
    ui->r1h3->setStyleSheet("QLineEdit#r1h3{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:orange}");
    ui->r1h3->setText("3");
    ui->r1h4->setStyleSheet("QLineEdit#r1h4{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:orange}");
    ui->r1h4->setText("4");

    ui->r2h1->setStyleSheet("QLineEdit#r2h2{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r2h1->setInputMask("0");
    ui->r2h1->setText(r2h1text);
    ui->r2h2->setStyleSheet("QLineEdit#r2h2{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");    
    ui->r2h2->setInputMask("0");
    ui->r2h2->setText(r2h2text);
    ui->r2h3->setStyleSheet("QLineEdit#r2h3{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r2h3->setInputMask("0");
    ui->r2h3->setText(r2h3text);
    ui->r2h4->setStyleSheet("QLineEdit#r2h4{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r2h4->setInputMask("0");
    ui->r2h4->setText(r2h4text);
    ui->r3h1->setStyleSheet("QLineEdit#r3h2{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r3h1->setInputMask("0");
    ui->r3h1->setText(r3h1text);
    ui->r3h2->setStyleSheet("QLineEdit#r3h2{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r3h2->setInputMask("0");
    ui->r3h2->setText(r3h2text);
    ui->r3h3->setStyleSheet("QLineEdit#r3h3{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r3h3->setInputMask("0");
    ui->r3h3->setText(r3h3text);
    ui->r3h4->setStyleSheet("QLineEdit#r3h4{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r3h4->setInputMask("0");
    ui->r3h4->setText(r3h4text);
    ui->r4h1->setStyleSheet("QLineEdit#r4h2{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r4h1->setInputMask("0");
    ui->r4h1->setText(r4h1text);
    ui->r4h2->setStyleSheet("QLineEdit#r4h2{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r4h2->setInputMask("0");
    ui->r4h2->setText(r4h2text);
    ui->r4h3->setStyleSheet("QLineEdit#r4h3{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r4h3->setInputMask("0");
    ui->r4h3->setText(r4h3text);
    ui->r4h4->setStyleSheet("QLineEdit#r4h4{background-color:white;"
                            "border:1px solid rgb(200,200,200);"
                            "color:black}");
    ui->r4h4->setInputMask("0");
    ui->r4h4->setText(r4h4text);

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
   /* ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->previous_page_pbtn->setStyleSheet("QPushButton#previous_page_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");
    ui->saving_pbtn->setStyleSheet("QPushButton#saving_pbtn{border:2px solid rgb(74,122,60);"
                                                   "background-color:rgb(173,199,160);"
                                                   "border-radius:8px;"
                                                   "color:rgb(74,122,60)}");
    ui->next_page_pbtn->setStyleSheet("QPushButton#next_page_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");*/
    //qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;
    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&Program_Loop::currentTime);
    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&Program_Loop::programLoop_sendTo_mainWindow);
    connect(ui->previous_page_pbtn,&QPushButton::clicked,this,&Program_Loop::programLoop_sendTo_programEditing);
    connect(ui->next_page_pbtn,&QPushButton::clicked,this,&Program_Loop::programLoop_sendTo_fixedValueSetting);
}

Program_Loop::~Program_Loop()
{
    delete ui;
}

void Program_Loop::on_saving_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(addr_touch_edit_pgm_save,"2");
}
/*
 * time: 2022-11-14
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void Program_Loop::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

/*
 * time: 2022-11-15
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Program_Loop::programLoop_sendTo_mainWindow(){
    emit programLoop_to_mainWindow();
}

/*
 * time: 2022-11-15
 * type: System EventFilter
 * effect: 事件过滤器
 * influence: this
*/
bool Program_Loop::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(ui->r2h2->hasFocus()){
                ui->r2h2->clearFocus();//如果点击屏幕任意位置则取消对应lineEdit的聚焦
            }
            else if(ui->r2h3->hasFocus()){
                ui->r2h3->clearFocus();
            }
            else if(ui->r2h4->hasFocus()){
                ui->r2h4->clearFocus();
            }
            else if(ui->r3h2->hasFocus()){
                ui->r3h2->clearFocus();
            }
            else if(ui->r3h3->hasFocus()){
                ui->r3h3->clearFocus();
            }
            else if(ui->r3h4->hasFocus()){
                ui->r3h4->clearFocus();
            }
            else if(ui->r4h2->hasFocus()){
                ui->r4h2->clearFocus();
            }
            else if(ui->r4h3->hasFocus()){
                ui->r4h3->clearFocus();
            }
            else if(ui->r4h4->hasFocus()){
                ui->r4h4->clearFocus();
            }
        }
    }

    //监听lineEdit
    if(watched == ui->choose_program_edit)
    {
       /* if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Keyboard_Signal(6);
            ui->choose_program_edit->setFocus();   //lineEdit聚焦
        }*/
    }
    else if(watched == ui->all_loops_edit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x511);
            ui->all_loops_edit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->link_edit){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x513);
            ui->link_edit->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->r2h1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x520);
            ui->r2h2->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->r2h2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x530);
            ui->r2h2->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->r2h3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x540);
            ui->r2h3->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->r2h4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x550);
            ui->r2h4->setFocus();   //lineEdit聚焦
        }
    } else if(watched == ui->r3h1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x522);
            ui->r3h2->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->r3h2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x532);
            ui->r3h2->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->r3h3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x542);
            ui->r3h3->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->r3h4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x552);
            ui->r3h4->setFocus();   //lineEdit聚焦
        }
    } else if(watched == ui->r4h1){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x524);
            ui->r4h2->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->r4h2){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x534);
            ui->r4h2->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->r4h3){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x544);
            ui->r4h3->setFocus();   //lineEdit聚焦
        }
    }
    else if(watched == ui->r4h4){
        if(event->type() == QEvent::MouseButtonPress){
            emit Request_Use_Calculate_Signal(0x554);
            ui->r4h4->setFocus();   //lineEdit聚焦
        }
    }
    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}

/*
 * time: 2022-11-15
 * type: Get
 * effect: Get函数
 * influence: ui->r2h2
*/
QString Program_Loop::getr2h2Text(){
    return r2h2text;
}

/*
 * time: 2022-11-15
 * type: Get
 * effect: Get函数
 * influence: ui->r2h3
*/
QString Program_Loop::getr2h3Text(){
    return r2h3text;
}

/*
 * time: 2022-11-15
 * type: Get
 * effect: Get函数
 * influence: ui->r2h4
*/
QString Program_Loop::getr2h4Text(){
    return r2h4text;
}

/*
 * time: 2022-11-15
 * type: Get
 * effect: Get函数
 * influence: ui->r3h2
*/
QString Program_Loop::getr3h2Text(){
    return r3h2text;
}

/*
 * time: 2022-11-15
 * type: Get
 * effect: Get函数
 * influence: ui->r3h3
*/
QString Program_Loop::getr3h3Text(){
    return r3h3text;
}

/*
 * time: 2022-11-15
 * type: Get
 * effect: Get函数
 * influence: ui->r3h4
*/
QString Program_Loop::getr3h4Text(){
    return r3h4text;
}

/*
 * time: 2022-11-15
 * type: Get
 * effect: Get函数
 * influence: ui->r4h2
*/
QString Program_Loop::getr4h2Text(){
    return r4h2text;
}

/*
 * time: 2022-11-15
 * type: Get
 * effect: Get函数
 * influence: ui->r4h3
*/
QString Program_Loop::getr4h3Text(){
    return r4h3text;
}

/*
 * time: 2022-11-15
 * type: Get
 * effect: Get函数
 * influence: ui->r4h4
*/
QString Program_Loop::getr4h4Text(){
    return r4h4text;
}

/*
 * time: 2024-1-18
 * type: Set
 * effect: Set函数
 * influence: r2h1text
*/
void Program_Loop::setr2h1Text(QString strs){
    r2h1text = strs;
    ui->r2h1->setText(r2h1text);
}
/*
 * time: 2022-11-15
 * type: Set
 * effect: Set函数
 * influence: r2h2text
*/
void Program_Loop::setr2h2Text(QString strs){
    r2h2text = strs;
    ui->r2h2->setText(r2h2text);
}

/*
 * time: 2022-11-15
 * type: Set
 * effect: Set函数
 * influence: r2h3text
*/
void Program_Loop::setr2h3Text(QString strs){
    r2h3text = strs;
    ui->r2h3->setText(r2h3text);
}



/*
 * time: 2022-11-15
 * type: Set
 * effect: Set函数
 * influence: r2h4text
*/
void Program_Loop::setr2h4Text(QString strs){
    r2h4text = strs;
    ui->r2h4->setText(r2h4text);
}

/*
 * time: 2024-1-18
 * type: Set
 * effect: Set函数
 * influence: r3h1text
*/
void Program_Loop::setr3h1Text(QString strs){
    r3h1text = strs;
    ui->r3h1->setText(r3h1text);
}

/*
 * time: 2022-11-15
 * type: Set
 * effect: Set函数
 * influence: r3h2text
*/
void Program_Loop::setr3h2Text(QString strs){
    r3h2text = strs;
}

/*
 * time: 2022-11-15
 * type: Set
 * effect: Set函数
 * influence: r3h3text
*/
void Program_Loop::setr3h3Text(QString strs){
    r3h3text = strs;
    ui->r3h3->setText(r3h3text);
}

/*
 * time: 2022-11-15
 * type: Set
 * effect: Set函数
 * influence: r3h4text
*/
void Program_Loop::setr3h4Text(QString strs){
    r3h4text = strs;
    ui->r3h4->setText(r3h4text);
}

/*
 * time: 2024-1-18
 * type: Set
 * effect: Set函数
 * influence: r4h1text
*/
void Program_Loop::setr4h1Text(QString strs){
    r4h1text = strs;
    ui->r4h1->setText(r4h1text);
}

/*
 * time: 2022-11-15
 * type: Set
 * effect: Set函数
 * influence: r4h2text
*/
void Program_Loop::setr4h2Text(QString strs){
    r4h2text = strs;
    ui->r4h2->setText(r4h2text);
}

/*
 * time: 2022-11-15
 * type: Set
 * effect: Set函数
 * influence: r4h3text
*/
void Program_Loop::setr4h3Text(QString strs){
    r4h3text = strs;
    ui->r4h3->setText(r4h3text);
}

/*
 * time: 2022-11-15
 * type: Set
 * effect: Set函数
 * influence: r4h4text
*/
void Program_Loop::setr4h4Text(QString strs){
    r4h4text = strs;
    ui->r4h4->setText(r4h4text);
}

QString Program_Loop::getProgramName(){
    return programName;
}

QString Program_Loop::getChooseProgram(){
    return chooseProgram;
}

QString Program_Loop::getAllLoops(){
    return all_loops;
}

QString Program_Loop::getLink(){
    return link;
}

void Program_Loop::setAllLoops(QString strs){
    this->all_loops = strs;
    ui->all_loops_edit->setText(all_loops);
}

void Program_Loop::setChooseProgram(QString strs){
    this->chooseProgram = strs;
    ui->choose_program_edit->setText(chooseProgram);
}

void Program_Loop::setLink(QString strs){
    this->link = strs;
    ui->link_edit->setText(link);
}

void Program_Loop::setProgramName(QString strs){
    this->programName = strs;
    ui->program_name_edit->setText(programName);
}

/*
 * time: 2022-11-14
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Program_Loop::programLoop_sendTo_programEditing(){
    emit programLoop_to_programEditing();
}

/*
 * time: 2022-11-17
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Program_Loop::programLoop_sendTo_fixedValueSetting(){
    emit programLoop_to_fixedValueSetting();
}

void Program_Loop::freezeOneSec()
{
    /*
    ui->font_page_pbtn->setEnabled(false);
    ui->previous_page_pbtn->setEnabled(false);
    ui->next_page_pbtn->setEnabled(false);
    ui->saving_pbtn->setEnabled(false);
    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    ui->font_page_pbtn->setEnabled(true);
    ui->previous_page_pbtn->setEnabled(true);
    ui->next_page_pbtn->setEnabled(true);
    ui->saving_pbtn->setEnabled(true);*/
}

void Program_Loop::addrSetPgmLoopInterfaceData(int addr_num, QString set_value){

    qDebug() << QString("addrSetMonitorInterfaceData addr_num: %1").arg(addr_num);
    QString covert_data;
    switch(addr_num)
    {
    case addr_pgm_edit_pgm_number:
        setChooseProgram(set_value);
        break;
    case addr_pgm_edit_pgm_name:
        setProgramName(set_value);
        break;
    case 0x512: // all cycle
        setAllLoops(set_value);
        break;
    case 0x514: // pgm link
        setLink(set_value);
        break;
    case 0x521: // partial cycle start  1
        setr2h1Text(set_value);
        break;
    case 0x531: // partial cycle start  2
        setr2h2Text(set_value);
        break;
    case 0x541: // partial cycle start  3
        setr2h3Text(set_value);
        break;
    case 0x551: // partial cycle start  4
        setr2h4Text(set_value);
        break;
    case 0x523: // partial cycle end  1
        setr3h1Text(set_value);
        break;
    case 0x533: // partial cycle end  2
        setr3h2Text(set_value);
        break;
    case 0x543:// partial cycle end  3
        setr3h3Text(set_value);
        break;
    case 0x553:// partial cycle end  4
        setr3h4Text(set_value);
        break;
    case 0x525: // partial cycle num  1
        setr4h1Text(set_value);
        break;
    case 0x535: // partial cycle num  2
        setr4h2Text(set_value);
        break;
    case 0x545: // partial cycle num  3
        setr4h3Text(set_value);
        break;
    case 0x555:// partial cycle num  4
        setr4h4Text(set_value);
        break;
    default:break;
    }
}

void Program_Loop::refreshPgmLoopInterfaceData()
{

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
