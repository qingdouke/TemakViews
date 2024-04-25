#ifndef PROGRAM_LOOP_H
#define PROGRAM_LOOP_H

#include <QWidget>
#include <QBuffer>

namespace Ui {
class Program_Loop;
}

class Program_Loop : public QWidget
{
    Q_OBJECT

public:
    explicit Program_Loop(QWidget *parent = nullptr);
    ~Program_Loop();

    bool eventFilter(QObject *watched, QEvent *event);
    QString getr2h2Text();
    QString getr2h3Text();
    QString getr2h4Text();
    QString getr3h2Text();
    QString getr3h3Text();
    QString getr3h4Text();
    QString getr4h2Text();
    QString getr4h3Text();
    QString getr4h4Text();
    void setr2h1Text(QString);
    void setr2h2Text(QString);
    void setr2h3Text(QString);
    void setr2h4Text(QString);
    void setr3h1Text(QString);
    void setr3h2Text(QString);
    void setr3h3Text(QString);
    void setr3h4Text(QString);
    void setr4h1Text(QString);
    void setr4h2Text(QString);
    void setr4h3Text(QString);
    void setr4h4Text(QString);
    QString getChooseProgram();
    QString getLink();
    QString getProgramName();
    QString getAllLoops();
    void setChooseProgram(QString);
    void setLink(QString);
    void setProgramName(QString);
    void setAllLoops(QString);

    void programLoop_sendTo_mainWindow();
    void programLoop_sendTo_programEditing();
    void programLoop_sendTo_fixedValueSetting();
    void addrSetPgmLoopInterfaceData(int , QString );

    void freezeOneSec();

private:
    Ui::Program_Loop *ui;

    QString r2h1text="0";
    QString r2h2text="0";
    QString r2h3text="0";
    QString r2h4text="0";
    QString r3h1text="0";
    QString r3h2text="0";
    QString r3h3text="0";
    QString r3h4text="0";
    QString r4h1text="0";
    QString r4h2text="0";
    QString r4h3text="0";
    QString r4h4text="0";
    QString chooseProgram="1";
    QString link="0";
    QString programName="test";
    QString all_loops="2";

private slots:
    void currentTime();

    void on_saving_pbtn_clicked();

signals:
    void programLoop_to_mainWindow();
    void programLoop_to_programEditing();
    void programLoop_to_fixedValueSetting();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);


};

#endif // PROGRAM_LOOP_H
