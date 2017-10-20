#ifndef SPACESTATION_H
#define SPACESTATION_H

class SpaceStation : public SpaceCraft
{
    int numHangar, maxPassenger;
    bool eShield;

public:

    SpaceStation(int nh,int mp, bool es, int cw, float p, PropTy pro, string rn, string o);//Constructor
};

#endif // SPACESTATION_H
