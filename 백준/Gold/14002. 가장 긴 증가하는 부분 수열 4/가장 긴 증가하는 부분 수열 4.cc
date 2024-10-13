#include <iostream>
#include <vector>
using namespace std;

struct Check {
    int now;
    int cnt = 1;
    vector<int> save;
};

int main() {
    int n;
    cin>> n;

    Check check[n];
    int outputIndex = 0;

    for(int i = 0; i < n; i++) {
        cin>> check[i].now;

        int index = -1;

        for(int j = 0; j < i; j++) {
            if(check[j].now < check[i].now) {
                if(check[i].cnt < check[j].cnt + 1) {
                    check[i].cnt = check[j].cnt + 1;
                    index = j;
                }
            }
        }

        if(index != -1) {
            check[i].save = check[index].save;
        }
        check[i].save.push_back(check[i].now);

        if(check[outputIndex].cnt < check[i].cnt) {
            outputIndex = i;
        }
    }

    cout<< check[outputIndex].cnt<< '\n';
    for(int i = 0; i < check[outputIndex].save.size(); i++) {
        cout<< check[outputIndex].save.at(i)<< ' ';
    }
}