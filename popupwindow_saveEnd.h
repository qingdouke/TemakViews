#ifndef POPUPWINDOW_SAVEEND_H
#define POPUPWINDOW_SAVEEND_H

#include <QDialog>

namespace Ui {
class PopupWindow_SaveEnd;
}

class PopupWindow_SaveEnd : public QDialog
{
    Q_OBJECT

public:
    explicit PopupWindow_SaveEnd(QWidget *parent = 0);
    ~PopupWindow_SaveEnd();
    void centerShow(int,int);
    void setChinese(QString);
    void setEnglish(QString);
    void setPopupWindowAddr(int);
private:
    Ui::PopupWindow_SaveEnd *ui;
    int pbtn_ok_addr = 0;
    QString pbtn_ok_code = "0";
signals:

    void Request_Use_Keyboard_Signal(int);
    void Request_Use_Calculate_Signal(int);
    void touch_InterfaceDataSignal(int,QString);

private slots:
    void on_pBtn_OK_clicked();
};

#endif // POPUPWINDOW_SAVEEND_H
