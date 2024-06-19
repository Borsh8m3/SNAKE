#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <time.h>

class Menu {
private:
	HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
	std::vector<std::string> MenuGlowne;
	std::string nazwa = "SNAKE";
	int polozenie;
	int obecnie_wybrana_opcja;
public:
	Menu();
	void Wypisz_linie(int ilosc_opcji);
	void Wypisz_opcje_menu();
	void Ustaw_pozycje_xy(int x, int y);
	int menu();
};