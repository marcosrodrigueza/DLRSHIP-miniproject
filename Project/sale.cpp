#include "sale.h"

Sale::Sale(Date d, string i)
{
    dateSale = d;
    id = i;
}

void Sale::showSale()
{
    cout << "-------------------------------------" << endl;
    cout << " Buyer: " << id << endl;
    cout << "Date: ";
    dateSale.display();
}

Date Sale::getDate()
{
    return dateSale;
}

bool Sale::compareDate(const Date& date)
{
   bool check = false;
   if(dateSale == date)
       check = true;
   return check;
}

