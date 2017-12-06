#ifndef OWNERS_H
#define OWNERS_H
#include<string>
using namespace std;

class Owners
{
public:

    virtual void show();
    virtual void editId(const string id)= 0;
    virtual string getId()= 0;
    virtual bool checkId(const string &n)const = 0;
    virtual ~Owners();
};

#endif // OWNERS_H
