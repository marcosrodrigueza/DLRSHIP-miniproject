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
    if (selector == false) cout << "Not able to use this nie" << endl;
    if (n.size() != 10)
    {
        selector = false;
        cout << "Not adequate size" << endl;
    }

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
    if (selector == false) cout << "Not able to use this nif number" << endl;
    if (n.size() != 9)
    {
        selector = false;
        cout << "Not adequate size" << endl;
    }

    return selector;

}

bool Platform::checkRegNum(const string &n)const
{
    bool selector = false;
    int error = 0;

    if (n[0]< 65 || n[0] > 90) error++;

    for(unsigned i = 1; i < n.size()-3; i++)
    {
        if(n[i] < 48 || n[i] > 57) error++;
    }
    for(unsigned j = n.size()-3; j < n.size(); j++)
    {
        if(n[j] < 65 || n[j] > 90) error++;
    }

    if (error == 0) selector = true;
    if (selector == false) cout << "Not able to use this registration number" << endl;
    if (n.size() != 8)
    {
        selector = false;
        cout << "Not adequate size" << endl;
    }
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
    if( owner_ty == 'A') //Alien chosen
    {
        string nie = "non-sense"; //for use the value by default

        cout << "Please introduce the nie in the format 'NNNNNNNNNN'" << endl << "being 'N' a natural number: ";
        do
        {
            cin >> nie;
            correct = this->checkNie(nie); //we verify the identity through a bool variable
                                          //We may introduce a message for try again
        }
        while (correct == false);
        vect_alien.push_back(Alien(nie));//if OK then we create the object
    }
    else if (owner_ty == 'h') //Human chosen
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

void Platform::spaceCraftCreator()
{
    string registration = "non-sense";
    unsigned int type = 0;
    bool valid = false;
    string owner = "non-sense";
    bool alien = false;
    bool human = false;
    unsigned int crew = 0;
    float price = 0.0;
    SpaceCraft *p;
    //
    do
    {
        cout << "Introduce the registration number in the format 'LNNNNLLL' " << endl;
        cout << "(L capital leter,N natural nº): ";
        cin >> registration;
        valid = this->checkRegNum(registration);
    }
    while(valid != true);
    valid = false;
    do //Here we only check the format, later we will check if the owner exists
    {
        cout << "Introduce its Owner id (nif/nie): ";
        cin >> owner;
        alien = this->checkNie(owner);
        human = this->checkNif(owner);

        if(alien == true && human == false) //alien detected
        {
          cout << "Alien detected" << endl;
          valid = true;
        }
        else if(alien == false && human == true) //human detected
        {
          cout << "Human detected" << endl;
          valid = true;
        }
        else { cout << "Not valid format" << endl;}
    }
    while(valid != true);
    cout << "Enter the maximum crew number: ";
    cin >> crew;
    cout << "Enter the selling price in Units: ";
    cin >> price;
    do
    {
        cout << "Please, choose its specific type:" << endl << "-1.Destroyer" << endl << "-2. Fighter" << endl;
        cout << "-3. SpaceCarrier" << endl << "4.-SpaceStation" << endl << "Type: ";
        cin >> type;
        if(type == 1)
        {
            unsigned int num_weapons = 0;
            //
            cout << "how many weapons does it have?: ";
            cin >> num_weapons;
            //Since we do not know lists, the types will be developed in the future.
            p = new Destroyer(crew,price,registration,owner);
            vect_space.push_back(*p);
            cout << "---Destroyer Created---" << endl;
            p = NULL;
        }
        else if(type == 2)
        {
            unsigned int num_weapons = 0;
            unsigned int speedTop = 0;
            //
            cout << "What is its maximum speed? (in light-years): ";
            cin >> speedTop;
            cout << "how many weapons does it have?: ";
            cin >> num_weapons;
            p = new Fighter(speedTop,crew,price,registration,owner);
            vect_space.push_back(*p);
            cout << "---Fighter Created---" << endl;
            p = NULL;
        }
        else if(type == 3)
        {
            unsigned int maxLoad = 0;
            unsigned int speedCruise = 0;
            bool eShield = false;
            //
            cout << "Maximum Load(in tons): ";
            cin >> maxLoad;
            cout << "Does it have Energy Shield(yes = 1/ no = 0): ";
            cin >> eShield;
            cout << "What is its cruise speed?(in light-years): ";
            cin >> speedCruise;

            p = new SpaceCarrier(maxLoad,eShield,speedCruise,crew,price,registration,owner);
            vect_space.push_back(*p);
            cout << "---Carrier Created---" << endl;
            p = NULL;

        }
        else if(type == 4)
        {
            unsigned int hangars = 0;
            unsigned int eShield = false;
            unsigned int passengers = 0;
            //
            cout << "Number of hangars: ";
            cin >> hangars;
            cout << "Does it have Energy Shield(yes = 1/ no = 0): ";
            cin >> eShield;
            cout << "Maximum of passangers: ";
            cin >> passengers;
            p = new SpaceStation(hangars,passengers,eShield,crew,price,registration,owner);
            vect_space.push_back(*p);
            cout << "---Carrier Created---" << endl;
            p = NULL;
        }
        else
        {
            cout << "Ilegal option" << endl;
            valid = false;
        }
    } while(valid != true);
}

void Platform::spaceCraftSearch(const string &registration, vector<SpaceCraft>::iterator &iterator, bool &found)
{
    for(iterator = vect_space.begin(); iterator != vect_space.end(); iterator ++)
    {
        if(iterator->getReg() == registration)
        {
            found = true;
            break;
            cout << "FOUND" <<endl;
        }
    }
}

void Platform::deleteOwn() //almost the same code than in edit except from the final in the If's statements.
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
        vect_alien.erase(it);
    }
    else if(alien == false && human == true) //human detected
    {
        vector<Human>::iterator ite;
        this->searchHuman(id,ite); //=Alien-> will be the same with polymorphism
        vect_human.erase(ite);
    }

    else { cout << "Not valid format" << endl; }

}

void Platform::performer() //Deals with the menu and call the proper methods of the classes
{
    //we are supposed to have called initializer() before
    char option = '\0';
    char close = 'N';
    //
    do
    {
        this->displayMenu();
        cin >> option;
         //the implementation through char is to avoid the problems with ints when you introduce other type
        switch (option)
        {
        case '1':
            this->ownerCreator();
            break;

        case '2' :
            this->editorOwn();
            break;

        case '3' :
            this->deleteOwn();
            break;

        case '4' :
            this->spaceCraftCreator();
            break;

        case '5' :
        {
            string reg = "non-sense";
            bool fnd = false;
            vector<SpaceCraft>::iterator its;
            //
            cout << "Introduce the registration number: ";
            cin >> reg;
            this->spaceCraftSearch(reg, its, fnd);
            if(fnd == true)
            {
                its->editSpacecraft();
            }
            else {cout <<"Sorry, there aren't SpaceCrafts with this registration" << endl;}

            break;
        }

        default:

            cout << "Not a valid option" << endl;
            break;
        }

        cout << "Do you want to close the program? (y/N): ";
        cin >> close;
        if(close == 'N') cout << endl;
    }

    while (close != 'y');
}
