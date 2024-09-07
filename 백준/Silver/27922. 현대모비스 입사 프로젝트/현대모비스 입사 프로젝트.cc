#include <iostream>
using namespace std;

struct Gain {
    int a;
    int b;
    int c;
};

Gain gain[100001];

int test1[3][100001];
int temp[100001];

void merge(int test, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;
    int total = start;

    while(left <= mid && right <= end) {
        if(test1[test][left]> test1[test][right]) {
            temp[total++] = test1[test][left++];
        } else {
            temp[total++] = test1[test][right++];
        }
    }

    if(left > mid) {
        for(int i = right; i <= end; i++) {
            temp[total++] = test1[test][i];
        }
    } else {
        for(int i = left; i <= mid; i++) {
            temp[total++] = test1[test][i];
        }
    }

    for(int i= start; i<= end; i++) {
        test1[test][i] = temp[i];
    }
}

void sort(int test, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        sort(test, start, mid);
        sort(test, mid + 1, end);
        merge(test, start, mid, end);
    }
}

int main() {
    int n, m;
    cin>> n>> m;

    for(int i= 0; i< n; i++) {
        cin>> gain[i].a>> gain[i].b>> gain[i].c;
        test1[0][i] = gain[i].a + gain[i].b;
        test1[1][i] = gain[i].b + gain[i].c;
        test1[2][i] = gain[i].a + gain[i].c;
    }

    sort(0, 0, n-1);
    sort(1, 0, n-1);
    sort(2, 0, n-1);

    int output[3] = {};
    for(int i = 0; i< m; i++) {
        output[0] += test1[0][i];
        output[1] += test1[1][i];
        output[2] += test1[2][i];
    }

    if(output[0] >= output[1] && output[0] >= output[2]) {
        cout<< output[0];
    } else if(output[1] >= output[2] && output[1] >= output[0]) {
        cout<< output[1];
    } else {
        cout<< output[2];
    }
}