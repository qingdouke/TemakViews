#ifndef CURVE_MONITORING_H
#define CURVE_MONITORING_H

#include <QWidget>
#include <QBuffer>
#include <QMap>
#include <popupwindow06.h>
#include <QVector>

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

    void freezeOneSec();

    //曲线绘制
    void draw(int num,int size,QVector<QVector<double>> xdata,QVector<QVector<double>> data,QString startTime,double* dataInfo,QString* axisInfo,int status);
    void trendDraw();


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

    //曲线部分
    QColor color[12] = {Qt::red,Qt::blue,Qt::green,Qt::yellow,QColor(172,45,79),QColor(54,78,189),QColor(112,45,128),
                       QColor(202,125,78),QColor(202,17,202),QColor(12,152,12),QColor(102,145,152),QColor(255,255,205)};//曲线颜色
    QVector<QVector<double>> DATA;
    QVector<QVector<double>> XDATA;

    //曲线测试信息
    int num;
    int size;
    QVector<QVector<double>> xdata;
    QVector<QVector<double>> data;
    QString startTime;
    int dataInfoSize;
    double* dataInfo;
    QString* axisInfo;
    int status;
    int endSize;
    QTimer* curveTimer;
    bool isconnect = false;

    PopUpWindow06 popUpWindow06;

public slots:
    void saving_pBtn_clicked();
    void real_time_pBtn_clicked();
private slots:
    void currentTime();
    void on_storage_frequency_pushButton_clicked();

    void on_real_time_pbtn_clicked();

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
