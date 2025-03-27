#include "throw.h"

void Throw::fire(Cave& c, string userCommand)
{
    string s = tail(userCommand); //the instruction after the command (eg. coin north)
    string item = s.substr(0,s.find(' '));//creates a substring of the direction (eg. coin)
    string dir = tail(s);//gives direction (eg. north)

    int throwLocX = c.getTom()->getX(),  throwLocY = c.getTom()->getY();//get location of Tom

    if (dir[0] == 'w')//++ / -- location based on dir
        throwLocX--;
    else if  (dir[0] == 'n')
        throwLocY--;
    else if (dir[0] == 's')
        throwLocY++;
    else if (dir[0] == 'e')
        throwLocX++;

    if ( c.getMap()[throwLocX][throwLocY] -> isBlocking() )//return if something is blocking
        {
            cerr << "can't throw there, something is blocking the way" << endl;
            return;
        }
    Location* loc = c.getMap()[throwLocX][throwLocY];

    if (item.compare("coin")==0)
        loc ->add(new Coin());
    else if (item.compare("mushroom")==0)
        loc ->add(new Mushroom());
    else
        cerr << "I don't know how to throw a " << userCommand << endl;
}

