#ifndef PLATFORM_H
#define PLATFORM_H
#include <vector>
#include <algorithm>
#include "date.h"
#include "owners.h"
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
    void searchAlien(const string &id, vector<Alien>::iterator &iterator);
    void searchHuman(const string &id, vector<Human>::iterator &iterator);
    void editAlien(vector<Alien>::iterator &iterator);
    void editHuman(vector<Human>::iterator &iterator);
    void ownerCreator(); //Englobes contructor for alien and human and manage all the checkings
                         //Maybe its not needed when exceptions are explained
    void editorOwn();
    void performer();
};

#endif // PLATFORM_H
