#include <iostream>
using namespace std;

int main(){
    double x,y;
    cout << "Enter x & y coordinates: ";
    cin >> x >> y;
    if ( x >= 0 && x <= 3 && y >= 0 && y <= 3){
        cout << "Inside";
    }
    else{
        cout << "Outside";
    }
    return 0;
}
