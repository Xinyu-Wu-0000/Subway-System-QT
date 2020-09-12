#include "noteswindows.h"
#include "ui_noteswindows.h"

NotesWindows::NotesWindows(QWidget *parent) : QMainWindow(parent),
                                              ui(new Ui::NotesWindows)
{
    ui->setupUi(this);
}

NotesWindows::~NotesWindows()
{
    delete ui;
}
