#ifndef SINEWAVE_H
#define SINEWAVE_H
#include <QPoint>
#include <QColor>

class QPainter;

class SineWave
{
    //y = A*sin(wt);
public:
    SineWave(double radius, double speed, const QColor & color,const QPoint & center = QPoint(0,0));
    void draw(QPainter *painter);
    void refresh();
    QPointF currentPosition() const;
private:
    QPointF _center;
    double _radius;
    double _speed;
    double _currentPhase;
    QColor _color;
};

#endif // SINEWAVE_H
