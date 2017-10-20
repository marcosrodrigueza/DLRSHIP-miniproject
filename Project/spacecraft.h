#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class SpaceCraft
{
    int crewMax;
    float price;
    PropTy prop;
    string regNum;

public:

    string owner;

    void show();
    bool checkSale();
};

#endif // SPACECRAFT_H
