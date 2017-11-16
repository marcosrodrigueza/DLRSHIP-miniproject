#include <iostream>
#include <platform.h>


using namespace std;

int main()
{
    Date test;
    test.day = 12;
    test.month = 11;
    test.year = 2017;

    Platform platform = Platform(test);
    platform.performer();


    return 0;
}

//it = find(vect_human.begin()->getId(),vect_human.end()->getId(), id);
