#include <iostream>
using namespace std;

int main() {
    int n;
    cin>> n;

    int stair[n + 1] = {};
    int stairCount[n + 1];
    int memoiz[n + 1] = {};
    for(int i= 1; i<= n; i++) {
        cin>> stair[i];
    }

    // 다음 계단에서 이전 계단에서 한 칸 오르거나
    // 전 전 계단에서 두칸을 한번에 오르거나
    // 값 비교

    // 그런데 세 개의 계단을 연속으로 밟으면 안되므로 각 최대값에서 연속계단 카운트를 해줌
    // 이 카운트에서 2면 무조건 전전 계단에서 오르기

    for(int i= 1; i<= n; i++) {
        switch(i) {
            case 1:
                memoiz[1] = stair[1];
                stairCount[1] = 1;
                break;
            case 2:
                memoiz[2] = stair[1] + stair[2];
                stairCount[2] = 2;
                break;
            default:
                if(stairCount[i-1] == 2) {
                    if(memoiz[i-3] + stair[i-1] > memoiz[i-2]) {
                        memoiz[i] = memoiz[i-3] + stair[i-1] + stair[i];
                        stairCount[i] = 2;
                    } else {
                        memoiz[i] = memoiz[i-2] + stair[i];
                        stairCount[i] = 1;
                    }
                } else {
                    if(memoiz[i-1] > memoiz[i-2]) {
                        memoiz[i] = memoiz[i-1] + stair[i];
                        stairCount[i] = 2;
                    } else {
                        memoiz[i] = memoiz[i-2] + stair[i];
                        stairCount[i] = 1;
                    }
                }
        }
    }

    cout<< memoiz[n];
    
}