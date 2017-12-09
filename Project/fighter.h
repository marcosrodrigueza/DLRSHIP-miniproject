#ifndef FIGHTER_H
#define FIGHTER_H
#include<iostream>
#include <string>
#include <vector>
#include "spacecraft.h"

using namespace std;

class Fighter : public SpaceCraft
{
    int maxSpeed;
    vector<char> fighter_weapons;
    int num_weapons; //to know the weapon number for the file loader--Internal variable


public:

    Fighter(int ms,int cm, float p, int pro, string rn, string o, bool b, vector<char> w); //Constructor
    void show();
    void showTypes();
    //string getReg();
    void editSpacecraft();
    void saveCraft(ofstream &output);
    ~Fighter();
};

#endif // FIGHTER_H
