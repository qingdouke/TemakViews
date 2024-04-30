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
    bool eventFilter(QObject *watched, QEvent *event);
    void freezeOneSec();
    void addrSetUserPsdInterfaceData(int, QString);
private:
    Ui::UserPasswordPage02 *ui;


private slots:
    void currentTime();

    void on_common_programs_pushButton_clicked();

    void on_record_naming_method_checkBox_1_clicked();

    void on_record_naming_method_checkBox_2_clicked();

    void on_auto_temperature_protected_locked_clicked();

    void on_shutdown_protected_locked_clicked();

    void on_nitrogen_function_checkBox_clicked();

    void on_ultrasonic_humidification_locked_clicked();

    void on_wind_speed_locked_clicked();

    void on_ultra_low_humidity_locked_clicked();

    void on_test_article_protection_locked_clicked();

    void on_culmulative_time_locked_clicked();

    void on_remote_recording_locked_clicked();

    void on_history_curve_list_display_locked_clicked();

signals:
    void userPasswordPage02_to_mainWindow();
    void userPasswordPage02_to_userPasswordPage01();
    void userPasswordPage02_to_userPasswordPage03();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);

};

#endif // USERPASSWORDPAGE02_H
