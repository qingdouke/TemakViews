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
    void addrSetUserPsdInterfaceData(int, QString);
    void freezeOneSec();
    bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::UserPasswordPage03 *ui;

private slots:
    void currentTime();

    void on_turn_off_humidity_function_locked_clicked();

    void on_automatic_defrosting_locked_clicked();

    void on_remote_recording_locked_clicked();

    void on_excessive_warning_locked_clicked();

    void on_text_messaging_locked_clicked();

    void on_program_downloading_clicked();

    void on_program_uploading_clicked();

signals:
    void userPasswordPage03_to_mainWindow();
    void userPasswordPage03_to_userPasswordPage02();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);

};

#endif // USERPASSWORDPAGE03_H
