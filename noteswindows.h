#ifndef NOTESWINDOWS_H
#define NOTESWINDOWS_H

#include <QMainWindow>

namespace Ui
{
    class NotesWindows;
}

class NotesWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit NotesWindows(QWidget *parent = nullptr);
    ~NotesWindows();

private:
    Ui::NotesWindows *ui;
};

#endif // NOTESWINDOWS_H
