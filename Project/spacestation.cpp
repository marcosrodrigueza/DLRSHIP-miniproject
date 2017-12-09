#include "spacestation.h"
#include "spacecraft.h"

SpaceStation::SpaceStation(int nh,int mp, bool es, int cn, float p,int pro, string rn, string o, bool b)
    : SpaceCraft(cn, p, pro, rn, o, b)
{
    numHangar = nh;
    maxPassenger = mp;
    eShield = es;
}

void SpaceStation::show()
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
    cout << " Number of Hangars: " << numHangar << endl;
    cout << " Maximum Passengers: " << maxPassenger << endl;
    cout << " Energy Shield: " << eShield << endl << endl;
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

void SpaceStation::saveCraft(ofstream &output)
{
    string code = "@";
    //
    output << regNum << endl;
    output << owner << endl;
    output << crewMax << endl;
    output << price << endl;
    output << av_sale << endl;
    output << code << endl;
    output << numHangar << endl;
    output << maxPassenger << endl;
    output << eShield << endl;
}

SpaceStation::~SpaceStation()
{
    cout <<"-Space Station succesfully eliminated-" << endl;
}

/*string SpaceStation::getReg()
{
    return regNum;
}
*/
