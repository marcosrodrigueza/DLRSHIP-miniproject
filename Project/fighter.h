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

    Fighter(int ms,int cm, float p,/* PropTy pro,*/ string rn, string o, vector<char> w); //Constructor
    void show();
    //string getReg();
    void editSpacecraft();
    ~Fighter();
};

#endif // FIGHTER_H
