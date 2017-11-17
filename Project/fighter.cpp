#include "fighter.h"
#include "spacecraft.h"

Fighter::Fighter(int ms,int cn, float p, /*PropTy pro,*/ string rn, string o): SpaceCraft(cn, p, /*pro,*/ rn, o)
{
    maxSpeed = ms;
}

void Fighter::editSpacecraft()
{
    unsigned int new_maxspeed = 0;
    //
    this->editBaseParameters();

    cout << "Máximum speed : ";
    cin >> new_maxspeed;
    if(new_maxspeed != 0)
        maxSpeed = new_maxspeed;

    cout << "----Changes done----" << endl;
}
