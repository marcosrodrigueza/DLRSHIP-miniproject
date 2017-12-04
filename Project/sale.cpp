#include "sale.h"

Sale::Sale(Date d, string i)
{
    dateSale = d;
    id = i;
}

void Sale::showSale()
{
    cout << " Buyer: " << id << endl << endl;
}
