#include "destroyer.h"
#include "spacecraft.h"

Destroyer::Destroyer(int cm, float p, /*PropTy pro,*/string rn, string o): SpaceCraft(cm,p /*,pro*/,rn,o){}

void Destroyer::editSpacecraft()
{
    this->editBaseParameters();
    cout << "----Changes done----" << endl;
}
//Need to implement types through lists
