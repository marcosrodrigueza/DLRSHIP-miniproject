#ifndef ALIEN_H
#define ALIEN_H
#include<string>
#include "owners.h"

using namespace std;

class Alien : public Owners
{
    int nie;

public:

    Alien(int n);
    void buyD(string &ship);
};

#endif // ALIEN_H
