#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <monitoring_interface.h>
#include <QMutex>
#include <output_monitoring.h>
#include <curve_monitoring.h>
#include <program_editing.h>
#include <program_loop.h>
#include <fixed_value_setting.h>
#include <parameter_setting.h>
#include <error_log.h>
#include <keyboard.h>
#include <QBuffer>
#include <calculate.h>
#include <popupwindow07.h>
#include <userpasswordpage01.h>
#include <userpasswordpage02.h>
#include <userpasswordpage03.h>
#include <canset.h>
#include <data.h>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QMutex page_mutex;
    Monitoring_Interface monitoring_interface_page;
    Output_Monitoring output_monitoring_page;
    Curve_Monitoring curve_monitoring_page;
    Program_Editing program_editing_page;
    Program_Loop program_loop_page;
    Fixed_Value_Setting fixed_value_setting_page;
    Parameter_Setting parameter_setting_page;
    Error_Log error_log_page;
    Keyboard keyboard;
    Calculate calculate;
    PopUpWindow07 popUpWindow07;
    UserPasswordPage01 userPasswordPage01;
    UserPasswordPage02 userPasswordPage02;
    UserPasswordPage03 userPasswordPage03;
    CANSET canset_page;
    Data* readData01;
    Data* readData02;
    QThread* dataReadThread;

    void deal_monitoring_interface_to_mainwindow();
    void deal_monitoringInterface_to_outputMonitoring();
    void deal_outputMonitoring_to_mainWindow();
    void deal_outputMonitoring_to_monitoringInterface();
    void deal_outputMonitoring_to_curveMonitoring();
    void deal_curveMonitoring_to_mainWindow();
    void deal_curveMonitoring_to_outputMonitoring();
    void deal_programEditing_to_mainWindow();
    void deal_programLoop_to_mainWindow();
    void deal_programLoop_to_programEditing();
    void deal_programLoop_to_fixedValueSetting();
    void deal_fixedValueSetting_to_mainWindow();
    void deal_fixedValueSetting_to_programLoop();
    void deal_errorLog_to_mainWindow();
    void deal_parameterSetting_to_mainWindow();
    void deal_parameterSetting_to_CANSET();
    void deal_KeyboardEnter();
    void deal_KeyboardEsc();
    void deal_RequestUseKeyBoardSignal(int);
    void deal_CalculateOk();
    void deal_RequestUseCalculateSignal(int);
    void deal_ChooseProgramSignals(int,QString);
    void deal_userPasswordPage01_to_mainWindow();
    void deal_userPasswordPage01_to_userPasswordPage02();
    void deal_userPasswordPage02_to_mainWindow();
    void deal_userPasswordPage02_to_userPasswordPage01();
    void deal_userPasswordPage02_to_userPasswordPage03();
    void deal_userPasswordPage03_to_mainWindow();
    void deal_userPasswordPage03_to_userPasswordPage02();
    void deal_canset_to_mainWindow();
    void deal_canset_to_parameterSetting();
    //鼠标按下
    void mousePressEvent(QMouseEvent *event);
    //鼠标拖动
    void mouseMoveEvent(QMouseEvent *event);
    // 声明函数 setWidgetsEnabled()
    void setWidgetsEnabled(QList<QWidget*> widgets, bool enabled);


    //数据处理
    void deal_temperdaturePv_update(QString);
    void deal_curveData_update(int num,int size,QVector<QVector<double>> xdata,QVector<QVector<double>> data,QString startTime,double* dataInfo,QString* axisInfo,int status);

    void freezeOneSec();
private:
    Ui::MainWindow *ui;
    QString keyboardStrs;
    QString calculateStrs;
    int current_ID=0;
    int calculate_ID=0;
    int current_Page=-1;
    //鼠标移动时窗体与左上角的偏移
    QPoint mOffset;
private slots:
    void currentTime();
    void on_pBtn_1_clicked();
    void on_pBtn_2_clicked();
    void on_pBtn_3_clicked();
    void on_pBtn_4_clicked();
    void on_pBtn_5_clicked();
    void on_pBtn_6_clicked();
    void on_pBtn_7_clicked();
    void on_pBtn_8_clicked();
    void on_login_clicked();
signals:
    void InitDataThread01(int);
    void InitDataThread02(int);
};
#endif // MAINWINDOW_H
