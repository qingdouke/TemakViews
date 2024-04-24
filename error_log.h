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

private:
    Ui::Error_Log *ui;

private slots:
    void currentTime();

signals:
    void errorLog_to_mainWindow();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);

};

#endif // ERROR_LOG_H
