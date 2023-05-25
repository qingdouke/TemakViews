#ifndef MONITORING_INTERFACE_H
#define MONITORING_INTERFACE_H

#include <QWidget>
#include <QString>
#include <QMap>
#include <QBuffer>
#include <popupwindow01.h>
#include <popupwindow02.h>
#include <popupwindow03.h>
#include <popupwindow04.h>
#include <popupwindow05.h>

namespace Ui {
class Monitoring_Interface;
}

class Monitoring_Interface : public QWidget
{
    Q_OBJECT

public:
    explicit Monitoring_Interface(QWidget *parent = nullptr);
    ~Monitoring_Interface();

    bool eventFilter(QObject *watched, QEvent *event);
    QString getTemperaturePV();
    QString getTemperatureSV();
    QString getTemperaturePercent();
    void setTemperaturePV(QString);
    void setTemperatureSV(QString);
    void setTemperaturePercent(QString);
    QString getHumidityPV();
    QString getHumiditySV();
    QString getHumidityPercent();
    void setHumidityPV(QString);
    void setHumiditySV(QString);
    void setHumidityPercent(QString);
    QString getProgramName();
    QString getProgramTime();
    QString getPeriodTime();
    QString getEstimateTime();
    QString getProgramCycle();
    QString getProgramRunPeriod();
    QString getProgramLink();
    void setProgramName(QString);
    void setProgramTime(QString,QString);
    void setProgramTime_A(QString);
    void setProgramTime_B(QString);
    void setPeriodTime(QString,QString);
    void setPeriodTime_A(QString);
    void setPeriodTime_B(QString);
    void setEstimateTime(QString);
    void setProgramCycle(QString);
    void setProgramRunPeriod(QString);
    void setProgramLink(QString);
    void monitoring_interface_sendTo_mainwindow();
    void monitoringInterface_sendTo_outputMonitoring();
    void LED_pBtn_clicked();
    void running_pBtn_clicked();
    void loading_pBtn_clicked();

    void start_run_gif();
    void InitProgram(int,QString);

    void deal_popUpWindow01PushButtonOKClickedSignal();
    void deal_popUpWindow02PushButtonOKClickedSignal();
    void deal_popUpWindow03PushButtonYESClickedSignal();
    void deal_popUpWindow04WithoutDataSignals(int,int);
    void deal_popUpWindow04PushButtonClickedSignals(int,QString);

    void freezeOneSec();
private:
    Ui::Monitoring_Interface *ui;

    QString temperature_pv="12.12";
    QString temperature_sv="13.13";
    QString temperature_percent="0.00";
    QString humidity_pv="24.24";
    QString humidity_sv="25.25";
    QString humidity_percent="0.00";
    QString program_name="Viola";
    QString program_time_A="0000:00:00";
    QString program_time_B="0000:00:00";
    QString program_time=program_time_A+"/"+program_time_B;
    QString period_time_A="0000:00:00";
    QString period_time_B="0000:00:00";
    QString period_time=period_time_A+"/"+period_time_B;
    QString estimate_time="2022-10-28 14:42:50";
    QString program_cycle="0000/0000";
    QString program_run_period="000";
    QString program_link="003/000";
    bool isStart = false;
    int run_gif_currentBmp = 11;
    bool isLEDChecked = false;
    bool isRunning = false;

    PopUpWindow01 popUpWindow01;
    PopUpWindow02 popUpWindow02;
    PopUpWindow03 popUpWindow03;
    PopUpWindow04 popUpWindow04;
    PopUpWindow05 popUpWindow05;

private slots:
    void currentTime();

signals:
    void monitoring_interface_to_mainwindow();
    void monitoringInterface_to_outputMonitoring();
//    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void LED_pBtn_clickedSignals();
    void running_pBtn_clickedSignals();
    void loading_pBtn_clickedSignals();
    void monitoring_interface_choose_program(int,QString);
};

#endif // MONITORING_INTERFACE_H
