#include "calculate.h"
#include "ui_calculate.h"

#include <QFile>
#include <QTextStream>
#include <QKeyEvent>

Calculate::Calculate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculate)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->background->setStyleSheet("QWidget#background{border-image:url(:/Image/icon/Calculater.bmp)}");

    QFile file(":/qss/keyboard_pBtn.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    ui->lineEdit->setStyleSheet("QLineEdit#lineEdit{background-color:transparent;border:none}");

    //处理按键事件
    connect(ui->pushButton_1,&QPushButton::clicked,this,&Calculate::pushButton_1_clicked);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Calculate::pushButton_2_clicked);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Calculate::pushButton_3_clicked);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&Calculate::pushButton_4_clicked);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&Calculate::pushButton_5_clicked);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&Calculate::pushButton_6_clicked);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&Calculate::pushButton_7_clicked);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&Calculate::pushButton_8_clicked);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&Calculate::pushButton_9_clicked);
    connect(ui->pushButton_0,&QPushButton::clicked,this,&Calculate::pushButton_0_clicked);
    connect(ui->pushButton_Minus,&QPushButton::clicked,this,&Calculate::pushButton_Minus_clicked);
    connect(ui->pushButton_Backspace,&QPushButton::clicked,this,&Calculate::pushButton_Backspace_clicked);
    connect(ui->pushButton_Esc,&QPushButton::clicked,this,&Calculate::pushButton_Esc_clicked);
    connect(ui->pushButton_Period,&QPushButton::clicked,this,&Calculate::pushButton_Period_clicked);
    connect(ui->pushButton_OK,&QPushButton::clicked,this,&Calculate::pushButton_OK_clicked);
}

Calculate::~Calculate()
{
    delete ui;
}

void Calculate::Clean_Calculater_LineEdit()
{
    ui->lineEdit->setText("");
}

void Calculate::pushButton_0_clicked()
{
    /*QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_0, Qt::NoModifier, QString("0"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_0, Qt::NoModifier, QString("0"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);*/
    QString strs_ = ui->lineEdit->text();
    strs_.append("0");
    ui->lineEdit->setText(strs_);

}

void Calculate::pushButton_1_clicked()
{
    /*QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_1, Qt::NoModifier, QString("1"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_1, Qt::NoModifier, QString("1"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);*/
    QString strs_ = ui->lineEdit->text();
    strs_.append("1");
    ui->lineEdit->setText(strs_);

}

void Calculate::pushButton_2_clicked()
{
    QString strs_ = ui->lineEdit->text();
    strs_.append("2");
    ui->lineEdit->setText(strs_);

}

void Calculate::pushButton_3_clicked()
{
    QString strs_ = ui->lineEdit->text();
    strs_.append("3");
    ui->lineEdit->setText(strs_);
}

void Calculate::pushButton_4_clicked()
{
    QString strs_ = ui->lineEdit->text();
    strs_.append("4");
    ui->lineEdit->setText(strs_);

}

void Calculate::pushButton_5_clicked()
{
    QString strs_ = ui->lineEdit->text();
    strs_.append("5");
    ui->lineEdit->setText(strs_);
}

void Calculate::pushButton_6_clicked()
{
    QString strs_ = ui->lineEdit->text();
    strs_.append("6");
    ui->lineEdit->setText(strs_);
}

void Calculate::pushButton_7_clicked()
{
    QString strs_ = ui->lineEdit->text();
    strs_.append("7");
    ui->lineEdit->setText(strs_);

}

void Calculate::pushButton_8_clicked()
{
    QString strs_ = ui->lineEdit->text();
    strs_.append("8");
    ui->lineEdit->setText(strs_);
}

void Calculate::pushButton_9_clicked()
{
    QString strs_ = ui->lineEdit->text();
    strs_.append("9");
    ui->lineEdit->setText(strs_);

}

void Calculate::pushButton_Esc_clicked()
{
    this->hide();
    this->Clean_Calculater_LineEdit();
}

void Calculate::pushButton_Period_clicked()
{
    /*QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Period, Qt::NoModifier, QString("."));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Period, Qt::NoModifier, QString("."));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);*/
    QString strs_ = ui->lineEdit->text();
    int startIndex = strs_.indexOf(".");
    {
        if (startIndex == -1) {
            strs_.append(".");
        }
    }
    ui->lineEdit->setText(strs_);
}

void Calculate::pushButton_Minus_clicked()
{
    //    QWidget *receiver = QApplication::focusWidget();
    //    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Minus, Qt::NoModifier, QString("-"));
    //    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Minus, Qt::NoModifier, QString("-"));
    //    QApplication::sendEvent(receiver, &keyPress);
    //    QApplication::sendEvent(receiver, &keyRelease);
    QString strs_;
    strs_ = ui->lineEdit->text();
    if(strs_!=""){
        if(strs_[0]!='-'){
            strs_.prepend('-');
        }
        else{
            strs_.remove(0,1);
        }
    }
    else{
        strs_.append('-');
    }
    ui->lineEdit->setText(strs_);
}

void Calculate::pushButton_Backspace_clicked(){
    /*QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier, QString(""));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Backspace, Qt::NoModifier, QString(""));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);*/
    QString strs_ = ui->lineEdit->text();
    strs_.chop(1);
    ui->lineEdit->setText(strs_);
}

void Calculate::pushButton_sendOK_clicked()
{
    emit pushButton_OK_clicked();
}

QString Calculate::get_strs()
{
    return strs;
}

void Calculate::on_pushButton_OK_clicked()
{
    strs = ui->lineEdit->text();
    this->hide();
    this->Clean_Calculater_LineEdit();
}

