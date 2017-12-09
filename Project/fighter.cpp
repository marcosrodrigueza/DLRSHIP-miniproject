#include "fighter.h"
#include "spacecraft.h"

Fighter::Fighter(int ms, int cn, float p, int pro,string rn, string o, bool b, vector<char> w): SpaceCraft(cn,p,pro,rn,o,b)
{
    maxSpeed = ms;
    fighter_weapons = w;
    num_weapons = w.size();
}

void Fighter::show()
{
    vector<char>::iterator weapons;
    int ty_1 = 0, ty_2 = 0;
    //
    for (weapons = fighter_weapons.begin(); weapons != fighter_weapons.end(); weapons++) //to determine the total of types
    {
        if ((*weapons) == '1')
            ty_1++;
        else if((*weapons) == '2')
            ty_2++;
    }

    cout << "-------------------------------------" << endl;
    cout << " Owner: " << owner << endl;
    cout << " RegNum: " << regNum << endl;
    cout << " Price: " << price << endl;
    cout << " Propulsion type: ";

    switch (propulsion) //we use it like a map
    {
    case 1:
        cout << "Warp drive";
        break;
    case 2:
        cout << "Trace compressor";
        break;
    case 3:
        cout << "FTL engine";
        break;
    case 4:
        cout << "Solar sails";
        break;
    case 5:
        cout << "Ion engine";
        break;
    default:
        cout << "Typo";
        break;
    }
    cout << endl;
    cout << " Max Crew: " << crewMax << endl;
    cout << " Max Speed: " << maxSpeed << endl;
    cout << " Plasma Cannons: " << ty_1 << endl;
    cout << " Thermonuclear missiles: " << ty_2 << endl << endl;
}

void Fighter::showTypes()
{
    cout << endl << "------------------------------------" ;
    cout << endl << " Types are:" << endl << " 1. Plasma Cannon" << endl << " 2. Thermonuclear missiles" << endl;
    cout  << "------------------------------------" << endl;
}

void Fighter::editSpacecraft()
{
    unsigned int new_maxspeed = 0;
    char option = '\0';
    char tw = '\0';
    int amount = 0;
    int comparer = 0;
    vector<char>::iterator searcher;
    //
    this->editBaseParameters();
    crewMax = 1; //by security

    cout << "Máximum speed : ";
    cin >> new_maxspeed;
    if(new_maxspeed != 0)
        maxSpeed = new_maxspeed;

    cout << "#### WEAPON EDITOR ####" << endl << " Do you want to delete any weapon?(y/N) :";
    cin >> option;
    if(option == 'y')
    {
        cout << "Select the type of weapon to be eliminated ";

        this->showTypes();

        cout << "Type: ";
        cin >> tw;
        cout << " How many weapons of this type? :";
        cin >> amount;

        for(searcher = fighter_weapons.begin(); searcher != fighter_weapons.end(); searcher++)
        {
            if((*searcher) == tw) //compare if the type is the same as the introduced
            {
                fighter_weapons.erase(searcher);
                searcher--; //because all the elements have been shifted to the left one position
                comparer++; //we have found one element
            }

            if (comparer == amount) //if we have erased the same number as specified we end
            {
                break;

            }
        }
        amount = 0; //if we had use them(entered in the if)we clear to reuse them
        option = '\0';
        tw = '\0';
    }

    cout << " Do you want to add any weapon? (y/N) :";
    cin >> option;

    if( option == 'y')
    {
        cout << "how many weapons?: ";
        cin >> amount; //we ask for the lenght

        this->showTypes();

        for(int j = 0; j < amount; j++) //loop with the num of weapons specified
        {
            cout << "weapon " << j+1 << ": ";
            cin >> tw;

            fighter_weapons.push_back(tw);
        }
    }

    num_weapons = fighter_weapons.size();

    cout << "----Changes done----" << endl;
}

void Fighter::saveCraft(ofstream &output)
{
    string code = "%";
    //
    output << code << ',';
    output << regNum << ',';
    output << owner << ',';
    output << crewMax << ',';
    output << price << ',';
    output << propulsion << ',';
    output << av_sale << ',';

    output << num_weapons << ',';

    for (vector<char>::iterator i = fighter_weapons.begin(); i != fighter_weapons.end(); i++)
    {
        output << (*i);
    }

    output << ',';
    output << maxSpeed << endl;

}

Fighter::~Fighter()
{
    cout <<"-Fighter succesfully eliminated-" << endl;
}

/*string Fighter::getReg()
{
    return regNum;
}
*/
