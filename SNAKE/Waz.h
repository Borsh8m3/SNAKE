#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Polozenie.h"

class Waz : public Obiekt {
private:
	std::vector<Polozenie> waz;
	Polozenie pole_opuszczane;
	int ilosc_pkt;
public:
	Waz() {
		Polozenie pol1;
		pol1.ustaw_x(1);
		pol1.ustaw_y(1);
		pol1.ustaw_czlon('X');
		waz.push_back(pol1);
		pole_opuszczane = pol1;
		ustaw_obecne_polozenie(pol1);
		ustaw_poprzednie_polozenie(pol1);
		ustaw_nazwe_gracza("gracz1");
		ilosc_pkt = waz.size();
	}
	std::vector<Polozenie> &podaj_weza() { return waz; };
	int podaj_dlugosc_weza() { return waz.size(); };
	void ustaw_ilosc_pkt(int il) { ilosc_pkt = il; };
	int podaj_ilosc_pkt() { return ilosc_pkt; };
};