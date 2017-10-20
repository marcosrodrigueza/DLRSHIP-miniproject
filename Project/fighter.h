#ifndef FIGHTER_H
#define FIGHTER_H

class Fighter : public SpaceCraft
{
    int maxSpeed;

public:

    Fighter(int ms,int cw, float p, PropTy pro, string rn, string o); //Constructor
};

#endif // FIGHTER_H
