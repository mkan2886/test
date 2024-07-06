#include "KLASY.h"
#include "WYKRES.h"
#include <iostream>
#include <cstddef>
#include <utility>

using namespace std;

int OsLiczbowa::licznik_k = 0;
int OsLiczbowa::licznik_d = 0;

OsLiczbowa::OsLiczbowa() {

	min = 0.00;
	max = 4.2;
	interval = 4.2;
	licznik_k++;
	//	cout << "Licznik konstrukcji wynosi: " << licznik_k << endl;
}

OsLiczbowa::OsLiczbowa(const OsLiczbowa& o) :min(o.min), max(o.max), interval(o.interval) {
	licznik_k++;
	//cout << "Licznik konstrukcji wynosi: " << licznik_k << endl;
}

OsLiczbowa::OsLiczbowa(float mn, float mx) {

	min = mn;
	max = mx;
	interval = max - min;
	licznik_k++;

	//cout << "Licznik konstrukcji wynosi: " << licznik_k << endl;
}

OsLiczbowa::OsLiczbowa(float mn, float mx, float in) {

	min = mn;
	max = mx;
	interval = in;
	licznik_k++;

	//cout << "Licznik konstrukcji wynosi: " << licznik_k << endl;
}

OsLiczbowa::~OsLiczbowa() {

	licznik_d++;
	//cout << "Licznik dekonstrukcji wynosi: " << licznik_d << endl;
}

void OsLiczbowa::set(float mn, float mx, float iv) {

	min = mn;
	max = mx;
	interval = iv;

	cout << " Ustaw wartosci min, max i interval swojej osi:" << endl;
	cout << "min: ";
	cin >> mn;
	cout << "max: ";
	cin >> mx;
	cout << "interval: ";
}

float OsLiczbowa::get_min() {

	return min;
}

float OsLiczbowa::get_max() {

	return max;
}

float OsLiczbowa::get_interval() {

	return max - min;
}

void OsLiczbowa::wypisz() {

	cout << min << " " << max << " " << interval << " " << endl;
}

void OsLiczbowa::licznik_wartosc() {

	cout << "Aktualny stan licznika konstrukcji wynosi: " << licznik_k << endl;
	cout << "Aktualny stan licznika dekonstrukcji wynosi: " << licznik_d << endl;
}

ostream& operator <<(ostream& s, const OsLiczbowa& a)
{
	s << " " << a.min << " " << a.max << " " << a.interval;

	return s;
}

OsLiczbowa& OsLiczbowa::operator = (const OsLiczbowa& a) {

	if (&a == this) return *this;

	min = a.min;
	max = a.max;
	interval = a.interval;

	return *this;
}

OsLiczbowa& OsLiczbowa::operator*=(float b) {

	cout << "Wartosci przed uzyciem operatora rozciagania: " << min << " " << max << endl;

	float s;
	s = (min + max) / 2;

	min = s - b * (s - min);
	max = s + b * (max - s);

	cout << "Wartosci po uzyciu operatora rozciagania: " << min << " " << max << endl;

	return *this;

}

OsLiczbowa& OsLiczbowa::operator/=(float c) {

	cout << "Wartosci przed uzyciem operatora zgniatania: " << min << " " << max << endl;

	float s;
	s = (min + max) / 2;

	min = s - (s - min) / c;
	max = s + (max - s) / c;

	cout << "Wartosci po uzyciu operatora zgniatania: " << min << " " << max << endl;

	return *this;

}

ZbiorOsi::ZbiorOsi(int w) : rozmiar_tab(w) {

	osie = new OsLiczbowa[w];

	for (int i = 0; i < w; i++) {
		osie[i] = OsLiczbowa();
	}
}

ZbiorOsi::ZbiorOsi(const ZbiorOsi& z) : rozmiar_tab(z.rozmiar_tab) {

	osie = new OsLiczbowa[z.rozmiar_tab];
	for (int i = 0; i < z.rozmiar_tab; i++) {

		osie[i] = z.osie[i];
	}

}

ZbiorOsi::ZbiorOsi(ZbiorOsi&& c) : osie(c.osie), rozmiar_tab(c.rozmiar_tab) {

	c.osie = nullptr;
	c.rozmiar_tab = 0;

}

ZbiorOsi::~ZbiorOsi() {

	if (rozmiar_tab == 0 || osie == nullptr)
		delete[] osie;
}

ostream& operator <<(ostream& s, const ZbiorOsi& z)
{

	for (int i = 0; i < z.rozmiar_tab; i++) {
		s << z.osie[i] << " ";
	}
	return s;
}

ZbiorOsi& ZbiorOsi::operator= (const ZbiorOsi& a) {

	//cout << "Wywolanie operatora przypisania zb" << endl;

	//cout << "Wartosc argumentu przed przypisaniem: " << rozmiar_tab << " " << osie << endl;

	if (&a == this) return *this;

	delete[] osie;

	rozmiar_tab = a.rozmiar_tab;
	osie = new OsLiczbowa[rozmiar_tab];

	for (int i = 0; i < rozmiar_tab; i++) {

		osie[i] = a.osie[i];
	}

	//cout << "Wartosc argumentu po przypisaniu: " << a.rozmiar_tab << " " << a.osie << endl;

	return *this;
}

ZbiorOsi& ZbiorOsi::operator= (ZbiorOsi&& a) {

	cout << "Wywolanie operatora przeniesienia" << endl;

	cout << "Wartosc argumentu przed przeniesieniem: " << a.rozmiar_tab << " " << a.osie << endl;

	if (&a == this) return *this;

	rozmiar_tab = a.rozmiar_tab;
	osie = a.osie;

	cout << "Wartosc argumentu po przeniesieniu: " << rozmiar_tab << " " << osie << endl;

	a.rozmiar_tab = 0;
	a.osie = nullptr;

	return *this;
}

ZbiorOsi& ZbiorOsi::operator+=(const OsLiczbowa& ns) {

	OsLiczbowa* n_osie = new OsLiczbowa[rozmiar_tab + 1];

	for (int i = 0; i < rozmiar_tab; i++) {

		n_osie[i] = osie[i];
	}

	n_osie[rozmiar_tab] = ns;

	delete[] osie;

	osie = n_osie;
	rozmiar_tab++;

	return *this;

}

ZbiorOsi& ZbiorOsi::operator++() {
	++rozmiar_tab;
	return *this;
}

ZbiorOsi ZbiorOsi::operator++(int) {
	ZbiorOsi t = *this;
	++t.rozmiar_tab;
	return t;
}

void Column::rysuj() {

	Wykres::rysuj();

	cout << endl;

	cout << "-------" << endl;
	cout << "| | | |" << endl;
	cout << "| | | |" << endl;
	cout << "| | | |" << endl;
	cout << "| | | |" << endl;
	cout << "-------" << endl;
	//Linijki kodu przedstawiaj¹ce kolumny 

}

void Treemap::rysuj() {

	Wykres::rysuj(); //Wypisywanie nazwy? 

	cout << endl;

	cout << "-----------------------" << endl;
	cout << "|   |          |      |" << endl;
	cout << "|   |          |      |" << endl;
	cout << "|   |          |      |" << endl;
	cout << "|   |          |      |" << endl;
	cout << "-----------------------" << endl;
	cout << "|       |      |      |" << endl;
	cout << "|       |      |      |" << endl;
	cout << "|       |      |      |" << endl;
	cout << "|       |      |      |" << endl;
	cout << "-----------------------" << endl;

}

Column::Column(string nazwa, int rozmiar) : Wykres(0, "Jakas nazwa ", TypWykresu::XY) {

	inne = new char[100];

}


Treemap::Treemap(string nazwa, int rozmiar) : Wykres(0, "Jakas nazwa ", TypWykresu::XY) {

	inne = new char[100];

}

Column::~Column() {

}

Treemap::~Treemap() {


}

