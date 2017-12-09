#include "spacecarrier.h"
#include "spacecraft.h"

SpaceCarrier::SpaceCarrier(int ml, int cs, bool es,int cn, float p,/* PropTy pro,*/ string rn, string o)
    : SpaceCraft(cn, p, /*pro,*/ rn, o)
{
    maxLoad = ml;
    cSpeed = cs;
    eShield = es;
}

void SpaceCarrier::show()
{
    cout << "-------------------------------------" << endl;
    cout << " Owner: " << owner << endl;
    cout << " RegNum: " << regNum << endl;
    cout << " Price: " << price << endl;
    cout << " Max Crew: " << crewMax << endl;
    cout << " Max Load: " << maxLoad << endl;
    cout << " Cruise Speed: " << cSpeed << endl;
    cout << " Energy Shield: " << eShield << endl << endl;
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
        cSpeed = new_cspeed;

    cout << "----Changes done----" << endl;
}

void SpaceCarrier::saveCraft(ofstream &output)
{
    string code = "#";
    //
    output << regNum << endl;
    output << owner << endl;
    output << crewMax << endl;
    output << price << endl;
    output << av_sale << endl;
    output << code << endl;
    output << maxLoad << endl;
    output << cSpeed << endl;
    output << eShield << endl;
}

SpaceCarrier::~SpaceCarrier()
{
    cout <<"-Space Carrier succesfully eliminated-" << endl;
}

/*string SpaceCarrier::getReg()
{
    return regNum;
}
*/
