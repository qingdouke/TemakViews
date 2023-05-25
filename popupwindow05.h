#ifndef POPUPWINDOW05_H
#define POPUPWINDOW05_H

#include <QDialog>

namespace Ui {
class PopUpWindow05;
}

class PopUpWindow05 : public QDialog
{
    Q_OBJECT

public:
    explicit PopUpWindow05(QWidget *parent = nullptr);
    ~PopUpWindow05();

    void centerShow(int,int);

private slots:
    void on_pBtn_OK_clicked();

private:
    Ui::PopUpWindow05 *ui;
};

#endif // POPUPWINDOW05_H
