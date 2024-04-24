#ifndef USERPASSWORDPAGE02_H
#define USERPASSWORDPAGE02_H

#include <QWidget>

namespace Ui {
class UserPasswordPage02;
}

class UserPasswordPage02 : public QWidget
{
    Q_OBJECT

public:
    explicit UserPasswordPage02(QWidget *parent = nullptr);
    ~UserPasswordPage02();

    void userPasswordPage02_sendTo_mainWindow();
    void userPasswordPage02_sendTo_userPasswordPage01();
    void userPasswordPage02_sendTo_userPasswordPage03();

    void freezeOneSec();
private:
    Ui::UserPasswordPage02 *ui;


private slots:
    void currentTime();

signals:
    void userPasswordPage02_to_mainWindow();
    void userPasswordPage02_to_userPasswordPage01();
    void userPasswordPage02_to_userPasswordPage03();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);

};

#endif // USERPASSWORDPAGE02_H
