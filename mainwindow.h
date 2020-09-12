#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ticketingwindows.h"
#include "noteswindows.h"
#include "usagewindows.h"
#include "mapwindows.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void exitsys();
    void callTicketintWindows();
    void callMapWindows();
    void callNotesWindows();
    void callUsageWindows();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
