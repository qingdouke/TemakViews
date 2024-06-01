#ifndef CURVE_MONITORING_H
#define CURVE_MONITORING_H

#include <QWidget>
#include <QBuffer>
#include <QMap>
#include <popupwindow06.h>
#include <QVector>
#include <QMouseEvent>
#include "qcustomplot.h"

namespace Ui {
class Curve_Monitoring;
}

class Curve_Monitoring : public QWidget
{
    Q_OBJECT

public:
    explicit Curve_Monitoring(QWidget *parent = nullptr);
    ~Curve_Monitoring();

    bool eventFilter(QObject *watched, QEvent *event);
    QString getStroageFrequency();
    QString getStorageSpacing();
    QString getCursorTime();
    void setStroageFrequency(QString);
    void setStorageSpacing(QString);
    void setCursorTime(QString);
    QString getTemperaturePV();
    QString getTemperatureSV();
    QString getHumidityPV();
    QString getHumiditySV();
    void setTemperaturePV(QString);
    void setTemperatureSV(QString);
    void setHumidityPV(QString);
    void setHumiditySV(QString);

    void curveMonitoring_sendTo_mainWindow();
    void curveMonitoring_sendTo_outputMonitoring();

    void deal_PopUpWindow06PushButtonClickedSignals(int);
    void addrSetCurveInterfaceData(int, QString);
    void freezeOneSec();
    void showTraceData(int);
    //曲线绘制
    void draw(int num,int size,QVector<QVector<double>> xdata,QVector<QVector<double>> data,QString startTime,double* dataInfo,QString* axisInfo,int status);
    void trendDraw();
    void refreshCurveInterfaceData();

private:
    Ui::Curve_Monitoring *ui;

    QString temperaturePV="";
    QString temperatureSV="";
    QString humidityPV="";
    QString humiditySV="";
    QString storage_frequency="0";
    QString storage_spacing="0.00";
    QString cursor_time="00:00:00";
    QString currentAddress;
    QString currentMessage;
    bool    curve_swi_1 = true;
    bool    curve_swi_2 = true;
    bool    curve_swi_3 = true;
    bool    curve_swi_4 = true;
    int     curve_data_num_1 = 0;
    int     curve_data_num_2 = 0;
    int     curve_data_num_3 = 0;
    int     curve_data_num_4 = 0;
    int     cur_x = -1;
    //曲线部分
    QColor color[12] = {QColor(203,153,204),QColor(253,154,52),QColor(107,149,255),QColor(153,204,101),QColor(172,45,79),
                        QColor(54,78,189),QColor(112,45,128),QColor(202,125,78),QColor(202,17,202),QColor(12,152,12),
                        QColor(102,145,152),QColor(255,255,205)};//曲线颜色
    QVector<QVector<double>> DATA;
    QVector<QVector<double>> XDATA;

    //曲线测试信息
    int curve_numb = 4;
    int size;
    QVector<QVector<double>> xdata;
    QVector<QVector<double>> ydata;
    QString startTime;
    int dataInfoSize;
    double* dataInfo;
    QString* axisInfo;
    int status;
    int endSize;
    QTimer* curveTimer;
    bool isconnect = false;

    PopUpWindow06 popUpWindow06;


    QCPItemTracer *tracer_curve_1;//追踪器的一个标记
    QCPItemText *cur_Label_curve_1;//显示坐标的文本
    QCPItemTracer *tracer_curve_2;
    QCPItemText *cur_Label_curve_2;
    QCPItemTracer *tracer_curve_3;
    QCPItemText *cur_Label_curve_3;
    QCPItemTracer *tracer_curve_4;
    QCPItemText *cur_Label_curve_4;

    QCPItemStraightLine *m_refer_lineV;//参考线

public slots:
    void saving_pBtn_clicked();
    void slot_mouseRelease(QMouseEvent *event);
    //void mousePressEvent(QMouseEvent *event);
private slots:
    void currentTime();


    void on_curve_pbtn_1_clicked();
    void on_curve_pbtn_2_clicked();
    void on_curve_pbtn_3_clicked();
    void on_curve_pbtn_4_clicked();
    void on_curve_pbtn_5_clicked();
    void on_curve_pbtn_6_clicked();
    void on_curve_pbtn_7_clicked();
    void on_curve_pbtn_8_clicked();
    void on_curve_pbtn_9_clicked();
    void on_curve_pbtn_10_clicked();


    void on_pushButton_0_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_curve_lastpage_pbtn_clicked();

    void on_curve_nextpage_pbtn_clicked();

    void on_real_time_pbtn_clicked();

    void on_temperature_pv_checkbox_clicked();

    void on_temperature_sv_checkbox_clicked();

    void on_humidity_pv_checkbox_clicked();

    void on_humidity_sv_checkbox_clicked();

signals:
    void curveMonitoring_to_mainWindow();
    void curveMonitoring_to_outputMonitoring();
    void savingClickedSignals();
    void realTimeClickedSignals(int);

    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);

};

#endif // CURVE_MONITORING_H
