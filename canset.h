#ifndef CANSET_H
#define CANSET_H

#include <QWidget>

namespace Ui {
class CANSET;
}

class CANSET : public QWidget
{
    Q_OBJECT

public:
    explicit CANSET(QWidget *parent = nullptr);
    ~CANSET();

    void canset_sendTo_mainWindow();
    void canset_sendTo_parameterSetting();
    void addrSetCanInterfaceData(int, QString);

    void freezeOneSec();
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::CANSET *ui;

signals:
    void canset_to_mainWindow();
    void canset_to_parameterSetting();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);   
    void touch_InterfaceDataSignal(int,QString);
private slots:
    void on_baudrate_1000k_checkBox_clicked();

    void on_baudrate_800k_checkBox_clicked();
    void on_baudrate_500k_checkBox_clicked();
    void on_baudrate_250k_checkBox_clicked();
    void on_baudrate_125k_checkBox_clicked();
    void on_baudrate_100k_checkBox_clicked();
    void on_baudrate_50k_checkBox_clicked();
    void on_baudrate_20k_checkBox_clicked();
    void on_baudrate_10k_checkBox_clicked();
    void on_baudrate_5k_checkBox_clicked();
    void on_baudrate_2k_checkBox_clicked();
};

#endif // CANSET_H
