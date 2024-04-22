#ifndef USERPASSWORDPAGE03_H
#define USERPASSWORDPAGE03_H

#include <QWidget>

namespace Ui {
class UserPasswordPage03;
}

class UserPasswordPage03 : public QWidget
{
    Q_OBJECT

public:
    explicit UserPasswordPage03(QWidget *parent = nullptr);
    ~UserPasswordPage03();
    void userPasswordPage03_sendTo_mainWindow();
    void userPasswordPage03_sendTo_userPasswordPage02();

    void freezeOneSec();
private:
    Ui::UserPasswordPage03 *ui;

private slots:
    void currentTime();

signals:
    void userPasswordPage03_to_mainWindow();
    void userPasswordPage03_to_userPasswordPage02();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
};

#endif // USERPASSWORDPAGE03_H
