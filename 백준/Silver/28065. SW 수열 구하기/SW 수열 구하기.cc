#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin>> n;

    int Max = n;
    int Min = 1;
    while(n--) {
        if(n % 2 == 1) {
            cout<< Max--<< ' ';
        } else {
            cout<< Min++<< ' ';
        }
    }   
}