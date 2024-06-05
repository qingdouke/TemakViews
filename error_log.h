#ifndef ERROR_LOG_H
#define ERROR_LOG_H

#include <QWidget>

namespace Ui {
class Error_Log;
}

class Error_Log : public QWidget
{
    Q_OBJECT

public:
    explicit Error_Log(QWidget *parent = nullptr);
    ~Error_Log();

    void errorLog_sendTo_mainWindow();
    void addrSetErrLogInterfaceData(int, QString);
    void refreshErrorLogInterfaceData();
private:
    Ui::Error_Log *ui;
    QString err_time;
    QString err_time_1;
    QString err_time_mid;
    QString err_time_2;

    QString err_code;
    QString err_code_1;
    QString err_code_2;

    QString freetime;
    QString freetime_1;
    QString freetime_2;

    QString page;
    QString page_1;
    QString page_2;

    QString out;
    QString out_1;
    QString out_2;
    QString out_3;
private slots:
    void currentTime();

    void on_LastPage_pbtn_clicked();

    void on_NextPage_pbtn_clicked();

    void on_clear_log_pbtn_clicked();

    void on_saving_pbtn_clicked();

signals:
    void errorLog_to_mainWindow();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);

};

#endif // ERROR_LOG_H
