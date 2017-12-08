#include "fighter.h"
#include "spacecraft.h"

Fighter::Fighter(int ms,int cn, float p, /*PropTy pro,*/ string rn, string o, vector<char> w): SpaceCraft(cn, p, /*pro,*/ rn, o)
{
    maxSpeed = ms;
    fighter_weapons = w;
    num_weapons = w.size();
}

void Fighter::show()
{
    cout << "-------------------------------------" << endl;
    cout << " Owner: " << owner << endl;
    cout << " RegNum: " << regNum << endl;
    cout << " Price: " << price << endl;
    cout << " Max Crew: " << crewMax << endl;
    cout << " Max Speed: " << maxSpeed << endl << endl;
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
Fighter::~Fighter()
{
    cout <<"-Fighter succesfully eliminated-" << endl;
}

/*string Fighter::getReg()
{
    return regNum;
}
*/
