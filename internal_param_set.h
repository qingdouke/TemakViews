#ifndef INTERNALPARAMSET_H
#define INTERNALPARAMSET_H

#include <QWidget>

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
    void clearPage();
    QTimer *time;
private slots:
    void on_font_page_pbtn_clicked();
    void currentTime();
    void on_row1column1_clicked();
    void on_row1column2_clicked();
    void on_row1column3_clicked();
    void on_row2column1_clicked();

private:
    Ui::InternalParamSet *ui;
    QString viewPassword = "8";
signals:
    void internalParamSet_to_mainWindow();
    void Request_Use_Calculate_Signal(int);
    void Request_Use_Keyboard_Signal(int);

};

#endif // InternalParamSet
