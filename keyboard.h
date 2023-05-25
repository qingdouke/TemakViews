#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>

namespace Ui {
class Keyboard;
}

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = nullptr);
    ~Keyboard();

    bool judge = false;

    //改变键盘位置的public接口函数
    void Set_Keyboard_Geometory(int x,int y);
    //清除键盘输入内容的public接口函数
    void Clean_Keyboard_LineEdit();
    //密码框设置（隐藏数字）的public接口函数
    void Set_Passwd();
    //普通输入框设置的public接口函数
    void Set_Normal();
    //获得当前输入内容的public接口函数
    QString get_strs();
    //清除大小写锁定
    void Clean_Keyboard_CapsLock();
    //定位
    void Set_Position(int x,int y);

private:
    Ui::Keyboard *ui;
    QString strs;

public slots:
    void pushButton_Caps_Lock_clicked();
    void pushButton_1_clicked();
    void pushButton_2_clicked();
    void pushButton_3_clicked();
    void pushButton_4_clicked();
    void pushButton_5_clicked();
    void pushButton_6_clicked();
    void pushButton_7_clicked();
    void pushButton_8_clicked();
    void pushButton_9_clicked();
    void pushButton_0_clicked();
    void pushButton_Tilde_clicked();
    void pushButton_Less_Than_clicked();
    void pushButton_More_Than_clicked();
    void pushButton_Quotation_Marks_clicked();
    void pushButton_Semicolon_clicked();
    void pushButton_Question_Marks_clicked();
    void pushButton_Minus_clicked();
    void pushButton_Plus_clicked();
    void pushButton_Left_Parenthesis_clicked();
    void pushButton_Right_Parenthesis_clicked();
    void pushButton_Q_clicked();
    void pushButton_W_clicked();
    void pushButton_E_clicked();
    void pushButton_R_clicked();
    void pushButton_T_clicked();
    void pushButton_Y_clicked();
    void pushButton_U_clicked();
    void pushButton_I_clicked();
    void pushButton_O_clicked();
    void pushButton_P_clicked();
    void pushButton_A_clicked();
    void pushButton_S_clicked();
    void pushButton_D_clicked();
    void pushButton_F_clicked();
    void pushButton_G_clicked();
    void pushButton_H_clicked();
    void pushButton_J_clicked();
    void pushButton_K_clicked();
    void pushButton_L_clicked();
    void pushButton_Z_clicked();
    void pushButton_X_clicked();
    void pushButton_C_clicked();
    void pushButton_V_clicked();
    void pushButton_B_clicked();
    void pushButton_N_clicked();
    void pushButton_M_clicked();
    void pushButton_Colon_clicked();
    void pushButton_sendEsc_clicked();
    void pushButton_Backspace_clicked();
    void pushButton_Left_clicked();
    void pushButton_Right_clicked();
    void pushButton_Space_clicked();
    void pushButton_sendEnter_clicked();

signals:
    void pushButton_Esc_clicked();
    void pushButton_Enter_clicked();
private slots:
    void on_pushButton_Enter_clicked();
};

#endif // KEYBOARD_H
