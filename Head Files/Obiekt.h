#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Polozenie.h"

class Obiekt {
private:
	Polozenie obecne_polozenie;
	Polozenie poprzednie_polozenie;
	std::string nazwa_gracza;
public:
	void ustaw_poprzednie_polozenie(Polozenie poprzednie) { poprzednie_polozenie = poprzednie; };
	void ustaw_obecne_polozenie(Polozenie obecne) { obecne_polozenie = obecne; };
	Polozenie& podaj_poprzednie_polozenie() { return poprzednie_polozenie; };
	Polozenie& podaj_obecne_polozenie() { return obecne_polozenie; };
	std::string podaj_nazwe_gracza() { return nazwa_gracza; }
	void ustaw_nazwe_gracza(std::string nazwa) { nazwa_gracza = nazwa; }
};
