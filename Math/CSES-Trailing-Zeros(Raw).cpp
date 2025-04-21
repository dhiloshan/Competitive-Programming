// CSES Problem Set Trailing Zeros (CSES): https://cses.fi/problemset/task/1618
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
int N, two, five;
int main(){
    cin >> N;
    int i = 2;
    while(N >= i){
        two += floor(N / i); i *= 2;
    }
    i = 5;
    while(N >= i){
        five += floor(N / i); i *= 5;
    }
    cout << min(two, five) << endl;
}
