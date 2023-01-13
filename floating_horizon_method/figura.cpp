#include <math.h>
#include "figura.h"
#include <math.h>
#include <string>

Matrix Wave::rotate (float x,  float y,  float z)
{
    Matrix old (1, 4);
    old.set(x, 0, 0);
    old.set(y, 0, 1);
    old.set(z, 0, 2);
    old.set(1, 0, 3);

    //Делаем матрицу поворота:
    float c = cos(this->Ux);
    float s = sin(this->Ux);

    float rot_[4][4] = {
       {1,0,0,0},
       {0,c,-s,0},
       {0,s,c,0},
       {0,0,0,1}
    };

    float** rot = new float* [4];

    for (int i = 0; i < 4; i++){
        rot[i] = new float [4];
        for (int j = 0; j < 4; j++)
            rot[i][j] = rot_[i][j];
    }

    Matrix Rot (rot, 4, 4); //матрица вращения

    Matrix res (old * Rot);

    return res;
}

Wave::Wave (float Xmin_, float Xmax_, float Zmin_, float Zmax_, float Dz_, float Dx_,/* float Uy_,*/ float Ux_, int MaxX_, int MaxY_)
{
    Xmin=Xmin_;    Xmax=Xmax_;
    Zmin=Zmin_;    Zmax=Zmax_;
    Dz=Dz_;        Dx=Dx_;
    Uy=0;/*Uy_;*/  Ux=Ux_;    //углы поворота, – π/2 < Uy, Ux < π/2
    MaxX=MaxX_;    MaxY=MaxY_;    //размер экрана


    Cx = MaxX/2;   Cy = MaxY/2;    //центр поля вывода на экране
    Px = MaxX/2;   Py = MaxY/2;    //полуразмеры поля вывода на экране

    Pkx = MaxX/2;  Pky = MaxY/2;  //полуразмеры окна на картинной плоскости


    this->Up = new int [MaxX];
    this->Down = new int [MaxX];
    // Устанавливаем горизонты Up[MaxX] и Down[MaxX] в 0 и МахY
    for (int i = 0; i < MaxX; i++){
        Up[i] = 0;
        Down[i] = MaxY;
    }

}

void Wave::move(QPainter *Painter)
{

    this->Zmax+=this->Dz;
    if (Zmax > 3*3.141) {
        this->Ux+=3.141;
        Zmax=-2*3.141+Dz;}
    //this->Ux+=0.4;

   draw(Painter);
}

void Wave::draw(QPainter *Painter)
{

    /****** 1 вариант: поворот вокруг оси x, рисовать точками ******/
    // Устанавливаем горизонты Up[MaxX] и Down[MaxX] в 0 и МахY
    for (int i = 0; i < MaxX; i++){
        Up[i] = 0;
        Down[i] = MaxY;
    }

  Painter->setPen(Qt::red);

    float z = Zmin;
    while (z <= Zmax){//ЦИКЛ по секущим плоскостям для Zmin ≤ z ≤ Zmax с шагом Dz.
        float x = Xmin;
        while (x <= Xmax){//ЦИКЛ по точкам сечения Xmin ≤ х ≤ Хmax с шагом Dx.
            float y = this->f(x,z); //Вычисляем значение функции y = f(x,z).
             //Повернув точку x, y, z, имеем её проекцию Хк, Yк на картинную плоскость:
            float Xk = rotate(x, y, z).get(0, 0);
            float Yk = rotate(x, y, z).get(0, 1);
            //Учтя размеры окна и поля вывода, вычисляем экранные координаты точки Yэ, Xэ

            int Xe = Xk*Pkx/8 + Cx;
            int Ye = (Yk*Pky/8 + Cy);

            //Формируем признак ее видимости VID, используя старые горизонты (Up и Down):
            unsigned int VID;
            if (Ye < Up[Xe] && Ye > Down[Xe]) VID = 0; //тточк ниже верхнего и выше нижнего горизонтов
            if (Ye > Up[Xe]) VID = 1;   //точка выше верхнего горизонта (видна)
            if (Ye < Down[Xe]) VID = 2; //точка ниже нижнего горизонта (видна)
            if (Ye > Up[Xe] && Ye < Down[Xe]) VID = 3;  //точка выше верхнего и ниже нижнего горизонтов

            if (VID == 1 || VID == 2 || VID == 3){
            //if (Ye > Up[Xe] || Ye < Down[Xe]){
                Painter->drawPoint(Xe, Ye);

              if (VID == 1) Up[Xe] = Ye;
              if (VID == 2) Down[Xe] = Ye;
              if (VID == 3){
                  Down[Xe] =Ye;
                  Up [Xe] = Ye;
              }

            }
            x+=Dx;            
        }
        z+=Dz;
    }
}
