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

    Alien(string n, string planet_or);
    void editId(const string id);
    string getId();
    void show();
    bool checkId(const string &n)const;
    ~Alien();
};

#endif // ALIEN_H
