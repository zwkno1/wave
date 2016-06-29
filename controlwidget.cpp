#include "controlwidget.h"
#include "ui_controlwidget.h"

ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(addSineWave()));
    connect(ui->pushButton_deleteLast, SIGNAL(clicked()), this, SIGNAL(signalPop()));
    connect(ui->pushButton_step, SIGNAL(clicked()), this, SIGNAL(signalStep()));
    connect(ui->pushButton_control, SIGNAL(clicked()), this, SLOT(pauseResume()));
}

ControlWidget::~ControlWidget()
{
    delete ui;
}

void ControlWidget::addSineWave()
{
    bool isOk = true;
    double r =  ui->lineEdit_1->text().toFloat(&isOk);
    if(!isOk)
        return;
    double w =  ui->lineEdit_2->text().toFloat(&isOk);
    if(!isOk)
        return;
    emit signalAdd(r, w);
}

void ControlWidget::pauseResume()
{
    if(this->ui->pushButton_control->text() == QString("&Pause"))
    {
        this->ui->pushButton_control->setText("Resume");
    }
    else
    {
        this->ui->pushButton_control->setText(QString("Pause"));
    }
    emit signalPauseResume();
}
