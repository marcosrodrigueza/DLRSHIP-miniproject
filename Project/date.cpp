#include "date.h"

void Date::display()
{
    cout << day << "/" << month << "/" << year << endl;
}
bool Date::operator ==(const Date& d2)
{
    bool check = false;
    if (day == d2.day && month == d2.month && year == d2.year)
        check = true;

    return check;
}
