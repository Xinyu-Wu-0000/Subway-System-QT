#ifndef USAGEWINDOWS_H
#define USAGEWINDOWS_H

#include <QMainWindow>

namespace Ui
{
    class UsageWindows;
}

class UsageWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit UsageWindows(QWidget *parent = nullptr);
    ~UsageWindows();

private:
    Ui::UsageWindows *ui;
};

#endif // USAGEWINDOWS_H
