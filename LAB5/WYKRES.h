#pragma once

#include "KLASY.h"
#include <string>


enum class TypWykresu {
    XY,
    Column,
    Sunburst,
    Treemap,
};


class Wykres : public ZbiorOsi {

protected:

    string nazwa_wykresu;
    TypWykresu typ_wykresu;

public:

    Wykres& operator=(const Wykres& a);

    Wykres& operator=(Wykres&& b);

    friend ostream& operator<<(ostream& s, const Wykres& w);

    string konwerter(TypWykresu typ) const;

    virtual void rysuj() {

        cout << nazwa_wykresu << endl;

    }


    Wykres();
    Wykres(int rozmiar, const string& nazwa, TypWykresu typ);
    Wykres(const Wykres& o);
    Wykres(Wykres&& o);
    ~Wykres();


};

class Column : public Wykres {

  
public:

    char* inne;
    void rysuj();
    Column(string nazwa, int rozmiar);

    ~Column();

};


class Treemap : public Wykres {

    char* inne;

public:
    void rysuj();
    Treemap(string nazwa, int rozmiar);

    ~Treemap();
};


