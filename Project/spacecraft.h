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
    bool av_sale; // to determine its state. true = available for sale: false = non available.
                 //intern variable, never can be edited explicitely from the interface.
    void editBaseParameters();

public:

    SpaceCraft(int cm, float pri/*, PropTy prop*/, string rn, string o);
    virtual void show();
    void transaction(bool &create_sale);
    bool checkSale(string check);
    string getReg()const;
    string getOwner()const;
    void setOwner(const string & newOwner);
    bool getAvailible()const;
    virtual void editSpacecraft();
    virtual ~SpaceCraft();
};

#endif // SPACECRAFT_H
