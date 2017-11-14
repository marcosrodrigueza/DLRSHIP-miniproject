#ifndef PLATFORM_H
#define PLATFORM_H
#include "date.h"

class Platform
{
public:

    Date actualDate;

    Platform(Date ad);
    void initialize();
    void performer();
};

#endif // PLATFORM_H
