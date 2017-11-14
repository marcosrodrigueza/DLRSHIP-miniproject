#include "fighter.h"
#include "spacecraft.h"

Fighter::Fighter(int ms,int cn, float p, /*PropTy pro,*/ string rn, string o): SpaceCraft(cn, p, /*pro,*/ rn, o)
{
    maxSpeed = ms;
}
