#ifndef POPUPWINDOW02_H
#define POPUPWINDOW02_H

#include <QDialog>

namespace Ui {
class PopUpWindow02;
}

class PopUpWindow02 : public QDialog
{
    Q_OBJECT

public:
    explicit PopUpWindow02(QWidget *parent = nullptr);
    ~PopUpWindow02();

private slots:
    void on_pBtn_Cancel_clicked();

    void on_pBtn_OK_clicked();

private:
    Ui::PopUpWindow02 *ui;
signals:
    void popWindow02PushButtonOKClickedSignal();
};

#endif // POPUPWINDOW02_H
