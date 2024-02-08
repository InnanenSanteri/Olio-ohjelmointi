#include <iostream>
using namespace std;

class Asunto
{
public:
    Asunto();
    void Maarita(int, int);
    double laskeKulutus(double);

private:
    int AsukasMaara;
    int Neliot;
};

Asunto::Asunto()
{
    cout << "Asunto luotu" << endl;
}

void Asunto::Maarita(int a, int n)
{
    AsukasMaara = a;
    Neliot = n;
    cout << "Asunto maaritelty, asukkaita = " << AsukasMaara << ", neliot = " << Neliot << endl;
}

double Asunto::laskeKulutus(double hinta)
{
    return AsukasMaara * Neliot * hinta;
}

class Kerros
{
public:
    Kerros();
    void virtual MaaritaAsunnot();
    double laskeKulutus(double);

private:
    Asunto as1;
    Asunto as2;
    Asunto as3;
    Asunto as4;
};

Kerros::Kerros()
{
    cout << "Kerros luotu" << endl;
}

void Kerros::MaaritaAsunnot()
{
    cout << "Maaritetaan 4 kpl kerroksen asuntoja" << endl;
    as1.Maarita(2, 100);
    as2.Maarita(2, 100);
    as3.Maarita(2, 100);
    as4.Maarita(2, 100);
}

double Kerros::laskeKulutus(double hinta)
{
    return as1.laskeKulutus(hinta) + as2.laskeKulutus(hinta) + as3.laskeKulutus(hinta) + as4.laskeKulutus(hinta);
}

class Katutaso : public Kerros
{
public:
    Katutaso();
    void MaaritaAsunnot();
    double laskeKulutus(double);

private:
    Asunto as1;
    Asunto as2;
};

Katutaso::Katutaso()
{
    cout << "Katutaso luotu" << endl;
}

void Katutaso::MaaritaAsunnot()
{
    cout << "Maaritetaan 2 kpl katutason asuntoja" << endl;
    as1.Maarita(2, 100);
    as2.Maarita(2, 100);
    Kerros::MaaritaAsunnot();
}

double Katutaso::laskeKulutus(double hinta)
{
    return as1.laskeKulutus(hinta) + as2.laskeKulutus(hinta);
    Kerros::MaaritaAsunnot();
}

class Kerrostalo
{
public:
    Kerrostalo();
    double laskeKulutus(double);

private:
    Katutaso eka;
    Kerros toka;
    Kerros kolmas;
};

Kerrostalo::Kerrostalo()
{
    cout << "Kerrostalo luotu" << endl;
    cout << "Maaritellaan koko kerrostalon kaikki asunnot" << endl;
    eka.MaaritaAsunnot();
    toka.MaaritaAsunnot();
    kolmas.MaaritaAsunnot();
}

double Kerrostalo::laskeKulutus(double hinta)
{
    double katutasonKulutus = eka.laskeKulutus(hinta);
    double kerrostenKulutus = toka.laskeKulutus(hinta) + kolmas.laskeKulutus(hinta);
    return katutasonKulutus + kerrostenKulutus;
}

int main()
{
    Kerrostalo talo;
    cout << "Kerrostalon kulutus = " << talo.laskeKulutus(1) << endl;

    return 0;
}
