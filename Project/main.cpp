//////////RELEASE NOTES//////////
// This version is not fully protected against some User errors.
// Those errors include a bad id in the sale proccess or entering/selling a Craft to a Owner type not permitted.
// In this version, polymorphism is only implemented for SpaceCrafts, so the code has not been fully optimized yet.
// List for the type of propulsion and weapon is not implemented yet.
//***IMPORTANT NOTE:
// In this version you can not enter for editing or deleting an unregistered user. The solution is prepared and
// optimized for Polymorphic Owner class that will be implemented in future versions. (The reason is that within this
// version you have several if's to detected and conduce to the correct Owner type, and we will obtain nested if's
// and a very ugly solution.
//***COMMENTS:
// Platform has methods to create owners, that at the end call the constructor of the classes.
// This is resolved in this way to prevent creating objects with bad parameters, so we use the creator methods
// to identify the specific Class type and to take the data from the user before the calls.
// Date must be introduced manually down here in the main. In future releases it will be done automatically
//***AUTHORS.
// Marcos Rodríguez Aranda

#include <iostream>
#include <platform.h>

using namespace std;

int main()
{
    Date test;
    test.day = 19;
    test.month = 11;
    test.year = 2017;

    Platform platform = Platform(test);
    //platform.initialize()
    platform.performer();
    platform.deleter();

    return 0;
}

/*To do list:
 * enumeration for planet of origin and type of weapon (see how this matchecurrent implementation.//watch how to in reference
 * implement polymorphism for owners class.
 * impelement the last functionalities.
 * - show owners
 * - show spacecrafts
 * -show sale and search by date
 * parser for files. ie method to load the file and method to save all the modifications.
 * take a look into restrictions for the type of owner to perform the sale.
 * automatic date set
*/


