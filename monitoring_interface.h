#ifndef MONITORING_INTERFACE_H
#define MONITORING_INTERFACE_H

#include "sql_generic_data.h"
#include "sqliteoperator.h"

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

    void idSetMonitorInterfaceData(int, QString);
    void addrSetMonitorInterfaceData(int, QString);

    QString getTestTemperaturePV();
    QString getTestTemperatureSV();
    QString getTestTemperaturePercent();
    void setTestTemperaturePV(QString);
    void setTestTemperatureSV(QString);
    void setTestTemperaturePercent(QString);
    QString getHumidityPV();
    QString getHumiditySV();
    QString getHumidityPercent();
    void setHumidityPV(QString);
    void setHumiditySV(QString);
    void setHumidityPercent(QString);

    QString getProgramName();
    QString getProgramTime();
    QString getSegmentTime();
    QString getEstimateTime();
    QString getProgramCycle();
    QString getProgramRunSegment();
    QString getProgramLink();
    void setProgramName(QString);
    void setProgramTime(QString,QString);
    void setProgramRunTime(QString);
    void setProgramFreeTime(QString);
    void setSegmentTime(QString,QString);
    void setSegmentRunTime(QString);
    void setSegmentFreeTime(QString);
    void setEstimateEndTime(QString);
    void setProgramCycle(QString);
    void setProgramRunSegment(QString);
    void setProgramLink(QString);


    void monitoring_interface_sendTo_mainwindow();
    void monitoringInterface_sendTo_outputMonitoring();
    void setLedPBtnState(bool);
    void pause_pBtn_clicked();

    void start_run_gif();

    void setRunningPBtnState(bool );
    void deal_popUpWindow01PushButtonOKClickedSignal();
    void deal_popUpWindow02PushButtonOKClickedSignal();
    void deal_popUpWindow03PushButtonYESClickedSignal();
    void deal_popUpWindow04WithoutDataSignals(int,int);
    void refreshMonitorInterfaceData();
    void freezeOneSec();
private:
    Ui::Monitoring_Interface *ui;
    QString monitor_page_title = "Monitor";

    QString test_temperature_pv = "--.--";
    QString test_temperature_sv = "--.--";
    QString prec_temperature_pv = "--.--";
    QString prec_temperature_sv = "--.--";
    QString preh_temperature_pv = "--.--";
    QString preh_temperature_sv = "--.--";
    QString humidity_pv = "--.-";
    QString humidity_sv = "--.-";
    QString wet_temperature_pv = "--.-";
    QString wet_temperature_sv = "--.-";

    QString test_temperature_heat_percent = "--.-";
    QString humidity_heat_percent = "--.-";

    QString run_program_name = "--------";
    QString program_run_time = "0000:00:00";
    QString program_free_time = "0000:00:00";
    QString program_time = "0000:00:00/0000:00:00";
    QString segment_run_time = "0000:00:00";
    QString segment_free_time = "0000:00:00";
    QString segment_time = "0000:00:00/0000:00:00";
    QString estimate_end_time = "2022-10-28 14:42:50";
    QString program_cycle = "0000/0000";
    QString program_run_segment = "000";
    QString program_link = "003/000";

    int run_gif_currentBmp = 11;


    PopUpWindow01 popUpWindow01;
    PopUpWindow02 popUpWindow02;
    PopUpWindow03 popUpWindow03;
    PopUpWindow04 popUpWindow04;
    PopUpWindow05 popUpWindow05;

private slots:
    void currentTime();

    void on_LED_pbtn_clicked();

    void on_reset_pbth_clicked();

    void on_constant_value_running_pbtn_clicked();

    void on_running_pBtn_clicked();

    void on_loading_pBtn_clicked();

signals:
    void monitoring_interface_to_mainwindow();
    void monitoringInterface_to_outputMonitoring();
    void monitoring_interface_choose_program(int,QString);

    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);
};

#endif // MONITORING_INTERFACE_H
