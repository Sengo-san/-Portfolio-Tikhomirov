#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>
#include <QWidget>
#include "matrix.h"

class Wave
{
private:
    float Xmin, Xmax, Zmin, Zmax; //область определения
  //  int* z;//(?) = Zmin, …, Zmax семейство секущих плоскостей
    float Dz,   //шаг по z (между секущими плоскостями);
        Dx;   //шаг по x (между точками сечения)
    float Uy, Ux,   //углы поворота, – π/2 < Uy, Ux < π/2
          Cx, Cy,    //центр поля вывода на экране
           Px,Py;    //полуразмеры поля вывода на экране
   int   MaxX, MaxY;   //размер экрана
     float     Pkx, Pky;  //полуразмеры окна на картинной плоскости

    int *Up;
   int *Down;


    void draw (QPainter *Painter);

public:
    void move (QPainter *Painter);
    float f(float x, float z) {return cos(sqrt(x*x+z*z)); }; //волна
    //float f(float x, float z) {return exp(-sqrt(x*x+z*z)) - 0.5; }; //пик
    //float f(float x, float z) {return abs(x*z); }; //птичка
    Matrix rotate (float x, float y, float z);//поворот трех координат вокруг Ох
    //Matrix rotate_2dim (float x, float y);//поворот двух точек вокруг оси Оy
    Wave (float Xmin_, float Xmax_, float Zmin_, float Zmax_, float Dz_, float Dx_,/* float Uy_,*/ float Ux_, int MaxX_, int MaxY_);
};


#endif // FIGURA_H
