#ifndef PROGRAM_EDITING_H
#define PROGRAM_EDITING_H

#include <QWidget>
#include <QStackedWidget>
#include <QVector>
#include <QTableWidget>
#include <QBuffer>
#include <popupwindow04.h>
#include "qcustomplot.h"
namespace Ui {
class Program_Editing;
}

class Program_Editing : public QWidget
{
    Q_OBJECT

public:
    explicit Program_Editing(QWidget *parent = nullptr);
    ~Program_Editing();

    QStackedWidget* page;

    //QVector<QTableWidget*> table;
    //QVector<int> num;
    //int index = 0;
    //int count = 0;
    //int ncount = 0;
    //int nindex = 0;

    bool eventFilter(QObject *watched, QEvent *event);
    QString getChooseProgram();
    QString getProgramName();
    QString getLowTempProtect();
    QString getHighTempProtect();
    void setChooseProgram(QString);
    void setProgramName(QString);
    void setLowTempProtect(QString);
    void setHighTempProtect(QString);

    void addrSetPgmEditInterfaceData(int, QString);
    void freezeOneSec();
    void refreshPgmEditInterfaceData();
    void draw(int num,int size,QVector<QVector<double>> xdata,QVector<QVector<double>> ydata,QString startTime,double* dataInfo,QString* axisInfo,int status);

private:
    Ui::Program_Editing *ui;

    QString chooseProgram="1";
    QString programName="test";
    QString lowTempProtect="";
    QString highTempProtect="";
    int dataAddressInfoNum=1;
    QString* dataAddressInfo;
    
    QString edit_pgm_list_step[4] = {"1","2","3","4"};
    QString edit_pgm_list_temp[4] = {"0.00","0.00","0.00","0.00"};
    QString edit_pgm_list_humi[4] = {"0.0","0.0","0.0","0.0"};
    QString edit_pgm_list_hour[4] = {"0","0","0","0"};
    QString edit_pgm_list_min[4] = {"0","0","0","0"};
    QString edit_pgm_list_sec[4] = {"0","0","0","0"};
    QString edit_pgm_list_ts1[4] = {"0","0","0","0"};
    QString edit_pgm_list_ts2[4] = {"0","0","0","0"};
    QString edit_pgm_list_ts3[4] = {"0","0","0","0"};
    QString edit_pgm_list_wt[4] = {"0","0","0","0"};


    //曲线部分
    QColor color[12] = {QColor(253,154,52),QColor(107,149,255),QColor(153,204,101),QColor(172,45,79),
                        QColor(54,78,189),QColor(112,45,128),QColor(202,125,78),QColor(202,17,202),QColor(12,152,12),
                        QColor(102,145,152),QColor(255,255,205),QColor(203,153,204)};//曲线颜色
    //曲线测试信息
    int curve_numb = 2;
    int curve_data_num[12];
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

    PopUpWindow04 popUpWindow04;

private slots:
    void currentTime();
    void on_lastPage_pbtn_clicked();
    void on_nextPage_pbtn_clicked();
    void on_firstPage_pbtn_clicked();
    void on_endPage_pbtn_clicked();
    void on_saving_pbtn_clicked();
    void on_loop_setting_pbtn_clicked();
    void on_new_program_pbtn_clicked();

    void on_delete_program_pbtn_clicked();


    void on_insert_pbtn_clicked();

    void on_delete_program_clicked();

    void on_font_page_pbtn_clicked();

signals:
    void programEditing_to_mainWindow();    

    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);


};

#endif // PROGRAM_EDITING_H
