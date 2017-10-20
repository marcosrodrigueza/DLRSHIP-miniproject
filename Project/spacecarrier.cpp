#include "spacecarrier.h"

SpaceCarrier::SpaceCarrier(int ml, int cs, bool es,int cw, float p, PropTy pro, string rn, string o)
{
    maxLoad = ml;
    cSpeed = cs;
    eShield = es;
    crewMax = cw;
    price = p;
    prop = pro;
    regNum = rn;
    owner = o;
}
