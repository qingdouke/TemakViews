#ifndef ERRORINSTRUCTION_H
#define ERRORINSTRUCTION_H

#include <QDialog>

namespace Ui {
class ErrorInstruction;
}

class ErrorInstruction : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorInstruction(QWidget *parent = 0);
    ~ErrorInstruction();

private:
    Ui::ErrorInstruction *ui;
};

#endif // ERRORINSTRUCTION_H
