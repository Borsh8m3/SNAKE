#pragma once
#include <iostream>

class Polozenie {
private:
	int X;
	int Y;
	char* adres_polozenia;
	char czlon;
public:
	Polozenie() { X = 0; Y = 0; czlon = '#'; adres_polozenia = nullptr; };
	int podaj_x() { return X; }
	int podaj_y() { return Y; }
	void ustaw_x(int x) { X = x; };
	void ustaw_y(int y) { Y = y; };
	void ustaw_adres(char* adres) { adres_polozenia = adres; };
	char* podaj_adres() { return adres_polozenia; };
	void ustaw_czlon(char znak) { czlon = znak; };
	char podaj_czlon() { return czlon; };
};
