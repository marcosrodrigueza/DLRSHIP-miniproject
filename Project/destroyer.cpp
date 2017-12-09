#include "destroyer.h"
#include "spacecraft.h"

Destroyer::Destroyer(int cm, float p, int pro, string rn, string o,bool b,vector<char> w): SpaceCraft(cm,p,pro,rn,o,b)
{
    destroyer_weapons = w;
    num_weapons = w.size();
}

void Destroyer::show()
{
    vector<char>::iterator weapons;
    int ty_1 = 0, ty_2 = 0, ty_3 = 0, ty_4 = 0; //all types
    //
    for (weapons = destroyer_weapons.begin(); weapons != destroyer_weapons.end(); weapons++) //to determine the total of types
    {
        if ((*weapons) == '1')
            ty_1++;

        else if((*weapons) == '2')
            ty_2++;

        else if((*weapons) == '3')
            ty_3++;

        else if((*weapons) == '4')
            ty_4++;
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
    cout << " Plasma Cannons: " << ty_1 << endl;
    cout << " Thermonuclear missiles: " << ty_2 << endl;
    cout << " Laser Beams: " << ty_3 << endl;
    cout << " PEM's: " << ty_4 << endl << endl;
}

void Destroyer::showTypes()
{
    cout << endl << "------------------------------------" ;
    cout << endl << " Types are:" << endl << " 1. Plasma Cannon" << endl << " 2. Thermonuclear missiles" << endl;
    cout << " 3. Laser beams" << endl << " 4. PEM" << endl << "------------------------------------" << endl;
}

void Destroyer::editSpacecraft()
{
    char option = '\0';
    char tw = '\0';
    int amount = 0;
    int comparer = 0;
    vector<char>::iterator searcher;
    //
    this->editBaseParameters();//edit the parameters inhereted
    crewMax = 1; //by security

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

        for(searcher = destroyer_weapons.begin(); searcher != destroyer_weapons.end(); searcher++)
        {
            if((*searcher) == tw) //compare if the type is the same as the introduced
            {
                destroyer_weapons.erase(searcher);
                searcher--; //because all the elements have been shifted to the left one position
                comparer++; //we have found one element
            }

            if (comparer == amount) //if we have erased the same number as specified we end
            {

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

            destroyer_weapons.push_back(tw);
        }
    }

    num_weapons = destroyer_weapons.size();

    cout << "----Changes done----" << endl;
}

void Destroyer::saveCraft(ofstream &output)
{
    string code = "-";
    //
    output << code << ',';
    output << regNum << ',';
    output << owner << ',';
    output << crewMax << ',';
    output << price << ',';
    output << propulsion << ',';
    output << av_sale << ',';
    output << num_weapons << ',';

    for (vector<char>::iterator i = destroyer_weapons.begin(); i != destroyer_weapons.end(); i++)
    {
        output << (*i);
    }

    output << endl;
}

Destroyer::~Destroyer()
{
    cout <<"-Destroyer succesfully eliminated-" << endl;
}

