// CSES Problem Set Counting Divisors (CSES): https://cses.fi/problemset/task/1713/
// ANNOTATED CODE -  https://cses.fi/paste/c45a7db59c7afa35ae1571/
#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    cin >> N;
    for(int i = 0, x; i < N; i++){
        cin >> x;
        int cnt = 0;
        for(int i = 1; i * i <= x; i++){ // runs in square root x time
            if(i * i == x) cnt++; // ex. 2 * 2 == 4, so there is only one divisor
            else if(x % i == 0) cnt+=2; // 1 * 4 == 4, so there are two divisors
        }
        cout << cnt << endl; // answer queries right away, no need to store it
    } // O(Nsqrt(x))
}
