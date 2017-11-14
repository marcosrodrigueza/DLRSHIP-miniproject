#ifndef HUMAN_H
#define HUMAN_H
#include<string>
#include "owners.h"

using namespace std;

class Human : public Owners
{
    string nif;

public:

    Human(string n);
    void buySS(string &ship);
};

#endif // HUMAN_H
