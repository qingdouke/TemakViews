#ifndef OUTPUT_MONITORING_H
#define OUTPUT_MONITORING_H

#include <QWidget>
#include <QStackedWidget>
#include <QVector>
#include <QTableWidget>
#include <QSharedMemory>
#include <QMap>
#include <QBuffer>
#include <popupwindow01.h>
#include <popupwindow02.h>
#include <popupwindow03.h>
#include <popupwindow04.h>
#include <popupwindow05.h>

namespace Ui {
class Output_Monitoring;
}

class Output_Monitoring : public QWidget
{
    Q_OBJECT

public:
    explicit Output_Monitoring(QWidget *parent = nullptr);
    ~Output_Monitoring();

    QStackedWidget* page;

    QTableWidget table;

    QVector<int> num;
    int index = 0;
    int count = 0;
    int ncount = 0;
    int nindex = 0;

    void idSetOutputInterfaceData(int, QString);
    void addrSetOutputInterfaceData(int,QString);
    
    QString getTestTemperaturePV();
    QString getTestTemperatureSV();
    void setTestTemperaturePV(QString);
    void setTestTemperatureSV(QString);
    QString getHumidityPV();
    QString getHumiditySV();
    void setHumidityPV(QString);
    void setHumiditySV(QString);

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

    void setTableItem(int,int,int,QString);


    QString getHighTempProtect();
    QString getLowTempProtect();
    QString getTestTemperaturePercent();
    QString getHumidityPercent();
    QString getServerPercent();

    void setHighTempProtect(QString);
    void setLowTempProtect(QString);
    void setTestTemperaturePercent(QString);
    void setHumidityPercent(QString);
    void setServerPercent(QString);

    void setCurrentReceive(QString);
    void InitProgram(int,QString);

    bool eventFilter(QObject *watched, QEvent *event);
    void outputMonitoring_sendTo_monitoringInterface();
    void outputMonitoring_sendTo_mainWindow();
    void outputMonitoring_sendTo_curveMonitoring();

    void deal_popUpWindow01PushButtonOKClickedSignal();
    void deal_popUpWindow02PushButtonOKClickedSignal();
    void deal_popUpWindow03PushButtonYESClickedSignal();
    void deal_popUpWindow04WithoutDataSignals(int,int);
    void deal_popUpWindow04PushButtonClickedSignals(int,QString);
    void setRunningPBtnState(bool);
    QString getPgmTableHMS(int);
    void freezeOneSec();

private:
    Ui::Output_Monitoring *ui;

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

    QString high_temperature_protect = "--.-";
    QString low_temperature_protect = "--.-";
    QString test_temperature_heat_percent = "--.-";
    QString humidity_heat_percent = "--.-";
    QString server_percent = "--.-";

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

    QString ry_output1 = " ";
    QString ry_output2 = " ";
    QString ry_output3 = " ";
    QString ry_output4 = " ";
    QString ry_output5 = " ";
    QString ry_output6 = " ";
    QString run_pgm_list_step[4] = {"1","2","3","4"};
    QString run_pgm_list_temp[4] = {"0.00","0.00","0.00","0.00"};
    QString run_pgm_list_humi[4] = {"0.0","0.0","0.0","0.0"};
    QString run_pgm_list_hour[4] = {"0","0","0","0"};
    QString run_pgm_list_min[4] = {"0","0","0","0"};
    QString run_pgm_list_sec[4] = {"0","0","0","0"};
    QString run_pgm_list_ts1[4] = {"0","0","0","0"};
    QString run_pgm_list_ts2[4] = {"0","0","0","0"};
    QString run_pgm_list_ts3[4] = {"0","0","0","0"};
    QString run_pgm_list_wt[4] = {"0","0","0","0"};

    QString HMS[4];
    bool isRunning = false;

    PopUpWindow01 popUpWindow01;
    PopUpWindow02 popUpWindow02;
    PopUpWindow03 popUpWindow03;
    PopUpWindow04 popUpWindow04;
    PopUpWindow05 popUpWindow05;

public slots:
    void on_previousPage_pbtn_clicked();
    void on_nextPage_pbtn_clicked();
    void setRunPgmTable(int);
    void on_edit_pbtn_clicked();
    void on_jumpping_pbtn_clicked();
    void on_running_pbtn_clicked();
    void on_loading_pbtn_clicked();
    void on_constant_value_running_pbtn_clicked();

private slots:
    void currentTime();


signals:
    void outputMonitoring_to_monitoringInterface();
    void outputMonitoring_to_mainWindow();
    void outputMonitoring_to_curveMonitoring();
    void tableNextPageClickedSignals();
    void tablePreviousPageClickedSignals();
    void tableEditClickedSignals();
    void tabelJumppingClickedSignals();
    void outputMonitoringChooseProgramSignals(int,QString);

    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);


};

#endif // OUTPUT_MONITORING_H
