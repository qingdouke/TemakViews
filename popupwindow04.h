#ifndef POPUPWINDOW04_H
#define POPUPWINDOW04_H

#include <QWidget>
#include <QMap>
#include <QFile>

namespace Ui {
class PopUpWindow04;
}

class PopUpWindow04 : public QWidget
{
    Q_OBJECT

public:
    explicit PopUpWindow04(QWidget *parent = nullptr);
    ~PopUpWindow04();
    bool eventFilter(QObject *watched, QEvent *event);
    void addrSetPgmListInterfaceData(int, QString);

private slots:
    void on_back_pbtn_clicked();
    void on_pervious_page_pbtn_clicked();
    void on_next_page_pbtn_clicked();


private:
    Ui::PopUpWindow04 *ui;
    int endNumber = 30;
    QMap<int,QString> map;
    int mapIndex = 1;
    int status = 0; //0选择 1添加 2删除

signals:
    void popUpWindow04WithoutDataSignals(int,int);
    void popUpWindow04InsertDataSignals();
    void popUpWindow04DeleteDataSignals(int,QString);
    void touch_InterfaceDataSignal(int,QString);
};

#endif // POPUPWINDOW04_H
