#ifndef ALIEN_H
#define ALIEN_H
#include<string>
#include "owners.h"

using namespace std;

class Alien : public Owners
{
    string nie;

public:

    Alien(string n);
    void buyD(string &ship);
};

#endif // ALIEN_H
