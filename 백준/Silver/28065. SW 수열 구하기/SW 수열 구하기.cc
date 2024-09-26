#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin>> n;

    int Max = n;
    int Min = 1;
    bool stat = true;
    while(n--) {
        if(stat == true) {
            cout<< Max--<< ' ';
            stat = false;
        } else {
            cout<< Min++<< ' ';
            stat = true;
        }
    }   
}