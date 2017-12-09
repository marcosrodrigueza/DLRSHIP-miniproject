#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SpaceCraft
{
protected:

    int crewMax;
    float price;
    int propulsion;
    string regNum;
    string owner;
    bool av_sale; // to determine its state. true = available for sale: false = non available.
                 //intern variable, never can be edited explicitely from the interface.
    void editBaseParameters();

public:

    SpaceCraft(int cm, float pri,int prop, string rn, string o, bool b);
    virtual void show();
    void transaction(bool &create_sale);
    bool checkSale(string check);
    string getReg()const;
    string getOwner()const;
    void setOwner(const string & newOwner);
    bool getAvailible()const;
    virtual void editSpacecraft();
    virtual void saveCraft(ofstream &output);
    virtual ~SpaceCraft();
};

#endif // SPACECRAFT_H
