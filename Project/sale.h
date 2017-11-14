#ifndef SALE_H
#define SALE_H
#include <string>
#include "date.h"

using namespace std;

class Sale
{
    Date dateSale;
    string id;

public:

    Sale(Date d, string i);
    void showSale();
};

#endif // SALE_H
