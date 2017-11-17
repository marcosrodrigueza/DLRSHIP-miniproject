#include "spacecarrier.h"
#include "spacecraft.h"

SpaceCarrier::SpaceCarrier(int ml, int cs, bool es,int cn, float p,/* PropTy pro,*/ string rn, string o)
    : SpaceCraft(cn, p, /*pro,*/ rn, o)
{
    maxLoad = ml;
    cSpeed = cs;
    eShield = es;
}

void SpaceCarrier::editSpacecraft()
{
    unsigned int new_maxLoad = 0;
    unsigned int new_cspeed = 0;

    //energy shield is intrinsic

    this->editBaseParameters();
    cout << "Máximum Load: ";
    cin >> new_maxLoad;
    if(new_maxLoad != 0)
        maxLoad = new_maxLoad;

    cout << "Cruise Speed: ";
    cin >> new_cspeed;
    if(new_cspeed != 0)
        maxLoad = new_cspeed;

    cout << "----Changes done----" << endl;
}
