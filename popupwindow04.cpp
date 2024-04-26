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
    //初始化
    map.insert(mapIndex++,"@Viola");
    map.insert(mapIndex++,"@Linne");
    this->changeLabelID(endNumber);

    //qss
    QFile file(":/qss/popupwindow04.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();
}

PopUpWindow04::~PopUpWindow04()
{
    delete ui;
}

void PopUpWindow04::on_back_pbtn_clicked()
{
    this->close();
}


void PopUpWindow04::on_pervious_page_pbtn_clicked()
{
    if(endNumber==30)
        endNumber=100;
    else if(endNumber==100)
        endNumber=90;
    else
        endNumber-=30;
    this->changeLabelID(endNumber);
}

void PopUpWindow04::changeLabelID(int endNum){
    if(endNum!=100){
        ui->label_name_30->setText(this->checkMap(endNum));
        ui->label_id_30->setText(QString::number(endNum--));
        ui->label_name_29->setText(this->checkMap(endNum));
        ui->label_id_29->setText(QString::number(endNum--));
        ui->label_name_28->setText(this->checkMap(endNum));
        ui->label_id_28->setText(QString::number(endNum--));
        ui->label_name_27->setText(this->checkMap(endNum));
        ui->label_id_27->setText(QString::number(endNum--));
        ui->label_name_26->setText(this->checkMap(endNum));
        ui->label_id_26->setText(QString::number(endNum--));
        ui->label_name_25->setText(this->checkMap(endNum));
        ui->label_id_25->setText(QString::number(endNum--));
        ui->label_name_24->setText(this->checkMap(endNum));
        ui->label_id_24->setText(QString::number(endNum--));
        ui->label_name_23->setText(this->checkMap(endNum));
        ui->label_id_23->setText(QString::number(endNum--));
        ui->label_name_22->setText(this->checkMap(endNum));
        ui->label_id_22->setText(QString::number(endNum--));
        ui->label_name_21->setText(this->checkMap(endNum));
        ui->label_id_21->setText(QString::number(endNum--));
        ui->label_name_20->setText(this->checkMap(endNum));
        ui->label_id_20->setText(QString::number(endNum--));
        ui->label_name_19->setText(this->checkMap(endNum));
        ui->label_id_19->setText(QString::number(endNum--));
        ui->label_name_18->setText(this->checkMap(endNum));
        ui->label_id_18->setText(QString::number(endNum--));
        ui->label_name_17->setText(this->checkMap(endNum));
        ui->label_id_17->setText(QString::number(endNum--));
        ui->label_name_16->setText(this->checkMap(endNum));
        ui->label_id_16->setText(QString::number(endNum--));
        ui->label_name_15->setText(this->checkMap(endNum));
        ui->label_id_15->setText(QString::number(endNum--));
        ui->label_name_14->setText(this->checkMap(endNum));
        ui->label_id_14->setText(QString::number(endNum--));
        ui->label_name_13->setText(this->checkMap(endNum));
        ui->label_id_13->setText(QString::number(endNum--));
        ui->label_name_12->setText(this->checkMap(endNum));
        ui->label_id_12->setText(QString::number(endNum--));
        ui->label_name_11->setText(this->checkMap(endNum));
        ui->label_id_11->setText(QString::number(endNum--));
        ui->label_name_10->setText(this->checkMap(endNum));
        ui->label_id_10->setText(QString::number(endNum--));
        ui->label_name_9->setText(this->checkMap(endNum));
        ui->label_id_9->setText(QString::number(endNum--));
        ui->label_name_8->setText(this->checkMap(endNum));
        ui->label_id_8->setText(QString::number(endNum--));
        ui->label_name_7->setText(this->checkMap(endNum));
        ui->label_id_7->setText(QString::number(endNum--));
        ui->label_name_6->setText(this->checkMap(endNum));
        ui->label_id_6->setText(QString::number(endNum--));
        ui->label_name_5->setText(this->checkMap(endNum));
        ui->label_id_5->setText(QString::number(endNum--));
        ui->label_name_4->setText(this->checkMap(endNum));
        ui->label_id_4->setText(QString::number(endNum--));
        ui->label_name_3->setText(this->checkMap(endNum));
        ui->label_id_3->setText(QString::number(endNum--));
        ui->label_name_2->setText(this->checkMap(endNum));
        ui->label_id_2->setText(QString::number(endNum--));
        ui->label_name_1->setText(this->checkMap(endNum));
        ui->label_id_1->setText(QString::number(endNum--));
    }
    else{
        ui->label_name_30->setText("");
        ui->label_id_30->setText("0");
        ui->label_name_29->setText("");
        ui->label_id_29->setText("0");
        ui->label_name_28->setText("");
        ui->label_id_28->setText("0");
        ui->label_name_27->setText("");
        ui->label_id_27->setText("0");
        ui->label_name_26->setText("");
        ui->label_id_26->setText("0");
        ui->label_name_25->setText("");
        ui->label_id_25->setText("0");
        ui->label_name_24->setText("");
        ui->label_id_24->setText("0");
        ui->label_name_23->setText("");
        ui->label_id_23->setText("0");
        ui->label_name_22->setText("");
        ui->label_id_22->setText("0");
        ui->label_name_21->setText("");
        ui->label_id_21->setText("0");
        ui->label_name_20->setText("");
        ui->label_id_20->setText("0");
        ui->label_name_19->setText("");
        ui->label_id_19->setText("0");
        ui->label_name_18->setText("");
        ui->label_id_18->setText("0");
        ui->label_name_17->setText("");
        ui->label_id_17->setText("0");
        ui->label_name_16->setText("");
        ui->label_id_16->setText("0");
        ui->label_name_15->setText("");
        ui->label_id_15->setText("0");
        ui->label_name_14->setText("");
        ui->label_id_14->setText("0");
        ui->label_name_13->setText("");
        ui->label_id_13->setText("0");
        ui->label_name_12->setText("");
        ui->label_id_12->setText("0");
        ui->label_name_11->setText("");
        ui->label_id_11->setText("0");
        ui->label_name_10->setText(this->checkMap(endNum));
        ui->label_id_10->setText(QString::number(endNum--));
        ui->label_name_9->setText(this->checkMap(endNum));
        ui->label_id_9->setText(QString::number(endNum--));
        ui->label_name_8->setText(this->checkMap(endNum));
        ui->label_id_8->setText(QString::number(endNum--));
        ui->label_name_7->setText(this->checkMap(endNum));
        ui->label_id_7->setText(QString::number(endNum--));
        ui->label_name_6->setText(this->checkMap(endNum));
        ui->label_id_6->setText(QString::number(endNum--));
        ui->label_name_5->setText(this->checkMap(endNum));
        ui->label_id_5->setText(QString::number(endNum--));
        ui->label_name_4->setText(this->checkMap(endNum));
        ui->label_id_4->setText(QString::number(endNum--));
        ui->label_name_3->setText(this->checkMap(endNum));
        ui->label_id_3->setText(QString::number(endNum--));
        ui->label_name_2->setText(this->checkMap(endNum));
        ui->label_id_2->setText(QString::number(endNum--));
        ui->label_name_1->setText(this->checkMap(endNum));
        ui->label_id_1->setText(QString::number(endNum--));
    }
}

void PopUpWindow04::on_next_page_pbtn_clicked()
{
    if(endNumber==100)
        endNumber=30;
    else if(endNumber==90)
        endNumber=100;
    else
        endNumber+=30;
    this->changeLabelID(endNumber);
}

QString PopUpWindow04::checkMap(int index){
    if(map.value(index)!=""){
        return map.value(index);
    }
    else
        return "";
}

void PopUpWindow04::on_pushButton_1_clicked()
{
    if(status == 0)
    {
        QString Name = ui->label_name_1->text();
        if(Name!=""){            
            emit touch_InterfaceDataSignal(0xB00, QString::number(0xB01));
            this->close();
        }        
    }    
}


void PopUpWindow04::on_pushButton_2_clicked()
{
    if(status == 0)
    {
        QString Name = ui->label_name_2->text();
        if(Name!=""){
            emit touch_InterfaceDataSignal(0xB00, QString::number(0xB02));
            this->close();
        }        
    }    
}


void PopUpWindow04::on_pushButton_3_clicked()
{
    if(status == 0)
    {
        QString Name = ui->label_name_3->text();
        if(Name!=""){
            emit touch_InterfaceDataSignal(0xB00, QString::number(0xB03));
            this->close();
        }
    }    
}


void PopUpWindow04::on_pushButton_4_clicked()
{
    if(status == 0)
    {
        QString Name = ui->label_name_4->text();
        if(Name!=""){
            emit touch_InterfaceDataSignal(0xB00, QString::number(0xB04));
            this->close();
        }        
    }
}


void PopUpWindow04::on_pushButton_5_clicked()
{
    if(status == 0)
    {
        QString Name = ui->label_name_5->text();
        if(Name!=""){
            emit touch_InterfaceDataSignal(0xB00, QString::number(0xB05));
            this->close();
        }
     }
}


void PopUpWindow04::on_pushButton_6_clicked()
{
    QString Name = ui->label_name_6->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB06));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_7_clicked()
{
    QString Name = ui->label_name_7->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB07));

        this->close();
    }    
}


void PopUpWindow04::on_pushButton_8_clicked()
{
    QString Name = ui->label_name_8->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB08));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_9_clicked()
{
    QString Name = ui->label_name_9->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB09));
        this->close();
    }

}


void PopUpWindow04::on_pushButton_10_clicked()
{
    QString Name = ui->label_name_10->text();
    if(Name!=""){
       emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0A));
        this->close();
    }

}


void PopUpWindow04::on_pushButton_11_clicked()
{
    QString Name = ui->label_name_11->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0B));
        this->close();
    }

}


void PopUpWindow04::on_pushButton_12_clicked()
{
    QString Name = ui->label_name_12->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0C));
        this->close();
    }   
}


void PopUpWindow04::on_pushButton_13_clicked()
{
    QString Name = ui->label_name_13->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0D));
        this->close();
    }   
}


void PopUpWindow04::on_pushButton_14_clicked()
{
    QString Name = ui->label_name_14->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0E));
        this->close();
    }   
}


void PopUpWindow04::on_pushButton_15_clicked()
{
    QString Name = ui->label_name_15->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB0F));
        this->close();
    }    
}


void PopUpWindow04::on_pushButton_16_clicked()
{
    QString Name = ui->label_name_16->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB10));
        this->close();
    }    
}


void PopUpWindow04::on_pushButton_17_clicked()
{
    QString Name = ui->label_name_17->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB11));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_18_clicked()
{
    QString Name = ui->label_name_18->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB12));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_19_clicked()
{
    QString Name = ui->label_name_19->text();
    if(Name!=""){
       emit touch_InterfaceDataSignal(0xB00, QString::number(0xB13));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_20_clicked()
{
    QString Name = ui->label_name_20->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB14));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_21_clicked()
{
    QString Name = ui->label_name_21->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB15));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_22_clicked()
{
    QString Name = ui->label_name_22->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB16));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_23_clicked()
{
    QString Name = ui->label_name_23->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB17));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_24_clicked()
{
    QString Name = ui->label_name_24->text();
    if(Name!=""){
       emit touch_InterfaceDataSignal(0xB00, QString::number(0xB18));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_25_clicked()
{
    QString Name = ui->label_name_25->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB19));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_26_clicked()
{
    QString Name = ui->label_name_26->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB1A));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_27_clicked()
{
    QString Name = ui->label_name_27->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB1B));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_28_clicked()
{
    QString Name = ui->label_name_28->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB1C));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_29_clicked()
{
    QString Name = ui->label_name_29->text();
    if(Name!=""){
       emit touch_InterfaceDataSignal(0xB00, QString::number(0xB1D));
        this->close();
    }
}


void PopUpWindow04::on_pushButton_30_clicked()
{
    QString Name = ui->label_name_30->text();
    if(Name!=""){
        emit touch_InterfaceDataSignal(0xB00, QString::number(0xB1E));
        this->close();
    }
}

void PopUpWindow04::setStatus(int num)
{
    this->status = num;
}

int PopUpWindow04::getStatus()
{
    return this->status;
}

void PopUpWindow04::insertMap(QString Name)
{
    map.insert(mapIndex++,Name);
}

int PopUpWindow04::getMapIndex()
{
    return mapIndex;
}

int PopUpWindow04::getEndNumber(){
    return endNumber;
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


