#include <iostream>
using namespace std;

int main() {
    int day, n;
    cin>> day>> n;

    int dp[day + 1] = {};

    int need, value;
    for(int i= 0; i < n; i++) {
        cin>> need>> value;

        for(int i = day; i >= need; i--) {
            if(dp[i] < dp[i - need] + value) {
                dp[i] = dp[i - need] + value;
            }
        }
    }

    cout<< dp[day];
}