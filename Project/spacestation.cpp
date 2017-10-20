#include "spacestation.h"

SpaceStation::SpaceStation(int nh,int mp, bool es, int cw, float p, PropTy pro, string rn, string o)
{
    numHangar = nh;
    maxPassenger = mp;
    eShield = es;
    crewMax = cw;
    price = p;
    prop = pro;
    regNum = rn;
    owner = o;
}
