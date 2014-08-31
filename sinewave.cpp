#include "sinewave.h"
#include <QPainter>
#include <QTime>
#include <math.h>
const int pi = 3.14159265;

SineWave::SineWave(double radius, double speed, const QColor & color, const QPoint & center) :
    _radius(radius),
    _speed(speed),
    _center(center),
    _currentPhase(0),
    _color(color)
{
    qsrand(QTime::currentTime().msec());
}

void SineWave::draw(QPainter *painter)
{
    painter->save();
    painter->setPen(QPen(_color));
    painter->drawEllipse(_center, _radius, _radius);
    painter->setBrush(QBrush(_color));
    painter->drawEllipse(currentPosition(), 2, 2);
    painter->restore();
}

void SineWave::refresh()
{
    _currentPhase += _speed;
}

QPointF SineWave::currentPosition() const
{
    return QPointF(_radius*cos(_currentPhase),_radius*sin(_currentPhase));;
}
