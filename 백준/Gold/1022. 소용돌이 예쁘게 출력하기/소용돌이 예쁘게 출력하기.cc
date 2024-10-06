#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//int output[1000][1000];

int main() {
    int x[2], y[2];
    cin>> x[0] >> y[0] >> x[1] >> y[1];

    int xmax = max(abs(x[0]), abs(x[1]));
    int ymax = max(abs(y[0]), abs(y[1]));
    int Max = max(xmax, ymax);

    int xnow = Max;
    int ynow = Max;

    int xbojung = Max + x[0];
    int ybojung = Max + y[0];

    int xrange = x[1] - x[0] + 1;
    int yrange = y[1] - y[0] + 1;

    int now = 1;
    int jari = 0;
    
    int output[xrange][yrange];
    if(x[0] + Max <= xnow && xnow <= x[1] + Max && y[0] + Max <= ynow && ynow <= y[1] + Max) {
        output[xnow-xbojung][ynow-ybojung] = now;
        ynow++;
    } else {
        ynow++;
        now;
    }

    //output[xnow][ynow++] = now;

    int stat = 2;
    int check = Max;
    while(check--) {
        for(int i = 0; i < stat; i++) {
            //cout<< xnow<< ' '<< ynow<< '\n';
            now++;
            if(x[0] + Max <= xnow && xnow <= x[1] + Max && y[0] + Max <= ynow && ynow <= y[1] + Max) {
                output[xnow-xbojung][ynow-ybojung] = now;
                jari = now;
            }

            //output[xnow][ynow] = now;

            xnow--;
        } xnow++; ynow--;
        for(int i = 0; i < stat; i++) {
            //cout<< xnow<< ' '<< ynow<< '\n';
            now++;
            if(x[0] + Max <= xnow && xnow <= x[1] + Max && y[0] + Max <= ynow && ynow <= y[1] + Max) {
                output[xnow-xbojung][ynow-ybojung] = now;
                jari = now;
            }

            //output[xnow][ynow] = now;

            ynow--;
        } ynow++; xnow++;
        for(int i = 0; i < stat; i++) {
            //cout<< xnow<< ' '<< ynow<< '\n';
            now++;
            if(x[0] + Max <= xnow && xnow <= x[1] + Max && y[0] + Max <= ynow && ynow <= y[1] + Max) {
                output[xnow-xbojung][ynow-ybojung] = now;
                jari = now;
            }

            //output[xnow][ynow] = now;

            xnow++;
        } xnow--; ynow++;
        for(int i = 0; i < stat; i++) {
            //cout<< xnow<< ' '<< ynow<< '\n';
            now++;
            if(x[0] + Max <= xnow && xnow <= x[1] + Max && y[0] + Max <= ynow && ynow <= y[1] + Max) {
                output[xnow-xbojung][ynow-ybojung] = now;
                jari = now;
            }

            //output[xnow][ynow] = now;

            ynow++;
        }
        stat+=2;
    }

    jari = to_string(jari).length();

    for(int i = 0; i < xrange; i++) {
        for(int j = 0; j < yrange; j++) {
            cout<< setw(jari)<< output[i][j]<< ' ';
        } cout<< '\n';
    }
    // for(int i = 0; i <= Max*2; i++) {
    //     for(int j = 0; j <= Max*2; j++) {
    //         cout<< output[i][j]<< ' ';
    //     } cout<< '\n';
    // }
}