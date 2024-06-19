#include "Plansza.h"
#include <fstream>

Plansza::Plansza()
{
	//w tym miejscu dodajemy tworzymy plansze pe³n¹ 0:
	for (int i = 0; i < 22; i++) plansza[i][0] = '|';
	for (int i = 0; i < 22; i++) plansza[i][21] = '|';
	for (int i = 1; i < 21; i++) plansza[0][i] = '-';
	for (int i = 1; i < 21; i++) plansza[21][i] = '-';
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			plansza[i][j] = ' ';
		}
	}
	generuj_jablko();
	plansza[1][1] = snake.podaj_weza()[0].podaj_czlon();
	snake.podaj_weza()[0].ustaw_adres(&plansza[1][1]);
	ustaw_kursor(false);
	g_over = false;
}

void Plansza::generuj_jablko()
{
	srand(time(NULL));
	char X = 1, Y = 1;
	X = (rand() % 20) + 1;
	Y = (rand() % 20) + 1;
	plansza[X][Y] = '0';
	Polozenie p1;
	p1.ustaw_x(X);
	p1.ustaw_x(Y);
	p1.ustaw_czlon('0');
	p1.ustaw_adres(&plansza[X][Y]);
	jablko.ustaw_obecne_polozenie(p1);
	jablko.ustaw_nazwe_gracza("Jablko");
}

void Plansza::generuj_weza(int X, int Y, char znak)
{
	Polozenie pol1;
	pol1.ustaw_x(X);
	pol1.ustaw_y(Y);
	pol1.ustaw_czlon(znak);
	pol1.ustaw_adres(&plansza[X][Y]);
	snake.podaj_weza().push_back(pol1);
	plansza[X][Y] = znak;
}

int Plansza::graj(int polozenie)
{
	Menu menu1; 
	int counter = 0;
	int wybor = 80;
	if (polozenie == 0) {
		ustaw_kursor(true);
		do {
			system("cls");
			std::cout << "Podaj nazwe gracza\n";
			std::string nazw;
			std::cin >> nazw;
			if (std::cin.fail() == true)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
				counter++;
			}
			else {
				snake.ustaw_nazwe_gracza(nazw);
			}
		} while (counter > 0);
	}
	ustaw_kursor(false);
	switch (polozenie) {
	case 0:
		do {
			system("cls");
			
			counter = 0;
			rysuj();
			wybor = _getch(); // pobieraj znak za pomoc¹ getch() bez oczekiwania na znak powrotu

			if (wybor == 224) { // jak 224 znak zosta³ wprowadzony to trzeba jeszcze pobraæ jeden znak
				wybor = wybor << 8; // przesuwam bitowo o 8 pozycji
				wybor |= _getch(); // i operacjê bitow¹ OR robiê z wartoœci¹ uzyskan¹ z getch() -a
			}
			else {
				//TU NAPISZ CZYSZCZENIE BUFORU
			}
			Polozenie nowe_pol;
			Waz waz1;
			switch (wybor) {
			case (224 << 8) | 75: // to dla strza³ki w górê
				nowe_pol.ustaw_x(snake.podaj_weza()[0].podaj_x());
				nowe_pol.ustaw_y(snake.podaj_weza()[0].podaj_y() - 1);
				nowe_pol.ustaw_czlon('X');
				nowe_pol.ustaw_adres(&plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()]);
			
				wybor = 75;
				break;
			case (224 << 8) | 77: // to dla strza³ki w dó³
				nowe_pol.ustaw_x(snake.podaj_weza()[0].podaj_x());
				nowe_pol.ustaw_y(snake.podaj_weza()[0].podaj_y() + 1);
				nowe_pol.ustaw_czlon('X');
				nowe_pol.ustaw_adres(&plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()]);
								
				wybor = 77;
				break;
			case (224 << 8) | 80: // to dla strza³ki w prawo
				nowe_pol.ustaw_x(snake.podaj_weza()[0].podaj_x() + 1);
				nowe_pol.ustaw_y(snake.podaj_weza()[0].podaj_y());
				nowe_pol.ustaw_czlon('X');
				nowe_pol.ustaw_adres(&plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()]);
				
				wybor = 80;
				break;
			case (224 << 8) | 72: // to dla strza³ki w lewo	
				nowe_pol.ustaw_x(snake.podaj_weza()[0].podaj_x() - 1);
				nowe_pol.ustaw_y(snake.podaj_weza()[0].podaj_y());
				nowe_pol.ustaw_czlon('X');
				nowe_pol.ustaw_adres(&plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()]);
								
				wybor = 72;
				break;
			case (13): //wyjscie
				wybor = 0;
				break;
			default: // w przypadkach innych ni¿ powy¿sze
				if (wybor == 75) {
					nowe_pol.ustaw_x(snake.podaj_weza()[0].podaj_x());
					nowe_pol.ustaw_y(snake.podaj_weza()[0].podaj_y() - 1);
					nowe_pol.ustaw_czlon('X');
					nowe_pol.ustaw_adres(&plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()]);
				}
				else if (wybor == 77) {
					nowe_pol.ustaw_x(snake.podaj_weza()[0].podaj_x());
					nowe_pol.ustaw_y(snake.podaj_weza()[0].podaj_y() + 1);
					nowe_pol.ustaw_czlon('X');
					nowe_pol.ustaw_adres(&plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()]);
				}
				else if (wybor == 80) {
					nowe_pol.ustaw_x(snake.podaj_weza()[0].podaj_x() + 1);
					nowe_pol.ustaw_y(snake.podaj_weza()[0].podaj_y());
					nowe_pol.ustaw_czlon('X');
					nowe_pol.ustaw_adres(&plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()]);
				}
				else if (wybor == 72) {
					nowe_pol.ustaw_x(snake.podaj_weza()[0].podaj_x() - 1);
					nowe_pol.ustaw_y(snake.podaj_weza()[0].podaj_y());
					nowe_pol.ustaw_czlon('X');
					nowe_pol.ustaw_adres(&plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()]);
				}
				break;
			}
			int test = 0;
			if (!(plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()] == ' ' || plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()] == '0'))
			{
				polozenie = -1;
				test++;
			}
			
			if (counter == 0) snake.ustaw_poprzednie_polozenie(snake.podaj_weza().back());
				for (int i = snake.podaj_dlugosc_weza()-1; i > 0; i--)
				{
					if (snake.podaj_dlugosc_weza() > 1) {
						plansza[snake.podaj_weza()[i-1].podaj_x()][snake.podaj_weza()[i-1].podaj_y()] = snake.podaj_weza()[i].podaj_czlon();
						snake.podaj_weza()[i].ustaw_x(snake.podaj_weza()[i-1].podaj_x());
						snake.podaj_weza()[i].ustaw_y(snake.podaj_weza()[i-1].podaj_y());
						snake.podaj_weza()[i].ustaw_adres(snake.podaj_weza()[i-1].podaj_adres());
						plansza[snake.podaj_poprzednie_polozenie().podaj_x()][snake.podaj_poprzednie_polozenie().podaj_y()] = ' ';
					}
				}
				if (snake.podaj_dlugosc_weza() == 1) {
					plansza[snake.podaj_poprzednie_polozenie().podaj_x()][snake.podaj_poprzednie_polozenie().podaj_y()] = ' ';
				}
		
				counter = 0;
				plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()] = 'X';
				snake.podaj_weza()[0].ustaw_x(nowe_pol.podaj_x());
				snake.podaj_weza()[0].ustaw_y(nowe_pol.podaj_y());
				snake.podaj_weza()[0].ustaw_adres(&plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()]);
			
			if (snake.podaj_weza()[0].podaj_adres() == jablko.podaj_obecne_polozenie().podaj_adres()) {
				counter = 2;
				Polozenie dodatkowy;
				dodatkowy = snake.podaj_poprzednie_polozenie();
				dodatkowy.ustaw_czlon('#');
				snake.podaj_weza().push_back(dodatkowy);
				generuj_jablko();

				plansza[snake.podaj_weza()[snake.podaj_dlugosc_weza() - 1].podaj_x()][snake.podaj_weza()[snake.podaj_dlugosc_weza() - 1].podaj_y()] = '#';
				
				plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()] = 'X';
				snake.podaj_weza()[0].ustaw_x(nowe_pol.podaj_x());
				snake.podaj_weza()[0].ustaw_y(nowe_pol.podaj_y());
				snake.podaj_weza()[0].ustaw_adres(&plansza[nowe_pol.podaj_x()][nowe_pol.podaj_y()]);
				snake.ustaw_poprzednie_polozenie(snake.podaj_weza()[snake.podaj_dlugosc_weza() - 1]);
				plansza[snake.podaj_poprzednie_polozenie().podaj_x()][snake.podaj_poprzednie_polozenie().podaj_y()] = snake.podaj_weza()[snake.podaj_dlugosc_weza() - 1].podaj_czlon();
				
			}
			if (test == 1)
			{
				system("cls");
				ustaw_kursor(true);
				game_over();
				rysuj();
				std::cout << "koniec gry, twoj wynik to: " << snake.podaj_dlugosc_weza() - 1 << std::endl;
				std::cout << "Wcisnij dowolny przycisk zeby przjesc dalej\n" << std::endl;
				counter = _getch();
				std::cout << "Wciœnij q, jeœli naprawdê chcesz wyjœæ z programu...\n";
				while (_getch() != 'q')
				polozenie = -1;
				zapisz();
			}
		} while (polozenie > -1);
		break;
	case 1:
		system("cls");
		ustaw_kursor(true);
		odczyt();
		std::cout << "Wciœnij enter, aby przejœæ do menu...";
		_getch();
		system("cls");
		break;
	case 2:
		system("cls");
		ustaw_kursor(true);
		std::cout << "Wciœnij q, jeœli naprawdê chcesz wyjœæ z programu...\n";
		if (_getch() == 'q')
		polozenie = -1;
		break;
	}
	return polozenie;
}

void Plansza::rysuj()
{
	std::cout << "  ---------------------------- SNAKE ----------------------------" << std::endl;
	std::cout << "  Nazwa gracza: ";
	SetConsoleTextAttribute(uchwyt, 240); // to trzeba j¹ podœwietliæ
	std::cout << snake.podaj_nazwe_gracza() << "\n";
	SetConsoleTextAttribute(uchwyt, 7); // to trzeba j¹ podœwietliæ
	std::cout << "     Ilosc Punktow:  "; 
	SetConsoleTextAttribute(uchwyt, 240); // to trzeba j¹ podœwietliæ
	std::cout << snake.podaj_dlugosc_weza() - 1;
	SetConsoleTextAttribute(uchwyt, 7); // to trzeba j¹ podœwietliæ
	std::cout << "          Jesli chesz wyjsc wcisnij:  ";
	SetConsoleTextAttribute(uchwyt, 240); // to trzeba j¹ podœwietliæ
	std::cout << "ESC";
	SetConsoleTextAttribute(uchwyt, 7); // to trzeba j¹ podœwietliæ
	std::cout << std::endl;
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if ((6 < i) && (i < 14) && (5 < j) && (j < 16) && (g_over == true)) SetConsoleTextAttribute(uchwyt, 240); // to trzeba j¹ podœwietliæ
			std::cout << "  ";
			std::cout << plansza[i][j];
			if ((6 < i) && (i < 14) && (5 < j) && (j < 16) && (g_over == true)) SetConsoleTextAttribute(uchwyt, 7); // to trzeba j¹ podœwietliæ
		}
		std::cout << std::endl;
	}
}

void Plansza::game_over()
{
	g_over = true;
	for (int i = 7; i < 13; i++)
	{
		for (int j = 5; j < 16; j++)
		{
			plansza[i][j] = ' ';
		}
	}
	plansza[8][6] = 'G';
	plansza[8][7] = 'A';
	plansza[8][8] = 'M';
	plansza[8][9] = 'E';
	plansza[8][10] = ' ';
	plansza[8][11] = 'O';
	plansza[8][12] = 'V';
	plansza[8][13] = 'E';
	plansza[8][14] = 'R';

	plansza[10][6] = 'I';
	plansza[10][7] = 'L';
	plansza[10][8] = 'O';
	plansza[10][9] = 'S';
	plansza[10][10] = 'C';
	
	plansza[10][12] = 'P';
	plansza[10][13] = 'K';
	plansza[10][14] = 'T';
	
	int a = snake.podaj_dlugosc_weza();
	int b = 0;
	if (snake.podaj_dlugosc_weza() > 10)
	{
		b = a/10;
		plansza[12][9] = b+48;
		plansza[12][11] = snake.podaj_dlugosc_weza() - 1 - (b * 10) + 48;
	}
	else plansza[12][10] = a+47;
}

void Plansza::zapisz()
{
	std::ofstream plik;
	plik.open("wyniki_gier.txt", std::ifstream::app);
	plik << snake.podaj_nazwe_gracza();
	plik << "\n";
	plik << snake.podaj_dlugosc_weza()-1;
	plik << "\n";
	plik.close();
}

void Plansza::odczyt()
{
	std::ifstream plik;
	std::vector<Waz> odczyt;
	std::string nazwa = "5";
	char punkty[3];
	char test = 0;
	Waz p;
	plik.open("wyniki_gier.txt", std::ifstream::in);
	if (plik.is_open() > 0)
	{
		while (getline(plik, nazwa))
		{
			int pkt = 0;
			p.ustaw_nazwe_gracza(nazwa);
			getline(plik, nazwa);
			int j = 1;
			while(j >= 0) {
				if((j == 0) && (pkt != 0)) pkt += ((int)nazwa[j] - 48) *10;
				else if((int)nazwa[j] != 0) pkt = ((int)nazwa[j]-48);
				else if((j == 0) && (pkt == 0)) pkt = ((int)nazwa[j] - 48);
				j--;
			}
			p.ustaw_ilosc_pkt(pkt);
			odczyt.push_back(p);
		}
		for (int i = 0; i < odczyt.size() - 1; i++) {
			for (int j = 0; j < odczyt.size() - i - 1; j++) {
				if (odczyt[j].podaj_ilosc_pkt() < odczyt[j + 1].podaj_ilosc_pkt()) {
					Waz temp = odczyt[j];
					odczyt[j] = odczyt[j + 1];
					odczyt[j + 1] = temp;
				}
			}
		}
		std::cout << "Lista najlepszych wyników\n";
		for (int i = 0; i < odczyt.size(); i++) {
			if(odczyt[i].podaj_ilosc_pkt() > 10) std::cout << i + 1 << ". " << odczyt[i].podaj_ilosc_pkt() << "PKT" << "  -->  " << odczyt[i].podaj_nazwe_gracza() << "\n";
			else std::cout << i + 1 << ". " << odczyt[i].podaj_ilosc_pkt() << "PKT" << "  --->  " << odczyt[i].podaj_nazwe_gracza() << "\n";
		}
		
	}
	else {
		std::cout << "Brak zapisanych wyników\n";
	}
	plik.close();
}

void Plansza::ustaw_kursor(bool ustaw)
{
	_CONSOLE_CURSOR_INFO kursor;
	kursor.dwSize = sizeof(CONSOLE_CURSOR_INFO);
	kursor.bVisible = ustaw;
	SetConsoleCursorInfo(uchwyt, &kursor);
}

