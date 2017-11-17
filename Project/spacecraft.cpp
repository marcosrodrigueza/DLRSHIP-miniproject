#include "spacecraft.h"

SpaceCraft::SpaceCraft(int cm, float pri/*, PropTy prop*/, string rn, string o)
{
 crewMax = cm;
 price = pri;
 //propType = prop;
 regNum = rn;
 owner = o;
}

void SpaceCraft::show()
{
    //
}

bool SpaceCraft::checkSale()
{
    //
}
string SpaceCraft::getReg()
{
    return regNum;
}

void SpaceCraft::editBaseParameters()
{
    float new_price = 0;
    unsigned int new_crew = 0;
    //
    cout << " New parameters of this Spacecraft: (Write 0 in the ones that you don't want to change)" << endl;

    cout << " $ (units): ";
    cin >> new_price;
    if(new_price != 0)
        price = new_price;

    cout << "Máximum crew : ";
    cin >> new_crew;
    if(new_crew != 0)
        crewMax = new_crew;

}
