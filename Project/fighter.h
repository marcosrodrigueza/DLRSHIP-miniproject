#ifndef FIGHTER_H
#define FIGHTER_H
#include<iostream>
#include <string>
#include "spacecraft.h"

using namespace std;

class Fighter : public SpaceCraft
{
    int maxSpeed;

public:

    Fighter(int ms,int cm, float p,/* PropTy pro,*/ string rn, string o); //Constructor
    void show();
    //string getReg();
    void editSpacecraft();
    ~Fighter();
};

#endif // FIGHTER_H
