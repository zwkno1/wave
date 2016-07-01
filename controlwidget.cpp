#include "controlwidget.h"
#include "ui_controlwidget.h"

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(addSineWave()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SIGNAL(signalClear()));
    connect(ui->pushButton_step, SIGNAL(clicked()), this, SIGNAL(signalStep()));
    connect(ui->pushButton_control, SIGNAL(clicked()), this, SLOT(pauseResume()));
    connect(ui->pushButton_squareWave, SIGNAL(clicked()), this, SLOT(square()));
    connect(ui->pushButton_sawtooth, SIGNAL(clicked()), this, SLOT(sawtooth()));
}

ControlWidget::~ControlWidget()
{
    delete ui;
}

void ControlWidget::addSineWave()
{
    bool isOk = true;
    double a =  ui->lineEdit_1->text().toFloat(&isOk);
    if(!isOk)
        return;
    double w =  ui->lineEdit_2->text().toFloat(&isOk);
    if(!isOk)
        return;
    emit signalAdd(a, w);
}

void ControlWidget::pauseResume()
{
    if(this->ui->pushButton_control->text() == QString("&Pause") || this->ui->pushButton_control->text() == QString("Pause"))
    {
        this->ui->pushButton_control->setText("Resume");
    }
    else
    {
        this->ui->pushButton_control->setText(QString("Pause"));
    }
    emit signalPauseResume();
}

void ControlWidget::square()
{
    fourier(1);
}

void ControlWidget::sawtooth()
{
    fourier(2);
}

void ControlWidget::fourier(int type)
{
    bool isOk = true;
    double a =  ui->lineEdit_1->text().toFloat(&isOk);
    if(!isOk)
        return;
    double w =  ui->lineEdit_2->text().toFloat(&isOk);
    if(!isOk)
        return;
    int stage = ui->lineEdit_stage->text().toInt(&isOk);
    if(!isOk)
        return;

    emit signalFourier(type, a, w, stage);
}
