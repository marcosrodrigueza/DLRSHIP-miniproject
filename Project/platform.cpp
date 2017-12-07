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
    cout << "   6. Delete SpaceCraft." << endl;
    cout << "   7. Register a Sale." << endl;
    cout << "   8. Show owners registered. " <<endl << endl;
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

    if (error == 0)
        selector = true;

    if (n.size() != 10)
    {
        selector = false;
        // Last time added because we realize that the format can be introduced right without correct size
    }
    if (selector == false)
        cout << "--Not Alien type--" << endl;

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

void Platform::searchOwner(const string &id, vector<Owners*>::iterator &iterator, bool &found)
{
    for(iterator = vect_owner.begin(); iterator != vect_owner.end(); iterator ++)
    {
        if((*iterator)->getId() == id)
        {
            found = true;
            break;
            cout << "--FOUND--" <<endl;
        }
    }
}

void Platform::modifyItsSpaces(const string &id /*old id*/,const string &n_id/*new one*/)
{
     vector<SpaceCraft*>::iterator iter;

    for(iter = vect_space.begin(); iter != vect_space.end(); iter ++)
    {
        if((*iter)->getOwner() == id)
        {
            (*iter)->setOwner(n_id);
        }
    }
}

void Platform::modifyItsSpaces(const string &id)
{
     vector<SpaceCraft*>::iterator iter;

    for(iter = vect_space.begin(); iter != vect_space.end(); iter ++)
    {
        if((*iter)->getOwner() == id)
        {
            delete *iter;
            vect_space.erase(iter);
            iter --;
        }
    }
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
        string nie = "non-sense"; // the value by default

        do
        {
            cout << "Please introduce the nie in the format 'NNNNNNNNNN'" << endl << "being 'N' a natural number: ";
            cin >> nie;
            correct = this->checkNie(nie); //we verify the identity through a bool variable
                                          //We may introduce a message for try again
        }
        while (correct == false);
        vect_owner.push_back(new Alien(nie));//if OK then we create the object
    }
    else if (owner_ty == 'h') //Human chosen
    {
        string nif = "non-sense";

        do
        {
            cout << "Please introduce the nif in the format 'NNNNNNNNL' "<< endl << "being 'N' a natural number and 'L'";
            cout << "a CAPITAL lettter: ";
            cin >> nif;
            correct = this->checkNif(nif); //we verify the identity through a bool variable
        }                                  //We may introduce a message for try again

        while (correct == false);
        vect_owner.push_back(new Human(nif));//if OK then we create the object

    }
    else
    {
        cout << "Error, try again" << endl;
    }
}

void Platform::editorOwn()
{
    string id = "non-sense";
    string new_id ="non-sense";
    bool alien = false;
    bool human = false;
    bool own_found = false;
    vector<Owners*>::iterator it;
    vector<SpaceCraft*>::iterator space_editor;
    //
    cout << "Introduce the id of the owner: ";
    cin >> id;
    alien = this->checkNie(id);
    human = this->checkNif(id);

    if(alien == true || human == true) //only checks without loop and allow search
    {
        this->searchOwner(id,it,own_found);
    }

    else { cout << "Not valid format" << endl; }

    if (own_found == true) //can not be true if search has not been done
    {
        bool new_id_correct = false;
        do
        {
            cout << "Introduce the new id of the Owner:";
            cin >> new_id;  //we are using the variable in order to set the new id
            new_id_correct = (*it)->checkId(new_id); //checks that syntax corresponds to the one demanded by
                                                    //the object to be edited
        } while(new_id_correct != true);

        (*it)->editId(new_id); //now that the syntax is correct we change the id
        this->modifyItsSpaces(id,new_id); //and here we apply this changes to the spaceships of the owner
    }
}
void Platform::deleteOwn()
{
    string id = "non-sense";
    bool alien = false;
    bool human = false;
    bool own_found = false;
    vector<Owners*>::iterator it;
    vector<SpaceCraft*>::iterator space_editor;
    //
    cout << "Introduce the id of the owner you want to erase: ";
    cin >> id;
    alien = this->checkNie(id);
    human = this->checkNif(id);

    if(alien == true || human == true) //only checks without loop and allow search
    {
        this->searchOwner(id,it,own_found);
    }

    else { cout << "Not valid format" << endl; }

    if (own_found == true) //can not be true if search has not been done
    {
        delete *it; //delete the contents (the object itself)
        vect_owner.erase(it);

        this->modifyItsSpaces(id); //if only one atribute the modification is an erase
    }
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
          cout << "----Alien detected----" << endl;
          valid = true;
        }
        else if(alien == false && human == true) //human detected
        {
          cout << "----Human detected----" << endl;
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

            vect_space.push_back(new  Destroyer(crew,price,registration,owner));
            cout << "---Destroyer Created---" << endl;
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

            vect_space.push_back(new Fighter(speedTop,crew,price,registration,owner));
            cout << "---Fighter Created---" << endl;
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

            vect_space.push_back(new SpaceCarrier(maxLoad,eShield,speedCruise,crew,price,registration,owner));
            cout << "---Carrier Created---" << endl;

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

            vect_space.push_back(new SpaceStation(hangars,passengers,eShield,crew,price,registration,owner));
            cout << "---Carrier Created---" << endl;

        }
        else
        {
            cout << "Ilegal option" << endl;
            valid = false;
        }
    } while(valid != true);
}

void Platform::spaceCraftSearch(const string &registration, vector<SpaceCraft*>::iterator &iterator, bool &found)
{
    for(iterator = vect_space.begin(); iterator != vect_space.end(); iterator ++)
    {
        if((*iterator)->getReg() == registration)
        {
            found = true;
            break;
            cout << "--FOUND--" <<endl;
        }
    }
}

void Platform::showOwners()
{
    vector<Owners*>::iterator shower;
    for(shower = vect_owner.begin(); shower != vect_owner.end(); shower++)
    {
        (*shower)->show();
    }
}
void Platform::showSpacesAvailible()
{
    vector<SpaceCraft*>::iterator av;
    for(av = vect_space.begin(); av != vect_space.end(); av++)
    {
        if((*av)->getAvailible() == true) //if it has not been purchased, show this spacecraft
            (*av)->show();
    }
}
void Platform::showSales()
{
    vector<Sale>::iterator sales;
    for(sales = vect_sale.begin(); sales != vect_sale.end(); sales++)
    {
        sales->showSale();
    }
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
            vector<SpaceCraft*>::iterator its;
            //
            cout << "Introduce the registration number: ";
            cin >> reg;
            this->spaceCraftSearch(reg, its, fnd);
            if(fnd == true)
            {
                (*its)->editSpacecraft();
            }
            else {cout <<"Sorry, there aren't SpaceCrafts with this registration" << endl;}

            break;
        }

        case '6' :
        {
            string delete_string = "non-sense";
            bool found = false;
            vector<SpaceCraft*>::iterator itd;
            //
            cout << "Introduce the registration number: ";
            cin >> delete_string;
            this->spaceCraftSearch(delete_string, itd, found);
            if(found == true)
            {
                delete *itd; //first we free the memory where the content is placed
                vect_space.erase(itd); //then we erase the pointer from our vector
            }
            else {cout <<"Sorry, there aren't SpaceCrafts with this registration" << endl;}
            break;
        }
        case '7' : // not error-friendly yet
        {
            bool found_for_sale = false;
            bool create_sale = false;
            string regTarget = "non-sense";
            vector<SpaceCraft*>::iterator saler;
            //
            cout << "Introduce the registration number: ";
            cin >> regTarget;
            this->spaceCraftSearch(regTarget, saler, found_for_sale);
            if(found_for_sale == true)
            {
                (*saler)->transaction(create_sale);
            }
            else
            {
                cout << "Sorry, there aren't SpaceCrafts with this registration" << endl;
            }

            if(create_sale == true)
            {
                vect_sale.push_back(Sale(actualDate, (*saler)->getOwner()));
            }
            break;
        }
        case '8':

            this->showOwners();
            break;
         /*
        case 'f':
        {

            vector<Alien>::iterator aliens;
            vector<Human>::iterator humans;
            vector<SpaceCraft*>::iterator spacecrafts;
            vector<Sale>::iterator sales;
            //
            for(aliens = vect_alien.begin(); aliens != vect_alien.end(); aliens++)
            {
                aliens->show();
            }
            for(humans = vect_human.begin(); humans != vect_human.begin(); humans++)
            {
                humans->show();
            }
            for(spacecrafts = vect_space.begin(); spacecrafts != vect_space.end(); spacecrafts++)
            {
                (*spacecrafts)->show();
            }
            for(sales = vect_sale.begin(); sales != vect_sale.end(); sales++)
            {
                sales->showSale();
            }
            break;
        }
        case 'h':
        {
            vector<Human>::iterator humans;
            for(humans = vect_human.begin(); humans != vect_human.end(); humans++)
            {
                humans->show();

            break;
        }
        */
        default:

            cout << "Not a valid option" << endl;
            break;
        }

        cout << "Do you want to close the program? (y/N): ";
        cin >> close;
        if(close == 'N') cout <<  "\033[2J\033[1;1H"; //clear screen and set cursor to beginning
    }

    while (close != 'y');
}

void Platform::deleter()
{

    vector<Owners*>::iterator free_Owners;
    for(free_Owners = vect_owner.begin(); free_Owners != vect_owner.end(); free_Owners++)
    {
        delete *free_Owners;
    }
    vector<SpaceCraft*>::iterator free_Spaces;
    for(free_Spaces = vect_space.begin(); free_Spaces != vect_space.end(); free_Spaces++)
    {
        delete *free_Spaces;
    }
}
