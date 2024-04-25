#ifndef CANSET_H
#define CANSET_H

#include <QWidget>

namespace Ui {
class CANSET;
}

class CANSET : public QWidget
{
    Q_OBJECT

public:
    explicit CANSET(QWidget *parent = nullptr);
    ~CANSET();

    void canset_sendTo_mainWindow();
    void canset_sendTo_parameterSetting();
    void addrSetCanInterfaceData(int, QString);

    void freezeOneSec();

private:
    Ui::CANSET *ui;

signals:
    void canset_to_mainWindow();
    void canset_to_parameterSetting();
    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
};

#endif // CANSET_H
