#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->showMaximized();
    connect(ui->ExitBut, &QPushButton::clicked, this, &MainWindow::exitsys);
    connect(ui->TicketBut, &QPushButton::clicked, this, &MainWindow::callTicketintWindows);
    connect(ui->MapBut, &QPushButton::clicked, this, &MainWindow::callMapWindows);
    connect(ui->NotesBut, &QPushButton::clicked, this, &MainWindow::callNotesWindows);
    connect(ui->UsageBut, &QPushButton::clicked, this, &MainWindow::callUsageWindows);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exitsys()
{
    exit(0);
}

void MainWindow::callTicketintWindows()
{
    TicketingWindows *t = new TicketingWindows(this);
    t->show();
}

void MainWindow::callMapWindows()
{
    MapWindows *m = new MapWindows(this);
    m->show();
}

void MainWindow::callNotesWindows()
{
    NotesWindows *t = new NotesWindows(this);
    t->show();
}

void MainWindow::callUsageWindows()
{
    UsageWindows *u = new UsageWindows(this);
    u->show();
}
