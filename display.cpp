#include "display.h"
#include <QPainter>
#include "sinewave.h"
#include <QTimer>

namespace
{
const int FX = 300;  //first circle center x
const int FY = 300;  //first circle center y
const int WAVE_LEFT = 600; //wave display left x
//const int WAVE_MAX_DISPLAY_LENTH = 800;  //wavw display max length
}

Display::Display(QWidget *parent) :
    QWidget(parent),
    waves_(new QList<SineWave *>),
    timer_id_(0)
{
    this->setMinimumSize(800, 600);
    setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(222,123,102));
    setPalette(palette);
}

Display::~Display()
{
    foreach (SineWave *sw, *waves_) {
        delete sw;
    }
    delete waves_;
}

void Display::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    foreach (SineWave * sineWave, *waves_) {
        sineWave->draw(&painter);
    }

    if(!points_.isEmpty()){
        double x1 = WAVE_LEFT;
        double y1 = points_.first();
        double x2 = x1;
        foreach (double y2, points_) {
            painter.drawLine(x1, y1, x2, y2);
            x1 = x2;
            y1 = y2;
            x2++;
        }
    }

    if(!waves_->isEmpty()){
        QPointF p = waves_->last()->currentPosition();
        painter.drawLine(p, QPointF(WAVE_LEFT + points_.length(), p.y()));
    }

}

void Display::timerEvent(QTimerEvent *)
{
    step();
}

void Display::push(double radius, double speed)
{
    SineWave *sw = new SineWave(radius, speed, qRgb(qrand()%256, qrand()%256, qrand()%256));

    if(waves_->isEmpty())
        sw->setCenter(QPoint(FX, FY));
    else
        sw->setCenter(waves_->last()->currentPosition());
    waves_->push_back(sw);
    repaint();
}

void Display::pop()
{
    if(!waves_->empty())
        waves_->pop_back();
    repaint();
}

void Display::clear()
{
    waves_->clear();
    repaint();
}

void Display::step()
{
    static QPointF p;
    p = QPoint(FX, FY);
    foreach (SineWave * sineWave, *waves_)
    {
        sineWave->refresh();
        sineWave->setCenter(p);
        p = sineWave->currentPosition();
    }

    if(!waves_->isEmpty())
    {
        while(!points_.empty() && points_.length() >= this->width() - WAVE_LEFT)
            points_.pop_front();
        points_.push_back(waves_->last()->currentPosition().y());
    }
    else
    {
        while(!points_.empty() && points_.length() >= this->width()- WAVE_LEFT)
            points_.pop_front();
        points_.push_back(FY);
    }
    repaint();
}



