#ifndef TICKETINGWINDOWS_H
#define TICKETINGWINDOWS_H

#include <QMainWindow>
#include <QCompleter>
#include <functions.h>

namespace Ui
{
    class TicketingWindows;
}

class TicketingWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicketingWindows(QWidget *parent = nullptr);
    void confirm();
    ~TicketingWindows();

private:
    QStringList word_list;
    Ui::TicketingWindows *ui;
    QCompleter *myCompleter;
};

#endif // TICKETINGWINDOWS_H
