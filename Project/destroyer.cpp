#include "destroyer.h"
#include "spacecraft.h"

Destroyer::Destroyer(int cm, float p, /*PropTy pro,*/string rn, string o,vector<char> w): SpaceCraft(cm,p /*,pro*/,rn,o)
{
    destroyer_weapons = w;
    num_weapons = w.size();
}

void Destroyer::show()
{
    cout << "-------------------------------------" << endl;
    cout << " Owner: " << owner << endl;
    cout << " RegNum: " << regNum << endl;
    cout << " Price: " << price << endl;
    cout << " Max Crew: " << crewMax << endl << endl;
}

void Destroyer::editSpacecraft()
{
    this->editBaseParameters();
    cout << "----Changes done----" << endl;
}
Destroyer::~Destroyer()
{
    cout <<"-Destroyer succesfully eliminated-" << endl;
}

//Need to implement types through lists
/*string Destroyer::getReg()
{
    return regNum;
}
*/
