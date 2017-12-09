#ifndef DESTROYER_H
#define DESTROYER_H
#include<iostream>
#include<string>
#include<vector>
#include "spacecraft.h"
#include "weapon.h"

using namespace std;

class Destroyer : public SpaceCraft
{
    vector<char> destroyer_weapons;
    int num_weapons; //to know the weapon number for the file loader


public:

    Destroyer(int cm, float p/*, PropTy pro*/, string rn, string o, vector<char> w);
    void show();
    void showTypes();
    void editSpacecraft();
    void saveCraft(ofstream &output);
    ~Destroyer();
};

#endif // DESTROYER_H
