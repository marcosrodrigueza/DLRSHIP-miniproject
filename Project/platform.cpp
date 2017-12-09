#include "platform.h"

using namespace std;

Platform::Platform(Date ad)
{
    actualDate = ad;
}

bool Platform::strToBool(const string str) //if garbage input we give a zero (oclude a spacecraft in the listing)
{
    bool result = false;

    if(str == "1")
        result = true;

    return result;
}
float Platform::stof(const string str)
{
    float result = 10.5;
    return result;
}

int Platform::stoi(const string str)
{
    int result = 100;
    return result;
}

/*void Platform::loadCrafts(ifstream &sec_loader)
{
    string el_1 = "non-sense"; //First row - RegNum
    string el_2 = "non-sense"; //Second row and so - owner
    string el_3 = "non-sense"; // crew_máx
    string el_4 = "non-sense"; //price
    string el_5 = "non-sense"; //av for sale
    string el_6 = "non-sense"; //here is encoded the value that determines the type of ship
    string el_7 = "non-sense"; //nw/máx_load/num/hangars
    string el_8 = "non-sense"; // vect-Weapons/cSpeed/max_passangers
    string el_9 = "non-sense"; // none/eShield
    int crew_m = 0;
    float pri = 0;
    bool a_sale = false;
    int nw_loa_nhang = 0;
    int cspeed_max_pass = 0;
    int max_s = 0;
    bool eShd = false;
    vector<char> vect_w;
    //
    getline(sec_loader, el_1, '\n');
    getline(sec_loader, el_2, '\n');
    getline(sec_loader, el_3, '\n');
    getline(sec_loader, el_4, '\n');
    getline(sec_loader, el_5, '\n');
    getline(sec_loader, el_6, '\n');
    getline(sec_loader, el_7, '\n');
    getline(sec_loader, el_8, '\n');
    getline(sec_loader, el_9, '\n');

    //we obtain the 9 lines- now we adress them

    crew_m = this->stoi(el_3); //convert string to int
    pri = this->stof(el_4); //string to float

    a_sale = this->strToBool(el_5);

    // we have obtained base parameters

    if(el_6 == "-") //destroyer type
    {
        nw_loa_nhang = stoi(el_7);

        for(int i = 0; i < nw_loa_nhang; i++)
        {
            vect_w.push_back(el_8[i]);
        }
        //element 9 is negligible
        vect_space.push_back(new Destroyer(crew_m, pri, el_1, el_2,vect_w)); //Destroyer constructor
        vect_w.clear(); // clear the vector for the future
    }
    else if(el_6 == "@") // Space Station
    {
        nw_loa_nhang = stoi(el_7);
        cspeed_max_pass = stoi(el_8);
        eShd = this->strToBool(el_9);

        vect_space.push_back(new SpaceStation(nw_loa_nhang, cspeed_max_pass, eShd, crew_m, pri, el_1, el_2));
    }
    else if(el_6 == "#") //Space Carrier - do the same but call other constructor
    {
        nw_loa_nhang = stoi(el_7);
        cspeed_max_pass = stoi(el_8);
        eShd = this->strToBool(el_9);

        vect_space.push_back(new SpaceCarrier(nw_loa_nhang, cspeed_max_pass, eShd, crew_m, pri, el_1, el_2));
    }
    else if(el_6 == "%")//is a fighter
    {
        nw_loa_nhang = stoi(el_7);

        for(int i = 0; i < nw_loa_nhang; i++)
        {
            vect_w.push_back(el_8[i]);
        }

        max_s = stoi(el_9);
        vect_space.push_back(new Fighter(max_s,crew_m, pri, el_1, el_2, vect_w));
        vect_w.clear();
    }

}*/

void Platform::loadCrafts()
{
    ifstream load_crafts;

    string code = "non-sense";
    string reg = "non-sense";
    string id = "non-sense";
    string crew_max = "non-sense";
    string price = "non-sense";
    string prop = "non-sense";
    string a_sale = "non-sense";
    string nw = "non-sense";
    string ml = "non-sense";
    string nh = "non-sense";
    string wea = "non-sense";
    string cs = "non-sense";
    string mp = "non-sense";
    string es = "non-sense";
    string ms = "non-sense";
    vector<char> w;
    //

    load_crafts.open("spaces.txt", ios::in);

    if(!load_crafts)
    {
        cout << "Error_loading" << endl;
    }

    while(!load_crafts.eof())
    {
        getline(load_crafts, code, ',');
        getline(load_crafts, reg, ',');
        getline(load_crafts, id, ',');
        getline(load_crafts, crew_max, ',');
        getline(load_crafts, price, ',');
        getline(load_crafts, prop, ',');
        getline(load_crafts, a_sale, ',');

        switch(code[0])
        {
        case '-':
        {
           getline(load_crafts, nw, ',');
           getline(load_crafts, wea, '\n');

           for(int i = 0; i < atoi(nw.c_str()); i++)
           {
               w.push_back(wea[i]);
           }
           vect_space.push_back(new Destroyer(atoi(crew_max.c_str()),stof(price),atoi(prop.c_str()),reg,id,this->strToBool(a_sale),w));
           w.clear();
           break;
        }
        case '%':
        {
            getline(load_crafts, nw, ',');
            getline(load_crafts, wea, ',');
            getline(load_crafts, ms, '\n');

            for(int i = 0; i < atoi(nw.c_str()); i++)
            {
                w.push_back(wea[i]);
            }
            vect_space.push_back(new Fighter(atoi(es.c_str()),atoi(crew_max.c_str()),stof(price),atoi(prop.c_str()),reg,id,this->strToBool(a_sale),w));
            w.clear();
            break;
        }
        case '@':
        {
            getline(load_crafts, nh, ',');
            getline(load_crafts, mp, ',');
            getline(load_crafts, es, '\n');

            vect_space.push_back(new SpaceStation(atoi(nh.c_str()),atoi(mp.c_str()),this->strToBool(es),atoi(crew_max.c_str()),stof(price),atoi(prop.c_str()),reg,id,this->strToBool(a_sale)));
            break;
        }
        case '#':
        {
            getline(load_crafts, ml, ',');
            getline(load_crafts, cs, ',');
            getline(load_crafts, es, '\n');

            vect_space.push_back(new SpaceCarrier(atoi(ml.c_str()),atoi(cs.c_str()),this->strToBool(es),atoi(crew_max.c_str()),stof(price),atoi(prop.c_str()),reg,id,this->strToBool(a_sale)));
            break;
        }

        }//end of swich

    }
    load_crafts.close();
}

void Platform::initialize() //Load values from the files into the programs
{  
    ifstream loader;
    ifstream sec_loader;
    string ids = "non-sense";
    string porigin = "non-sense";
    //
    Date date_reg;
    string d = "non-sense";
    string m = "non-sense";
    string y = "non-sense";
    int day = 0;
    int month = 0;
    int year = 0;

    //

    loader.open("owners.txt",ios::in);
    if(loader.is_open()) //we check that the file is open. In our case not open means first use of the program
    {
        while(!loader.eof()) //Till the end
        {
            getline(loader, ids, ','); //delimiter of new line for security
            getline(loader, porigin, '\n');

            if (ids.size() == 10) //We only check lenght, not needed syntax
            {
                vect_owner.push_back(new Alien(ids, porigin)); //we create an alien
            }

            else if(ids.size() == 9) //The same, only lenght
            {
                vect_owner.push_back(new Human(ids, porigin)); //we create an human
            }
        }

         loader.close();
         cout <<  "\033[2J\033[1;1H";
    }

    else
    {
        cout << "<<Error loading the data, please close the program and reopen it again>>" << endl;
    }

    /*loader.open("ships.txt", ios::in);

    if (loader.is_open())
    {
        while(!loader.eof())
        {
            this->loadCrafts(loader);
        }

        loader.close();
    }
    else
        cout << "<<Error loading the data, please close the program and reopen it again>>" << endl;*/
//we start with sales
    this->loadCrafts();

    loader.open("sales.txt", ios::in);
    if(loader.is_open())
    {
        while(!loader.eof())
        {
            getline(loader, d, '/');
            getline(loader, m, '/');
            getline(loader, y, '\n');
            getline(loader, ids, '\n');

            day = atoi(d.c_str());
            month = atoi(m.c_str());
            year = atoi(y.c_str());

            date_reg.day = day;
            date_reg.month = month;
            date_reg.year = year;


            vect_sale.push_back(Sale(date_reg, ids));
        }
        vect_sale.pop_back(); //we observe that ilogically it creates an extra object so we delete it

        loader.close();
    }
}

void Platform::displayMenu()
{
    //displays the menu
    cout << "   ***** Welcome to DLRSHIP *****" << endl;
    cout << "-------------------------------------" << endl;
    cout << "   Select one of the options below:" << endl;
    cout << "   0. Introduce Owner." << endl;
    cout << "   1. Edit Owner." << endl;
    cout << "   2. Delete Owner." << endl;
    cout << "   3. Introduce new SpaceCraft." << endl;
    cout << "   4. Edit SpaceCraft." << endl;
    cout << "   5. Delete SpaceCraft." << endl;
    cout << "   6. Register a Sale." << endl;
    cout << "   7. Show owners registered. " <<endl;
    cout << "   8. Show Space Ships for sale" << endl;
    cout << "   9. Show the record of sales"  << endl;
    cout << "   <<< Press 'x' to save and exit >>>" << endl << endl;
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
        string planet = "non-sense";

        do
        {
            cout << "Please introduce the nie in the format 'NNNNNNNNNN'" << endl << "being 'N' a natural number: ";
            cin >> nie;
            correct = this->checkNie(nie); //we verify the identity through a bool variable
                                          //We may introduce a message for try again
        }
        while (correct == false);
        cout << "Introduce the planet of origin: ";
        cin >> planet;

        vect_owner.push_back(new Alien(nie, planet));//if OK then we create the object
    }
    else if (owner_ty == 'h') //Human chosen
    {
        string nif = "non-sense";
        string planet = "non-sense";

        do
        {
            cout << "Please introduce the nif in the format 'NNNNNNNNL' "<< endl << "being 'N' a natural number and 'L'";
            cout << "a CAPITAL lettter: ";
            cin >> nif;
            correct = this->checkNif(nif); //we verify the identity through a bool variable
        }                                  //We may introduce a message for try again

        while (correct == false);
        cout << "Introduce the planet of origin: ";
        cin >> planet;
        vect_owner.push_back(new Human(nif, planet));//if OK then we create the object

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

void Platform::destroyerCreator(int &crew, float &price,int &propu, string &registration, string &owner) //used in SpacaCraftCreator()
{
    unsigned int num_weapons = 0;
    vector<char> weapons;
    char type_weapon = '\0';
    //
    if (crew != 1)
        cout << "Crew must be one -- automatically changed" << endl;
    crew = 1; //by specification
    cout << "how many weapons does it have?: ";
    cin >> num_weapons; //we ask for the lenght
    cout << endl << "//////////////////////////////" ;
    cout << endl << " Types are:" << endl << " 1. Plasma Cannon" << endl << " 2. Thermonuclear missiles" << endl;
    cout << " 3. Laser beams" << endl << " 4. PEM" << endl << "//////////////////////////////" << endl;

    for(unsigned int i = 0; i < num_weapons; i++) //loop with the num of weapons specified
    {
        cout << "weapon " << i+1 << ": ";
        cin >> type_weapon;

        weapons.push_back(type_weapon);
    }

    vect_space.push_back(new  Destroyer(crew,price,propu,registration,owner,true,weapons)); //true means av by default
    cout << "---Destroyer Created---" << endl;

}

void Platform::showPropTypes()
{
    cout << "////////////////////////" << endl;
    cout << " 1. Warp Drive. " << endl << " 2. Trace compressor" << endl << " 3. FTL engine." << endl;
    cout << " 4. Solar sails." << endl << " 5. Ion engine." << endl;
    cout << "////////////////////////" << endl;
}

void Platform::fighterCreator(int &crew, float &price,int &propu, string &registration, string &owner)
{
    unsigned int num_weapons = 0;
    unsigned int speedTop = 0;
    vector<char> weapons;
    char type_weapon = '\0';
    //
    if (crew != 1)
        cout << "Crew must be one -- automatically changed" << endl;
    crew = 1; // by requirements must be one, so we force it
    cout << "What is its maximum speed? (in light-years): ";
    cin >> speedTop;
    cout << "how many weapons does it have?: ";
    cin >> num_weapons;
    cout << endl << "//////////////////////////////" ;
    cout << endl << " Types are:" << endl << " 1. Plasma Cannon" << endl << " 2. Thermonuclear missiles" << endl;
    cout << "//////////////////////////////" << endl;

    for(unsigned int i = 0; i < num_weapons; i++) //loop with the num of weapons specified
    {
        cout << "weapon " << i+1 << ": ";
        cin >> type_weapon;

        weapons.push_back(type_weapon); //loads the vector
    }

    vect_space.push_back(new Fighter(speedTop,crew,price,propu,registration,owner,true,weapons));
    cout << "---Fighter Created---" << endl;

}

void Platform::scCreator(int &crew, float &price,int &propu, string &registration, string &owner)
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

    vect_space.push_back(new SpaceCarrier(maxLoad,speedCruise, eShield,crew,price,propu,registration,owner, true));
    cout << "---Carrier Created---" << endl;
}

void Platform::ssCreator(int &crew, float &price, int &propu, string &registration, string &owner)
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

    vect_space.push_back(new SpaceStation(hangars,passengers,eShield,crew,price,propu,registration,owner,true));
    cout << "---Carrier Created---" << endl;
}

void Platform::spaceCraftCreator()
{
    vector<Owners*>::iterator it;
    string reg = "non-sense";
    unsigned int type = 0;
    string own = "non-sense";
    bool valid = false;
    bool found = false;
    int c = 0;
    float p = 0.0;
    int prop_type = 0;
    //
    cout << "Introduce its Owner id (nif/nie): ";
    cin >> own;

    this->searchOwner(own, it, found);

    if(found == false)
        cout << "The owner is not registered or you may have written bad the id" << endl;
    else
    {
        do
        {
            cout << "Introduce the registration number in the format 'LNNNNLLL' " << endl;
            cout << "(L capital leter,N natural nº): ";
            cin >> reg;
            valid = this->checkRegNum(reg);
        }
        while(valid != true);

        cout << "Enter the maximum crew-(remember figthers/destroyers are unipersonal): ";
        cin >> c;
        cout << "Enter the selling price in Units: ";
        cin >> p;
        cout << "Enter the propulsion type" << endl;
        this->showPropTypes();
        cout << "Type: ";
        cin >> prop_type;

        cout <<  "\033[2J\033[1;1H"; //clear screen

        do
        {
            if(own.size() == 9) //if hte size of the string of the founder is human type (we have checked that exists)
            {
                cout << "Please, choose its specific type:" << endl  << "-1. Fighter" << endl;
                cout << "-2. SpaceCarrier" << endl << "3.-SpaceStation" << endl << "Type: ";
                cin >> type;
            }
            else if(own.size() == 10) //size of a nie
            {
                cout << "Please, choose its specific type:" << endl  << "-1. Fighter" << endl;
                cout << "-2. SpaceCarrier" << endl << "3.-Destroyer" << endl << "Type: ";
                cin >> type;
                type += 3;
            }

            if(type == 1 || type == 4) //means Fighter selected
            {
                this->fighterCreator(c,p,prop_type,reg,own);
            }
            else if(type == 2 || type == 5) //means Space Carrier
            {
                this->scCreator(c,p,prop_type,reg,own);
            }
            else if(type == 3) //means Space Station
            {
                this->ssCreator(c,p,prop_type,reg,own);
            }
            else if(type == 6) //means destroyer
            {
                this->destroyerCreator(c,p,prop_type,reg,own);
            }
            else
            {
                cout << "Ilegal option" << endl;
                valid = false; //if we obtain a false we toggle to false and not allow
            }

        } while(valid != true);

    }

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

void Platform::showSales(Date d)
{
    vector<Sale>::iterator sales;
    bool date_equ;
    //
    for(sales = vect_sale.begin(); sales != vect_sale.end(); sales++)
    {
        date_equ = sales->compareDate(d); //not the optimum solution, but reasons explained below
        if(date_equ == true) //if the comparison returns true we show
            sales->showSale();
    }
}
/* In the original aproach we used  if(saler->getDate() == d) that is more direct since it does not need an extra variable
 * like date_equ but the compiler did not recognize the left element as a Date type although the method getDate()
 * returns the Date atribute in the Sale object
 */

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
        case '0':
            this->ownerCreator();
            break;

        case '1' :
            this->editorOwn();
            break;

        case '2' :
            this->deleteOwn();
            break;

        case '3' :
            this->spaceCraftCreator();
            break;

        case '4' :
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

        case '5' :
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
        case '6' : // not error-friendly yet
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
                (*saler)->transaction(create_sale); //we pass a bool that will told us if the id has been changed
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
        case '7':

            this->showOwners();
            cout << endl;
            break;

        case '8':
            this->showSpacesAvailible();
            cout << endl;
            break;

        case '9':
        {
            char c = '\0';
            cout << "Do you want to search in a specific date(y/N):";
            cin >> c;
            cout << "*************************" << endl;
            if(c == 'y')
            {
                Date start = vect_sale[0].getDate(); //we get the first day in the record
                Date target;
                //
                cout << " Starting at ";
                start.display(); //we show the first date to the user
                cout << " Day: ";
                cin >> target.day; //not protected against bad user input, its just not found
                cout << " Month: ";
                cin >> target.month;
                cout << " Year: ";
                cin >> target.year;

                //create the target date
                this->showSales(target);
                cout << endl;
            }

            else if(c == 'N')
            {
                this->showSales();
                cout << endl;
            }

            else
                cout << "--Error in the key pressed--";

            break;
        }
        case 'x':
            break;

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

void Platform::saver()
{
    ofstream saver;
    saver.open("owners.txt");
    if(saver.is_open())
    {
        for(vector<Owners*>::iterator i = vect_owner.begin(); i != vect_owner.end();i++)
        {
            saver << (*i)->getId() << ',';
            saver << (*i)->getPlanet() << endl;
        }
        saver.close();
    }
    //Done with owners
    saver.open("spaces.txt");

    if(saver.is_open())
    {
        for(vector<SpaceCraft*>::iterator i = vect_space.begin(); i != vect_space.end();i++)
        {
            (*i)->saveCraft(saver);
        }
        saver.close();
    }
    //Done with Spaceships

    saver.open("sales.txt");

    if(saver.is_open())
    {
        for(vector<Sale>::iterator i = vect_sale.begin(); i != vect_sale.end();i++)
        {
            i->saveSale(saver);
        }

        saver.close();
    }
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

    cout << "\033[2J\033[1;1H";
}
