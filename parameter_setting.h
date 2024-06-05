#ifndef PARAMETER_SETTING_H
#define PARAMETER_SETTING_H

#include <QWidget>
#include <QButtonGroup>
#include <QBuffer>
#include <QMap>

namespace Ui {
class Parameter_Setting;
}

class Parameter_Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Parameter_Setting(QWidget *parent = nullptr);
    ~Parameter_Setting();

    int Light_Value = 80;

    QButtonGroup *box1;
    QButtonGroup *box2;
    void setPassword(QString);
    QString getPassword();
    void setBackLightingTime(QString);
    QString getBackLightingTime();
    void setprogramPrepared1(QString);
    void setprogramPrepared2(QString);
    void setprogramPrepared3(QString);
    void setprogramPrepared4(QString);
    void setprogramPrepared5(QString);
    QString getprogramPrepared();
    void setChooseProgram(QString);
    QString getChooseProgram();
    void setCommunicationAddress485(QString);
    QString getCommunicationAddress485();
    void setIpAddress1(QString);
    void setIpAddress2(QString);
    void setIpAddress3(QString);
    void setIpAddress4(QString);
    QString getIpAddress();
    void setSubnetMask1(QString);
    void setSubnetMask2(QString);
    void setSubnetMask3(QString);
    void setSubnetMask4(QString);
    QString getSubnetMask();
    void setDefaultGateway1(QString);
    void setDefaultGateway2(QString);
    void setDefaultGateway3(QString);
    void setDefaultGateway4(QString);
    QString getDefaultGateway();
    void setPort(QString);
    QString getPort();

    bool eventFilter(QObject *watched, QEvent *event);
    void parameterSetting_sendTo_mainWindow();
    void parameterSetting_sendTo_CANSET();
    void addrSetParamSetInterfaceData(int, QString);
    void refreshParamSetInterfaceData();
    void freezeOneSec();

private:
    QString password;
    QString backLightingTime;
    QString programPrepared_1;
    QString programPrepared_2;
    QString programPrepared_3;
    QString programPrepared_4;
    QString programPrepared_5;
    QString programPrepared;
    QString chooseProgram;
    QString communicationAddress485;
    QString ipAddress_1;
    QString ipAddress_2;
    QString ipAddress_3;
    QString ipAddress_4;
    QString ipAddress;
    QString subnetMask_1;
    QString subnetMask_2;
    QString subnetMask_3;
    QString subnetMask_4;
    QString subnetMask;
    QString defaultGateway_1;
    QString defaultGateway_2;
    QString defaultGateway_3;
    QString defaultGateway_4;
    QString defaultGateway;
    QString port;

    Ui::Parameter_Setting *ui;
    bool screenLocked=false;

private slots:
    void currentTime();
    void on_pBtn_Light_Adjustment_Low_clicked();
    void on_pBtn_Light_Adjustment_High_clicked();
    void on_horizontalSlider_light_valueChanged(int value);
    void on_checkBox_Screen_Lock_clicked();

    void on_languageChinese_pBtn_clicked();

    void on_languageEnglish_pBtn_clicked();

    void on_languageTraditionalChinese_pBtn_clicked();

    void on_PCLINK_radioButton_clicked();

    void on_PCLINK_SUM_radioButton_clicked();

    void on_MODBUS_RTU_radioButton_clicked();

    void on_baudRate9600_radioButton_clicked();

    void on_baudRate19200_radioButton_clicked();

    void on_baudRate38400_radioButton_clicked();

    void on_baudRate57600_radioButton_clicked();

    void on_baudRate115200_radioButton_clicked();

    void on_auto_static_pbtn_clicked();

    void on_save_ip_pbtn_clicked();

signals:
    void parameterSetting_to_mainWindow();
    void parameterSetting_to_CANSET();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);

};

#endif // PARAMETER_SETTING_H
