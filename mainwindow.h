#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sqliteoperator.h"
#include "sql_generic_data.h"
#include "server.h"
#include "tcp_server.h"

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
#include <popupwindow_saveEnd.h>
#include <userpasswordpage01.h>
#include <userpasswordpage02.h>
#include <userpasswordpage03.h>
#include <internal_param_set.h>
#include <canset.h>
#include <data.h>
#include <QThread>

#define TEMP_EGO_PAGE			(13)				// 温度保护设置提示页
#define MAIN_PAGE				(12)				// 主目录界面号
#define STATE_MONITOR			(1)				// 监视界面号
#define OUTPUT_MONITOR			(2)				// 输出监视号
#define CURE_SHOW				(3)				// 曲线监视号
#define PGM_EDIT				(4)				// 程式编辑号
#define PGM_CYCLE				(5)				// 程式循环号
#define FIXED_FUN				(6)				// 定点功能号
#define PARAM_SET				(7)				// 参数设置号
#define ERR_LOG_PAGE			(10)				// 错误记录号
#define PGM_SLT_PAGE			(11)				//程式选择界面
#define CLT_DATA_PAGE			(14)				// 多通道监视
#define USER_PSD_PAGE1			(15)				// 用户密码界面1
#define USER_PSD_PAGE2			(16)				// 用户密码界面2
#define USER_PSD_PAGE3			(17)				// 用户密码界面3
//#define LIST_PARAM_PAGE		(20)				// 列表式系统参数页
#define TAB_PARAM_PAGE			(21)				// 表格式系统参数页

#define SAVE_SUC_KEY            (0x01)		 // 储存成功键码
#define PWD_CHANGE_SUC_KEY      (0x02)		 // 密码修改成功键码
#define SAVEING_KEY			    (0x03)		// 存储中，请稍候
#define N0_PGM_LOAD_KEY         (0x04)		 // 运行中程式不可载入键码
//#define PGM_LOAD_KEY			(0x05)		 // 程式载入键码
//#define NO_CH_DEL_KEY			(0x06)		 // 载入中程式不可更名或删除键码
#define NO_PGM_JUMP_KEY			(0x07)		 // 非运行中程式不可跳段键码
#define THE_NUM_KEY				(0x08)			//目标段数字键盘
#define NO_THIS_SGM				(0x09)			//无效段
#define PGM_TIME_ZERO_KEY		(0x0B)		 // 程式时间不可为零键码
//#define PGM_SAVE_SUC_KEY		(0x0A)		 // 程式储存成功
#define RUN_NOT_SAVE_KEY   		(0x0C)		 // 运行中不可被编辑
#define NO_PGM_RUN_KEY			(0x0D)		// 没有程式，请加载程式
#define SAVE_FAL_KEY			(0x0F)		 // 储存失败键码
#define SYS_RUN_KEY				(0x10)        // 系统运转键码
#define SYS_STOP_KEY			(0x11)        // 系统停止键码
//#define RELAY_REPEAT_KEY		(0x12)        // 继电器冲突键码
#define	NO_THIS_FUNCTIION		(0x13)				// 暂不支持此功能
#define PLEASE_ENTER_USB		(0x14)				// 请插入U盘
#define PLEASE_ENTER_SD			(0x15)				// 请插入SD卡
#define NO_ACCESS_KEY			(0x17)				// 无操作权限
//#define SYS_LOCKED_KEY			(0x18)			// 系统已锁定
#define	ENTER_ASCII_KEY			(0x20)				// 弹出字符输入键盘
#define SYSTEM_STOP_KEY			(0x21)			// 停机取样提示
#define PGM_LOG_SEC_DEY			(0x31)			// 程式运行数据保存时间间隔
#define NUM_NO_DEC_KEY			(0x40)			// 整数键盘
#define NUM_ONE_DEC_KEY			(0x41)			// 一位小数键盘
#define NUM_TWO_DEC_KEY			(0x42)			// 两位小数键盘
#define NUM_THR_DEC_KEY			(0x43)			// 两位小数键盘
#define STR_DEC_KEY				(0x50)			// 字符串输入键盘
#define THE_PASSWORD_ERR		(0x70)	  		// 密码错误
#define PGMNAME_CANT_DEFT		(0x71)			// 程式名不能为空
#define PGM_PAUSE_KEY			(0x74)			// 是否暂停确认窗口
#define SCREEN_LOCK_KEY			(0x75)			// 系统已锁屏，提示窗口
#define ENTER_KEY				(0xF1)			// 确定键码


class  SYS_INFO_F{
 public:
    bool sys_sta = false;					// 系统状态 definition
    int lcd_socket_sta = 0;
    int run_sta = 0;					// 运行状态
    int temp_sta = 0;					// 温度状态
    int humi_sta = 0;					// 湿度状态
    bool humi_sw = false;					// 湿度开闭状态,0开1关,2，只显示不计算
    bool usb_flag = false;					// U盘连接标志位，1：已连接 0：未连接
    bool sd_flag = false;
    bool host_mode = false;				// 与上位连接标志，0：未连接，1：通过485方式连接，2：通过网口连接
    bool err_code = false;					// 错误码
    short         alarm = 0;					// 系统警告模式，16位bit类型（short），alarm0 - alarm15
    unsigned char lohumi = 0;					// 低湿状态  1105008
    bool          led_sta = false;
private:
    int ver_num = 0;
    unsigned char lcd_type = 1;					// the lcd type 0:vertical  (竖屏） 1:horizontal （横屏）


};

extern SYS_INFO_F sys_info;

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
    CANSET canset_page;
    Error_Log error_log_page;
    UserPasswordPage01 userPasswordPage01;
    UserPasswordPage02 userPasswordPage02;
    UserPasswordPage03 userPasswordPage03;
    InternalParamSet internal_param_set_page;

    Keyboard keyboard;
    Calculate calculate;
    PopUpWindow01 popUpWindow01;
    PopUpWindow02 popUpWindow02;
    PopUpWindow03 popUpWindow03;
    PopUpWindow04 popUpWindow04;
    PopUpWindow05 popUpWindow05;
    PopUpWindow06 popUpWindow06;
    PopUpWindow07 popUpWindow07;
    PopupWindow_SaveEnd popUpWindow08;
    Data* readData01;
    Data* readData02;
    Server serverTask;
    tcpServer tcpServerTask;
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
    void deal_internalParamSet_to_mainWindow();
    //鼠标按下
//    void mousePressEvent(QMouseEvent *event);
//    //鼠标拖动
//    void mouseMoveEvent(QMouseEvent *event);
//    // 声明函数 setWidgetsEnabled()
//    void setWidgetsEnabled(QList<QWidget*> widgets, bool enabled);


    //数据处理
    void deal_TouchInterfaceDataSignal(int ,QString );

    void deal_updateInterfaceNumber(int,QString);
    void deal_SQLInterfaceData_update(int ,QString);
    void deal_CommInterfaceData_update(int,QString);
    void deal_updateInterfaceDataSignal();
    void oldPageHide(int);
    void newPageShow(int);
    void usePopupWindow(int);

    void freezeOneSec();
    void dataThreadInit(int page_num);

private:
    Ui::MainWindow *ui;
    QString keyboardStrs;
    QString calculateStrs;
    int current_ID=0;
    int calculate_ID=0;
    int current_Page=MAIN_PAGE;
    int last_page = 0;
    int page_debug_state = 1;
    //鼠标移动时窗体与左上角的偏移
    //QPoint mOffset;
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
    void on_pBtn_1_pressed();


signals:
    void InitDataThread01(int);
    void InitDataThread02(int);

};
#endif // MAINWINDOW_H
