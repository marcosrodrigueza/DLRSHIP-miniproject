#include "spacecarrier.h"
#include "spacecraft.h"

SpaceCarrier::SpaceCarrier(int ml, int cs, bool es,int cn, float p, int pro, string rn, string o, bool b)
    : SpaceCraft(cn, p, pro, rn, o, b)
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
    cout << " Propulsion type: ";

    switch (propulsion) //we use it like a map
    {
    case 1:
        cout << "Warp drive";
        break;
    case 2:
        cout << "Trace compressor";
        break;
    case 3:
        cout << "FTL engine";
        break;
    case 4:
        cout << "Solar sails";
        break;
    case 5:
        cout << "Ion engine";
        break;
    default:
        cout << "Typo";
        break;
    }
    cout << endl;
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
    output << code << ',';
    output << regNum << ',';
    output << owner << ',';
    output << crewMax << ',';
    output << price << ',';
    output << propulsion << ',';
    output << av_sale << ',';
    output << maxLoad << ',';
    output << cSpeed << ',';
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
