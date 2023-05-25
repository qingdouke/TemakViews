#ifndef POPUPWINDOW03_H
#define POPUPWINDOW03_H

#include <QDialog>

namespace Ui {
class PopUpWindow03;
}

class PopUpWindow03 : public QDialog
{
    Q_OBJECT

public:
    explicit PopUpWindow03(QWidget *parent = nullptr);
    ~PopUpWindow03();

private slots:
    void on_pBtn_YES_clicked();

    void on_pBtn_NO_clicked();

private:
    Ui::PopUpWindow03 *ui;

signals:
    void popWindow03PushButtonYESClickedSignal();
};

#endif // POPUPWINDOW03_H
