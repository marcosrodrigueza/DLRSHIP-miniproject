//////////RELEASE NOTES//////////
// This version is not fully protected against some User errors.
// That errors include entering an id with different lenght or trying to edit a owner that is not registered.
// In this version, polymorphism is not implemented, so the code has not been optimized yet.
//***COMMENTS:
// Platform has methods to create owners, that at the end call the constructor of the classes.
// This is resolved in this way to prevent creating objects with bad parameters, so we use the creator methods
// to identify the specific Class type and to take the data from the user before the calls.
//***AUTHORS.
// Marcos Rodríguez Aranda
// Miguel Fernandez Millán

#include <iostream>
#include <platform.h>

using namespace std;

int main()
{
    Date test;
    test.day = 17;
    test.month = 11;
    test.year = 2017;

    Platform platform = Platform(test);
    platform.performer();


    return 0;
}


