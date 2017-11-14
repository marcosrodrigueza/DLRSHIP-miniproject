#include "spacecarrier.h"
#include "spacecraft.h"

SpaceCarrier::SpaceCarrier(int ml, int cs, bool es,int cn, float p,/* PropTy pro,*/ string rn, string o)
    : SpaceCraft(cn, p, /*pro,*/ rn, o)
{
    maxLoad = ml;
    cSpeed = cs;
    eShield = es;
}
