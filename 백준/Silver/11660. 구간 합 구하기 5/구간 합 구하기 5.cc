#include <iostream>
using namespace std;

int input[1025][1025];
int check[1025][1025];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>> n>> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<= n; j++) {
            cin>> input[i][j];

            //check[i][j] = check[i][j-1] + input[i][j];
            //check[i][j] += check[i-1][j];
            check[i][j] = check[i-1][j] + check[i][j-1] - check[i-1][j-1] + input[i][j];
        }
    }

    int x1, y1, x2, y2;
    while(m--) {
        cin>> x1>> y1>> x2>> y2;
        cout<< check[x2][y2] - check[x2][y1-1] - check[x1-1][y2] + check[x1-1][y1-1]<< '\n';
    }
}