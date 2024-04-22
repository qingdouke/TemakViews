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

    void freezeOneSec();

private:
    QString password;
    QString backLightingTime;
    QString programPrepared_1;
    QString programPrepared_2;
    QString programPrepared_3;
    QString programPrepared_4;
    QString programPrepared_5;
    QString programPrepared = programPrepared_1+" "+programPrepared_2+" "+programPrepared_3+" "+programPrepared_4+" "+programPrepared_5;
    QString chooseProgram;
    QString communicationAddress485;
    QString ipAddress_1;
    QString ipAddress_2;
    QString ipAddress_3;
    QString ipAddress_4;
    QString ipAddress = ipAddress_1+"."+ipAddress_2+"."+ipAddress_3+"."+ipAddress_4;
    QString subnetMask_1;
    QString subnetMask_2;
    QString subnetMask_3;
    QString subnetMask_4;
    QString subnetMask = subnetMask_1+"."+subnetMask_2+"."+subnetMask_3+"."+subnetMask_4;
    QString defaultGateway_1;
    QString defaultGateway_2;
    QString defaultGateway_3;
    QString defaultGateway_4;
    QString defaultGateway = defaultGateway_1+"."+defaultGateway_2+"."+defaultGateway_3+"."+defaultGateway_4;
    QString port;

    Ui::Parameter_Setting *ui;
    bool screenLocked=false;

private slots:
    void currentTime();
    void on_pBtn_Light_Adjustment_Low_clicked();
    void on_pBtn_Light_Adjustment_High_clicked();
    void on_horizontalSlider_light_valueChanged(int value);
    void on_checkBox_Screen_Lock_clicked();

signals:
    void parameterSetting_to_mainWindow();
    void parameterSetting_to_CANSET();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
};

#endif // PARAMETER_SETTING_H
