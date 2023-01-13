#ifndef AREA_H
#define AREA_H

#include "figura.h"

class Area : public QWidget //класс холст
    {
     int myTimer; // идентификатор таймера
public:
     Area(QWidget *parent = 0);
     ~Area();
     Wave *wave;
protected:
    // обработчики событий
     void paintEvent(QPaintEvent *event); //рисование пошагово перемещающихся фигур
     void timerEvent(QTimerEvent *event); //инициация перерисовки Холста
     void showEvent(QShowEvent *event); //включение таймера
     void hideEvent(QHideEvent *event); //выключение таймера
    };

#endif // AREA_H
