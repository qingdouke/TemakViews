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

    QVector<QTableWidget*> table;
    QVector<int> num;
    int index = 0;
    int count = 0;
    int ncount = 0;
    int nindex = 0;

    QString getProgramName();
    QString getProgramTime();
    QString getPeriodTime();
    QString getEstimateTime();
    QString getProgramCycle();
    QString getProgramRunPeriod();
    QString getProgramLink();
    void setProgramName(QString);
    void setProgramTime_A(QString);
    void setProgramTime_B(QString);
    void setProgramTime(QString,QString);
    void setPeriodTime_A(QString);
    void setPeriodTime_B(QString);
    void setPeriodTime(QString,QString);
    void setEstimateTime(QString);
    void setProgramCycle(QString);
    void setProgramRunPeriod(QString);
    void setProgramLink(QString);
    void setTableItem(int,int,int,QString);
    QString getTemperturePV();
    QString getTempertureSV();
    QString getHumidityPV();
    QString getHumiditySV();
    void setTemperaturePV(QString);
    void setTemperatureSV(QString);
    void setHumidityPV(QString);
    void setHumiditySV(QString);
    QString getHighTempProtect();
    QString getLowTempProtect();
    QString getTemperatureOutput();
    QString getHumidityOutput();
    QString getServoOutput();
    void setHighTempProtect(QString);
    void setLowTempProtect(QString);
    void setTemperatureOutput(QString);
    void setHumidityOutput(QString);
    void setServoOutput(QString);
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

    void freezeOneSec();

private:
    Ui::Output_Monitoring *ui;

    QString temperaturePV="";
    QString temperatureSV="";
    QString humidityPV="";
    QString humiditySV="";
    QString highTempProtect="";
    QString lowTempProtect="";
    QString temperatureOutput="";
    QString humidityOutput="";
    QString servoOutput="";
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
    QString H="0";
    QString M="0";
    QString S="0";
    QString HMS=H+":"+M+":"+S;
    bool isRunning = false;

    PopUpWindow01 popUpWindow01;
    PopUpWindow02 popUpWindow02;
    PopUpWindow03 popUpWindow03;
    PopUpWindow04 popUpWindow04;
    PopUpWindow05 popUpWindow05;

public slots:
    void on_previousPage_pbtn_clicked();
    void on_nextPage_pbtn_clicked();
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
    void running_pBtn_clickedSignals();
    void loading_pBtn_clickedSignals();
    void constantValueRunning_pBtn_clickedSignals();
    void outputMonitoringChooseProgramSignals(int,QString);
};

#endif // OUTPUT_MONITORING_H
