#ifndef PAYWINDOWS_H
#define PAYWINDOWS_H

#include <QDialog>

namespace Ui {
class PayWindows;
}

class PayWindows : public QDialog
{
    Q_OBJECT

public:
    explicit PayWindows(QWidget *parent = nullptr);
    ~PayWindows();

private:
    Ui::PayWindows *ui;
};

#endif // PAYWINDOWS_H
