#ifndef PROGRAM_EDITING_H
#define PROGRAM_EDITING_H

#include <QWidget>
#include <QStackedWidget>
#include <QVector>
#include <QTableWidget>
#include <QBuffer>
#include <popupwindow04.h>

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
    void programEditing_sendTo_mainWindow();
    QString getChooseProgram();
    QString getProgramName();
    QString getLowTempProtect();
    QString getHighTempProtect();
    void setChooseProgram(QString);
    void setProgramName(QString);
    void setLowTempProtect(QString);
    void setHighTempProtect(QString);
    void inset(QString);
    void InitProgram(int,QString);

    void deal_popUpWindow04PushButtonClickedSignals(int,QString);
    void addrSetPgmEditInterfaceData(int, QString);
    void freezeOneSec();

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
    void on_choose_program_pushButton_clicked();

    void on_delete_program_pbtn_clicked();

public slots:
    void creatNewProgramClicked();
    void deleteProgramClicked();
    void insertClicked();
    void deleteClicked();

signals:
    void programEditing_to_mainWindow();
    void creatNewProgramClickedSignals();
    void deleteProgramClickedSignals();
    void insertClickedSignals();
    void deleteClickedSignals();
    void programEditingChooseProgramSignals(int,QString);

    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);


};

#endif // PROGRAM_EDITING_H
