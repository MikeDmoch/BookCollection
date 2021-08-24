#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ksiazka.h"
using namespace std;

#define N 40

struct ksiazka
{
	char autor[N];
	char tytul[N];
	char gatunek[N]; // literacki
	int rok; // wydania
	int ID;
};

struct biblioteka
{
	ksiazka* k;
	biblioteka* nast;
};

int sortuj(biblioteka**, int warunek_sortowania);

int generuj_id(biblioteka*);

int dodaj_ksiazke(biblioteka**, ksiazka);

void wypisz_biblioteke(biblioteka*);

void wypisz_czesc_ksiazek(biblioteka*, ksiazka, int warunek);

int usun_ksiazke(biblioteka**, int ID);

int pobierz_ID();

void pobierz_ksiazke(ksiazka& k);

int main()
{
	system("chcp 1250");
	system("cls");

	bool good = 1;
	ksiazka auxk;
	biblioteka* B = NULL;

	int a; 

	ksiazka ksiazki[] = { "Adam_Mickiewicz", "Dziady", "dramat", 1822, 1,
		"Henryk_Sienkiewicz", "Potop", "powieœæ", 1886, 2,
		"Adam_Mickiewicz", "Pan_Tadeusz", "epopeja", 1834, 3,
		"Eliza_Orzeszkowa", "Nad_Niemnem", "nowela", 1888, 4,
		"Boles³aw_Prus", "Lalka", "nowela", 1890, 5,
		"Cyprian_Kamil_Norwid", "Fortepian_Szopina", "poemat", 1865, 6,
		"Platon", "Pañstwo", "dialog", -380, 7,
		"Henryk_Sienkiewicz", "Ogniem_i_mieczem", "powieœæ", 1884, 8,
		"Henryk_Sienkiewicz", "Pan_Wo³odyjowski", "powieœæ", 1887, 9,
		"Juliusz_S³owacki", "Grób_Agamamnona", "wiersz", 1839, 10,
		"Jan_Kochanowski", "Odprawa_pos³ów_greckich", "tragedia", 1578, 11,
		"Jan_Kochanowski", "Na_lipê", "fraszka", 1584, 12,
		"Jan_Kochanowski", "Raki", "fraszka", 1584, 13,
		"W³adys³aw_Stanis³aw_Reymont", "Ch³opi_tom_I", "powieœæ", 1904, 14,
		"W³adys³aw_Stanis³aw_Reymont", "Ch³opi_tom_II", "powieœæ", 1904, 15,
		"W³adys³aw_Stanis³aw_Reymont", "Ch³opi_tom_III", "powieœæ", 1906, 16,
		"W³adys³aw_Stanis³aw_Reymont", "Ch³opi_tom_IV", "powieœæ", 1909, 17,
		"Stefan_¯eromski", "Przedwioœnie", "powieœæ", 1924, 18,
		"Stanis³aw_Wyspiañski", "Wesele", "dramat", 1901, 19,
		"Stefan_¯eromski", "Ludzie_bezdomni", "powieœæ", 1899, 20,
		"S³awomir_Mro¿ek", "Tango", "dramat", 1964, 21,
		"Stanis³aw_Ignacy_Witkiewicz", "Szewcy", "dramat", 1948, 22,
		"Juliusz_S³owacki", "Balladyna", "dramat", 1839, 23,
		"W³adys³aw_Reymont", "Ziemia_obiecana", "powieœæ", 1899, 24,
		"Juliusz_S³owacki", "Kordian", "dramat", 1834, 25,
		"Henryk_Sienkiewicz", "Krzy¿acy", "powieœæ", 1900, 26,
		"Aleksander_Fredro", "Zemsta", "komedia", 1838, 27,
		"Stefan_¯eromski", "Rozdziobi¹_nas_kruki,_wrony", "nowela", 1895, 28,
		"Zygmunt_Krasiñski", "Nie-Boska_komedia", "dramat", 1833, 29,
		"Zofia_Na³kowska", "Granica", "powieœæ", 1935, 30,
		"Henryk_Sienkiewicz", "Latarnik", "nowela", 1881, 31,
		"Stefan_¯eromski", "Si³aczka", "nowela", 1895, 32,
		"Bruno_Schultz", "Sklepy_cynamonowe", "opowiadania", 1933, 33,
		"Zofia_Na³kowska", "Medaliony", "opowiadania", 1946, 34,
		"Gabriela_Zapolska", "Moralnoœæ_Pani_Dulskiej", "komedia", 1907, 35,
		"Juliusz_S³owacki", "Sen_srebrny_Salomei", "dramat", 1843, 36,
		"Jaros³aw_Iwaszkiewicz", "Panny_z_Wilka", "opowiadanie", 1933, 37,
		"Gustaw_Herling-Grudziñski", "Inny_œwiat", "wspomnienia", 1951, 38,
		"Henryk_Sienkiewicz", "W_pustyni_i_w_puszczy", "powieœæ", 1911, 39,
		"Stefan_¯eromski", "Syzyfowe_prace", "powieœæ", 1897, 40
	};
	int n = sizeof(ksiazki) / sizeof(ksiazka); // ile ksi¹¿ek?

	for (int i = 0; i < n; i++) {
		if (dodaj_ksiazke(&B, ksiazki[i])); // funkcja w warunku zostanie wykonana przy jego sprawdzeniu
	}

	int var;
	do {
		puts("------------------- MOJA BIBLIOTEKA ------------------- ");
		puts("1.\tDodaj ksi¹¿kê");
		puts("2.\tWypisz ksi¹¿ki");
		puts("3.\tSortuj ksi¹¿ki");
		puts("4.\tUsuñ ksi¹¿kê");
		puts("5.\tWyszukaj ksi¹¿kê");
		puts("6.\tWyczyœæ ekran");
		puts("0.\tWyjœcie");

		cin >> var;
		switch (var)
		{
			case 1:	// dopisz ksi¹¿kê
			{
				pobierz_ksiazke(auxk);				
				auxk.ID = generuj_id(B);
				dodaj_ksiazke(&B, auxk);
				
				system("cls");
				break;
			}
			case 2:	// wypisz ksi¹¿ki
			{
				puts("\n"); // estetyka
				wypisz_biblioteke(B);
				break;
			}
			case 3:	// sortuj
			{
				cout << "Sortuj po:\n\n3.1. autor\n3.2. tytu³\n3.3. gatunek\n3.4. rok wydania\n3.5. numer ID" << endl;
				cin >> a;
				switch (a)
				{
					case 1:
					{
						sortuj(&B, 1);					
						break;
					}
					case 2:
					{
						sortuj(&B, 2);
						break;
					}
					case 3:
					{
						sortuj(&B, 3);
						break;
					}
					case 4:
					{
						sortuj(&B, 4);
						break;
					}
					case 5:
					{
						sortuj(&B, 5);
						break;
					}
					default:
					{
						puts("podano b³êdn¹ wartoœæ");
						break;
					}
					
				}
				break;
			}
			case 4: // usuñ
			{			
				usun_ksiazke(&B, pobierz_ID());

				break;
			}
			case 5: // wyszukaj
			{
				cout << "5.1. autor\n5.2. tytu³\n5.3. gatunek\n5.4. rok wydania\n5.5. ID" << endl;
				cin >> a;

				switch (a)
				{
				case 1: {
					cout << "Proszê podaæ autora" << endl;
					puts("u¿ywaj¹c podkreœlników '_' zamiast spacji ' ', podanie spacji spowoduje nieprawid³owe dzia³anie programu");
					scanf("%s", auxk.autor);				
					wypisz_czesc_ksiazek(B, auxk, a);
					break;
				}
				case 2: {
					cout << "Proszê podaæ tytu³" << endl;
					puts("u¿ywaj¹c podkreœlników '_' zamiast spacji ' ', podanie spacji spowoduje nieprawid³owe dzia³anie programu");
					scanf("%s", auxk.tytul);
					wypisz_czesc_ksiazek(B, auxk, a);
					break;
				}
				case 3: {
					cout << "Proszê podaæ gatunek" << endl;
					puts("u¿ywaj¹c podkreœlników '_' zamiast spacji ' ', podanie spacji spowoduje nieprawid³owe dzia³anie programu");
					scanf("%s", auxk.gatunek);
					wypisz_czesc_ksiazek(B, auxk, a);
					break;
				}
				case 4: {
					cout << "Proszê podaæ rok wydania" << endl;
					cin >> auxk.rok;
					wypisz_czesc_ksiazek(B, auxk, a);
					break;
				}
				case 5: {
					cout << "Proszê podaæ numer ID" << endl;
					cin >> auxk.ID;
					wypisz_czesc_ksiazek(B, auxk, a);
					break;
				}
				}
				break;

				wypisz_czesc_ksiazek(B, auxk, a);
			}
			case 6: // wyczyœæ ekran
			{
				system("cls");
				break;
			}
			case 0: // koniec
			{
				break;
			}
			default: break;
			
		}	

	} while (var); // zatrzymujemy gdy podamy '0'

	system("pause");
	return 0;
}

int dodaj_ksiazke(biblioteka** x, ksiazka y) // dodajemy ksi¹¿kê na pocz¹tek listy
{
	biblioteka* b1 = (biblioteka*)malloc(sizeof(biblioteka));	// rezerwacja pamiêci na wskaŸnik
	if (b1 == NULL) return 1; // malloc zwraca wskaŸnik NULL w przypadku b³êdu
	b1->k = (ksiazka*)malloc(sizeof(ksiazka));
	if (b1->k == NULL) return 1;

	b1->nast = *(x); // to po prawej "*(x)" mo¿na przeczytaæ jako "to na co wskazuje 'x'"
	*(b1->k) = y;
	*(x) = b1;

	return 0;
}

void wypisz_biblioteke(biblioteka* x)
{
	biblioteka* temp = (biblioteka*)malloc(sizeof(biblioteka));	// btw taka operacja (nazwa_typu*)(...) nazywa siê rzutowaniem
	temp = x;
	int rok;

	while (temp != NULL) {

		cout << temp->k->autor;
		cout << "\t";
		if (strlen(temp->k->autor) < 24) cout << "\t";	// liczby '8','16','24' wynikaj¹ z definicji oepratora '\t'
		if (strlen(temp->k->autor) < 16) cout << "\t";
		if (strlen(temp->k->autor) < 8) cout << "\t";

		cout << temp->k->tytul;
		cout << "\t";
		if (strlen(temp->k->tytul) < 24) cout << "\t";
		if (strlen(temp->k->tytul) < 16) cout << "\t";
		if (strlen(temp->k->tytul) < 8) cout << "\t";

		cout << temp->k->gatunek;
		cout << "\t";

		if (strlen(temp->k->gatunek) < 16) cout << "\t";
		if (strlen(temp->k->gatunek) < 8) cout << "\t";

		rok = temp->k->rok;

		if (rok >= 0) {
			cout << rok << " r.";
			cout << "\t" << "\t";
		}
		else {
			rok *= -1;
			cout << rok << " r.p.n.e." << "\t";
		}

		if (temp->k->ID < 10000) cout << "0";
		if (temp->k->ID < 1000) cout << "0";
		if (temp->k->ID < 100) cout << "0";
		if (temp->k->ID < 10) cout << "0";

		cout << temp->k->ID << endl;
		

		temp = temp->nast;
	}
}

int sortuj(biblioteka** x, int warunek_sortowania)
{

	ksiazka* tempk;

	int tempr;
	int compare;

	biblioteka* tempb = (biblioteka*)malloc(sizeof(biblioteka));	// rezerwacja pamiêci na wskaŸnik
	if (tempb == NULL) return 1; // malloc zwraca wskaŸnik NULL w przypadku b³êdu
	tempb->k = (ksiazka*)malloc(sizeof(ksiazka));
	if (tempb->k == NULL) return 1;

	biblioteka* tempb1 = (biblioteka*)malloc(sizeof(biblioteka));	// rezerwacja pamiêci na wskaŸnik
	if (tempb1 == NULL) return 1; // malloc zwraca wskaŸnik NULL w przypadku b³êdu
	tempb1->k = (ksiazka*)malloc(sizeof(ksiazka));
	if (tempb1->k == NULL) return 1;

	tempb = *(x);

	int n1 = 0; // ile ksi¹¿ek?
	{
		while (tempb != NULL) {
			n1++;
			tempb = tempb->nast;
		}
	}
	tempb = *(x);

	for (int i = 0; i < n1 - 1; i++) {
			// b¹belkowe nie zoptymalizowane
			tempb = *(x);

			while (tempb != NULL && tempb->nast != NULL) {

				tempb1 = tempb;
				tempb = tempb->nast;

				{	// w zale¿noœci od wyboru u¿ytkownika
					if (warunek_sortowania == 1) { // autor
						compare = strcmp(tempb1->k->autor, tempb->k->autor);
					}
					else if (warunek_sortowania == 2) { // tytu³
						compare = strcmp(tempb1->k->tytul, tempb->k->tytul);
					}
					else if (warunek_sortowania == 3) { // gatunek
						compare = strcmp(tempb1->k->gatunek, tempb->k->gatunek);
					}
					else if (warunek_sortowania == 4) { // rok wydania
						compare = tempb1->k->rok - tempb->k->rok;
					}
					else if (warunek_sortowania == 5) { // rok wydania
						compare = tempb1->k->ID - tempb->k->ID;
					}
				}
							
				if (compare > 0) { // zamiana

					tempk = tempb->k;	/// tempk - slot pamiêci
					tempb->k = tempb1->k;
					tempb1->k = tempk;
				}
				
			}
		}
}

void pobierz_ksiazke(ksiazka& k)
{
	puts("Proszê podaæ autora ksi¹¿ki");
	puts("u¿ywaj¹c podkreœlników '_' zamiast spacji ' ', podanie spacji spowoduje nieprawid³owe dzia³anie programu");

	scanf("%s", k.autor);
	
	puts("Proszê podaæ tytu³ ksi¹¿ki");
	puts("u¿ywaj¹c podkreœlników '_' zamiast spacji ' ', podanie spacji spowoduje nieprawid³owe dzia³anie programu");
	scanf("%s", k.tytul);

	puts("Proszê podaæ gatunek ksi¹¿ki");
	puts("u¿ywaj¹c podkreœlników '_' zamiast spacji ' ', podanie spacji spowoduje nieprawid³owe dzia³anie programu");
	scanf("%s", k.gatunek);

	puts("Proszê podaæ rok wydania tytu³u (jeœli rok jest p.n.e proszê podaæ wartoœæ ujemn¹)");
	puts("u¿ywaj¹c podkreœlników '_' zamiast spacji ' ', podanie spacji spowoduje nieprawid³owe dzia³anie programu");
	cin >> k.rok;
	while (cin.fail()) {

		cin.clear();
		cin.ignore();
		puts("Podano nieprawid³ow¹ wartoœæ, proszê wczytaæ ponownie");
		cin >> k.rok;
	}
}

int usun_ksiazke(biblioteka** x, int ID)
{
	int compare = 1;

	biblioteka* tempb = (biblioteka*)malloc(sizeof(biblioteka));	// rezerwacja pamiêci na wskaŸnik
	if (tempb == NULL) return 1; // malloc zwraca wskaŸnik NULL w przypadku b³êdu
	tempb->k = (ksiazka*)malloc(sizeof(ksiazka));
	if (tempb->k == NULL) return 1;

	biblioteka* tempb1 = (biblioteka*)malloc(sizeof(biblioteka));	// rezerwacja pamiêci na wskaŸnik
	if (tempb1 == NULL) return 1; // malloc zwraca wskaŸnik NULL w przypadku b³êdu
	tempb1->k = (ksiazka*)malloc(sizeof(ksiazka));
	if (tempb1->k == NULL) return 1;

	tempb = *(x);
	tempb1 = *(x);

	while (tempb != NULL && tempb->nast != NULL)
	{
		tempb1 = tempb->nast;

		if (tempb1->k->ID == ID) {	// tu nast¹pi usuniêcie ksi¹¿ki
			tempb->nast = tempb1->nast;
		}
		tempb = tempb->nast;
	}
}

int generuj_id(biblioteka* x)
{
	biblioteka* temp = (biblioteka*)malloc(sizeof(biblioteka));	// btw taka operacja (nazwa_typu*)(...) nazywa siê rzutowaniem
	temp = x;
	int n = 0;	// zliczamy ile jest ksi¹¿ek w bibliotece i na tej podstawie generujemy ID

	while (temp != NULL) {

		n++;
		temp = temp->nast;
	}

	return ++n;
}

int pobierz_ID()
{
	int a;

	cout << "Proszê podaæ numer ID ksi¹¿ki do usuniêcia" << endl;
	cin >> a;

	return a;
}

void wypisz_czesc_ksiazek(biblioteka* x, ksiazka y, int warunek)
{
	biblioteka* temp = (biblioteka*)malloc(sizeof(biblioteka));	// btw taka operacja (nazwa_typu*)(...) nazywa siê rzutowaniem
	temp = x;
	int rok;

	int opcja = 1;

	while (temp != NULL) {

		switch (warunek)
		{
		case 1:
		{
			opcja = strcmp(temp->k->autor, y.autor);
			break;
		}
		case 2:
		{
			opcja = strcmp(temp->k->tytul, y.tytul);
			break;
		}
		case 3:
		{
			opcja = strcmp(temp->k->gatunek, y.gatunek);
			break;
		}
		case 4:
		{
			opcja = opcja = temp->k->rok - y.rok;
			break;
		}
		case 5:
		{
			opcja = opcja = temp->k->ID - y.ID;
			break;
		}
		}

		if (opcja == 0) {

			cout << temp->k->autor;
			cout << "\t";
			if (strlen(temp->k->autor) < 24) cout << "\t";	// liczby '8','16','24' wynikaj¹ z definicji oepratora '\t'
			if (strlen(temp->k->autor) < 16) cout << "\t";
			if (strlen(temp->k->autor) < 8) cout << "\t";

			cout << temp->k->tytul;
			cout << "\t";
			if (strlen(temp->k->tytul) < 24) cout << "\t";
			if (strlen(temp->k->tytul) < 16) cout << "\t";
			if (strlen(temp->k->tytul) < 8) cout << "\t";

			cout << temp->k->gatunek;
			cout << "\t";

			if (strlen(temp->k->gatunek) < 16) cout << "\t";
			if (strlen(temp->k->gatunek) < 8) cout << "\t";

			rok = temp->k->rok;

			if (rok >= 0) {
				cout << rok << " r.";
				cout << "\t" << "\t";
			}
			else {
				rok *= -1;
				cout << rok << " r.p.n.e." << "\t";
			}

			if (temp->k->ID < 10000) cout << "0";
			if (temp->k->ID < 1000) cout << "0";
			if (temp->k->ID < 100) cout << "0";
			if (temp->k->ID < 10) cout << "0";

			cout << temp->k->ID << endl;			
		}

		temp = temp->nast;		
	}

}