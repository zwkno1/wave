#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controlwidget.h>
class Display;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:
    void pauseResume();

    void push(double radius, double speed);

    void clear();

    void step();

    void fourier(int type, double a, double w, int stage);

protected:
    void timerEvent(QTimerEvent * e);

private:
    enum
    {
        time_tick = 100, //ms
    };

    void resume();

    void pause();

    Ui::MainWindow *ui;

    int timer_id_;
};

#endif // MAINWINDOW_H
