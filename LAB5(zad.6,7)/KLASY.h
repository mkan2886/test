#pragma once
#include <iostream>
#include <cstddef>
#define CLASS_H

using namespace std;


class OsLiczbowa {

private:
	float min, max, interval;
	static int licznik_d;
	static int licznik_k;
public:

	OsLiczbowa();

	OsLiczbowa(const OsLiczbowa& o);

	OsLiczbowa(float mn, float mx);

	OsLiczbowa(float mn, float mx, float in);

	void set(float mn, float mx, float iv);

	float get_min();
	float get_max();
	float get_interval();

	void wypisz();

	static void licznik_wartosc();

	friend ostream& operator << (ostream& s, const OsLiczbowa&);

	OsLiczbowa& operator = (const OsLiczbowa& a);

	OsLiczbowa& operator*=(float b);

	OsLiczbowa& operator/=(float c);

	~OsLiczbowa();
};



class ZbiorOsi {

	OsLiczbowa* osie;

public:

	int rozmiar_tab;

	ZbiorOsi(int w);

	ZbiorOsi(const ZbiorOsi& z);

	ZbiorOsi(ZbiorOsi&& c);

	~ZbiorOsi();

	friend ostream& operator << (ostream& s, const ZbiorOsi&);

	ZbiorOsi& operator= (const ZbiorOsi& a);

	ZbiorOsi& operator= (ZbiorOsi&& a);

	ZbiorOsi& operator+= (const OsLiczbowa& a);

	ZbiorOsi& operator++();

	ZbiorOsi operator++(int);

};


