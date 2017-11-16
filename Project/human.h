#ifndef HUMAN_H
#define HUMAN_H
#include<iostream>
#include<string>
#include "owners.h"

using namespace std;

class Human : public Owners
{
    string nif;

public:

    Human(string n);
    void buySS(string &ship);
    void editId(const string id);
    string getId();
};

#endif // HUMAN_H
