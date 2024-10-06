#include <iostream>
#include <queue>
using namespace std;

struct Greed {
    int x;
    int y;
    int move;
};

int main() {
    int x, y;
    cin>> x>> y;

    string input[x];
    bool visit[x][y]={};
    for(int i = 0; i < x; i++) {
        cin>> input[i];
    }

    queue<Greed> q;
    q.push({0, 0, 1});
    visit[0][0] = true;

    int tempX, tempY, moveCount;

    while(!q.empty()) {
        tempX = q.front().x;
        tempY = q.front().y;
        moveCount = q.front().move;
        q.pop();

        if(tempX == x-1 && tempY == y-1) {
            cout<< moveCount;
            return 0;
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for(int i = 0; i < 4; i++) {
            if(tempX + dx[i] >= 0 && tempX + dx[i] < x && tempY + dy[i] >= 0 && tempY + dy[i] < y &&  
                input[tempX + dx[i]][tempY + dy[i]] == '1' && visit[tempX + dx[i]][tempY + dy[i]] == false) {
                q.push({tempX + dx[i], tempY + dy[i], moveCount+1});
                visit[tempX + dx[i]][tempY +dy[i]] = true;
            }
        }

    }
}