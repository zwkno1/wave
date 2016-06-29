#include "sinewave.h"
#include <QPainter>
#include <QTime>
#include <math.h>

SineWave::SineWave(double radius, double speed, const QColor & color) :
    center_(QPoint(0,0)),
    radius_(radius),
    speed_(speed),
    current_phase_(0),
    color_(color)
{
    qsrand(QTime::currentTime().msec());
}

void SineWave::draw(QPainter *painter)
{
    painter->save();
    painter->setPen(QPen(color_));
    painter->drawEllipse(center_, radius_, radius_);
    painter->setBrush(QBrush(color_));
    painter->drawEllipse(currentPosition(), 2, 2);
    painter->restore();
}

void SineWave::refresh()
{
    current_phase_ += speed_;
}

QPointF SineWave::currentPosition() const
{
    return QPointF(center_.x() + radius_*cos(current_phase_), center_.y() + radius_*sin(current_phase_));
}

void SineWave::setCenter(const QPointF &center)
{
    center_ = center;
}
