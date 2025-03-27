#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <utility>
#include "explode.h"
#include "thing.h"

using namespace std;



void Explode::fire(Cave& c, string userCommand)
{
    if (tail(userCommand) == ""){ //Ensures no command after command "explode"


        set <Location* >*s = new set <Location*>();//initialises a set


        int getTomX = c.getTom()->getX(), getTomY = c.getTom()->getY();//get Toms location
        DFS(c, s, getTomX, getTomY); //call DFS for toms current location

        destroy(s);//removes all items except Tom in the set containing location of the bombs
    }
}


void Explode::DFS(Cave& c, set<Location*>*s, int col, int row){
    //for all locations around x,y,
    int dirRow[] = { 0, 0, 1, 0, -1 };
    int dirCol[] = { 0, -1, 0, 1, 0 };
    for (int i=0; i<5; i++){ //sets row and column to point under and adjacent to x,y
        row = row + dirRow[i];
        col = col + dirCol[i];
        if (row < 0 || col < 0 || row >= c.getHeight() || col >= c.getWidth()){ //check if row and col are within range
            continue;
        }
        else{ //if within range //NB: ONLY CHECKS VERTICAL?????
            for(auto t : *c.getMap()[row][col]->getThings()){ //for t in things
                if(t->getName() == "bomb"){ //if there is a bomb
                    if (s->insert(c.getMap()[row][col]).second){ //check if correctly inserted to s without duplicates
                        DFS(c, s, col, row); //recursively call DFS

                    }
                }
            }
        }
    }
/*
    //Prints the locations with bomb
    int count =0;
    for (auto& loc : *s){
        for (auto &thing : *loc->getThings()){

            count += 1;

        }
    }
    cout<< count<< endl;
*/
}


void Explode::destroy(set<Location*> *s){
    for (auto *loc : *s){
        //cout << loc << endl;

        for(auto &thing : *loc->getThings()){
            //cout << "checking: " + thing->getName() << endl;
            if (thing->getName() != "tom"){
                //cout << "removing: " << thing->getName() << endl;
                loc->remove(thing);//remove all things in vector
            }
        }
    }
}


