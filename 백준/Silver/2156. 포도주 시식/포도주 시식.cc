#include <iostream>
using namespace std;

int main() {
    int n;
    cin>> n;

    int output = -1;

    int input[n];
    for(int i = 0; i < n; i++) {
        cin>> input[i];
    }

    int dp[n] = {};

    for(int i = 0; i < n; i++) {
        switch(i) {
            case 0:
                dp[0] = input[0];
                break;
            case 1:
                dp[1] = input[0] + input[1];
                break;
            case 2:
                dp[2] = max(input[0] + input[2], input[1] + input[2]);
                break;
            case 3:
                dp[3] = max(dp[i-3] + input[i-1] + input[i], dp[i-2] + input[i]);
                break;
            default:
                dp[i] = max(dp[i-2] + input[i], dp[i-3] + input[i-1] + input[i]);
                dp[i] = max(dp[i], dp[i-4] + input[i-1] + input[i]);
        }
        //output = max(dp[i], output);
        if(i != 0) {
            dp[i] = max(dp[i], dp[i-1]);
        }
    }

    cout<< dp[n-1];
}