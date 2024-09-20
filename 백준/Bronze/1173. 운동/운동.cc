#include <iostream>
using namespace std;

int main() {
    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;

    int output = 0;
    int now = m;

    while(N) {
        if(now + T <= M) {
            N--;
            now += T;
        } else {
            if(now - R >= m) {
                now -= R;
            } else {
                if(now == m) {
                    cout<< -1;
                    return 0;
                } else {
                    now = m;
                }
            }
        }
        output++;
    }

    cout<< output;
}