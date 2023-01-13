#include "area.h"



Area::Area(QWidget *parent) : QWidget(parent)
{
    setFixedSize (QSize(600, 600)); //размер холста

    this->wave = new Wave (-2 * 3.141, //Xmin_
                            2 * 3.141,//Xmax_
                           -2 * 3.141,//Zmin_
                            -2 * 3.141, //Zmax_
                            0.5, //Dz_
                            0.03, //Dx_
                            3.14 + 0.5,//Ux_
                            600, //MaxX_
                            600);//MaxY_
}

void Area::showEvent(QShowEvent *) //включение таймера
{
     myTimer = startTimer(100); // создать таймер (50 мс)
}

void Area::paintEvent(QPaintEvent *) //рисование пошагово перемещающихся фигур
{
     QPainter painter(this); //перо
     painter.setPen(Qt::red); //цвет пера - красный
     this->wave->move(&painter);//перерисовка
}

void Area::timerEvent (QTimerEvent *event) //инициация перерисовки Холста
{
     if (event->timerId() == myTimer){ // если наш таймер
       update(); // обновить внешний вид
     }
     else
     QWidget::timerEvent(event); // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *) //выключение таймера
{
    killTimer(myTimer); // уничтожить таймер
}

Area::~Area() //деструктор. Класс-родитель (в смысле иерархии виджетов) холст отвечает за освобождение памяти от потомков (линии и квадрата)
{
 delete wave;
}
