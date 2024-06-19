#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "Polozenie.h"
#include "Obiekt.h"
#include "Waz.h"
#include "Menu.h"

class Plansza {
private:
	HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
	char plansza[32][32];
	Obiekt jablko;
	Waz snake;
	bool g_over;
public:
	Plansza();
	void generuj_jablko();
	void generuj_weza(int X, int Y, char znak);
	char* podaj_pozycje(Polozenie p) { return &plansza[p.podaj_x()][p.podaj_y()]; };
	int graj(int polozenie);
	void rysuj();
	void game_over();
	void zapisz();
	void odczyt();
	void ustaw_kursor(bool ustaw);
};
