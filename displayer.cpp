#include "displayer.h"
#include <QPainter>
#include	"sinewave.h"
#include <QTimer>

Displayer::Displayer(int width, int height, const QColor & background, QWidget *parent) :
    QWidget(parent),
    sineWaveList(new QList<SineWave *>)
{
    setGeometry(0, 0, width, height);
    QPalette palette;
    palette.setColor(QPalette::Background, background);
    setPalette(palette);

    QTimer *timer = new QTimer(this);
    timer->setInterval(100);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));

}

Displayer::~Displayer()
{
    foreach (SineWave *sw, *sineWaveList) {
        delete sw;
    }
    delete sineWaveList;
}

void Displayer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.translate(300,300);
    int i = 0;
    foreach (SineWave * sineWave, *sineWaveList) {
        sineWave->refresh();
        sineWave->draw(&painter);
        painter.translate(sineWave->currentPosition());
        if(i++ == sineWaveList->length()-1){
            points.push_back(sineWave->currentPosition().y());
        }
    }
    painter.transform().dx();
    painter.setPen(Qt::black);
    QPainter p(this);
    int x = 600;
    foreach (int y, points) {
        p.drawPoint(painter.transform().dx()+x, painter.transform().dy()+y);
            x++;
    }
}

void Displayer::push(SineWave *sw)
{
    sineWaveList->push_back(sw);
}

void Displayer::pop()
{
    sineWaveList->pop_back();
}
