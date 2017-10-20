#ifndef SPACECARRIER_H
#define SPACECARRIER_H

class SpaceCarrier : public Spacecraft
{
    int maxLoad, cSpeed;
    bool eShield;

public:

    SpaceCarrier(int ml, int cs, bool es, int cw, float p, PropTy pro, string rn, string o);//Constructor
};

#endif // SPACECARRIER_H
