#ifndef SPACECARRIER_H
#define SPACECARRIER_H
#include <string>
#include "spacecraft.h"

using namespace std;

class SpaceCarrier : public SpaceCraft
{
    int maxLoad, cSpeed;
    bool eShield;

public:

    SpaceCarrier(int ml, int cs, bool es, int cn, float p,/* PropTy pro,*/ string rn, string o);//Constructor
    void editSpacecraft();
};

#endif // SPACECARRIER_H
