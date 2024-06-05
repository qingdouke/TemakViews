#include "error_log.h"
#include "ui_error_log.h"
#include "address_data_show.h"
#include "general_tools.h"
#include "mainwindow.h"
#include <QTimer>
#include <QDateTime>

Error_Log::Error_Log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Error_Log)
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

    //line
    ui->line_1->setStyleSheet("QLabel#line_1{background-color:rgb(150,150,150)}");
    ui->line_2->setStyleSheet("QLabel#line_2{background-color:rgb(150,150,150)}");
    ui->line_3->setStyleSheet("QLabel#line_3{background-color:rgb(150,150,150)}");
    ui->line_4->setStyleSheet("QLabel#line_4{background-color:rgb(150,150,150)}");
    ui->line_5->setStyleSheet("QLabel#line_5{background-color:rgb(150,150,150)}");
    ui->line_6->setStyleSheet("QLabel#line_6{background-color:rgb(150,150,150)}");
    ui->line_7->setStyleSheet("QLabel#line_7{background-color:rgb(150,150,150)}");
    ui->line_8->setStyleSheet("QLabel#line_8{background-color:rgb(150,150,150)}");
    ui->line_9->setStyleSheet("QLabel#line_9{background-color:rgb(150,150,150)}");

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    /*ui->font_page_pbtn->setStyleSheet("QPushButton#font_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->clear_log_pbtn->setStyleSheet("QPushButton#clear_log_pbtn{border:2px solid rgb(74,122,60);"
                                  "background-color:rgb(173,199,160);"
                                  "border-radius:8px;"
                                  "color:rgb(74,122,60)}");
    ui->saving_pbtn->setStyleSheet("QPushButton#saving_pbtn{border:2px solid rgb(74,122,60);"
                                                   "background-color:rgb(173,199,160);"
                                                   "border-radius:8px;"
                                                   "color:rgb(74,122,60)}");*/

    //ui->current_time的connect 显示实时时间
    connect(timer,&QTimer::timeout,this,&Error_Log::currentTime);

    connect(ui->font_page_pbtn,&QPushButton::clicked,this,&Error_Log::errorLog_sendTo_mainWindow);

}

Error_Log::~Error_Log()
{
    delete ui;
}

/*
 * time: 2022-11-21
 * type: private slots
 * effect: 每秒更新一次当前时间
 * influence: ui->current_time
*/
void Error_Log::currentTime(){
    QDateTime datetime = QDateTime::currentDateTime();
    QString datetimestrs = datetime.toString("yyyy-MM-dd hh:mm:ss");
    ui->current_time->setText(datetimestrs);
}

/*
 * time: 2022-11-21
 * type: send Signals
 * effect: 信号发送函数 向mainwindow发送请求页面跳转信号
 * influence: this
*/
void Error_Log::errorLog_sendTo_mainWindow(){
    emit errorLog_to_mainWindow();
}

void Error_Log::addrSetErrLogInterfaceData(int addr_num, QString set_value){

    QString covert_data;
    switch(addr_num)
    {
    // set program id show
    case 0xA90:
        ui->SysTypeText_label->setText(set_value);
        break;
    case 0xAA0:
        ui->VersionText_label->setText(set_value);
        break;
    case 0xA10:
        err_time_1 = set_value;
        err_time = err_time_1 + err_time_mid + err_time_2;
        ui->ErrcodeText_label->setText(err_time);
        break;
    case 0xA0E:
        err_time_mid = set_value;
        err_time = err_time_1 + err_time_mid + err_time_2;
        ui->ErrcodeText_label->setText(err_time);
        break;
    case 0xA22:
        err_time_2 = set_value;
        err_time = err_time_1 + err_time_mid + err_time_2;
        ui->ErrcodeText_label->setText(err_time);
        break;
    case 0xA61:
        err_code_1 = set_value;
        err_code = err_code_1 + err_code_2;
        ui->ErrcodeText_label->setText(err_code);
        break;
    case 0xA80:
        err_code_2 = set_value;
        err_code = err_code_1 + err_code_2;
        ui->ErrcodeText_label->setText(err_code);
        break;
    case 0xAB0:
        ui->LastTimeText_label->setText(set_value);
        break;
    case 0xA70:
        ui->StaText_label->setText(set_value);
        break;
    case 0xA42:
        ui->CycText_label->setText(set_value);
        break;
    case 0xA43:
        ui->LinkText_label->setText(set_value);
        break;
    case 0xA30:
        ui->PgmText_label->setText(set_value);
        break;
    case 0xA44:
        freetime_1 = set_value;
        freetime = freetime_1 + freetime_2;
        ui->FreetimeText_label->setText(freetime);
        break;
    case 0xA45:
        freetime_2 = set_value;
        freetime = freetime_1 + freetime_2;
        ui->FreetimeText_label->setText(freetime);
        break;
    case 0xA40:
        ui->Step_label_1->setText(set_value);
        break;
    case 0xA41:
        ui->Step_label_2->setText(set_value);
        break;
    case 0xA03:
        covert_data = convertToDecimalString(set_value,2);
        ui->value1_label_1->setText(covert_data);
        break;
    case 0xA04:
        covert_data = convertToDecimalString(set_value,1);
        ui->value2_label_1->setText(covert_data);
        break;
    case 0xA05:
        ui->hour_label_1->setText(set_value);
        break;
    case 0xA06:
        ui->min_label_1->setText(set_value);
        break;
    case 0xA07:
        ui->sec_label_1->setText(set_value);
        break;
    case 0xA08:
        ui->ts1_label_1->setText(set_value);
        break;
    case 0xA09:
        ui->ts2_label_1->setText(set_value);
        break;
    case 0xA0A:
        ui->ts3_label_1->setText(set_value);
        break;
    case 0xA0B:
        ui->wt_label_1->setText(set_value);
        break;
    case 0xA53:
        covert_data = convertToDecimalString(set_value,2);
        ui->value1_label_2->setText(covert_data);
        break;
    case 0xA54:
        covert_data = convertToDecimalString(set_value,1);
        ui->value2_label_2->setText(covert_data);
        break;
    case 0xA55:
        ui->hour_label_2->setText(set_value);
        break;
    case 0xA56:
        ui->min_label_2->setText(set_value);
        break;
    case 0xA57:
        ui->sec_label_2->setText(set_value);
        break;
    case 0xA58:
        ui->ts1_label_2->setText(set_value);
        break;
    case 0xA59:
        ui->ts2_label_2->setText(set_value);
        break;
    case 0xA5A:
        ui->ts3_label_2->setText(set_value);
        break;
    case 0xA5B:
        ui->wt_label_2->setText(set_value);
        break;
    case 0xA46:
        covert_data = convertToDecimalString(set_value,2);
        ui->HilimitText_label->setText(covert_data);
        break;
    case 0xA47:
        covert_data = convertToDecimalString(set_value,2);
        ui->LolimitText_label->setText(covert_data);
        break;
    case 0xA48:
        covert_data = convertToDecimalString(set_value,2);
        ui->TpvText_label->setText(covert_data);
        break;
    case 0xA4B:
        covert_data = convertToDecimalString(set_value,2);
        ui->TsvText_label->setText(covert_data);
        break;
    case 0xA49:
        covert_data = convertToDecimalString(set_value,2);
        ui->HpvText_label->setText(covert_data);
        break;
    case 0xA4C:
        covert_data = convertToDecimalString(set_value,2);
        ui->HsvText_label->setText(covert_data);
        break;
    case 0xA4A:
        covert_data = convertToDecimalString(set_value,2);
        ui->WpvText_label->setText(covert_data);
        break;
    case 0xA4D:
        covert_data = convertToDecimalString(set_value,2);
        ui->WsvText_label->setText(covert_data);
        break;
    case 0xAC0:
        out_1 = set_value;
        out = out_1 + out_2 + out_3;
        ui->OutText_label->setText(out);
        break;
    case 0xAD0:
        out_2 = set_value;
        out = out_1 + out_2 + out_3;
        ui->OutText_label->setText(out);
        break;
    case 0xAE0:
        out_3 = set_value;
        out = out_1 + out_2 + out_3;
        ui->OutText_label->setText(out);
        break;
    case 0xA4E:
        covert_data = convertToDecimalString(set_value,2);
        ui->TempPidText_label->setText(covert_data);
        break;
    case 0xA4F:
        covert_data = convertToDecimalString(set_value,2);
        ui->HumiPidText_label->setText(covert_data);
        break;
    case 0xA50:
        covert_data = convertToDecimalString(set_value,2);
        ui->SvrPidText_label->setText(covert_data);
        break;
    case 0xA51:
        page_1 = set_value;
        page = page_1 + "/" +page_2;
        ui->PageText_label->setText(set_value);
        break;
    case 0xA52:
        page_2 = set_value;
        page = page_1 + "/" +page_2;
        ui->PageText_label->setText(set_value);
        break;
    default:break;
    }
}

void Error_Log::on_LastPage_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(0xA00,"1");
}

void Error_Log::on_NextPage_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(0xA00,"2");
}

void Error_Log::on_clear_log_pbtn_clicked()
{
    emit Request_Use_Keyboard_Signal(0xA01);
}

void Error_Log::on_saving_pbtn_clicked()
{
     emit touch_InterfaceDataSignal(0xA02,"2");
}
void Error_Log::refreshErrorLogInterfaceData()
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
