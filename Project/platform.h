#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
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
    vector<Owners*> vect_owner;
    vector<SpaceCraft*> vect_space;
    vector<Sale> vect_sale;


public:

    Date actualDate;

    Platform(Date ad);
    void initialize();
    void displayMenu();
    bool checkNie(const string &n)const;
    bool checkNif(const string &n)const;
    bool checkRegNum(const string &n)const;
    void searchOwner(const string &id, vector<Owners*>::iterator &iterator, bool &found);
    void spaceCraftSearch(const string &registration, vector<SpaceCraft*>::iterator &iterator, bool &found);
    void  modifyItsSpaces(const string &id /*old id*/,const string &n_id/*new one*/);
    void  modifyItsSpaces(const string &id); //if only one argument is for erasing its spaces
    void ownerCreator(); //Englobes contructor for alien and human and manage all the checkings
                         //Maybe its not needed when exceptions are explained
    void editorOwn();
    void deleteOwn();
    void destroyerCreator(int &crew, float &price, string &registration, string &owner); //This and the following 4 are used in SpacaCraftCreator()
    void fighterCreator(int &crew, float &price, string &registration, string &owner);
    void scCreator(int &crew, float &price, string &registration, string &owner);
    void ssCreator(int &crew, float &price, string &registration, string &owner);
    void spaceCraftCreator();
    void showOwners();
    void showSpacesAvailible();
    void showSales();
    void showSales(Date d);
    void performer();
    void saver();
    void deleter();
};

#endif // PLATFORM_H
