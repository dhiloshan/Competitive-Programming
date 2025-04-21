// CSES Problem Set Trailing Zeros (CSES): https://cses.fi/problemset/task/1618
// ANNOTATED CODE - https://cses.fi/paste/88e5c94511f01436c1b2d8/
#include <bits/stdc++.h>
using namespace std;
int N, two, five;
int main(){
    cin >> N;
    int i = 2;
    while(N >= i){ // you don't even need this, just calculate the # of fives
        two += floor(N / i); i *= 2;
    }
    i = 5;
    while(N >= i){ // # of factors of 5 in factorial = floor(N/5) + floor(N/5^2) + floor(N/5^3) + ....
        five += floor(N / i); i *= 5;
    }
    cout << min(two, five) << endl; // if there are more 2's than 5's, then you can't make more pairs of 2's of 5's (to multiply to 10 => 1 trailing zero) than the # of 5's
}
