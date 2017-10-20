#include "fighter.h"

Fighter::Fighter(int ms,int cw, float p, PropTy pro, string rn, string o)
{
    maxSpeed = ms;
    crewMax = cw;
    price = p;
    prop = pro;
    regNum = rn;
    owner = o;
}
