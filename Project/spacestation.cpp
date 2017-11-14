#include "spacestation.h"
#include "spacecraft.h"

SpaceStation::SpaceStation(int nh,int mp, bool es, int cn, float p,/* PropTy pro,*/ string rn, string o)
    : SpaceCraft(cn, p, /*pro,*/ rn, o)
{
    numHangar = nh;
    maxPassenger = mp;
    eShield = es;
}

