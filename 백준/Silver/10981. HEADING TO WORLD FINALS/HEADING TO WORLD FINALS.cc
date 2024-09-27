#include <iostream>
#include <set>
using namespace std;

struct Score {
    int correct;
    int panalty;
    int index;
};

struct cmp {
    bool operator() (Score a, Score b) const {
        if(a.correct != b.correct)
            return a.correct > b.correct;
        else
            return a.panalty < b.panalty; 
    }
};

int main() {
    int n, k;
    cin>> n>> k;

    set<Score, cmp> st;
    set<string> univCmp;
    
    string univ[n];
    string name[n];
    Score score[n];
    for(int i = 0; i< n; i++) {
        cin>> univ[i]>> name[i];
        cin>> score[i].correct>> score[i].panalty;
        score[i].index = i;
        st.insert(score[i]);
    }

    int check;

    for(int i = 0; i< k; i++) {
        check = univCmp.size();
        univCmp.insert(univ[(*st.begin()).index]);

        while(check == univCmp.size()) {
            st.erase(*st.begin());
            check = univCmp.size();
            univCmp.insert(univ[(*st.begin()).index]);
        }
        cout<< name[(*st.begin()).index]<< '\n';
        st.erase(*st.begin());
    }
}