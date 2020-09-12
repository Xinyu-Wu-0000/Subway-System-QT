#ifndef MAPWINDOWS_H
#define MAPWINDOWS_H

#include <QMainWindow>
#include <QCompleter>

namespace Ui
{
    class MapWindows;
}

class MapWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindows(QWidget *parent = nullptr);
    void search();
    ~MapWindows();
    QCompleter *myCompleter;

private:
    QStringList word_list;
    Ui::MapWindows *ui;
};

#endif // MAPWINDOWS_H
