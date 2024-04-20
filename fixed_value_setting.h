#ifndef FIXED_VALUE_SETTING_H
#define FIXED_VALUE_SETTING_H

#include <QWidget>
#include <QBuffer>

namespace Ui {
class Fixed_Value_Setting;
}

class Fixed_Value_Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Fixed_Value_Setting(QWidget *parent = nullptr);
    ~Fixed_Value_Setting();

    bool eventFilter(QObject *watched, QEvent *event);
    void fixedValueSetting_sendTo_mainWindow();
    void fixedValueSetting_sendTo_programLoop();
    void OnepointSavePgm();
    void addrSetOnepointInterfaceData(int , QString );

    QString getTemperatureText();
    QString getHumidityText();
    QString getSlopeTimeHText();
    QString getSlopeTimeMText();
    QString getSlopeTimeSText();
    QString getconstantTempHText();
    QString getconstantTempMText();
    QString getconstantTempSText();
    QString getTS1Text();
    QString getTS2Text();
    QString getTS3Text();
    QString getWaitText();
    void setTemperatureText(QString);
    void setHumidityText(QString);
    void setSlopeTimeHText(QString);
    void setSlopeTimeMText(QString);
    void setSlopeTimeSText(QString);
    void setconstantTempHText(QString);
    void setconstantTempMText(QString);
    void setconstantTempSText(QString);
    void setTS1Text(QString);
    void setTS2Text(QString);
    void setTS3Text(QString);
    void setWaitText(QString);

    void freezeOneSec();

private:
    Ui::Fixed_Value_Setting *ui;
    QString temperatureText="00.00";
    QString humidityText="0.0";
    QString slopeTimeHText="0";
    QString slopeTimeMText="0";
    QString slopeTimeSText="0";
    QString constantTempHText="0";
    QString constantTempMText="0";
    QString constantTempSText="0";
    QString TS1Text="0";
    QString TS2Text="0";
    QString TS3Text="0";
    QString waitText="0";

private slots:
    void currentTime();

signals:
    void fixedValueSetting_to_mainWindow();
    void fixedValueSetting_to_programLoop();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);

};

#endif // FIXED_VALUE_SETTING_H
