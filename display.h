#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>

class SineWave;

class Display : public QWidget
{
    Q_OBJECT

public:
    Display(QWidget * parent = 0);

    ~Display();

    void push(double radius, double speed);

    void pop();

    void step();

    void clear();

protected:
    void paintEvent(QPaintEvent *);

    void timerEvent(QTimerEvent *);

private:
   
    QList <SineWave *> *waves_;

    QList<double> points_;

    int timer_id_;
};

#endif // DISPLAY_H
