#ifndef POPUPWINDOW07_H
#define POPUPWINDOW07_H

#include <QDialog>

namespace Ui {
class PopUpWindow07;
}

class PopUpWindow07 : public QDialog
{
    Q_OBJECT

public:
    explicit PopUpWindow07(QWidget *parent = nullptr);
    ~PopUpWindow07();
    void centerShow(int,int);
    void setChinese(QString);
    void setEnglish(QString);

private slots:
    void on_pBtn_OK_clicked();

private:
    Ui::PopUpWindow07 *ui;
};

#endif // POPUPWINDOW07_H
