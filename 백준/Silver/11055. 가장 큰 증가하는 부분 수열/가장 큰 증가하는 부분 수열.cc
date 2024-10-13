#include <iostream>
using namespace std;

struct Check {
    int now;
    int hap;
};

int main() {
    int n;
    cin>> n;

    Check check[n];
    int output = 0;

    for(int i = 0; i < n; i++) {
        cin>> check[i].now;
        check[i].hap = check[i].now;

        for(int j = 0; j < i; j++) {
            if(check[j].now < check[i].now) {
                check[i].hap = max(check[j].hap + check[i].now, check[i].hap);
            }
        }

        output = max(output, check[i].hap);
    }

    cout<< output;
}