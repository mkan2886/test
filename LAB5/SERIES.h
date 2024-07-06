#pragma once
#include <string>
#include <iostream>
#include "WYKRES.h"
#include "KLASY.h"

using namespace std;

class Series
{
protected:

	string nazwa;
	int liczbapunktow;

public:

	friend ostream& operator <<(ostream& s, const Series& a);

	Series(string anazwa, int aliczbapunktow);
	Series();
	~Series();
};

class RealChart : public Series, public Column {


public:

	RealChart(string nazwa, int lp, char* inne_);
	RealChart();
	~RealChart();
	string getNazwaSerii(); 
	string getNazwaWykresu();
	friend ostream& operator <<(ostream& s, const RealChart& a);

};
