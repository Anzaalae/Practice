#include <iostream>
#include <queue>
using namespace std;

int tomato[100][100][100];

struct Greed {
    int x;
    int y;
    int z;
    int day;
};

int main() {
    int n, m, h;
    cin>> n>> m>> h;

    queue<Greed> q;
    int lastday = 0;

    for(int k = 0; k < h; k++) {
        for(int i = 0; i< m; i++) {
            for(int j = 0; j< n; j++) {
                cin>> tomato[k][i][j];
                if(tomato[k][i][j] == 1) {
                    q.push({i, j, k, 0});
                }
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        lastday = q.front().day;
        q.pop();

        if(x > 0 && tomato[z][x-1][y] == 0) {
            tomato[z][x-1][y] = 1;
            q.push({x-1, y, z, lastday+1});
        }
        if(y > 0 && tomato[z][x][y-1] == 0) {
            tomato[z][x][y-1] = 1;
            q.push({x, y-1, z, lastday+1});
        }
        if(z > 0 && tomato[z-1][x][y] == 0) {
            tomato[z-1][x][y] = 1;
            q.push({x, y, z-1, lastday+1});
        }
        if(x < m-1 && tomato[z][x+1][y] == 0) {
            tomato[z][x+1][y] = 1;
            q.push({x+1, y, z, lastday+1});
        }
        if(y < n-1 && tomato[z][x][y+1] == 0) {
            tomato[z][x][y+1] = 1;
            q.push({x, y+1, z, lastday+1});
        }
        if(z < h-1 && tomato[z+1][x][y] == 0) {
            tomato[z+1][x][y] = 1;
            q.push({x, y, z+1, lastday+1});
        }
    }

    bool check = true;
    for(int k = 0; k < h; k++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(tomato[k][i][j] == 0) {
                    check = false;
                    break;
                }
            }
        }   
    }

    if(check) {
        cout<< lastday;
    } else {
        cout<< -1;
    }
}