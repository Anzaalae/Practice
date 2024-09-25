#include <iostream>
#include <set>
using namespace std;

struct cmp {
    bool operator() (const long long& left, const long long& right) const {
        return left > right;
    }
};

int main() {
    int n;
    cin>> n;

    char input;
    long long value, inputcnt, iter;

    while(n--) {
        cin>> inputcnt;

        multiset<long long> smallSet;
        multiset<long long, cmp> maxSet;

        while(inputcnt--) {
            cin>> input >> value;

            if(input == 'I') {
                smallSet.insert(value);
                maxSet.insert(value);
            } else {
                if(value == 1) {
                    if(maxSet.size() != 0) {
                        iter = *maxSet.begin();
                        maxSet.erase(maxSet.begin());
                        smallSet.erase(smallSet.find(iter));
                    }
                } else {
                    if(smallSet.size() != 0) {
                        iter = *smallSet.begin();
                        smallSet.erase(smallSet.begin());
                        maxSet.erase(maxSet.find(iter));
                    }
                }
            }
        }
        if(smallSet.size() == 0) {
            cout<< "EMPTY"<< '\n';
        } else {
            cout<< *maxSet.begin()<< ' '<< *smallSet.begin()<< '\n';
        }
    }
}