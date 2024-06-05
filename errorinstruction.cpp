#include "errorinstruction.h"
#include "ui_errorinstruction.h"

ErrorInstruction::ErrorInstruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorInstruction)
{
    ui->setupUi(this);
}

ErrorInstruction::~ErrorInstruction()
{
    delete ui;
}
