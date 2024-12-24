#include <iostream>
using namespace std;

int main() {
    int n;
    cin>> n;

    int input[n];
    
    for(int i = 0; i < n; i++) {
        cin>> input[i];
    }

    int m = 0;
    int remain = 30;
    int output = 0;

    while(m < n) {
        if(input[m] <= remain) {
            remain = remain - input[m] == 0 ? 30 : remain - input[m];
            output++;
            m++;
        } else {
            if(input[m] <= remain * 2) {
                output++;
            }

            remain = 30;
            m++;
        }
    }

    cout << output;
}