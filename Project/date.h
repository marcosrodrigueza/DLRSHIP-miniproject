#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;
class Date
{
public:
   int day, month, year;
   void display();
   bool operator ==(const Date& d2);
};

#endif // DATE_H
