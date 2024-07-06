#include "KLASY.h"
#include "WYKRES.h"
#include "SERIES.h"
#include <cstddef>
#include <utility>

using namespace std;

void aux_3() {

	Wykres w1(2, " Wykres1 ", TypWykresu::XY);
	Wykres w2;
	w2 = w1;
	cout << endl;
	Wykres w3(2, " Wykres2 ", TypWykresu::Column);
	Wykres w4(w3);
	Wykres w5(w1);
	Wykres w6 = move(w1);

	cout << "w4: " << w4 << endl;
	cout << "w5: " << w5 << endl;
	cout << "w6: " << w6 << endl;

	ZbiorOsi o(4);
	++o;
	o++;

}

void auxFun_4_3() {

	Wykres w;
	Column c("kolumna1", 4);
	Treemap t("treemap1", 5);

	Wykres* wsk[3];

	wsk[0] = &w;
	wsk[1] = &c;
	wsk[2] = &t;

	for (int i = 0; i < 3; i++) {

		wsk[i]->rysuj();
	}
}

void auxFun_4_4(Wykres* wsk) {

	Wykres* w = dynamic_cast<Wykres*>(wsk);

	Column* c = dynamic_cast<Column*>(wsk);

	if (w == nullptr) cout << "Wskaznik jest rowny nullptr" << endl;
	if (c == nullptr) cout << "Wskaznik jest rowny nullptr" << endl;

}

int main()
{

	OsLiczbowa::licznik_wartosc();

	OsLiczbowa* os1 = new OsLiczbowa();
	//os1->wypisz();
	OsLiczbowa* os2 = new OsLiczbowa(0.01, 3.2);
	//os2->wypisz();   
	OsLiczbowa* os3 = new OsLiczbowa(0.00, 4.6, 4.6);
	//os3->wypisz();
	OsLiczbowa* os4 = new OsLiczbowa(*os1);
	//os4->wypisz();
	OsLiczbowa os5;
	OsLiczbowa os6(0.01, 3.2);
	OsLiczbowa os7(0.78, 3.5);

	cout << "Wyswietlanie za pomoca operatora <<: " << endl;
	cout << "Obiekt pierwszy: " << *os1 << endl;
	cout << "Obiekt Drugi: " << *os2 << endl;
	cout << "Obiekt trzeci: " << *os3 << endl;
	cout << "Obiekt czwarty: " << *os4 << endl;
	cout << endl;

	os2 = os3;  //Przypisanie
	os4 = move(os2); //Przeniesienie 

	//operator rozciagania i zgniatania

	os5 *= 2;
	os6 /= 2;

	delete os1;
	delete os3;

	ZbiorOsi z0(6);
	ZbiorOsi z1(4);
	ZbiorOsi z2(3);
	ZbiorOsi z3(z1);
	ZbiorOsi z4(move(z2));
	ZbiorOsi z5(6);
	ZbiorOsi z6(2);

	z2 = z1;
	z5 = move(z0);
	z6 += os7;

	cout << "Wyswietlanie zawartosci zbioru osi: " << endl;
	cout << "z1: " << z1 << endl;
	cout << "z3: " << z3 << endl;
	cout << "z4: " << z4 << endl;
	cout << "z6: " << z6 << endl;

	OsLiczbowa::licznik_wartosc();

	Wykres w8;
	Wykres* w9 = new Wykres;
	w8.rysuj();

	aux_3();
	auxFun_4_3();
	auxFun_4_4(w9);


	cout << "---------"; 
	RealChart r("Test ", 5, nullptr);
	cout << "Nazwa wykresu: " << r.getNazwaWykresu() << endl;
	cout << "Nazwa serii: " << r.getNazwaSerii() << endl;
	cout << r << endl; 

	return 0;

}