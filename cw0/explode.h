#ifndef EXPLODE_H
#define EXPLODE_H

#include "command.h"
#include "location.h"
#include <set>


//Command makes all adjacent bombs explode as well, destroying all object except Tom
class Explode : public Command
{
public:
    Explode() : Command("explode"){};
    void fire(Cave& c, string userCommand);
    void DFS(Cave& c, set<Location*>*s, int col, int row);
    void destroy(set<Location*> *s);
};

#endif // EXPLODE_H
