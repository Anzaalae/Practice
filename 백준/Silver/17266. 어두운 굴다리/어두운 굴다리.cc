#include <iostream>
using namespace std;

int main() {
    int len, garo;
    cin>> len>> garo;

    int input[garo];
    for(int i= 0; i< garo; i++) {
        cin>> input[i];
    }

    int max;
    
    if(input[0] <= len - input[garo-1]) {
        max = len - input[garo-1];
    } else {
        max = input[0];
    }

    int temp;

    for(int i= 0; i< garo-1; i++) {
        temp = input[i+1] - input[i];
        if(temp % 2 == 1) temp++;
        temp/=2;
        if(max < temp) {
            max = temp;
        }
    }

    cout<< max;
}