#ifndef INTERNALPARAMSET_H
#define INTERNALPARAMSET_H

#include <QWidget>
#include <QBuffer>

namespace Ui {
class InternalParamSet;
}

class InternalParamSet : public QWidget
{
    Q_OBJECT

public:
    explicit InternalParamSet(QWidget *parent = 0);
    ~InternalParamSet();
    QString getViewPassword();
    void internalParamSet_sendTo_mainWindow();
    void addrInternalParamInterfaceData(int , QString);
    void clearPage();
    QTimer *time;
private slots:
    void on_font_page_pbtn_clicked();
    void currentTime();
    void on_row1column1_clicked();
    void on_row1column2_clicked();
    void on_row1column3_clicked();
    void on_row2column1_clicked();

    void on_row2column2_clicked();

    void on_row1column4_clicked();

    void on_row1column5_clicked();

    void on_row1column6_clicked();

    void on_row1column7_clicked();

    void on_row1column8_clicked();

    void on_row2column3_clicked();

    void on_row2column4_clicked();

    void on_row2column5_clicked();

    void on_row2column6_clicked();

    void on_row2column7_clicked();

    void on_row2column8_clicked();

    void on_row3column1_clicked();

    void on_row3column2_clicked();

    void on_row3column3_clicked();

    void on_row3column4_clicked();

    void on_row3column5_clicked();

    void on_row3column6_clicked();

    void on_row3column7_clicked();

    void on_row3column8_clicked();

    void on_row4column1_clicked();

    void on_row4column2_clicked();

    void on_row4column3_clicked();

    void on_row4column4_clicked();

    void on_row4column5_clicked();

    void on_row4column6_clicked();

    void on_row4column7_clicked();

    void on_row4column8_clicked();

    void on_row5column1_clicked();

    void on_row5column2_clicked();

    void on_row5column3_clicked();

    void on_row5column4_clicked();

    void on_row5column5_clicked();

    void on_row5column6_clicked();

    void on_row5column7_clicked();

    void on_row5column8_clicked();

    void on_row6column1_clicked();

    void on_row6column2_clicked();

    void on_row6column3_clicked();

    void on_row6column4_clicked();

    void on_row6column5_clicked();

    void on_row6column6_clicked();

    void on_row6column7_clicked();

    void on_row6column8_clicked();

    void on_row7column1_clicked();

    void on_row7column2_clicked();

    void on_row7column3_clicked();

    void on_row7column4_clicked();

    void on_row7column5_clicked();

    void on_row7column6_clicked();

    void on_row7column7_clicked();

    void on_row7column8_clicked();

    void on_row8column1_clicked();

    void on_row8column2_clicked();

    void on_row8column3_clicked();

    void on_row8column4_clicked();

    void on_row8column5_clicked();

    void on_row8column6_clicked();

    void on_row8column7_clicked();

    void on_row8column8_clicked();

    void on_row9column1_clicked();

    void on_row9column2_clicked();

    void on_row9column3_clicked();

    void on_row9column4_clicked();

    void on_row9column5_clicked();

    void on_row9column6_clicked();

    void on_row9column7_clicked();

    void on_row9column8_clicked();

    void on_row10column1_clicked();

    void on_row10column2_clicked();

    void on_row10column3_clicked();

    void on_row10column4_clicked();

    void on_row10column5_clicked();

    void on_row10column6_clicked();

    void on_row10column7_clicked();

    void on_row10column8_clicked();

    void on_row11column1_clicked();

    void on_row11column2_clicked();

    void on_row11column3_clicked();

    void on_row11column4_clicked();

    void on_row11column5_clicked();

    void on_row11column6_clicked();

    void on_row11column7_clicked();

    void on_row11column8_clicked();

    void on_row12column1_clicked();

    void on_row12column2_clicked();

    void on_row12column3_clicked();

    void on_row12column4_clicked();

    void on_row12column5_clicked();

    void on_row12column6_clicked();

    void on_row12column7_clicked();

    void on_row12column8_clicked();

    void on_last_page_pbtn_clicked();

    void on_next_page_pbtn_clicked();

    void on_retrun_pbtn_clicked();

private:
    Ui::InternalParamSet *ui;
    QString viewPassword = "8";
    QString table_title_1;
    QString table_title_2;
    QString table_title_3;
    QString table_title_4;
    QString table_title_5;
    QString table_title;
signals:
    void internalParamSet_to_mainWindow();
    void Request_Use_Calculate_Signal(int);
    void Request_Use_Keyboard_Signal(int);
    void touch_InterfaceDataSignal(int,QString);


};

#endif // InternalParamSet
