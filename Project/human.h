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
    void editId(const string id);
    string getId();
    void show();
    bool checkId(const string &n)const;
    ~Human();
};

#endif // HUMAN_H
