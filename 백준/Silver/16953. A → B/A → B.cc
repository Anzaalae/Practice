#include <iostream>
#include <queue>
using namespace std;

struct cal {
    long long now;
    int time;
};

int main() {
    int a, b;
    cin>> a>> b;

    queue<cal> q;
    q.push({a, 1});

    long long now;
    int time;
    int output = -1;

    while(!q.empty()) {
        now = q.front().now;
        time = q.front().time;
        q.pop();

        if(now*10 + 1 == b || now * 2 == b) {
            if(output == -1) {
                output = time + 1;
            } else {
                output = min(output, time+1);
            }
        }

        if(now*10 + 1 < b) {
            q.push({now*10 + 1, time+1});
        }

        if(now * 2 < b) {
            q.push({now*2, time+1});
        }
    }

    cout<< output;
    return 0;
}