#ifndef ALIEN_H
#define ALIEN_H
#include<iostream>
#include<string>
#include "owners.h"

using namespace std;

class Alien : public Owners
{
    string nie;

public:

    Alien(string n);
    void buyD(string &ship);
    void editId(const string id);
    string getId();
    void show();
};

#endif // ALIEN_H
