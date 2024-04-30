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

    void userPasswordPage01_sendTo_mainWindow();
    void userPasswordPage01_sendTo_userPasswordPage02();
    void freezeOneSec();
    void addrSetUserPsdInterfaceData(int , QString );


private:
    Ui::UserPasswordPage01 *ui;
    bool isChangingPassword = false;
    QString currentPassword = "3337";
    QString tempPassword = "";
    QString confirmPassword = "";
    PopUpWindow07 popUpWindow07;

private slots:
    void currentTime();


    void on_monitor_checkBox_clicked();

    void on_pgm_monitor_checkBox_clicked();

    void on_sick_checkBox_clicked();

    void on_recorder_checkBox_clicked();

    void on_edit_pgm_checkBox_clicked();

    void on_pgm_cycle_checkBox_clicked();

    void on_one_poinit_checkBox_clicked();

    void on_param_set_checkBox_clicked();

    void on_continue_checkBox_clicked();

    void on_again_checkBox_clicked();

    void on_stop_checkBox_clicked();

signals:
    void userPasswordPage01_to_mainWindow();
    void userPasswordPage01_to_userPasswordPage02();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);

};

#endif // USERPASSWORDPAGE01_H
