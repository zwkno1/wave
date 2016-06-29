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
    void signalPop();
    void signalStep();
    void signalPauseResume();

private slots:
    void addSineWave();
    void pauseResume();

private:
    Ui::ControlWidget *ui;
};

#endif // CONTROLWIDGET_H
