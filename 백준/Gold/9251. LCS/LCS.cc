#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin>> a>> b;

    int size = a.size();
    int bsize = b.size();

    int dp[size+1][bsize+1] = {};

    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= bsize; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<< dp[size][bsize];
}