#include <iostream>
using namespace std;

int main() {
    int n, pack;
    cin>> n>> pack;

    int memoiz[pack + 1] = {};

    int weight;
    int value;
    for(int i= 0; i< n; i++) {
        cin>> weight>> value;
        
        // switch(i) {
        //     case 0:
        //         for(int j = weight; j <= pack; j++) {
        //             memoiz[0][j] = value;
        //         }
        //         break;
        //     default:
        //         for(int j = 1; j <= pack; j++) {
        //             if(j < weight) {
        //                 memoiz[i][j] = memoiz[i-1][j];
        //             } else {
        //                 if(memoiz[i-1][j] < memoiz[i-1][j-weight] + value) {
        //                     memoiz[i][j] = memoiz[i-1][j-weight] + value;
        //                 } else {
        //                     memoiz[i][j] = memoiz[i-1][j];
        //                 }
        //             }
        //         }
        // }

        // 하나 입력 받을 때 마다 배열의 index가 무게, 값이 가치를 의미하는 dp 테이블 업데이트
        // 역순으로 확인해보자!

        switch(i) {
            case 0:
                for(int i= weight; i<= pack; i++) {
                    memoiz[i] = value;
                }
                break;
            default:
                for(int i = pack; i >= weight; i--) {
                    if(i >= weight) {
                        if(memoiz[i] < memoiz[i-weight] + value) {
                            memoiz[i] = memoiz[i-weight] + value;
                        }
                    }
                }
        }

        // for(int i= weight; i<= pack; i++) {
        //     if(memoiz[i] < memoiz[i-weight] + value) {
        //         memoiz[i] = memoiz[i-weight] + value;
        //         for(int j= i+1; j<= pack; j++) {
        //             if(memoiz[i] <= memoiz[j]) {
        //                 continue;
        //             } else {
        //                 memoiz[j] = memoiz[i];
        //             }
        //         }
        //         i = pack;
        //     } else {
        //         continue;
        //     }
        // }

        // for(int k= 0; k<= pack; k++) {
        //     cout<< memoiz[k]<< ' ';
        // } cout<< '\n';
    }

    cout<< memoiz[pack];
}