#include <iostream>
#include "Plansza.h"

int main()
{
    HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
    _CONSOLE_CURSOR_INFO kursor;
    kursor.dwSize = sizeof(CONSOLE_CURSOR_INFO);
    kursor.bVisible = false;
    SetConsoleCursorInfo(uchwyt, &kursor);
    setlocale(LC_CTYPE, "Polish");
    Menu m1;
    int zmienna = 0;
    do {
        system("cls");
        zmienna = m1.menu();
        Plansza gra1;
        gra1.graj(zmienna);
    } while (zmienna != 2);
    return 0;
}