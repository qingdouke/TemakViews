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
    //qDebug () << "[" << __FILE__ << ":" << __LINE__ << "]" ;
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
    /*ui->back_pbtn->setStyleSheet("QPushButton#back_pbtn{border:2px solid rgb(74,122,60);"
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
                                          "color:rgb(74,122,60)}");*/
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
        label_id[1] = set_value;
        break;
    case 0xB02:
        label_id[2] = set_value;
        break;
    case 0xB03:
        label_id[3] = set_value;
        break;
    case 0xB04:
        label_id[4] = set_value;
        break;
    case 0xB05:
        label_id[5] = set_value;
        break;
    case 0xB06:
        label_id[6] = set_value;
        break;
    case 0xB07:
        label_id[7] = set_value;
        break;
    case 0xB08:
        label_id[8] = set_value;
        break;
    case 0xB09:
        label_id[9] = set_value;
        break;
    case 0xB0A:
        label_id[10] = set_value;
        break;
    case 0xB0B:
        label_id[11] = set_value;
        break;
    case 0xB0C:
        label_id[12] = set_value;
        break;
    case 0xB0D:
        label_id[13] = set_value;
        break;
    case 0xB0E:
        label_id[14] = set_value;
        break;
    case 0xB0F:
        label_id[15] = set_value;
        break;
    case 0xB10:
        label_id[16] = set_value;
        break;
    case 0xB11:
        label_id[17] = set_value;
        break;
    case 0xB12:
        label_id[18] = set_value;
        break;
    case 0xB13:
        label_id[19] = set_value;
        break;
    case 0xB14:
        label_id[20] = set_value;
        break;
    case 0xB15:
        label_id[21] = set_value;
        break;
    case 0xB16:
        label_id[22] = set_value;
        break;
    case 0xB17:
        label_id[23] = set_value;
        break;
    case 0xB18:
        label_id[24] = set_value;
        break;
    case 0xB19:
        label_id[25] = set_value;
        break;
    case 0xB1A:
        label_id[26] = set_value;
        break;
    case 0xB1B:
        label_id[27] = set_value;
        break;
    case 0xB1C:
        label_id[28] = set_value;
        break;
    case 0xB1D:
        label_id[29] = set_value;
        break;
    case 0xB1E:
        label_id[30] = set_value;
        break;
    // set program name show
    case 0xB20:
       label_name[1] = set_value;
        break;
    case 0xB30:
       label_name[2] = set_value;
        break;
    case 0xB40:
       label_name[3] = set_value;
        break;
    case 0xB50:
       label_name[4] = set_value;
        break;
    case 0xB60:
       label_name[5] = set_value;
        break;
    case 0xB70:
       label_name[6] = set_value;
        break;
    case 0xB80:
       label_name[7] = set_value;
        break;
    case 0xB90:
       label_name[8] = set_value;
        break;
    case 0xBA0:
       label_name[9] = set_value;
        break;
    case 0xBB0:
       label_name[10] = set_value;
        break;
    case 0xBC0:
       label_name[11] = set_value;
        break;
    case 0xBD0:
       label_name[12] = set_value;
        break;
    case 0xBE0:
       label_name[13] = set_value;
        break;
    case 0xBF0:
       label_name[14] = set_value;
        break;
    case 0xC00:
       label_name[15] = set_value;
        break;
    case 0xC10:
       label_name[16] = set_value;
        break;
    case 0xC20:
       label_name[17] = set_value;
        break;
    case 0xC30:
       label_name[18] = set_value;
        break;
    case 0xC40:
       label_name[19] = set_value;
        break;
    case 0xC50:
       label_name[20] = set_value;
        break;
    case 0xC60:
       label_name[21] = set_value;
        break;
    case 0xC70:
       label_name[22] = set_value;
        break;
    case 0xC80:
       label_name[23] = set_value;
        break;
    case 0xC90:
       label_name[24] = set_value;
        break;
    case 0xCA0:
       label_name[25] = set_value;
        break;
    case 0xCB0:
       label_name[26] = set_value;
        break;
    case 0xCC0:
       label_name[27] = set_value;
        break;
    case 0xCD0:
       label_name[28] = set_value;
        break;
    case 0xCE0:
       label_name[29] = set_value;
        break;
    case 0xCF0:
       label_name[30] = set_value;
        break;

    default:break;
    }
}
//刷新页面显示数据
void PopUpWindow04::refreshOutPutInterfaceData()
{

    ui->label_id_1->setText(label_id[1]);
    ui->label_id_2->setText(label_id[2]);
    ui->label_id_3->setText(label_id[3]);
    ui->label_id_4->setText(label_id[4]);
    ui->label_id_5->setText(label_id[5]);
    ui->label_id_6->setText(label_id[6]);
    ui->label_id_7->setText(label_id[7]);
    ui->label_id_8->setText(label_id[8]);
    ui->label_id_9->setText(label_id[9]);
    ui->label_id_10->setText(label_id[10]);
    ui->label_id_11->setText(label_id[11]);
    ui->label_id_12->setText(label_id[12]);
    ui->label_id_13->setText(label_id[13]);
    ui->label_id_14->setText(label_id[14]);
    ui->label_id_15->setText(label_id[15]);
    ui->label_id_16->setText(label_id[16]);
    ui->label_id_17->setText(label_id[17]);
    ui->label_id_18->setText(label_id[18]);
    ui->label_id_19->setText(label_id[19]);
    ui->label_id_20->setText(label_id[20]);
    ui->label_id_21->setText(label_id[21]);
    ui->label_id_22->setText(label_id[22]);
    ui->label_id_23->setText(label_id[23]);
    ui->label_id_24->setText(label_id[24]);
    ui->label_id_25->setText(label_id[25]);
    ui->label_id_26->setText(label_id[26]);
    ui->label_id_27->setText(label_id[27]);
    ui->label_id_28->setText(label_id[28]);
    ui->label_id_29->setText(label_id[29]);
    ui->label_id_30->setText(label_id[30]);

     // set program name show
    ui->label_name_1->setText(label_name[1]);
    ui->label_name_2->setText(label_name[2]);
    ui->label_name_3->setText(label_name[3]);
    ui->label_name_4->setText(label_name[4]);
    ui->label_name_5->setText(label_name[5]);
    ui->label_name_6->setText(label_name[6]);
    ui->label_name_7->setText(label_name[7]);
    ui->label_name_8->setText(label_name[8]);
    ui->label_name_9->setText(label_name[9]);
    ui->label_name_10->setText(label_name[10]);
    ui->label_name_11->setText(label_name[11]);
    ui->label_name_12->setText(label_name[12]);
    ui->label_name_13->setText(label_name[13]);
    ui->label_name_14->setText(label_name[14]);
    ui->label_name_15->setText(label_name[15]);
    ui->label_name_16->setText(label_name[16]);
    ui->label_name_17->setText(label_name[17]);
    ui->label_name_18->setText(label_name[18]);
    ui->label_name_19->setText(label_name[19]);
    ui->label_name_20->setText(label_name[20]);
    ui->label_name_21->setText(label_name[21]);
    ui->label_name_22->setText(label_name[22]);
    ui->label_name_23->setText(label_name[23]);
    ui->label_name_24->setText(label_name[24]);
    ui->label_name_25->setText(label_name[25]);
    ui->label_name_26->setText(label_name[26]);
    ui->label_name_27->setText(label_name[27]);
    ui->label_name_28->setText(label_name[28]);
    ui->label_name_29->setText(label_name[29]);
    ui->label_name_30->setText(label_name[30]);
}



