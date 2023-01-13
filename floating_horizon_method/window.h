#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtGui>

#include "area.h"

#include <QPushButton>
#include <QVBoxLayout>


class Window : public QWidget //класс окна
{
protected:
     //QTextCodec *codec;
     Area *area; // область отображения рисунка
     QPushButton *btn; //кнопка "завершить"

public:
    Window();
};

#endif // WINDOW_H
