#ifndef INTERNAL_PARAM_SET_H
#define INTERNAL_PARAM_SET_H

#include <QWidget>

namespace Ui {
class internal_param_set;
}

class internal_param_set : public QWidget
{
    Q_OBJECT

public:
    explicit internal_param_set(QWidget *parent = 0);
    ~internal_param_set();
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
    Ui::internal_param_set *ui;
    QString viewPassword = "8";
signals:
    void internalParamSet_to_mainWindow();
    void Request_Use_Calculate_Signal(int);
    void Request_Use_Keyboard_Signal(int);
};

#endif // INTERNAL_PARAM_SET_H
