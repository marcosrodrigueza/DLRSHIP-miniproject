#ifndef SALE_H
#define SALE_H
#include<iostream>
#include <string>
#include <fstream>
#include "date.h"

using namespace std;

class Sale
{
    Date dateSale;
    string id;

public:

    Sale(Date d, string i);
    void showSale();
    Date getDate();
    bool compareDate(const Date& date);
    void saveSale(ofstream &output);
};

#endif // SALE_H
