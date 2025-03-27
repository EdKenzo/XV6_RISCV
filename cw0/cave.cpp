#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <string>

#include "cave.h"
#include "rock.h"
#include "thing.h"
#include "location.h"
#include "move.h"
#include "place.h"
#include "throw.h"
#include "explode.h"

using namespace std;

Cave::Cave(int w, int h) : width(w), height(h) // width and height of the cave
{
    if ( width < 5 || height < 5)
        throw new logic_error("cave too small for tom.");

    map = new Location**[width];

    for (int x = 0; x < width; x++)
    {
        Location** column = new Location*[height];
        map[x] = column;
        for (int y = 0; y < height; y++)
            column[y] = new Location();
    }

    // create some rocks
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            if ( x == 0 || y == 0 || x == width-1 || y == height-1 )
                 map[x][y] -> add( new Rock() );

    tom = new Tom();
    // add tom to the middle of the map
    tom -> setLocation( this, width/2,height/2);
}

Cave::~Cave()
{
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            delete (map[x][y]);
    delete[] map;
}

void Cave::command (string userCommand)
{
    if (Move().triggersOn(userCommand))
        Move().fire(*this, userCommand);
    else if (Place().triggersOn(userCommand))
        Place().fire(*this, userCommand);
    else if (Throw().triggersOn(userCommand))
        Throw().fire(*this, userCommand);
    else if (Explode().triggersOn(userCommand))
        Explode().fire(*this, userCommand);
    else
        cerr << "tom doesn't know how to "+userCommand << endl;;
}

//Copy constructor and copy assignment
Cave::Cave(const Cave &cpCaveA) : Cave(cpCaveA.width, cpCaveA.height)
{
    map = new Location**[width];
    tom = new Tom();

    for (int x = 0; x < width; x++)
    {
        Location** column = new Location*[height];
        map[x] = column;
        for (int y = 0; y < height; y++)
            column[y] = new Location();
    }
    //Copying things onto the new map
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            for (Thing* t : *cpCaveA.map[x][y] -> getThings()){//for things in the vector
                if (t->getName() != "tom")// if not tom
                    map[x][y]->add(t->clone()); // clone on map
            }
        }
    }

    tom->setLocation(this, cpCaveA.tom->getX(), cpCaveA.tom->getY()); //set toms location
}


Cave& Cave::operator=(Cave &cpCaveB){

    if (&cpCaveB != &cpCaveB){
        /*

        for (int x = 0; x < width; x++)
        {
            Location** column = new Location*[height];
            map[x] = column;
            for (int y = 0; y < height; y++)
                column[y] = new Location();
        }
        //Copying things onto the new map
        for (int x = 0; x < width; x++){
            for (int y = 0; y < height; y++){
                for (Thing* t : *cpCave.map[x][y] -> getThings()){//for things in the vector
                    //cout << "thing: " + t->getName() << endl;
                    map[x][y]->add(t->clone());//add things to map

                    //cout << "added" << endl;
                    if (t->getName() == "tom"){
                       // cout << "set tom location" << endl;
                        tom -> setLocation(this, x , y);
                    }
                }
            }
        }*/

    }


    return *this;
}


void Cave::show()
{
    vector<Thing*>* thingsWithTom = map[tom -> getX()][tom -> getY()] -> getThings();

    for (int y = 0; y < height; y++)
    { // for all rows
        for (int x = 0; x < width; x++){ // for all columns
            cout << map[x][y] -> show(); // output whatever we find there
        }
        cout << "  "; // list the things at this location
        if (y <  (int) thingsWithTom -> size()){
            cout << (*thingsWithTom)[y] -> getName();
        }
        cout << endl;
    }

    cout << endl;
}


