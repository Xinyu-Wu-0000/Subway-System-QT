#include "usagewindows.h"
#include "ui_usagewindows.h"

UsageWindows::UsageWindows(QWidget *parent) : QMainWindow(parent),
                                              ui(new Ui::UsageWindows)
{
    ui->setupUi(this);
}

UsageWindows::~UsageWindows()
{
    delete ui;
}
