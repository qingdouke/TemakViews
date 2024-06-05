#ifndef DATA_H
#define DATA_H

#include "sqliteoperator.h"
#include "sql_generic_data.h"
#include "server.h"

#include <QObject>
#include <QMap>
#include <QList>
#include <monitoring_interface.h>
#include <output_monitoring.h>
#include <curve_monitoring.h>
#include <parameter_setting.h>
#include <program_editing.h>
#include <program_loop.h>
#include <userpasswordpage01.h>
#include <userpasswordpage02.h>
#include <userpasswordpage03.h>
#include <error_log.h>
#include <QThread>
#include <QTimer>

class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(QObject *parent = nullptr);
    ~Data();
    bool isRunning = false;
    bool isStart = false;

    QString callback_strs;

    //页面
    Monitoring_Interface monitoring_interface;
    Output_Monitoring output_monitoring;
    Curve_Monitoring curve_monitoring;
    Parameter_Setting parameter_setting;
    Program_Editing program_editing;
    Program_Loop program_loop;
    UserPasswordPage01 userPasswordPage01;
    UserPasswordPage02 userPasswordPage02;
    UserPasswordPage03 userPasswordPage03;
    Error_Log error_log;

    //数据处理
    void send_updateInterfaceNumber_signals(int,QString);
    void send_curveData_signals();
    //数据发送
    void dataFunction(int);

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
    void trendData();

private:
    //共有数据
    //温湿度数据
    //QString temperaturePv;
    //QString temperatureSv;
    //QString temperaturePercent;
    //QString humidityPv;
    //QString humiditySv;
    //QString humidityPercent;
    //QString highTempProtect;
    //QString lowTempProtect;
    //程式信息
    QMap<int,QString> programNameMap;
    QMap<int,QString> programTimeMap;
    QMap<int,QString> programPeriodTimeMap;
    QMap<int,QString> programEstimateTimeMap;
    QMap<int,QString> programCycleMap;
    QMap<int,QString> programRunPeriodMap;
    QMap<int,QString> programLinkMap;
    QList<QString> programSettingTemp;
    QList<QString> programSettingHumi;
    QList<QString> programSettingH;
    QList<QString> programSettingM;
    QList<QString> programSettingS;
    QList<QString> programSettingTS1;
    QList<QString> programSettingTS2;
    QList<QString> programSettingTS3;
    QList<QString> programSettingWT;
    //曲线数据
    QMap<int,QList<double>> curveData;


    //子页私有数据
    //output_monitoring
    QString output_monitoring_temperatureOutput;
    QString output_monitoring_humidityOutput;
    QString output_monitoring_servoOutput;
    //curve_monitoring
    QString curve_monitoring_storage_frequency;
    QString curve_monitoring_storage_spacing;
    QString curve_monitoring_cursor_time;
    //program_loop
    QString program_loop_all_loops;
    QString program_loop_link;
    QMap<int,QString> program_loop_start_map;
    QMap<int,QString> program_loop_over_map;
    QMap<int,QString> program_loop_times_map;
    //fixed_value_setting
    QString fixed_value_setting_temperature;
    QString fixed_value_setting_humidity;
    QString fixed_value_slope_time_H;
    QString fixed_value_slope_time_M;
    QString fixed_value_slope_time_S;
    QString fixed_value_setting_constant_temperature_H;
    QString fixed_value_setting_constant_temperature_M;
    QString fixed_value_setting_constant_temperature_S;
    QString fixed_value_setting_TS1;
    QString fixed_value_setting_TS2;
    QString fixed_value_setting_TS3;
    QString fixed_value_wait;
    //parameter_setting
    QString parameter_setting_password_change;
    QString parameter_setting_back_lighting_time;
    QString parameter_setting_program_prepared;
    int parameter_setting_communication_protocal;
    QString parameter_setting_communication_address_485;
    int parameter_setting_baud_rate;
    QString parameter_setting_ip_address;
    QString parameter_setting_subnet_mask;
    QString parameter_setting_default_gateway;
    QString parameter_setting_port;
    //can_set
    int can_set_baud_rate;
    QString can_set_period;
    QString can_set_send_sys_value;
    QString can_set_set_sys_value;
    QString can_set_send_sys_sta;
    QString can_set_send_pgm_run_time;
    //error_log
    QString error_log_type;
    QString error_log_version;
    QString error_log_err_time;
    QString error_log_err_code;
    QString error_log_lasting_time;
    QString error_log_sta;
    QString error_log_cyc;
    QString error_log_link;
    QString error_log_pgm;
    QString error_log_free_time;
    QString error_log_hilimit;
    QString error_log_lolimit;
    QString error_log_tpv;
    QString error_log_tsv;
    QString error_log_hpv;
    QString error_log_hsv;
    QString error_log_wpv;
    QString error_log_wsv;
    QString error_log_out;
    QString error_log_temp;
    QString error_log_humi;
    QString error_log_svr;
    QString error_log_page;
    //user_password_page01
    QString user_password_page01_on_2;
    QString user_password_page01_on_3;
    QString user_password_page01_on_4;
    QString user_password_page01_on_5;
    QString user_password_page01_on_6;
    QString user_password_page01_on_7;
    QString user_password_page01_on_8;
    QString user_password_page01_on_9;
    QString user_password_page01_off_2;
    QString user_password_page01_off_3;
    QString user_password_page01_off_4;
    QString user_password_page01_off_5;
    QString user_password_page01_off_6;
    QString user_password_page01_off_7;
    QString user_password_page01_off_8;
    QString user_password_page01_off_9;
    int user_password_page01_temperature_calorifier;
    int user_password_page01_humidity_calorifier;
    int user_password_page01_c1;
    int user_password_page01_server;
    QString user_password_page01_server_pid;
    QString user_password_page01_password;
    QString user_password_page01_power;
    QString user_password_page01_nagative_stata;
    //user_password_page02
    int user_password_page02_record_naming_method;
    bool user_password_page02_auto_temperature_protected;
    bool user_password_page02_shutdown_protected;
    QString user_password_page02_define_temperature;
    QString user_password_page02_define_time;
    QString user_password_page02_high_temperature_range;
    QString user_password_page02_low_temperature_range;
    bool user_password_page02_nitrogen_function;
    bool user_password_page02_ultrasonic_humidification;
    QString user_password_page02_ultrasonic_humidification_temperature_low;
    QString user_password_page02_ultrasonic_humidification_temperature_high;
    QString user_password_page02_ultrasonic_humidification_humidity;
    bool ultrasonic_humidification_wind_speed;
    bool ultrasonic_humidification_ultra_low_humidity;
    bool ultrasonic_humidification_test_article_protection;
    bool ultrasonic_humidification_culmulative_time;
    bool ultrasonic_humidification_remote_recording;
    bool ultrasonic_humidification_history_curve_list_display;
    //user_password_page03
    bool user_password_page03_turn_off_humidity_function;
    bool user_password_page03_automatic_defrosting;
    bool user_password_page03_remote_recording;
    bool user_password_page03_excessive_warning;
    QString user_password_page03_water_replenishment_mode;
    QString user_password_page03_water_level_warning;
    QString user_password_page03_water_level_warning_M;
    bool user_password_page03_text_messaging;
    int user_password_page03_temperature_control;

signals:
    void updateInterfaceNumberSignal(int,QString);
    void updateInterfaceDataSignal();
    void sql_updateMonitorInterfaceDataSignal(int,QString);
    void sql_updateOutputInterfaceDataSignal(int,QString);

    void updateCurve(int num,int size,QVector<QVector<double>> xdata,QVector<QVector<double>> data,QString startTime,double* dataInfo,QString* axisInfo,int status);
};

#endif // DATA_H
