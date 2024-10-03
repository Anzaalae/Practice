#include <iostream>
#include <queue>
using namespace std;

int tomato[1001][1001];

struct Greed {
    int x;
    int y;
    int day;
};

int main() {
    int n, m;
    cin>> n>> m;

    queue<Greed> q;
    int lastday = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin>> tomato[i][j];

            if(tomato[i][j] == 1)
                q.push({i, j, 0});
        }
    }

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        lastday = q.front().day;
        q.pop();

        if(x > 0 && tomato[x-1][y] == 0) {
            tomato[x-1][y] = 1;
            q.push({x-1, y, lastday+1});
        }
        if(y > 0 && tomato[x][y-1] == 0) {
            tomato[x][y-1] = 1;
            q.push({x, y-1, lastday+1});
        }
        if(x < m-1 && tomato[x+1][y] == 0) {
            tomato[x+1][y] = 1;
            q.push({x+1, y, lastday+1});
        }
        if(y < n-1 && tomato[x][y+1] == 0) {
            tomato[x][y+1] = 1;
            q.push({x, y+1, lastday+1});
        }
    }

    bool check = true;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(tomato[i][j] == 0) {
                check = false;
                break;
            }
        }
    }

    if(check) {
        cout<< lastday;
    } else {
        cout<< -1;
    }
}