#ifndef DESTROYER_H
#define DESTROYER_H
#include<string>
#include<vector>
#include "spacecraft.h"
#include "weapon.h"

using namespace std;

class Destroyer : public SpaceCraft
{
    vector<Weapon> destroyer_weapons;


public:

    Destroyer(int cm, float p/*, PropTy pro*/, string rn, string o);
    void editSpacecraft();
};

#endif // DESTROYER_H
