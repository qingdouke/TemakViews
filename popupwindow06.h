#ifndef POPUPWINDOW06_H
#define POPUPWINDOW06_H

#include <QDialog>

namespace Ui {
class PopUpWindow06;
}

class PopUpWindow06 : public QDialog
{
    Q_OBJECT

public:
    explicit PopUpWindow06(QWidget *parent = nullptr);
    ~PopUpWindow06();

private slots:
    void on_pushButton_3S_clicked();
    void on_pushButton_5S_clicked();
    void on_pushButton_6S_clicked();
    void on_pushButton_10S_clicked();
    void on_pushButton_15S_clicked();
    void on_pushButton_30S_clicked();
    void on_pushButton_60S_clicked();
    void on_pushButton_120S_clicked();
    void on_pushButton_300S_clicked();

private:
    Ui::PopUpWindow06 *ui;

signals:
    void popUpWindow06PushButtonClickedSignals(int);
};

#endif // POPUPWINDOW06_H
