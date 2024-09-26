#include <iostream>
#include <set>
using namespace std;

struct cmp {
    bool operator() (int a, int b) const{
        return a > b;
    }
};

int main() {
    int n;
    cin>> n;

    int input;
    set<int, cmp> st;
    for(int i = 0; i < n; i++) {
        cin>> input;
        st.insert(input);
    }

    for(int i = 0; i < n; i++) {
        cout<< *st.begin()<< '\n';
        st.erase(*st.begin());
    }
}