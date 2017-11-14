#ifndef DESTROYER_H
#define DESTROYER_H
#include<string>
#include "spacecraft.h"

using namespace std;

class Destroyer : public SpaceCraft
{

public:

    Destroyer(int cm, float p/*, PropTy pro*/, string rn, string o);
};

#endif // DESTROYER_H
