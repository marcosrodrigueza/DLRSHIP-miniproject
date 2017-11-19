#ifndef SPACESTATION_H
#define SPACESTATION_H
#include <string>
#include "spacecraft.h" //added in this because we did not defined the base class in Qt when created

using namespace std;

class SpaceStation : public SpaceCraft
{
    int numHangar, maxPassenger;
    bool eShield;

public:

    SpaceStation(int nh,int mp, bool es, int cw, float p,/* PropTy pro,*/ string rn, string o);//Constructor
    //string getReg();
    void editSpacecraft();
    ~SpaceStation();
};

#endif // SPACESTATION_H
