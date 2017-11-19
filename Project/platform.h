#ifndef PLATFORM_H
#define PLATFORM_H
#include <vector>
#include "date.h"
#include "owners.h"
#include "alien.h"
#include "human.h"
#include "spacecraft.h"
#include "destroyer.h"
#include "fighter.h"
#include "spacecarrier.h"
#include "spacestation.h"
#include "sale.h"

using namespace std;

class Platform
{
    vector<Alien> vect_alien;
    vector<Human> vect_human;
    vector<SpaceCraft> vect_space;
    vector<Sale> vect_sale;


public:

    Date actualDate;

    Platform(Date ad);
    void initialize();
    void displayMenu();
    bool checkNie(const string &n)const;
    bool checkNif(const string &n)const;
    bool checkRegNum(const string &n)const;
    void searchAlien(const string &id, vector<Alien>::iterator &iterator);
    void searchHuman(const string &id, vector<Human>::iterator &iterator);
    void spaceCraftSearch(const string &registration, vector<SpaceCraft>::iterator &iterator, bool &found);
    void editAlien(vector<Alien>::iterator &iterator);
    void editHuman(vector<Human>::iterator &iterator);
    void ownerCreator(); //Englobes contructor for alien and human and manage all the checkings
                         //Maybe its not needed when exceptions are explained
    void editorOwn();
    void deleteOwn();
    void spaceCraftCreator();

    void performer();
};

#endif // PLATFORM_H
