#ifndef HUMAN_H
#define HUMAN_H

class Human : public Owners
{
    string nif;

public:

    Human(string n);
    void buySS(string &ship);
};

#endif // HUMAN_H
