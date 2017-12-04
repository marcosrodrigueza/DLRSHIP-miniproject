#include "human.h"

Human::Human(string n)
{
    nif = n;
    cout << "Human Created succesfully" << endl;

}
void Human::buySS(string &ship)
{
    //
}
void Human::editId(const string id)
{
    nif = id;
    cout << "Your changes have been done" << endl;
}

string Human::getId() {return nif;}

void Human::show()
{
    cout << "nif:" << nif << endl;
}
