#include "alien.h"

Alien::Alien(string n)
{
    nie = n;
    cout << "Alien created succesfully" << endl;
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

bool Alien::checkId(const string &n)const
{
    bool selector = false;
    int error = 0;

    for(unsigned i = 0; i < n.size(); i++)
    {
        if(n[i] < 48 || n[i] > 57) error ++;
    }

    if (error == 0)
        selector = true;

    if (n.size() != 10)
    {
        selector = false;
        // Last time added because we realize that the format can be introduced right without correct size
    }
    if (selector == false)
        cout << "--Not Alien type--" << endl;

    return selector;
}

Alien::~Alien()
{
    cout << "-Alien deleted succesfully-" << endl;
}
