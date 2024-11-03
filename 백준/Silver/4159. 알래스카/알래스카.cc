#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int test;
    cin>> test;

    while(test != 0) {
        int input[test];
        int state = 1;

        for(int i = 0; i < test; i++) {
            cin>> input[i];
        }

        sort(input, input + test);

        // for(int i = 0; i < test; i++) {
        //     cout<< input[i]<< ' ';
        // }

        for(int i = 0; i < test-1; i++) {
            if(input[i+1] - input[i] > 200 || 1422 - input[test-1] > 100 || test < 8) {
                state = 0;
            }
        }

        if(state == 1) {
            cout<< "POSSIBLE"<< '\n';
        } else {
            cout<< "IMPOSSIBLE"<< '\n';
        }

        cin>> test;
    }
}