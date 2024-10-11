#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    unsigned long long cnt;
    cin>> n>> cnt;

    int input[5][5];
    int cal[5][5][37] = {0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>> input[i][j];
            cal[i][j][0] = input[i][j];
        }
    }

    for(int p = 1; p <= 36; p++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    cal[i][j][p] = (cal[i][j][p] + input[i][k] * input[k][j]) % 1000;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                input[i][j] = cal[i][j][p];
            }
        }
    }
    
    int output[5][5] = {0};
    int temp[5][5] = {0};
    for(int i = 0; i < n; i++) {
        output[i][i] = 1;
    }

    for(int p = 36; p >= 0; p--) {
        if(cnt >= (unsigned long long)pow(2, p)) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    for(int k = 0; k < n; k++) {
                        temp[i][j] = (temp[i][j] + output[i][k] * cal[k][j][p]) % 1000;
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    output[i][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
            cnt -= (unsigned long long)pow(2, p);
        }
        
        if(cnt == 0) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cout<< output[i][j]<< ' ';
                } cout<< '\n';
            }
            return 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<< output[i][j]<< ' ';
        } cout<< '\n';
    }
}