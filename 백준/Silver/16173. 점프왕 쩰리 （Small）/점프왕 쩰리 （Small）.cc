#include <iostream>
#include <queue>
using namespace std;

struct Greed {
    int x;
    int y;
};

int main() {
    int n;
    cin>> n;

    int greed[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>> greed[i][j];
        }
    }

    queue<Greed> q;
    q.push({0,0});

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if(greed[x][y] == -1) {
            cout<< "HaruHaru";
            return 0;
        } else if(greed[x][y] == 0) {
            cout<< "Hing";
            return 0;
        }

        if(x + greed[x][y] < n) {
            q.push({x + greed[x][y], y});
        }
        if(y + greed[x][y] < n) {
            q.push({x, y + greed[x][y]});
        }
    }

    cout<< "Hing";
}