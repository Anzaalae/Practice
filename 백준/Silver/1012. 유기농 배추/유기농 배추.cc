#include <iostream>
#include <queue>
using namespace std;

struct Greed {
    int x;
    int y;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>> n;

    int x, y, baechu, baechu_x, baechu_y;
    int output = 0;
    int queueX, queueY;
    while(n--) {
        cin>> y>> x>> baechu;
        int input[50][50]={};
        bool visit[50][50]={};
        while(baechu--) {
            cin>> baechu_x>> baechu_y;
            input[baechu_y][baechu_x] = 1;
        }

        queue<Greed> q;
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                if(input[i][j] == 1 && visit[i][j] == false) {
                    output++;
                    q.push({i, j});
                    visit[i][j] = true;
                    while(!q.empty()) {
                        queueX = q.front().x;
                        queueY = q.front().y;
                        q.pop();

                        if(queueX+1 < x && visit[queueX+1][queueY] == false) {
                            if(input[queueX+1][queueY] == 1) {
                                visit[queueX+1][queueY] = true;
                                q.push({queueX+1, queueY});
                            }
                        }
                        if(queueX-1 >= 0 && visit[queueX-1][queueY] == false) {
                            if(input[queueX-1][queueY] == 1) {
                                visit[queueX-1][queueY] = true;
                                q.push({queueX-1, queueY});
                            }
                        }
                        if(queueY+1 < y && visit[queueX][queueY+1] == false) {
                            if(input[queueX][queueY+1] == 1) {
                                visit[queueX][queueY+1] = true;
                                q.push({queueX, queueY+1});
                            }
                        }
                        if(queueY-1 >= 0 && visit[queueX][queueY-1] == false) {
                            if(input[queueX][queueY-1] == 1) {
                                visit[queueX][queueY-1] = true;
                                q.push({queueX, queueY-1});
                            }
                        }
                    }
                }
            }
        }

        cout<< output<< '\n';
        output = 0;
    }
}