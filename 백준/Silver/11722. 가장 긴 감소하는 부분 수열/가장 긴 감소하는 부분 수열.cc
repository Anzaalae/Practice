#include <iostream>
using namespace std;

struct Dp {
    int now;
    int cnt = 1;
};

int main() {
    int n;
    cin>> n;

    Dp dp[n];
    int output = 1;

    for(int i = 0; i < n; i++) {
        cin>> dp[i].now;

        for(int j = 0; j < i; j++) {
            if(dp[j].now > dp[i].now) {
                dp[i].cnt = max(dp[i].cnt, dp[j].cnt + 1);
            }
        }

        output = max(output, dp[i].cnt);
    }

    cout<< output;
}