#ifndef SINEWAVE_H
#define SINEWAVE_H
#include <QPoint>
#include <QColor>

class QPainter;

class SineWave
{
    //y = A*sin(wt);
public:
    SineWave(double radius, double speed, const QColor & colo);

    void draw(QPainter *painter);

    void refresh();

    QPointF currentPosition() const;

    void setCenter(const QPointF & center);

private:
    QPointF center_;

    double radius_;

    double speed_;

    double current_phase_;

    QColor color_;
};

#endif // SINEWAVE_H
