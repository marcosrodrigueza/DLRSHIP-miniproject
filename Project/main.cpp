//////////RELEASE NOTES//////////
// this comment is not fully protected against some user errors
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
