#include "window.h"

Window::Window()
{
     this->setWindowTitle("Lab 1 graphics"); //изменение имени окна
     area = new Area(this); //создание холста
     btn = new QPushButton("Finish", this); //создание кнопки "Завершить"

     //компановка
     QVBoxLayout *layout = new QVBoxLayout(this);
     layout->addWidget(area);
     layout->addWidget(btn);

     connect(btn, SIGNAL(clicked(bool)),this,SLOT(close())); //подключение сигнал кнопки "Завершить" и слот закрытия окна
};
