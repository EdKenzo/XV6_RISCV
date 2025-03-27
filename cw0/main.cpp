//
// Do not change this file - but you might edit the arguments passed to main:
//  - Projects (spanner on right)
//  - Under "Build and Run", select "Run" (small green arrow)
//  - Edit "Command line arguments" (main panel)
//
// v1: initial release
// v2: removed std:: from some strings & allowed students to edit the Location class
//

#include <string>
#include <iostream>

#include "cave.h"
#include "test.cpp"

using namespace std;


int main(int argc, char** argv) {

    int width = 8, height = 8; // provided code only works for these values(!)

    if (argc == 3) { //if input given, width and height are aguments
        width  = stoi (argv[1]);
        height = stoi (argv[2]);
    }

    if (argc != 2) {

        Cave c(width, height);

        Cave b(c);
        string input;
        while (true) {

            b.show();
            //c.show();
            cout << ">";
            getline(cin, input);

            if (input.compare("exit") == 0)
                break;
            b.command(input);
            //c.command(input);
        }
    }
    else test();
}
