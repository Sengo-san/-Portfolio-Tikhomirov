#include <QCoreApplication>

#include <string.h>
#include <iostream>

using namespace std;

#include <PersonKeeper.h>

//Тестирование 2 части лабораторной
int main(int argc, char *argv[])
{
   //открываем файл на чтение

    ifstream instr ("NameSource.txt");
    if (!instr)
        cout << "Opening file error"<<endl;
    //считываем из файла в стек
    PersonKeeper::Instance().readPersons(instr);
    instr.close();

   //открываем файл на запись
    ofstream outstr ("NameReciever.txt");
    //записываем из стека в файл
    PersonKeeper::Instance().writePersons(outstr);
    outstr.close();

    return 0;

}
