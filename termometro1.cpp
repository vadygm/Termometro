#include "termometro1.h"
#include "ui_termometro1.h"
#include <QDebug>

Termometro1::Termometro1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro1)
{
    ui->setupUi(this);

    connect(ui->dialCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Fahr(int)));
    connect(ui->dialFahr,SIGNAL(valueChanged(int)),
            this, SLOT(fhar2Cent(int)));
    connect(ui->dialCent, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));
    connect(ui->dialFahr, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));
    connect(ui->dialCent, SIGNAL(sliderReleased()),
            this, SLOT(dialRelajado()));
    connect(ui->dialFahr, SIGNAL(sliderReleased()),
            this, SLOT(dialRelajado()));
    ////////////////////////////////////////////////////
    connect(ui->dialKelvin, SIGNAL(valueChanged(int)),
            this, SLOT(cent2kelv(int)));
    connect(ui->dialKelvin, SIGNAL(valueChanged(int)),
            this, SLOT(fhar2kelv(int)));
    connect(ui->dialKelvin, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));
    connect(ui->dialKelvin, SIGNAL(sliderReleased()),
            this, SLOT(dialRelajado()));


    ui->dialFahr->setValue(32);
    ui->dialKelvin->setValue(273);

}

Termometro1::~Termometro1()
{
    delete ui;
}

float Termometro1::cent2Fahr(int valor)
{
    if(ui->dialCent->hasFocus()){
        float f=valor*9.0/5+32;
        ui->dialFahr->setValue(f);
        return f;
    }
    return 0;
}

float Termometro1::fhar2Cent(int valor)
{
    if(ui->dialFahr->hasFocus()){
        float c=(valor-32)*9.0/5;
        ui->dialCent->setValue(c);
        return c;
    }
    return 0;
}

float Termometro1::cent2kelv(int valor)
{
    if(ui->dialKelvin->hasFocus()){
        float c=(valor-273.15);
        ui->dialCent->setValue(c);
        return c;
    }
    return 0;
}

float Termometro1::fhar2kelv(int valor)
{
    if(ui->dialKelvin->hasFocus()){
        float f=(valor-273.15)*5/9.0+32;
        ui->dialFahr->setValue(f);
        return f;
    }
    return 0;
}

void Termometro1::dialPresionado()
{
    if(ui->dialCent->hasFocus()){
        ui->dialCent->setCursor(Qt::ClosedHandCursor);

    }else{
        ui->dialFahr->setCursor(Qt::ClosedHandCursor);
        ui->dialKelvin->setCursor(Qt::ClosedHandCursor);
    }

}

void Termometro1::dialRelajado()
{
    if(ui->dialCent->hasFocus()){
        ui->dialCent->setCursor(Qt::OpenHandCursor);

    }else{
        ui->dialFahr->setCursor(Qt::OpenHandCursor);
        ui->dialKelvin->setCursor(Qt::OpenHandCursor);
    }
}

