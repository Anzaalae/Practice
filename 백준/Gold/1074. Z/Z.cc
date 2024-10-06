#include <iostream>
#include <cmath>
using namespace std;

int output = 0;
int x;
int y;

int visit(int dan, int visit_x, int visit_y) {
    if(dan != 2) {
        dan /= 2;
        if(visit_x <= x && x < visit_x + dan && visit_y <= y && y < visit_y + dan) {
            visit(dan, visit_x, visit_y);
        } else if(visit_x + dan <= x && x < visit_x + 2*dan && visit_y <= y && y < visit_y + dan) {
            output += dan*dan;
            visit(dan, visit_x + dan, visit_y);
        } else if(visit_x <= x && x < visit_x + dan && visit_y + dan <= y && y < visit_y + 2*dan) {
            output += 2*dan*dan;
            visit(dan, visit_x, visit_y + dan);
        } else if(visit_x + dan <= x && x < visit_x + 2*dan && visit_y + dan <= y && y < visit_y + 2*dan) {
            output += 3*dan*dan;
            visit(dan, visit_x + dan, visit_y + dan);
        }
    } else {
        if(visit_x == x && visit_y == y) {
            cout<< output;
            return 0;
        } else if(visit_x + 1 == x && visit_y == y) {
            cout<< output + 1;
            return 0;
        }else if(visit_x == x && visit_y + 1 == y) {
            cout<< output + 2;
            return 0;
        }
        if(visit_x + 1 == x && visit_y + 1 == y) {
            cout<< output + 3;
            return 0;
        }
    }
    return 0;
}

int main() {
    int n, r, c;
    cin>> n>> r>> c;

    int dan = pow(2, n);
    int visit_x = 0;
    int visit_y = 0;
    x = c;
    y = r;
    visit(dan, visit_x, visit_y);
    return 0;
}