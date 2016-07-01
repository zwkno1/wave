#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>

namespace Ui {
class ControlWidget;
}

class ControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlWidget(QWidget *parent = 0);
    ~ControlWidget();
signals:
    void signalAdd(double, double);
    void signalClear();
    void signalStep();
    void signalPauseResume();
    void signalFourier(int, double, double, int);

private slots:
    void addSineWave();
    void pauseResume();
    void square();
    void sawtooth();

private:
    void fourier(int type);
    Ui::ControlWidget *ui;
};

#endif // CONTROLWIDGET_H
