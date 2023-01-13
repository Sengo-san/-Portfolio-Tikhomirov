//#include "Bintree.h"
//#include "SBinTree.h"
//#include "OSBinTree.h"
//const int N = 6;
//using namespace std;
//
//void PrTr(SBinTree T)
//{
//	if (T.GetRoot() == NULL) cout << "[Empty Tree]"<<endl;
//	else
//	{
//		cout << endl; T.Print(T.GetRoot(), 1, 4);
//	}
//}

////int main() //SBin
////{
////
////	
////	int a[11] = { 10,9,8,71,63,5,42,31,22,1 };
////	SBinTree T(a, 11);
////	SBinTree R(10);
////
////	cout <<endl<< "T(a[],11):"; PrTr(T);
////	cout << endl << "R(10):"; PrTr(R);
////
////	R.Delroot();
////	R.Add(10, R.GetRoot());
////	cout << endl << "R.delroot, add(10):"; PrTr(R);
////
////
////	cout << endl << "R.max: " << R.FindMax(R.GetRoot())->getkey();
////	cout << endl << "R.min: " << R.FindMin(R.GetRoot())->getkey();
////	
////	T.Del(T.FindKey(71, T.GetRoot()));
////	cout << endl << "T\71: "; PrTr(T);
////	
////	
////}
////
//int main()//OSbin
//{
//	
//
//	int* d = new int[N] {-1, 10, 20, 30, 40, 50 };
//	int* p = new int[N] {-1, 2, 1, 1, 5, 3};
//	int* q = new int[N] {1, 10, 1, 4, 10, 6};
//
//	OSBinTree T(d, p, q, N - 1);
//
//	PrTr(T);
//}


//
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    const int N = 6; //кол-во строк
//    const int M = 3; //кол-во столбцов 
//
//    int arr[N][M] =
//    {
//        {3, 2, 6},
//        {7, 0, 5},
//        {4, 9, 9},
//        {4, 6, 3},
//        {2, 11, 6},
//        {1, 1, 133}
//    };
//
//    int k, l, d; //k и l - пара с максимальным d, d - расстояние
//    int j, k_i, l_i; // j - индекс столбца, k_i - индекс для k строки, l_i - индекс для l строки
//
//    int sumK;   // сумма элементов k строки
//    int sumL;   // сумма элементов l строки
//    int d_max = 0;  // максимальное расстояние
//
//    _asm {
//
//        lea     ebx, [arr]; загружаем в ebx начальный адрес
//
//        mov     k_i, 0; k изначально 0
//        mov     j, 0; j - индекс столбца
//
//        mov     ecx, [N]; счетчик для цикла L1
//        dec     ecx; ecx = N - 1
//
//        L1:
//        push    ecx; сохраняем его в стек
//            mov     ecx, [N]; ecx - счетчик для L1
//            dec     ecx;
//        sub     ecx, [k_i]; ecx = N - k_i - 1
//            mov     edi, [k_i]; в edi помещаем k_i
//            inc     edi; k_i += 1
//            mov[l_i], edi; i = k_1 + 1
//
//            L2:
//        push    ecx; сохраняем его в стек
//            mov     ecx, [M]; в ecx помещаем M(счетчик для L3)
//            mov     sumK, 0; обнуляем сумму элементов строк k_i
//            mov     sumL, 0; обнуляем сумму элементов строк l_i
//
//            L3 :
//        mov     edi, [k_i]; находим смещение для arr[k_i][j]
//            imul    edi, [M]; edi = k_i * M + j
//            add     edi, j;
//
//        mov     eax, [ebx + edi * 4]; загружаем arr[k_i][j];
//        add[sumK], eax; sumK += arr[k][j]
//
//            mov     edi, [l_i]; находим смещение для arr[l_i][j]
//            imul    edi, [M]; edi = l_i * M + j
//            add     edi, j;
//
//        mov     eax, [ebx + edi * 4]; загружаем arr[l][j]
//            add[sumL], eax; sumL += arr[l_i][j]
//
//            inc     j; переход на следующий столбец
//            loop    L3; проход по столбцам
//
//            mov     j, 0; обнуляем индекс столбца для следующей пары строк
//            mov     eax, [sumK]; eax = sumK + sumL
//            add     eax, [sumL];
//        shr     eax, 1; eax = (sumK + sumL) / 2
//
//            cmp     eax, [d_max]; текущее растояние проверяем с максимальным d
//            jle     SKIP; если меньше или равно, то переход на SKIP
//            mov[d_max], eax; иначе в d_max помещаем расстояние данной пары
//
//            mov     eax, [k_i];
//        mov     k, eax; сохраняем k_i в памяти
//
//            mov     eax, [l_i];
//        mov     l, eax; сохраняем l_i в памяти
//
//            SKIP :
//        inc     l_i; переход на следующую строку l
//            pop     ecx; возвращаем счетчик(для L2) из стека
//            dec     ecx; вычитаем из счетчика проход
//            cmp     ecx, 0; проверяем на ноль
//            jne     L2; если не равен, то переход на L2
//
//            inc     k_i; переход на следующую строку k
//            pop     ecx; возвращаем счетчик(для L1) из стека
//
//            dec     ecx; вычитаем из счетчика проход
//            cmp     ecx, 0; проверяем на ноль
//            jne     L1; если не равен, то переход на L1
//    }
//
//    printf("k = %d, l = %d", k, l);
//
//}
//


// Author: Mario Talevski
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>

//Move OS defines up here to be used in different places
#if defined(_WIN32) || defined(WIN32) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WIN
//WINDOWS COLORS 
#define COLOR_RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED)
#define COLOR_WARNING SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN) 

#define COLOR_BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE)

#define COLOR_RESET SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)

#elif defined(linux) || defined(__CYGWIN__)
#define OS_LINUX

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m" 
#define COLOR_BLUE "\033[34m"
#define COLOR_RESET "\033[0m"

#elif (defined(__APPLE__) || defined(__OSX__) || defined(__MACOS__)) && defined(__MACH__)//To ensure that we are running on a mondern version of macOS
#define OS_MAC

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m" 
#define COLOR_BLUE "\033[34m"
#define COLOR_RESET "\033[0m"

#endif

#if defined(OS_WIN)
#include <windows.h> // Use for windows
#endif

using namespace std;

const int gridSize = 25;
void printGrid(bool gridOne[gridSize + 1][gridSize + 1]);
void determineState(bool gridOne[gridSize + 1][gridSize + 1]);
void clearScreen(void);


int main() {

    // system( "color A" );//LGT green
    cout << COLOR_GREEN;
    clearScreen();
    bool gridOne[gridSize + 1][gridSize + 1] = {};
    int x, y, n;
    string nc;
    string start;
    string filename;
    cout << "                         THE GAME OF life - Implementation in C++" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Also known simply as life, " << endl;
    cout << "is a cellular automaton devised by the British mathematician John Horton Conway in 1970." << endl;
    cout << endl;
    cout << "Rules" << endl;
    cout << "The universe of the Game of life is an infinite two-dimensional orthogonal grid of square cells," << endl;
    cout << "each of which is in one of two possible states, life or dead. Every" << endl;
    cout << "cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent." << endl;
    cout << "At each step in time, the following transitions occur:" << endl;
    cout << "1. Any live cell with fewer than two live neighbours dies, as if caused by under-population." << endl;
    cout << "2. Any live cell with two or three live neighbours lives on to the next generation." << endl;
    cout << "3. Any live cell with more than three live neighbours dies, as if by over-population." << endl;
    cout << "4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." << endl;
    cout << endl;
    cout << "O - living cell" << endl;
    cout << ". - dead cell" << endl;
    cout << endl;
    cout << "Enter the number of cells, or 'r' to read cells from file: ";
    cin >> nc;
    cout << endl;

    if (nc == "r")
    {
        while (true)
        {

            cout << "Enter name of file to read from: " << endl;
            cin >> filename;

            ifstream readfile(filename);
            if (readfile.is_open())
            {
                string fileline, xx, yy;

                while (getline(readfile, fileline))
                {
                    stringstream ss(fileline);

                    getline(ss, xx, ' ');
                    getline(ss, yy, ' ');

                    x = stoi(xx);
                    y = stoi(yy);

                    gridOne[x][y] = true;
                }
                break;
            }
            else {
                cout << "No such file, try again." << endl;
            }
        }
    }
    else
    {

        for (int i = 0; i < stoi(nc); i++)
        {
            cout << stoi(nc) << "Enter the coordinates of cell " << i + 1 << " : ";
            cin >> x >> y;
            gridOne[x][y] = true;
            printGrid(gridOne);
        }
    }
    cout << "Grid setup is done. Start the game ? (y/n)" << endl;
    printGrid(gridOne);
    cin >> start;
    if (start == "y" || start == "Y")
    {
        while (true)
        {
            printGrid(gridOne);
            determineState(gridOne);
            usleep(200000);
            clearScreen();
        }
    }
    else
    {
        cout << COLOR_RESET;
        clearScreen();
        return 0;
    }
}

void clearScreen(void) {
    // Tested and working on Ubuntu and Cygwin
#if defined(OS_WIN)
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = { 0, 0 };

    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords, &count);

    /* Fill the entire buffer with the current colors and attributes */
    FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count);

    SetConsoleCursorPosition(hStdOut, homeCoords);

#elif defined(OS_LINUX) || defined(OS_MAC)
    cout << "\033[2J;" << "\033[1;1H"; // Clears screen and moves cursor to home pos on POSIX systems
#endif

}


void printGrid(bool gridOne[gridSize + 1][gridSize + 1]) {
    for (int a = 1; a < gridSize; a++)
    {
        for (int b = 1; b < gridSize; b++)
        {
            if (gridOne[a][b] == true)
            {
                cout << " O ";
            }
            else
            {
                cout << " . ";
            }
            if (b == gridSize - 1)
            {
                cout << endl;
            }
        }
    }
}

void compareGrid(bool gridOne[gridSize + 1][gridSize + 1], bool gridTwo[gridSize + 1][gridSize + 1]) {
    for (int a = 0; a < gridSize; a++)
    {
        for (int b = 0; b < gridSize; b++)
        {
            gridTwo[a][b] = gridOne[a][b];
        }
    }
}

void determineState(bool gridOne[gridSize + 1][gridSize + 1]) {
    bool gridTwo[gridSize + 1][gridSize + 1] = {};
    compareGrid(gridOne, gridTwo);

    for (int a = 1; a < gridSize; a++)
    {
        for (int b = 1; b < gridSize; b++)
        {
            int alive = 0;
            for (int c = -1; c < 2; c++)
            {
                for (int d = -1; d < 2; d++)
                {
                    if (!(c == 0 && d == 0))
                    {
                        if (gridTwo[a + c][b + d])
                        {
                            ++alive;
                        }
                    }
                }
            }
            if (alive < 2)
            {
                gridOne[a][b] = false;
            }
            else if (alive == 3)
            {
                gridOne[a][b] = true;
            }
            else if (alive > 3)
            {
                gridOne[a][b] = false;
            }
        }
    }