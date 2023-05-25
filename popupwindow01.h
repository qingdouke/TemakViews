#ifndef POPUPWINDOW01_H
#define POPUPWINDOW01_H

#include <QDialog>

namespace Ui {
class PopUpWindow01;
}

class PopUpWindow01 : public QDialog
{
    Q_OBJECT

public:
    explicit PopUpWindow01(QWidget *parent = nullptr);
    ~PopUpWindow01();

private slots:
    void on_pBtn_OK_clicked();

    void on_pBtn_Cancel_clicked();

private:
    Ui::PopUpWindow01 *ui;

signals:
    void popWindow01PushButtonOKClickedSignal();
};

#endif // POPUPWINDOW01_H
