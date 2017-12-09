#ifndef OWNERS_H
#define OWNERS_H
#include<string>
using namespace std;

class Owners
{
protected:
    string planet;

public:
    Owners(string p);
    virtual void show();
    virtual void editId(const string id)= 0;
    virtual string getId()= 0;
    string getPlanet();
    virtual bool checkId(const string &n)const = 0;
    virtual ~Owners();
};

#endif // OWNERS_H
