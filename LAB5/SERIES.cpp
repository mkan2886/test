#include "SERIES.h"

#include "WYKRES.h"
#include <string>

using namespace std;


Series::Series(string anazwa, int aliczbapunktow) : nazwa(anazwa), liczbapunktow(aliczbapunktow)  {

}


Series::Series() : Series("Przykladowa nazwa", 6){

}

Series::~Series() {};

ostream& operator <<(ostream& s, const Series& a) {

	s << a.nazwa << a.liczbapunktow << endl;
	return s;

}


RealChart::RealChart(string anazwa, int lp, char* inne_) : Series(anazwa,lp), Column(anazwa, lp) {

	cout << "Wywolanie konstruktora wieloargumentowego RealChart" << endl;
}

RealChart::RealChart() : RealChart("Nazwa ", 9, nullptr) {

	cout << "Wywolanie konstruktora domyslnego RealChart" << endl;

}

RealChart::~RealChart() { cout << "Wywolanie dekonstruktora RealChart" << endl; }

string RealChart::getNazwaSerii() {

	cout << nazwa << endl; 
	return nazwa; 

}


string RealChart::getNazwaWykresu() {

	cout << nazwa_wykresu << endl;
	return nazwa_wykresu;

}


ostream& operator <<(ostream& s, const RealChart& a) {

	s << static_cast<const Series&>(a);
	s << static_cast<const Column&>(a);

	return s; 
}