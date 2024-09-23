#include <iostream>
using namespace std;

int main() {
    int n;
    cin>> n;

    string input[n];

    for(int i = 0; i< n; i++) {
        cin>> input[i];
    }

    int temp = max(input[0].size(), input[1].size());
    int stat = 0;

    for(int i= 0; i< temp; i++) {
        if(input[0][i] < input[1][i]) {
            stat = 1;
            break;
        } else if(input[0][i] > input[1][i]) {
            stat = -1;
            break;
        }
    }

    if(stat == 1) {
        for(int i= 1; i< n-1; i++) {
            temp = max(input[i].size(), input[i+1].size());
            for(int j= 0; j< temp; j++) {
                if(input[i][j] < input[i+1][j]) {
                    break;
                } else if(input[i][j] > input[i+1][j]) {
                    cout<< "NEITHER";
                    return 0;
                }
            }
        }
    } else {
        for(int i= 1; i< n-1; i++) {
            temp = max(input[i].size(), input[i+1].size());
            for(int j= 0; j< temp; j++) {
                if(input[i][j] > input[i+1][j]) {
                    break;
                } else if(input[i][j] < input[i+1][j]) {
                    cout<< "NEITHER";
                    return 0;
                }
            }
        }
    }

    if(stat == 1) {
        cout<< "INCREASING";
    } else {
        cout<< "DECREASING";
    }
}