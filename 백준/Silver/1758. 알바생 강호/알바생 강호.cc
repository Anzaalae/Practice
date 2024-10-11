#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a>b;
    }
};

int main() {
    int n;
    cin>> n;

    long long output= 0;
    int input;

    priority_queue<int> pq;

    for(int i = 0; i < n; i++) {
        cin>> input;
        pq.push(input);
    }
    for(int i = 0; i < n; i++) {
        input = pq.top();
        pq.pop();

        if(input - i > 0) {
            output += input - i;
        } 
    }

    cout<< output;
}