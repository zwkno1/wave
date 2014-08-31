#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "displayer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    displayer(new Displayer(800, 600, Qt::black, this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
