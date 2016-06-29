#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "display.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTime>
#include "sinewave.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer_id_(0)
{
    ui->setupUi(this);

    connect(ui->controlWidget, SIGNAL(signalAdd(double,double)), this, SLOT(push(double,double)));
    connect(ui->controlWidget, SIGNAL(signalPop()), this, SLOT(pop()));
    connect(ui->controlWidget, SIGNAL(signalStep()), this, SLOT(step()));
    connect(ui->controlWidget, SIGNAL(signalPauseResume()), this, SLOT(pauseResume()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *)
{
    ui->display->step();
}

void MainWindow::push(double radius, double speed)
{
    ui->display->push(radius, speed);
}

void MainWindow::pop()
{
    ui->display->pop();
}

void MainWindow::pauseResume()
{
    if(timer_id_)
    {
        pause();
    }
    else
    {
        resume();
    }
}

void MainWindow::resume()
{
    if(timer_id_ == 0)
        timer_id_ = this->startTimer(time_tick);
}

void MainWindow::pause()
{
    if(timer_id_)
    {
        this->killTimer(timer_id_);
        timer_id_ = 0;
    }
}

void MainWindow::step()
{
    ui->display->step();
}
