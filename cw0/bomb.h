#ifndef BOMB_H
#define BOMB_H


#include "thing.h"

// Bomb can does not block Tom and can be placed.
class Bomb : public Thing
{

    string getName()
    {
        return "bomb";
    }
    virtual Thing* clone()
    {
        return new Bomb(); // over-rides clone to return new bomb.
    }
};


#endif // BOMB_H


