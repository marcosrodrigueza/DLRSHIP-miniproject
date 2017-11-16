#ifndef OWNERS_H
#define OWNERS_H
#include<string>
using namespace std;

class Owners
{
public:

    void show();
    void buySC(string &ship);
    void buyF(string &ship);
    virtual void editId(const string id)= 0;
    virtual string getId()= 0;
};

#endif // OWNERS_H
