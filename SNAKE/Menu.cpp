#include "Menu.h"

Menu::Menu()
{
	polozenie = 0;
	obecnie_wybrana_opcja = 0;
	//w tym miejscu dodajemy opcje do menu:
	MenuGlowne.push_back("Graj ze mn�\t\t");
	MenuGlowne.push_back("Lista gier\t\t");
	MenuGlowne.push_back("Wyjd� z programu\t");
	//ustawianie pozycji 0
	Ustaw_pozycje_xy(0, 0);
}

void Menu::Ustaw_pozycje_xy(int x, int y)
{
	COORD kursor{}; // struktura stosowana do pozycjonowania
	kursor.X = x; // x i y to numery wiersza i kolumny, gdzie numeracja jest od 1 a w systemie od 0
	kursor.Y = y; // to samo co powy�ej
	SetConsoleCursorPosition(uchwyt, kursor); // ustaw pozycj� karetki
}

int Menu::menu()
{
	int wybor = 1;
	while (wybor) {
		Wypisz_opcje_menu(); // wypisuj dan� pozycj� korzystaj�c z funkcji WriteLine

		wybor = _getch(); // pobieraj znak za pomoc� getch() bez oczekiwania na znak powrotu

		if (wybor == 224) { // jak 224 znak zosta� wprowadzony to trzeba jeszcze pobra� jeden znak
			wybor = wybor << 8; // przesuwam bitowo o 8 pozycji
			wybor |= _getch(); // i operacj� bitow� OR robi� z warto�ci� uzyskan� z getch() -a
		}

		switch (wybor) {
		case (224 << 8) | 72: // to dla strza�ki w g�r�
			if (polozenie == 0) polozenie = MenuGlowne.size() - 1;
			else polozenie -= 1; // je�eli id nie jest r�wne zero to ustawiam id = id - 1
			obecnie_wybrana_opcja = polozenie;
			break;
		case (224 << 8) | 80: // to dla strza�ki w d�
			if (polozenie == MenuGlowne.size() - 1) polozenie = 0;
			else polozenie += 1; // jak id < liczby pozycji menu to id ++
			obecnie_wybrana_opcja = polozenie;
			break;
		case (13): //wyjscie
			wybor = 0;
			break;
		default: // w przypadkach innych ni� powy�sze
			if (polozenie > 47 && polozenie < 48 + MenuGlowne.size()) { // gdy dany znak odpowiada pozycji w menu (np. 0, 1, ...) to
				polozenie = wybor - 48; // obliczanie pozycji z menu
				break;
			}
		}
	}
	return polozenie; // zwracam numer wybranej pozycji
}

void Menu::Wypisz_linie(int ilosc_opcji)
{
	for (int i = 0; i < ilosc_opcji; i++) {
		std::cout << "-";
	}
	std::cout << " ";
}

void Menu::Wypisz_opcje_menu()
{
	Ustaw_pozycje_xy(0, 0); // ustawienie karetki klawiatury w linii 1 i kolumnie 1
	Wypisz_linie(4); // rysuj� lini� ------ o d�ugo�ci r�wnej d�ugo�ci tekstu tytu�y menu
	std::cout << nazwa << " "; // wypisuj� menu
	Wypisz_linie(4); // i znowu linia ------
	std::cout << std::endl;
	for (int i = 0; i < MenuGlowne.size(); i++) { // dla wszystkich pozycji menu
		if (i == obecnie_wybrana_opcja) { // gdy pozycja jest wybrana
			//SetConsoleTextAttribute(uchwyt, 240); // to trzeba j� pod�wietli�
			std::cout << "> " << i + 1 << ". " << MenuGlowne[i] << std::endl; // wypisuj� pozycj� z menu i dodaj� jej numer w nawiasach kwadratowych
			//SetConsoleTextAttribute(uchwyt, 7); // powracam do domy�lnych ustawie� kolor�w
		}
		else { // w przeciwnym przypadku
			std::cout << "  " << i + 1 << ". " << MenuGlowne[i] << std::endl; // wypisuj� tekst danej pozycji menu i dodaj� jej indeks w nawiasach kwadratowych
		}
	}
}