#include "paywindows.h"
#include "ui_paywindows.h"

PayWindows::PayWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PayWindows)
{
    ui->setupUi(this);
}

PayWindows::~PayWindows()
{
    delete ui;
}
