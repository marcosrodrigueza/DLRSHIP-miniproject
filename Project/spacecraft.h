#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include <iostream>
#include <string>

using namespace std;

class SpaceCraft
{
protected:

    int crewMax;
    float price;
    //PropTy prop;       In comment to be able to compie before implementing
    string regNum;
    string owner;
    void editBaseParameters();

public:

    SpaceCraft(int cm, float pri/*, PropTy prop*/, string rn, string o);
    void show();
    bool checkSale();
    string getReg();
    virtual void editSpacecraft();

};

#endif // SPACECRAFT_H
