#ifndef ALIEN_H
#define ALIEN_H

class Alien : public Owners
{
    int nie;

public:

    Alien(int n);
    void buyD(string &ship);
};

#endif // ALIEN_H
