#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

bool prime[3000000] = {1, 1, 0, 0, 1, 0, 1};
int dp[3000000] = {0, 0, 1, 1};
vector<int> loop;

int main() {
    int n;
    cin>> n;

    int check = sqrt(2999999) + 1;

    int cal;
    for(int i = 2; i <= check; i++) {
        if(prime[i] == false) {
            loop.push_back(i);
            cal = i*2;
            while(cal <= 2999999) {
                prime[cal] = true;
                cal += i;
            }
        }
    }

    int Max = 0;
    
    for(int i = 4; i <= n; i++) {
        if(prime[i]) continue;

        for(int j : loop) {
            if(j >= i) break;
            if(!prime[j] && !prime[i-j-1]) {
                Max = max(Max, dp[j] + dp[i-j-1]);
            }
        }

        // for(int j = 2; j <= i/2; j++) {
        //     if(!prime[j] && !prime[i-j-1]) 
        //         Max = max(Max, dp[j] + dp[i-j-1]);
        // }
        
        dp[i] = Max + 1;
        //cout<< i<< ' '<< Max+1 << '\n';
        Max = 0;
    }

    cout<< dp[n];
}