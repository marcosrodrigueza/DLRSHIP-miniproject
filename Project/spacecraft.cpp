#include "spacecraft.h"

SpaceCraft::SpaceCraft(int cm, float pri/*, PropTy prop*/, string rn, string o)
{
 crewMax = cm;
 price = pri;
 //propType = prop;
 regNum = rn;
 owner = o;
 av_sale = true; //if you register it of course its availible by default
}

void SpaceCraft::show()
{
    //
}

void SpaceCraft::transaction(bool &create_sale)
{
    string new_owner = "non-sense";
    string security_copy = this->getOwner(); // we store a copy of actual owner until  transaction checked
    bool accepted = false;
    //
    create_sale = false;
    cout << "Please, introduce the buyer's id: ";
    cin >> new_owner; //we don't check yet!
    this-> setOwner(new_owner);
    accepted = this->checkSale(new_owner);
    if(accepted == false)
    {
       this->setOwner(security_copy);
       cout << "Transaction error" << endl;
    }
    else
    {
        av_sale = false;
        create_sale = true;
        cout << "---Done succesfully---" << endl;
    }
}

bool SpaceCraft::checkSale(string check) //checks that the owner in the object equals the one introduced.
{
    bool checker = false;
    if(this->getOwner() == check)
    {
        checker = true;
    }
    return checker;
}



string SpaceCraft::getReg()const
{
    return regNum;
}

string SpaceCraft::getOwner()const
{
    return owner;
}

 void SpaceCraft::setOwner(const string & newOwner)
 {
     owner = newOwner;
 }

 bool SpaceCraft::getAvailible()const
 {
     return av_sale;
 }

void SpaceCraft::editBaseParameters()
{
    float new_price = 0;
    unsigned int new_crew = 0;
    //
    cout << " New parameters of this Spacecraft:" << endl << "(Write 0 in the ones that you don't want to change)" << endl;

    cout << " $ (units): ";
    cin >> new_price;
    if(new_price != 0)
        price = new_price;

    cout << "Máximum crew : ";
    cin >> new_crew;
    if(new_crew != 0)
        crewMax = new_crew;

}
void SpaceCraft::editSpacecraft()
{
    //void editSpacecraft()
}
void SpaceCraft::saveCraft(ofstream &output)
{
    //nothing to be added
}

SpaceCraft::~SpaceCraft()
{
    //
}
