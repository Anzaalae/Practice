#include <iostream>
using namespace std;

struct Check {
    int now;
    int cnt = 1;
};

int main() {
    int n;
    cin>> n;

    Check check[n];
    int output = 1;

    for(int i = 0; i < n; i++) {
        cin>> check[i].now;

        for(int j = 0; j < i; j++) {
            if(check[j].now < check[i].now) {
                check[i].cnt = max(check[i].cnt, check[j].cnt + 1);
            }
        }

        output = max(output, check[i].cnt);
    }

    cout<< output;
}