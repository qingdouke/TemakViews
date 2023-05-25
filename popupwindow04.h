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

    void changeLabelID(int);
    QString checkMap(int);
    void setStatus(int);
    int getStatus();
    void insertMap(QString);
    int getMapIndex();
    int getEndNumber();
private slots:
    void on_back_pbtn_clicked();
    void on_pervious_page_pbtn_clicked();
    void on_next_page_pbtn_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_29_clicked();
    void on_pushButton_30_clicked();

private:
    Ui::PopUpWindow04 *ui;
    int endNumber = 30;
    QMap<int,QString> map;
    int mapIndex = 1;
    int status = 0; //0选择 1添加 2删除

signals:
    void popUpWindow04ButtonClickedSignals(int,QString);
    void popUpWindow04WithoutDataSignals(int,int);
    void popUpWindow04InsertDataSignals();
    void popUpWindow04DeleteDataSignals(int,QString);
};

#endif // POPUPWINDOW04_H
