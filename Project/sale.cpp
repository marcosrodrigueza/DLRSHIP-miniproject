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
