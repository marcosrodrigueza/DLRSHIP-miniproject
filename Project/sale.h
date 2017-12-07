#ifndef SALE_H
#define SALE_H
#include<iostream>
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
    bool compareDate(const Date& date);
};

#endif // SALE_H
