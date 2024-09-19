#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin>> n>> k;

    int cnt [21] = {};
    string input;
    long long output = 0;

    queue<int> check;

    for(int i= 0; i< k; i++) {
        cin>> input;
        output += cnt[input.size()];

        check.push(input.size());
        cnt[input.size()]++;
    }

    int temp = n - k;

    for(int i= 0; i< temp; i++) {
        cin>> input;
        output += cnt[input.size()];

        check.push(input.size());
        cnt[input.size()]++;
        cnt[check.front()]--;
        check.pop();
    }

    cout<< output;
}