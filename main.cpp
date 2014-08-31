#include "mainwindow.h"
#include <QApplication>
#include "displayer.h"
#include "sinewave.h"
#include <QTime>
#include <unistd.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Displayer d(800, 600, QColor(222,123,102));
    qsrand(QTime::currentTime().msec() + QTime::currentTime().second()*1000);
    QColor color;
    ::usleep(2000);
    color = qRgb(qrand()%255, qrand()%255, qrand()%255);
    d.push(new SineWave(100, 0.01, color));
    ::usleep(2000);
    qsrand(QTime::currentTime().msec() + QTime::currentTime().second()*1000);
    color = qRgb(qrand()%255, qrand()%255, qrand()%255);
    d.push(new SineWave(50,0.03, color));
    ::usleep(2000);
    qsrand(QTime::currentTime().msec() + QTime::currentTime().second()*1000);
    color = qRgb(qrand()%255, qrand()%255, qrand()%255);
    d.push(new SineWave(30,0.05, color));

    d.show();

    //MainWindow w;
    //w.show();

    return a.exec();
}
