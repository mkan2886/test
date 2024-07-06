#include "WYKRES.h"
#include "KLASY.h"
#include "NAME.h"


Wykres& Wykres::operator=(const Wykres& a) {

	cout << "Wywolanie operatora przypisania" << endl;

	cout << "Wartosc argumentu przed przypisaniem: " << rozmiar_tab << " " << nazwa_wykresu << " " << konwerter(typ_wykresu) << endl;

	if (&a == this) return *this;

	ZbiorOsi::operator=(a);
	nazwa_wykresu = a.nazwa_wykresu;
	typ_wykresu = a.typ_wykresu;

	cout << "Wartosc argumentu po przypisaniu: " << rozmiar_tab << " " << nazwa_wykresu << " " << konwerter(typ_wykresu) << endl;

	return *this;

}

Wykres& Wykres::operator=(Wykres&& b) {

	cout << "Wywolanie operatora przeniesienia" << endl;

	cout << "Wartosc argumentu przed przeniesieniem: " << rozmiar_tab << " " << nazwa_wykresu << " " << konwerter(typ_wykresu) << endl;

	if (&b == this) return *this;

	ZbiorOsi::operator=(std::move(b));
	nazwa_wykresu = move(b.nazwa_wykresu);
	typ_wykresu = b.typ_wykresu;

	b.rozmiar_tab = 0;
	b.typ_wykresu = TypWykresu::XY;

	cout << "Wartosc argumentu po przeniesieniem: " << rozmiar_tab << " " << nazwa_wykresu << " " << konwerter(typ_wykresu) << endl;

	return *this;
}

ostream& operator<<(ostream& s, const Wykres& w) {

	s << static_cast<const ZbiorOsi&>(w) << endl;

	s << w.nazwa_wykresu << w.konwerter(w.typ_wykresu) << endl;

	return s;
}


string Wykres::konwerter(TypWykresu typ) const {

	switch (typ) {

	case TypWykresu::XY: return "XY";
	case TypWykresu::Column: return "Column";
	case TypWykresu::Sunburst: return "Sunburst";
	case TypWykresu::Treemap: return "Treemap";

	default:
		return "error";

	}

}

//Delegowanie do wieloagrumentowego 
Wykres::Wykres() : Wykres(0, "Jakas nazwa", TypWykresu::XY) {
	//cout << "Wywolanie konstruktora domyslnego" << endl;
}

Wykres::Wykres(int r, const string& n, TypWykresu t) : ZbiorOsi(r), nazwa_wykresu(n), typ_wykresu(t) {
	//cout << "Wywolanie konstruktora wieloargumetowego" << endl;
}

Wykres::Wykres(const Wykres& o) : ZbiorOsi(o.rozmiar_tab), nazwa_wykresu(o.nazwa_wykresu), typ_wykresu(o.typ_wykresu) {
	//cout << "Konstruktor kopiujacy" << endl;
}

Wykres::Wykres(Wykres&& o) : ZbiorOsi(move(o)), nazwa_wykresu(move(o.nazwa_wykresu)), typ_wykresu(o.typ_wykresu) {
	//cout << "Konstruktor przenoszacy" << endl;
}
Wykres:: ~Wykres() {
	//cout << "Wywolanie dekonstruktora" << endl;
}
