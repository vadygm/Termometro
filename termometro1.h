#ifndef TERMOMETRO1_H
#define TERMOMETRO1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Termometro1; }
QT_END_NAMESPACE

class Termometro1 : public QMainWindow
{
    Q_OBJECT

public:
    Termometro1(QWidget *parent = nullptr);
    ~Termometro1();
public slots:
    float cent2Fahr(int);
    float fhar2Cent(int);
    float cent2kelv(int);
    float fhar2kelv(int);
    void dialPresionado();
    void dialRelajado();

private:
    Ui::Termometro1 *ui;
};
#endif // TERMOMETRO1_H
