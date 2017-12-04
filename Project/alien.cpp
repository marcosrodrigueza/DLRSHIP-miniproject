#include "alien.h"

Alien::Alien(string n)
{
    nie = n;
    cout << "Alien created succesfully" << endl;
}

void Alien::buyD(string &ship)
{
    //
}
void Alien::editId(const string id)
{
    nie = id;

    cout << "Your changes have been done" << endl;
}

string Alien::getId() {return nie;}

void Alien::show()
{
    cout << "nie:" << nie << endl;
}
