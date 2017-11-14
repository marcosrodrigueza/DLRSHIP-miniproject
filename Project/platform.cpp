#include "platform.h"
#include <iostream>

using namespace std;

Platform::Platform(Date ad)
{
    actualDate = ad;
}
void Platform::initialize() //Load values from the files into the programs
{  

}

void Platform::displayMenu()
{
    //displays the menu
    cout << "   ***** Welcome to DLRSHIP *****" << endl;
    cout << "-------------------------------------" << endl;
    cout << "   Select one of the options below:" << endl;
    cout << "   1. Introduce Owner." << endl;
    cout << "   2. Edit Owner." << endl;
    cout << "   3. Delete Owner." << endl;
    cout << "   4. Introduce new SpaceCraft." << endl;
    cout << "   5. Edit SpaceCraft." << endl;
    cout << "   6. Delete SpaceCraft." << endl << endl;
    cout << "   Option : " ;
}

bool Platform::checkNie(const string &n)const //if we have time we should implement a search to discard a same id
{
    bool selector = false;
    int error = 0;

    for(unsigned i = 0; i < n.size(); i++)
    {
        if(n[i] < 48 || n[i] > 57) error ++;
    }

    if (error == 0) selector = true;

    return selector;
}

bool Platform::checkNif(const string &n)const
{
    bool selector = false;
    int error = 0;

    for(unsigned i = 0; i < n.size()-1; i++)
    {
        if(n[i] < 48 || n[i] > 57) error++;
    }

    if(n[n.size()-1] < 65 || n[n.size()-1] > 90) error++;

    if (error == 0) selector = true;

    return selector;

}

void Platform::ownerCreator()
{
    char owner_ty = 0;
    bool correct = false;

    //variables for the method initialized

    cout << "Please select 'A' for alien or 'h' for human(A/h): ";
    cin >> owner_ty;
    if( owner_ty == 'A')
    {
        string nie = "non-sesnse";

        cout << "Please introduce the nie in the format 'NNNNNNNNN' being 'N' a natural number: ";
        do
        {
            cin >> nie;
            correct = this->checkNie(nie); //we verify the identity through a bool variable
        }                                  //We may introduce a message for try again

        while (correct == false);
        vect_alien.push_back(Alien(nie));//if OK then we create the object
    }
    else if (owner_ty == 'h')
    {
        string nif = "non-sense";

        cout << "Please introduce the nif in the format 'NNNNNNNNL' being 'N' a natural number and 'L'";
        cout << "a CAPITAL lettter: ";

        do
        {
            cin >> nif;
            correct = this->checkNif(nif); //we verify the identity through a bool variable
        }                                  //We may introduce a message for try again

        while (correct == false);
        vect_human.push_back(Human(nif));//if OK then we create the object

    }
    else
    {
        cout << "Error, try again" << endl;
    }
}

void Platform::performer() //Deals with the menu and call the proper methods of the classes
{
    //we are supposed to have called initializer() before
    unsigned int option = 0;
    char close = 'N';
    //
    do
    {
        this->displayMenu();
        cin >> option;
        switch (option)
        {
        case 1:

            this->ownerCreator();
            break;

        default:

            cout << "Not a valid option" << endl;
            break;
        }

        cout << "Do you want to close the program (y/N): ";
        cin >> close;
    }

    while (close != 'y');
}

