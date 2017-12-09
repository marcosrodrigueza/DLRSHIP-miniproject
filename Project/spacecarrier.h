#ifndef SPACECARRIER_H
#define SPACECARRIER_H
#include<iostream>
#include <string>
#include "spacecraft.h"

using namespace std;

class SpaceCarrier : public SpaceCraft
{
    int maxLoad, cSpeed;
    bool eShield;

public:

    SpaceCarrier(int ml, int cs, bool es, int cn, float p, int pro, string rn, string o, bool b);//Constructor
    void show();
   // string getReg();
    void editSpacecraft();
    void saveCraft(ofstream &output);
    ~SpaceCarrier();

};

#endif // SPACECARRIER_H
