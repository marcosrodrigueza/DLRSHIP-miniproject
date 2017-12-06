#include "human.h"

Human::Human(string n)
{
    nif = n;
    cout << "Human Created succesfully" << endl;

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

bool Human::checkId(const string &n)const
{
    bool selector = false;
    int error = 0;

    for(unsigned i = 0; i < n.size()-1; i++)
    {
        if(n[i] < 48 || n[i] > 57) error++;
    }

    if(n[n.size()-1] < 65 || n[n.size()-1] > 90) error++;

    if (error == 0)
        selector = true;
    if (n.size() != 9)
    {
        selector = false;
        // Last time added because we realize that the format can be introduced right without correct size
    }
    if (selector == false)
        cout << "--Not Human type--" << endl;

    return selector;
}

Human::~Human()
{
    cout << "-Human deleted succesfully-" << endl;
}
