#ifndef PLATFORM_H
#define PLATFORM_H
#include <vector>
#include "date.h"
#include "alien.h"
#include "human.h"

using namespace std;

class Platform
{
    vector<Alien> vect_alien;
    vector<Human> vect_human;

public:

    Date actualDate;

    Platform(Date ad);
    void initialize();
    void displayMenu();
    bool checkNie(const string &n)const;
    bool checkNif(const string &n)const;
    void ownerCreator(); //Englobes contructor for alien and human and manage all the checkings
                         //Maybe its not needed when exceptions are explained
    void performer();
};

#endif // PLATFORM_H
