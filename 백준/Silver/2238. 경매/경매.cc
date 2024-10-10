#include <iostream>
#include <queue>
using namespace std;

struct call {
    int index;
    int value;
};

int main() {
    int u, n;
    cin>> u>> n;

    int check[100001]={};
    string callMan[100001];

    int input;

    queue<call> pq;

    for(int i = 0; i < n; i++) {
        cin>> callMan[i]>> input;

        if(input <= u) {
            check[input]++;
            pq.push({i, input});
        }
    }

    int minimum = INT32_MAX;
    int minValue;
    for(int i = 1; i <= u; i++) {
        if(check[i] < minimum && check[i] > 0) {
            minimum = check[i];
            minValue = i;
        }
    }

    for(int i = 0; i < n; i++) {
        if(pq.front().value == minValue) {
            cout<< callMan[pq.front().index]<< ' '<< minValue;
            break;
        }
        pq.pop();
    }
}