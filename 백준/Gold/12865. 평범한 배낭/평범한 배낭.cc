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
    }

    cout<< memoiz[pack];
}