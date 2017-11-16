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

void Platform::searchAlien(const string &id, vector<Alien>::iterator &iterator)
{
    for(iterator = vect_alien.begin(); iterator != vect_alien.end(); iterator++)
    {
        if(iterator->getId() == id) break;
    }
}
void Platform::searchHuman(const string &id, vector<Human>::iterator &iterator) //Not protected against non find
{
    for(iterator = vect_human.begin(); iterator != vect_human.end(); iterator++)
    {
        if(iterator->getId() == id) break;
    }
}

void Platform::editAlien(vector<Alien>::iterator &iterator)
{
    //if(iterator != vect_alien.end()) //Means that it exists
    //{
        string new_id = "non-sense";
        bool new_id_correct = false;
        //
        do
        {
            cout << "Introduce the new id of the alien:";
            cin >> new_id;
            new_id_correct = this->checkNie(new_id);

        } while(new_id_correct != true);

        iterator-> editId(new_id);
    //}

    //else{ cout << "Sorry, the alien does not exists" << endl;}
}

void Platform::editHuman(vector<Human>::iterator &iterator) //in comment the future protector
{
    //if(iterator != vect_human.end())
    //{
        string new_id = "non-sense";
        bool new_id_correct = false;
        do
        {
            cout << "Introduce the new id of the human:";
            cin >> new_id;
            new_id_correct = this->checkNif(new_id);

        } while(new_id_correct != true);

        iterator-> editId(new_id);
    //}

    //else{cout << "Sorry, the human does not exists" << endl;}
}

void Platform::ownerCreator()
{
    char owner_ty = 0;
    bool correct = false;

    //variables for the method initialized

    cout << "Please select 'A' for alien or 'h' for human(A/h): ";
    cin >> owner_ty;
    if( owner_ty == 'A') //Alien chose
    {
        string nie = "non-sense"; //for use the value by default

        cout << "Please introduce the nie in the format 'NNNNNNNNN'" << endl << "being 'N' a natural number: ";
        do
        {
            cin >> nie;
            correct = this->checkNie(nie); //we verify the identity through a bool variable
                                          //We may introduce a message for try again
        }
        while (correct == false);
        vect_alien.push_back(Alien(nie));//if OK then we create the object
    }
    else if (owner_ty == 'h') //Human chose
    {
        string nif = "non-sense";

        cout << "Please introduce the nif in the format 'NNNNNNNNL' "<< endl << "being 'N' a natural number and 'L'";
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

void Platform::editorOwn()
{
    string id = "non-sense";
    bool alien = false;
    bool human = false;
    //
    cout << "Introduce the id of the owner: ";
    cin >> id;
    alien = this->checkNie(id);
    human = this->checkNif(id);

    if(alien == true && human == false) //alien detected
    {
        vector<Alien>::iterator it;
        this-> searchAlien(id,it);
        this->editAlien(it);
    }
    else if(alien == false && human == true) //human detected
    {
        vector<Human>::iterator ite;
        this->searchHuman(id,ite); //=Alien-> will be the same with polymorphism
        this->editHuman(ite);
    }

    else { cout << "Not valid format" << endl; }
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

        case 2 :
            this->editorOwn();
            break;

        default:

            cout << "Not a valid option" << endl;
            break;
        }

        cout << "Do you want to close the program (y/N): ";
        cin >> close;
        if(close == 'N') cout << endl;
    }

    while (close != 'y');
}
