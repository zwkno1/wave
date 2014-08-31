#ifndef DISPLAYER_H
#define DISPLAYER_H

#include <QWidget>

class SineWave;

class Displayer : public QWidget
{
public:
    Displayer(int width, int height, const QColor & background, QWidget * parent = 0);
    ~Displayer();
    void push(SineWave * sw);
    void pop();
protected:
    void paintEvent(QPaintEvent *);
    QList <SineWave *> *sineWaveList;
    QList<int> points;
};

#endif // DISPLAYER_H
