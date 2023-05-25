#ifndef CALCULATE_H
#define CALCULATE_H

#include <QWidget>

namespace Ui {
class Calculate;
}

class Calculate : public QWidget
{
    Q_OBJECT

public:
    explicit Calculate(QWidget *parent = nullptr);
    ~Calculate();

    void Clean_Calculater_LineEdit();
    void pushButton_sendOK_clicked();
    QString get_strs();


public slots:
    void pushButton_1_clicked();
    void pushButton_2_clicked();
    void pushButton_3_clicked();
    void pushButton_4_clicked();
    void pushButton_5_clicked();
    void pushButton_6_clicked();
    void pushButton_7_clicked();
    void pushButton_8_clicked();
    void pushButton_9_clicked();
    void pushButton_0_clicked();
    void pushButton_Backspace_clicked();
    void pushButton_Minus_clicked();
    void pushButton_Period_clicked();
    void pushButton_Esc_clicked();


private:
    Ui::Calculate *ui;
    QString strs;

signals:
    void pushButton_OK_clicked();
private slots:
    void on_pushButton_OK_clicked();
};

#endif // CALCULATE_H
