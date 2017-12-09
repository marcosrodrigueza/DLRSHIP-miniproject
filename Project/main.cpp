//////////RELEASE NOTES//////////
// Normally methods are meant to act on its atributes, in this program there is an exception to this design philosophy
//with the method of check id, that through polymorphism automatically checks the proper syntax of id on the object
// "pointed" by the iterator without explicitely knowing the class of the object.
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
#include <ctime>
#include "platform.h"

using namespace std;

int main()
{
    Date test;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900

    test.day = day;
    test.month = month;
    test.year = year;

    Platform platform = Platform(test);
    platform.initialize();
    platform.performer();
    platform.saver();
    platform.deleter();

    return 0;
}

/*To do list:
 * enumeration for planet of origin and type of weapon (see how this matches current implementation.//watch how to in reference
 * check the id of sale
 * parser for files. ie method to load the file and method to save all the modifications.
 * take a look into restrictions for the type of owner to perform the sale.
 * automatic date set
 * only get a char with cin
 * flags in edits and so, check for the user experience
*/


