#include <iostream>
#include <string>

using namespace std;

class Chef
{
public:
    Chef(string);
    ~Chef();
    void makeSalad();
    void makeSoup();
protected:
    string name;
};

class ItalianChef : public Chef
{
public:
    ItalianChef(string);
    ItalianChef(string, int, int);
    string getName();
    void makePasta();
private:
    int vesi;
    int jauhot;
};

Chef::Chef(string chefName)
{
    name = chefName;
    cout << "Chef " << name << " konstruktori" << endl;
}

Chef::~Chef()
{
    cout << "Chef " << name << " destruktori" << endl;
}

void Chef::makeSalad()
{
    cout << "Chef " << name << " makes salad" << endl;
}

void Chef::makeSoup()
{
    cout << "Chef " << name << " makes soup" << endl;
}

ItalianChef::ItalianChef(string chefName) : Chef(chefName)
{

}

ItalianChef::ItalianChef(string chefName, int v, int j) : Chef(chefName)
{
    vesi = v;
    jauhot = j;
}

string ItalianChef::getName()
{
    return name;
}

void ItalianChef::makePasta()
{
    cout << "Chef " << getName() << " makes pasta with special recipe" << endl;
    cout << "Chef " << getName() << " uses jauhot = " << jauhot << endl;
    cout << "Chef " << getName() << " uses vesi = " << vesi << endl;
}

int main()
{
    ItalianChef kokki1("Mario", 100, 250);
    kokki1.makePasta();

    ItalianChef kokki2("Kokki2");
    kokki2.getName();

    return 0;
}
