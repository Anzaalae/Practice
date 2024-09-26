#include <iostream>
using namespace std;

int main() {
    int N, W, H, L;
    int output;
    cin>> N>> W>> H>> L;

    output = (W / L) * (H / L);
    cout<< min(output, N); 
}