#include "spacestation.h"
#include "spacecraft.h"

SpaceStation::SpaceStation(int nh,int mp, bool es, int cn, float p,/* PropTy pro,*/ string rn, string o)
    : SpaceCraft(cn, p, /*pro,*/ rn, o)
{
    numHangar = nh;
    maxPassenger = mp;
    eShield = es;
}

void SpaceStation::editSpacecraft()
{
    unsigned int new_hangars = 0;
    unsigned int new_passengers = 0;

    //energy shield is intrinsic

    this->editBaseParameters();
    cout << "Number of hangars: ";
    cin >> new_hangars;
    if(new_hangars != 0)
        numHangar = new_hangars;

    cout << "Máximum Passengers: ";
    cin >> new_passengers;
    if(new_passengers != 0)
        maxPassenger = new_passengers;

    cout << "----Changes done----" << endl;
}
SpaceStation::~SpaceStation()
{
    //
}

/*string SpaceStation::getReg()
{
    return regNum;
}
*/
