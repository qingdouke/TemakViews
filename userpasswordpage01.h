#ifndef USERPASSWORDPAGE01_H
#define USERPASSWORDPAGE01_H

#include <QWidget>
#include <popupwindow07.h>

namespace Ui {
class UserPasswordPage01;
}

class UserPasswordPage01 : public QWidget
{
    Q_OBJECT

public:
    explicit UserPasswordPage01(QWidget *parent = nullptr);
    ~UserPasswordPage01();

    bool eventFilter(QObject *watched, QEvent *event);
    void setCurrentPassword(QString);
    QString getCurrentPassword();
    void setTempPassword(QString);
    QString getTempPassword();
    void setConfirmPassword(QString);
    QString getConfirmPassword();
    void setPasswordLineEdit(QString);
    QString getPasswordLineEdit();

    void userPasswordPage01_sendTo_mainWindow();
    void userPasswordPage01_sendTo_userPasswordPage02();

    void freezeOneSec();
private:
    Ui::UserPasswordPage01 *ui;
    bool isChangingPassword = false;
    QString currentPassword = "3337";
    QString tempPassword = "";
    QString confirmPassword = "";
    PopUpWindow07 popUpWindow07;

private slots:
    void currentTime();
    void on_confirm_pushButton_clicked();


signals:
    void userPasswordPage01_to_mainWindow();
    void userPasswordPage01_to_userPasswordPage02();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
};

#endif // USERPASSWORDPAGE01_H
