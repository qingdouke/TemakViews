#include "keyboard.h"
#include "ui_keyboard.h"

#include <QFile>
#include <QTextStream>
#include <QKeyEvent>

Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);

    this->setWindowModality(Qt::ApplicationModal);

    setWindowFlags(Qt::FramelessWindowHint);
    QFile file(":/qss/keyboard_pBtn.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    ui->background->setStyleSheet("QWidget#background{border-image:url(:/Image/icon/Keyboard.bmp)}");

    //设置文字输入框样式
    QFont font_lineEdit = ui->lineEdit->font();
    font_lineEdit.setPointSize(18);
    ui->lineEdit->setFont(font_lineEdit);
    ui->lineEdit->setStyleSheet("QLineEdit#lineEdit{background-color:transparent;border:none}");

    //处理键盘点击事件
    connect(ui->pushButton_Caps_Lock,&QPushButton::clicked,this,&Keyboard::pushButton_Caps_Lock_clicked);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&Keyboard::pushButton_1_clicked);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Keyboard::pushButton_2_clicked);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Keyboard::pushButton_3_clicked);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&Keyboard::pushButton_4_clicked);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&Keyboard::pushButton_5_clicked);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&Keyboard::pushButton_6_clicked);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&Keyboard::pushButton_7_clicked);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&Keyboard::pushButton_8_clicked);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&Keyboard::pushButton_9_clicked);
    connect(ui->pushButton_0,&QPushButton::clicked,this,&Keyboard::pushButton_0_clicked);
    connect(ui->pushButton_Tilde,&QPushButton::clicked,this,&Keyboard::pushButton_Tilde_clicked);
    connect(ui->pushButton_Less_Than,&QPushButton::clicked,this,&Keyboard::pushButton_Less_Than_clicked);
    connect(ui->pushButton_More_Than,&QPushButton::clicked,this,&Keyboard::pushButton_More_Than_clicked);
    connect(ui->pushButton_Quotation_Marks,&QPushButton::clicked,this,&Keyboard::pushButton_Quotation_Marks_clicked);
    connect(ui->pushButton_Semicolon,&QPushButton::clicked,this,&Keyboard::pushButton_Semicolon_clicked);
    connect(ui->pushButton_Question_Marks,&QPushButton::clicked,this,&Keyboard::pushButton_Question_Marks_clicked);
    connect(ui->pushButton_Minus,&QPushButton::clicked,this,&Keyboard::pushButton_Minus_clicked);
    connect(ui->pushButton_Plus,&QPushButton::clicked,this,&Keyboard::pushButton_Plus_clicked);
    connect(ui->pushButton_Left_Parenthesis,&QPushButton::clicked,this,&Keyboard::pushButton_Left_Parenthesis_clicked);
    connect(ui->pushButton_Right_Parenthesis,&QPushButton::clicked,this,&Keyboard::pushButton_Right_Parenthesis_clicked);
    connect(ui->pushButton_Q,&QPushButton::clicked,this,&Keyboard::pushButton_Q_clicked);
    connect(ui->pushButton_W,&QPushButton::clicked,this,&Keyboard::pushButton_W_clicked);
    connect(ui->pushButton_E,&QPushButton::clicked,this,&Keyboard::pushButton_E_clicked);
    connect(ui->pushButton_R,&QPushButton::clicked,this,&Keyboard::pushButton_R_clicked);
    connect(ui->pushButton_T,&QPushButton::clicked,this,&Keyboard::pushButton_T_clicked);
    connect(ui->pushButton_Y,&QPushButton::clicked,this,&Keyboard::pushButton_Y_clicked);
    connect(ui->pushButton_U,&QPushButton::clicked,this,&Keyboard::pushButton_U_clicked);
    connect(ui->pushButton_I,&QPushButton::clicked,this,&Keyboard::pushButton_I_clicked);
    connect(ui->pushButton_O,&QPushButton::clicked,this,&Keyboard::pushButton_O_clicked);
    connect(ui->pushButton_P,&QPushButton::clicked,this,&Keyboard::pushButton_P_clicked);
    connect(ui->pushButton_A,&QPushButton::clicked,this,&Keyboard::pushButton_A_clicked);
    connect(ui->pushButton_S,&QPushButton::clicked,this,&Keyboard::pushButton_S_clicked);
    connect(ui->pushButton_D,&QPushButton::clicked,this,&Keyboard::pushButton_D_clicked);
    connect(ui->pushButton_F,&QPushButton::clicked,this,&Keyboard::pushButton_F_clicked);
    connect(ui->pushButton_G,&QPushButton::clicked,this,&Keyboard::pushButton_G_clicked);
    connect(ui->pushButton_H,&QPushButton::clicked,this,&Keyboard::pushButton_H_clicked);
    connect(ui->pushButton_J,&QPushButton::clicked,this,&Keyboard::pushButton_J_clicked);
    connect(ui->pushButton_K,&QPushButton::clicked,this,&Keyboard::pushButton_K_clicked);
    connect(ui->pushButton_L,&QPushButton::clicked,this,&Keyboard::pushButton_L_clicked);
    connect(ui->pushButton_Z,&QPushButton::clicked,this,&Keyboard::pushButton_Z_clicked);
    connect(ui->pushButton_X,&QPushButton::clicked,this,&Keyboard::pushButton_X_clicked);
    connect(ui->pushButton_C,&QPushButton::clicked,this,&Keyboard::pushButton_C_clicked);
    connect(ui->pushButton_V,&QPushButton::clicked,this,&Keyboard::pushButton_V_clicked);
    connect(ui->pushButton_B,&QPushButton::clicked,this,&Keyboard::pushButton_B_clicked);
    connect(ui->pushButton_N,&QPushButton::clicked,this,&Keyboard::pushButton_N_clicked);
    connect(ui->pushButton_M,&QPushButton::clicked,this,&Keyboard::pushButton_M_clicked);
    connect(ui->pushButton_Colon,&QPushButton::clicked,this,&Keyboard::pushButton_Colon_clicked);
    connect(ui->pushButton_Esc,&QPushButton::clicked,this,&Keyboard::pushButton_sendEsc_clicked);
    connect(ui->pushButton_Backspace,&QPushButton::clicked,this,&Keyboard::pushButton_Backspace_clicked);
    connect(ui->pushButton_Go_Left,&QPushButton::clicked,this,&Keyboard::pushButton_Left_clicked);
    connect(ui->pushButton_Go_Right,&QPushButton::clicked,this,&Keyboard::pushButton_Right_clicked);
    connect(ui->pushButton_Space,&QPushButton::clicked,this,&Keyboard::pushButton_Space_clicked);
    connect(ui->pushButton_Enter,&QPushButton::clicked,this,&Keyboard::pushButton_sendEnter_clicked);
}

Keyboard::~Keyboard()
{
    delete ui;
}

void Keyboard::Set_Keyboard_Geometory(int x, int y){
    this->setGeometry(x,y,793,518);
}

void Keyboard::Clean_Keyboard_LineEdit(){
    ui->lineEdit->setText("");
}

QString Keyboard::get_strs(){
    return strs;
}

void Keyboard::Set_Passwd(){
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

void Keyboard::Set_Normal(){
    ui->lineEdit->setEchoMode(QLineEdit::Normal);
}

void Keyboard::pushButton_Caps_Lock_clicked()
{
    if(judge==false){
        judge = true;
        ui->pushButton_Caps_Lock->setStyleSheet("QPushButton#pushButton_Caps_Lock{background-color:rgba(217,235,247,0.4);border:none;border-radius:5px}");
    }
    else{
        judge = false;
        ui->pushButton_Caps_Lock->setStyleSheet("QPushButton#pushButton_Caps_Lock{background-color:rgba(217,235,247,0);border:none}");
    }
}

void Keyboard::Clean_Keyboard_CapsLock(){
    judge = false;
    ui->pushButton_Caps_Lock->setStyleSheet("QPushButton#pushButton_Caps_Lock{background-color:rgba(217,235,247,0);border:none}");
}

void Keyboard::pushButton_1_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_1, Qt::NoModifier, QString("1"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_1, Qt::NoModifier, QString("1"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Exclam, Qt::NoModifier, QString("!"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Exclam, Qt::NoModifier, QString("!"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_2_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_2, Qt::NoModifier, QString("2"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_2, Qt::NoModifier, QString("2"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_At, Qt::NoModifier, QString("@"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_At, Qt::NoModifier, QString("@"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_3_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_3, Qt::NoModifier, QString("3"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_3, Qt::NoModifier, QString("3"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_NumberSign, Qt::NoModifier, QString("#"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_NumberSign, Qt::NoModifier, QString("#"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_4_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_5, Qt::NoModifier, QString("5"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_5, Qt::NoModifier, QString("5"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Dollar, Qt::NoModifier, QString("$"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Dollar, Qt::NoModifier, QString("$"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_5_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_5, Qt::NoModifier, QString("5"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_5, Qt::NoModifier, QString("5"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Percent, Qt::NoModifier, QString("%"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Percent, Qt::NoModifier, QString("%"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_6_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_6, Qt::NoModifier, QString("6"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_6, Qt::NoModifier, QString("6"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_AsciiCircum, Qt::NoModifier, QString("^"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_AsciiCircum, Qt::NoModifier, QString("^"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_7_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_7, Qt::NoModifier, QString("7"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_7, Qt::NoModifier, QString("7"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Ampersand, Qt::NoModifier, QString("&"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Ampersand, Qt::NoModifier, QString("&"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_8_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_8, Qt::NoModifier, QString("8"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_8, Qt::NoModifier, QString("8"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Asterisk, Qt::NoModifier, QString("*"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Asterisk, Qt::NoModifier, QString("*"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_9_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_9, Qt::NoModifier, QString("9"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_9, Qt::NoModifier, QString("9"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_ParenLeft, Qt::NoModifier, QString("("));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_ParenLeft, Qt::NoModifier, QString("("));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_0_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_0, Qt::NoModifier, QString("0"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_0, Qt::NoModifier, QString("0"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_ParenRight, Qt::NoModifier, QString(")"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_ParenRight, Qt::NoModifier, QString(")"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Tilde_clicked()
{
    if(judge==false){
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Apostrophe, Qt::NoModifier, QString("`"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Apostrophe, Qt::NoModifier, QString("`"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_AsciiTilde, Qt::NoModifier, QString("~"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_AsciiTilde, Qt::NoModifier, QString("~"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Less_Than_clicked()
{
    if(judge==false){
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Comma, Qt::NoModifier, QString(","));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Comma, Qt::NoModifier, QString(","));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Less, Qt::NoModifier, QString("<"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Less, Qt::NoModifier, QString("<"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_More_Than_clicked()
{
    if(judge==false){
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Period, Qt::NoModifier, QString("."));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Period, Qt::NoModifier, QString("."));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Greater, Qt::NoModifier, QString(">"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Greater, Qt::NoModifier, QString(">"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Quotation_Marks_clicked()
{
    if(judge==false){
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_QuoteLeft, Qt::NoModifier, QString("'"));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_QuoteLeft, Qt::NoModifier, QString("'"));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_QuoteDbl, Qt::NoModifier, QString("\""));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_QuoteDbl, Qt::NoModifier, QString("\""));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Semicolon_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Bar, Qt::NoModifier, QString("|"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Bar, Qt::NoModifier, QString("|"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Backslash, Qt::NoModifier, QString("\\"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Backslash, Qt::NoModifier, QString("\\"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Question_Marks_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Question, Qt::NoModifier, QString("?"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Question, Qt::NoModifier, QString("?"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Slash, Qt::NoModifier, QString("/"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Slash, Qt::NoModifier, QString("/"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Minus_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Minus, Qt::NoModifier, QString("-"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Minus, Qt::NoModifier, QString("-"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Underscore, Qt::NoModifier, QString("_"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Underscore, Qt::NoModifier, QString("_"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Plus_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Equal, Qt::NoModifier, QString("="));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Equal, Qt::NoModifier, QString("="));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Plus, Qt::NoModifier, QString("+"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Plus, Qt::NoModifier, QString("+"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Left_Parenthesis_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_BracketLeft, Qt::NoModifier, QString("["));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_BracketLeft, Qt::NoModifier, QString("["));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_BraceLeft, Qt::NoModifier, QString("{"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_BraceLeft, Qt::NoModifier, QString("{"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Right_Parenthesis_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_BracketRight, Qt::NoModifier, QString("]"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_BracketRight, Qt::NoModifier, QString("]"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_BraceRight, Qt::NoModifier, QString("}"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_BraceRight, Qt::NoModifier, QString("}"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_A_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier, QString("a"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_A, Qt::NoModifier, QString("a"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier, QString("A"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_A, Qt::NoModifier, QString("A"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_B_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_B, Qt::NoModifier, QString("b"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_B, Qt::NoModifier, QString("b"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_B, Qt::NoModifier, QString("B"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_B, Qt::NoModifier, QString("B"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_C_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_C, Qt::NoModifier, QString("c"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_C, Qt::NoModifier, QString("c"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_C, Qt::NoModifier, QString("C"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_C, Qt::NoModifier, QString("C"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_D_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_D, Qt::NoModifier, QString("d"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_D, Qt::NoModifier, QString("d"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_D, Qt::NoModifier, QString("D"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_D, Qt::NoModifier, QString("D"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_E_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_E, Qt::NoModifier, QString("e"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_E, Qt::NoModifier, QString("e"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_E, Qt::NoModifier, QString("E"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_E, Qt::NoModifier, QString("E"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_F_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_F, Qt::NoModifier, QString("f"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_F, Qt::NoModifier, QString("f"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_F, Qt::NoModifier, QString("F"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_F, Qt::NoModifier, QString("F"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_G_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_G, Qt::NoModifier, QString("g"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_G, Qt::NoModifier, QString("g"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_G, Qt::NoModifier, QString("G"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_G, Qt::NoModifier, QString("G"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_H_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_H, Qt::NoModifier, QString("h"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_H, Qt::NoModifier, QString("h"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_H, Qt::NoModifier, QString("H"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_H, Qt::NoModifier, QString("H"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_I_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_I, Qt::NoModifier, QString("i"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_I, Qt::NoModifier, QString("i"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_I, Qt::NoModifier, QString("I"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_I, Qt::NoModifier, QString("I"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_J_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_J, Qt::NoModifier, QString("j"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_J, Qt::NoModifier, QString("j"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_J, Qt::NoModifier, QString("J"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_J, Qt::NoModifier, QString("J"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_K_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_K, Qt::NoModifier, QString("k"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_K, Qt::NoModifier, QString("k"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_K, Qt::NoModifier, QString("K"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_K, Qt::NoModifier, QString("K"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_L_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_L, Qt::NoModifier, QString("l"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_L, Qt::NoModifier, QString("l"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_L, Qt::NoModifier, QString("L"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_L, Qt::NoModifier, QString("L"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_M_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_M, Qt::NoModifier, QString("m"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_M, Qt::NoModifier, QString("m"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_M, Qt::NoModifier, QString("M"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_M, Qt::NoModifier, QString("M"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_N_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_N, Qt::NoModifier, QString("n"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_N, Qt::NoModifier, QString("n"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_N, Qt::NoModifier, QString("N"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_N, Qt::NoModifier, QString("N"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_O_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_O, Qt::NoModifier, QString("o"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_O, Qt::NoModifier, QString("o"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_O, Qt::NoModifier, QString("O"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_O, Qt::NoModifier, QString("O"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_P_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_P, Qt::NoModifier, QString("p"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_P, Qt::NoModifier, QString("p"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_P, Qt::NoModifier, QString("P"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_P, Qt::NoModifier, QString("P"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Q_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Q, Qt::NoModifier, QString("q"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Q, Qt::NoModifier, QString("q"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Q, Qt::NoModifier, QString("Q"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Q, Qt::NoModifier, QString("Q"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_R_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_R, Qt::NoModifier, QString("r"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_R, Qt::NoModifier, QString("r"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_R, Qt::NoModifier, QString("R"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_R, Qt::NoModifier, QString("R"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_S_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_S, Qt::NoModifier, QString("s"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_S, Qt::NoModifier, QString("s"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_S, Qt::NoModifier, QString("S"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_S, Qt::NoModifier, QString("S"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_T_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_T, Qt::NoModifier, QString("t"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_T, Qt::NoModifier, QString("t"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_T, Qt::NoModifier, QString("T"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_T, Qt::NoModifier, QString("T"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_U_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_U, Qt::NoModifier, QString("u"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_U, Qt::NoModifier, QString("u"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_U, Qt::NoModifier, QString("U"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_U, Qt::NoModifier, QString("U"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_V_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_V, Qt::NoModifier, QString("v"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_V, Qt::NoModifier, QString("v"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_V, Qt::NoModifier, QString("V"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_V, Qt::NoModifier, QString("V"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_W_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_W, Qt::NoModifier, QString("w"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_W, Qt::NoModifier, QString("w"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_W, Qt::NoModifier, QString("W"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_W, Qt::NoModifier, QString("W"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_X_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_X, Qt::NoModifier, QString("x"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_X, Qt::NoModifier, QString("x"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_X, Qt::NoModifier, QString("X"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_X, Qt::NoModifier, QString("X"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Y_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Y, Qt::NoModifier, QString("y"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Y, Qt::NoModifier, QString("y"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Y, Qt::NoModifier, QString("Y"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Y, Qt::NoModifier, QString("Y"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Z_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Z, Qt::NoModifier, QString("z"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Z, Qt::NoModifier, QString("z"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Z, Qt::NoModifier, QString("Z"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Z, Qt::NoModifier, QString("Z"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_Colon_clicked()
{
    if(judge==false){
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Semicolon, Qt::NoModifier, QString(";"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Semicolon, Qt::NoModifier, QString(";"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
    else{
        QWidget *receiver = QApplication::focusWidget();
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Colon, Qt::NoModifier, QString(":"));
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Colon, Qt::NoModifier, QString(":"));
        QApplication::sendEvent(receiver, &keyPress);
        QApplication::sendEvent(receiver, &keyRelease);
    }
}

void Keyboard::pushButton_sendEsc_clicked(){
    emit pushButton_Esc_clicked();
}

void Keyboard::pushButton_Backspace_clicked(){
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier, QString(""));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Backspace, Qt::NoModifier, QString(""));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}

void Keyboard::pushButton_Left_clicked(){
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier, QString(""));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Left, Qt::NoModifier, QString(""));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}

void Keyboard::pushButton_Right_clicked(){
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Right, Qt::NoModifier, QString(""));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Right, Qt::NoModifier, QString(""));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}

void Keyboard::pushButton_Space_clicked(){
    QWidget *receiver = QApplication::focusWidget();
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier, QString(" "));
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Space, Qt::NoModifier, QString(" "));
    QApplication::sendEvent(receiver, &keyPress);
    QApplication::sendEvent(receiver, &keyRelease);
}

void Keyboard::pushButton_sendEnter_clicked(){
    emit pushButton_Enter_clicked();
}

void Keyboard::on_pushButton_Enter_clicked()
{
    strs = ui->lineEdit->text();
    ui->lineEdit->setText("");
    this->Clean_Keyboard_CapsLock();
    this->hide();
}

void Keyboard::Set_Position(int x,int y){
    this->setGeometry(x,y,793,518);
}
