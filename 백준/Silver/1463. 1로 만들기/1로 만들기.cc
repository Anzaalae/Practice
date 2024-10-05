#include <iostream>
using namespace std;

int dp[1000001] = {0, 0, 1, 1, 2, 3};

int main() {
    int n;
    cin>> n;

    for(int i = 6; i <= 1000000; i++) {
        if(i%3 == 0 && i%2 == 0) {
            if(dp[i/3] <= dp[i/2] && dp[i/3] <= dp[i-2]) {
                dp[i] = dp[i/3]+1;
            } else if(dp[i/2] <= dp[i/3] && dp[i/2] <= dp[i-1]) {
                dp[i] = dp[i/2]+1;
            } else {
                dp[i] = dp[i-1]+1;
            }
        } else if(i%3 == 0) {
            dp[i] = min(dp[i/3] + 1, dp[i-1] + 1);
        } else if(i%2 == 0) {
            dp[i] = min(dp[i/2] + 1, dp[i-1] + 1);
        } else {
            dp[i] = dp[i-1] + 1;
        }
    }

    cout<< dp[n];
}