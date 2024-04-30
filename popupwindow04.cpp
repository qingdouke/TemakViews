#include "popupwindow04.h"
#include "ui_popupwindow04.h"
#include <QTextStream>
#include <QDebug>

// 程序列表 选择程序
PopUpWindow04::PopUpWindow04(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopUpWindow04)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    //Header背景颜色
    qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;
    ui->Header->setStyleSheet("QWidget#Header{background-color:rgb(72,129,52)}");
    //标题颜色
    ui->title->setStyleSheet("QLabel#title{color:white}");
    //logo颜色
    ui->logo->setStyleSheet("QLabel#logo{background-image:url(:/Image/85/1.bmp)}");

    //Main背景颜色渐变
    ui->Main->setStyleSheet("QWidget#Main{background-color:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 white,stop:1 rgb(177,203,166))}");
    //program_selection_box
    ui->program_selection_box->setStyleSheet("QWidget#program_selection_box{background-color:white;"
                                             "border:3px solid rgb(72,129,52)}");
    ui->line_h_1->setStyleSheet("QLabel#line_h_1{background-color:rgb(72,129,52)}");
    ui->line_h_2->setStyleSheet("QLabel#line_h_2{background-color:rgb(72,129,52)}");
    ui->line_h_3->setStyleSheet("QLabel#line_h_3{background-color:rgb(72,129,52)}");
    ui->line_h_4->setStyleSheet("QLabel#line_h_4{background-color:rgb(72,129,52)}");
    ui->line_h_5->setStyleSheet("QLabel#line_h_5{background-color:rgb(72,129,52)}");
    ui->line_h_6->setStyleSheet("QLabel#line_h_6{background-color:rgb(72,129,52)}");
    ui->line_h_7->setStyleSheet("QLabel#line_h_7{background-color:rgb(72,129,52)}");
    ui->line_h_8->setStyleSheet("QLabel#line_h_8{background-color:rgb(72,129,52)}");
    ui->line_h_9->setStyleSheet("QLabel#line_h_9{background-color:rgb(72,129,52)}");
    ui->line_h_10->setStyleSheet("QLabel#line_h_10{background-color:rgb(72,129,52)}");
    ui->line_v_1->setStyleSheet("QLabel#line_v_1{background-color:rgb(72,129,52)}");
    ui->line_v_2->setStyleSheet("QLabel#line_v_2{background-color:rgb(72,129,52)}");
    ui->line_v_3->setStyleSheet("QLabel#line_v_3{background-color:rgb(72,129,52)}");
    ui->line_v_4->setStyleSheet("QLabel#line_v_4{background-color:rgb(72,129,52)}");
    ui->line_v_5->setStyleSheet("QLabel#line_v_5{background-color:rgb(72,129,52)}");

    //Footer
    ui->Footer->setStyleSheet("QWidget#Footer{background-color:rgb(171,199,158)}");
    ui->footer_line->setStyleSheet("QLabel#footer_line{background-color:rgb(74,122,60)}");
    ui->back_pbtn->setStyleSheet("QPushButton#back_pbtn{border:2px solid rgb(74,122,60);"
                                 "background-color:rgb(173,199,160);"
                                 "border-radius:8px;"
                                 "color:rgb(74,122,60)}");
    ui->next_page_pbtn->setStyleSheet("QPushButton#next_page_pbtn{border:2px solid rgb(74,122,60);"
                                      "background-color:rgb(173,199,160);"
                                      "border-radius:8px;"
                                      "color:rgb(74,122,60)}");
    ui->pervious_page_pbtn->setStyleSheet("QPushButton#pervious_page_pbtn{border:2px solid rgb(74,122,60);"
                                          "background-color:rgb(173,199,160);"
                                          "border-radius:8px;"
                                          "color:rgb(74,122,60)}");
    qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;
    ui->label_id_1->installEventFilter(this);
    ui->label_name_1->installEventFilter(this);
    ui->label_id_2->installEventFilter(this);
    ui->label_name_2->installEventFilter(this);
    ui->label_id_3->installEventFilter(this);
    ui->label_name_3->installEventFilter(this);
    ui->label_id_4->installEventFilter(this);
    ui->label_name_4->installEventFilter(this);
    ui->label_id_5->installEventFilter(this);
    ui->label_name_5->installEventFilter(this);
    ui->label_id_6->installEventFilter(this);
    ui->label_name_6->installEventFilter(this);
    ui->label_id_7->installEventFilter(this);
    ui->label_name_7->installEventFilter(this);
    ui->label_id_8->installEventFilter(this);
    ui->label_name_8->installEventFilter(this);
    ui->label_id_9->installEventFilter(this);
    ui->label_name_9->installEventFilter(this);
    ui->label_id_10->installEventFilter(this);
    ui->label_name_10->installEventFilter(this);

    ui->label_id_11->installEventFilter(this);
    ui->label_name_11->installEventFilter(this);
    ui->label_id_12->installEventFilter(this);
    ui->label_name_12->installEventFilter(this);
    ui->label_id_13->installEventFilter(this);
    ui->label_name_13->installEventFilter(this);
    ui->label_id_14->installEventFilter(this);
    ui->label_name_14->installEventFilter(this);
    ui->label_id_15->installEventFilter(this);
    ui->label_name_15->installEventFilter(this);
    ui->label_id_16->installEventFilter(this);
    ui->label_name_16->installEventFilter(this);
    ui->label_id_17->installEventFilter(this);
    ui->label_name_17->installEventFilter(this);
    ui->label_id_18->installEventFilter(this);
    ui->label_name_18->installEventFilter(this);
    ui->label_id_19->installEventFilter(this);
    ui->label_name_19->installEventFilter(this);
    ui->label_id_20->installEventFilter(this);
    ui->label_name_20->installEventFilter(this);

    ui->label_id_21->installEventFilter(this);
    ui->label_name_21->installEventFilter(this);
    ui->label_id_22->installEventFilter(this);
    ui->label_name_22->installEventFilter(this);
    ui->label_id_23->installEventFilter(this);
    ui->label_name_23->installEventFilter(this);
    ui->label_id_24->installEventFilter(this);
    ui->label_name_24->installEventFilter(this);
    ui->label_id_25->installEventFilter(this);
    ui->label_name_25->installEventFilter(this);
    ui->label_id_26->installEventFilter(this);
    ui->label_name_26->installEventFilter(this);
    ui->label_id_27->installEventFilter(this);
    ui->label_name_27->installEventFilter(this);
    ui->label_id_28->installEventFilter(this);
    ui->label_name_28->installEventFilter(this);
    ui->label_id_29->installEventFilter(this);
    ui->label_name_29->installEventFilter(this);
    ui->label_id_30->installEventFilter(this);
    ui->label_name_30->installEventFilter(this);
    this->installEventFilter(this);
    //qss
   /* QFile file(":/qss/popupwindow04.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();*/
}

PopUpWindow04::~PopUpWindow04()
{
    delete ui;
}


bool PopUpWindow04::eventFilter(QObject *watched, QEvent *event)
{
    //监听屏幕点击事件
    if(watched == this)
    {
        //处理点击屏幕时的焦点问题
        if(event->type() == QEvent::MouseButtonPress){
            if(ui->label_name_1->hasFocus()){
                ui->label_name_1->clearFocus();//如果点击屏幕任意位置则取消对应lineEdit的聚焦
            }
        }
    }
        //监听lineEdit
        if((watched == ui->label_id_1) || (watched == ui->label_name_1))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB01));
            }
        }else if((watched == ui->label_id_2) || (watched == ui->label_name_2))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB02));
            }
        }else if((watched == ui->label_id_3) || (watched == ui->label_name_3))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB03));
            }
        }else if((watched == ui->label_id_4) || (watched == ui->label_name_4))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB04));
            }
        }else if((watched == ui->label_id_5) || (watched == ui->label_name_5))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB05));
            }
        }else if((watched == ui->label_id_6) || (watched == ui->label_name_6))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB06));
            }
        }else if((watched == ui->label_id_7) || (watched == ui->label_name_7))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB07));
            }
        }else if((watched == ui->label_id_8) || (watched == ui->label_name_8))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB08));
            }
        }else if((watched == ui->label_id_9) || (watched == ui->label_name_9))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB09));
            }
        }else if((watched == ui->label_id_10) || (watched == ui->label_name_10))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0A));
            }
        }else if((watched == ui->label_id_11) || (watched == ui->label_name_11))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0B));
            }
        }else if((watched == ui->label_id_12) || (watched == ui->label_name_12))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0C));
            }
        }else if((watched == ui->label_id_13) || (watched == ui->label_name_13))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0D));
            }
        }else if((watched == ui->label_id_14) || (watched == ui->label_name_14))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0E));
            }
        }else if((watched == ui->label_id_15) || (watched == ui->label_name_15))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0F));
            }
        }else if((watched == ui->label_id_16) || (watched == ui->label_name_16))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB10));
            }
        }else if((watched == ui->label_id_17) || (watched == ui->label_name_17))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB11));
            }
        }else if((watched == ui->label_id_18) || (watched == ui->label_name_18))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB12));
            }
        }else if((watched == ui->label_id_19) || (watched == ui->label_name_19))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB13));
            }
        }else if((watched == ui->label_id_20) || (watched == ui->label_name_20))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB14));
            }
        }else if((watched == ui->label_id_21) || (watched == ui->label_name_21))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB15));
            }
        }else if((watched == ui->label_id_22) || (watched == ui->label_name_22))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB16));
            }
        }else if((watched == ui->label_id_23) || (watched == ui->label_name_23))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB17));
            }
        }else if((watched == ui->label_id_24) || (watched == ui->label_name_24))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB18));
            }
        }else if((watched == ui->label_id_25) || (watched == ui->label_name_25))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB19));
            }
        }else if((watched == ui->label_id_26) || (watched == ui->label_name_26))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB1A));
            }
        }else if((watched == ui->label_id_27) || (watched == ui->label_name_27))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB1B));
            }
        }else if((watched == ui->label_id_28) || (watched == ui->label_name_28))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB1C));
            }
        }else if((watched == ui->label_id_29) || (watched == ui->label_name_29))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB1D));
            }
        }else if((watched == ui->label_id_30) || (watched == ui->label_name_30))
        {
            if(event->type() == QEvent::MouseButtonPress){
                emit touch_InterfaceDataSignal(0xB00, QString::number(0xB1E));
            }
        }
    return QWidget::eventFilter(watched,event);         //返回事件过滤器
}
void PopUpWindow04::on_back_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(0xB1F, "0");
}

void PopUpWindow04::on_pervious_page_pbtn_clicked()
{
    emit touch_InterfaceDataSignal(0xB1F, "1");
}
void PopUpWindow04::on_next_page_pbtn_clicked()
{
   emit touch_InterfaceDataSignal(0xB1F, "2");
}



void PopUpWindow04::addrSetPgmListInterfaceData(int addr_num, QString set_value){


    switch(addr_num)
    {
    // set program id show
    case 0xB01:
        ui->label_id_1->setText(set_value);
        break;
    case 0xB02:
        ui->label_id_2->setText(set_value);
        break;
    case 0xB03:
        ui->label_id_3->setText(set_value);
        break;
    case 0xB04:
        ui->label_id_4->setText(set_value);
        break;
    case 0xB05:
        ui->label_id_5->setText(set_value);
        break;
    case 0xB06:
        ui->label_id_6->setText(set_value);
        break;
    case 0xB07:
        ui->label_id_7->setText(set_value);
        break;
    case 0xB08:
        ui->label_id_8->setText(set_value);
        break;
    case 0xB09:
        ui->label_id_9->setText(set_value);
        break;
    case 0xB0A:
        ui->label_id_10->setText(set_value);
        break;
    case 0xB0B:
        ui->label_id_11->setText(set_value);
        break;
    case 0xB0C:
        ui->label_id_12->setText(set_value);
        break;
    case 0xB0D:
        ui->label_id_13->setText(set_value);
        break;
    case 0xB0E:
        ui->label_id_14->setText(set_value);
        break;
    case 0xB0F:
        ui->label_id_15->setText(set_value);
        break;
    case 0xB10:
        ui->label_id_16->setText(set_value);
        break;
    case 0xB11:
        ui->label_id_17->setText(set_value);
        break;
    case 0xB12:
        ui->label_id_18->setText(set_value);
        break;
    case 0xB13:
        ui->label_id_19->setText(set_value);
        break;
    case 0xB14:
        ui->label_id_20->setText(set_value);
        break;
    case 0xB15:
        ui->label_id_21->setText(set_value);
        break;
    case 0xB16:
        ui->label_id_22->setText(set_value);
        break;
    case 0xB17:
        ui->label_id_23->setText(set_value);
        break;
    case 0xB18:
        ui->label_id_24->setText(set_value);
        break;
    case 0xB19:
        ui->label_id_25->setText(set_value);
        break;
    case 0xB1A:
        ui->label_id_26->setText(set_value);
        break;
    case 0xB1B:
        ui->label_id_27->setText(set_value);
        break;
    case 0xB1C:
        ui->label_id_28->setText(set_value);
        break;
    case 0xB1D:
        ui->label_id_29->setText(set_value);
        break;
    case 0xB1E:
        ui->label_id_30->setText(set_value);
        break;
    // set program name show

    case 0xB20:
        ui->label_name_1->setText(set_value);
        break;
    case 0xB30:
        ui->label_name_2->setText(set_value);
        break;
    case 0xB40:
        ui->label_name_3->setText(set_value);
        break;
    case 0xB50:
        ui->label_name_4->setText(set_value);
        break;
    case 0xB60:
        ui->label_name_5->setText(set_value);
        break;
    case 0xB70:
        ui->label_name_6->setText(set_value);
        break;
    case 0xB80:
        ui->label_name_7->setText(set_value);
        break;
    case 0xB90:
        ui->label_name_8->setText(set_value);
        break;
    case 0xBA0:
        ui->label_name_9->setText(set_value);
        break;
    case 0xBB0:
        ui->label_name_10->setText(set_value);
        break;
    case 0xBC0:
        ui->label_name_11->setText(set_value);
        break;
    case 0xBD0:
        ui->label_name_12->setText(set_value);
        break;
    case 0xBE0:
        ui->label_name_13->setText(set_value);
        break;
    case 0xBF0:
        ui->label_name_14->setText(set_value);
        break;
    case 0xC00:
        ui->label_name_15->setText(set_value);
        break;
    case 0xC10:
        ui->label_name_16->setText(set_value);
        break;
    case 0xC20:
        ui->label_name_17->setText(set_value);
        break;
    case 0xC30:
        ui->label_name_18->setText(set_value);
        break;
    case 0xC40:
        ui->label_name_19->setText(set_value);
        break;
    case 0xC50:
        ui->label_name_20->setText(set_value);
        break;
    case 0xC60:
        ui->label_name_21->setText(set_value);
        break;
    case 0xC70:
        ui->label_name_22->setText(set_value);
        break;
    case 0xC80:
        ui->label_name_23->setText(set_value);
        break;
    case 0xC90:
        ui->label_name_24->setText(set_value);
        break;
    case 0xCA0:
        ui->label_name_25->setText(set_value);
        break;
    case 0xCB0:
        ui->label_name_26->setText(set_value);
        break;
    case 0xCC0:
        ui->label_name_27->setText(set_value);
        break;
    case 0xCD0:
        ui->label_name_28->setText(set_value);
        break;
    case 0xCE0:
        ui->label_name_29->setText(set_value);
        break;
    case 0xCF0:
        ui->label_name_30->setText(set_value);
        break;

    default:break;
    }
}


