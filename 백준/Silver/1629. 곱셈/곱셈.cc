#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned long long a, b, c;
    cin>> a>> b>> c;

    unsigned long long dp[35];
    dp[0] = a % c;

    for(int i = 1; i < 35; i++) {
        dp[i] = dp[i-1]*dp[i-1]%c;
    }

    unsigned long long output = 1;

    for(int i = 34; i >= 0; i--) {
        if(b >= (unsigned long long)pow(2, i)) {
            b -= (unsigned long long)pow(2, i);
            output = output * dp[i] % c;
        }
        if(b == 0) {
            cout<< output;
            return 0;
        }
    }

    //cout<< output;
}