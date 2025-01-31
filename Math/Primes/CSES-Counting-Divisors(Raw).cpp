// CSES Problem Set Counting Divisors (CSES): https://cses.fi/problemset/task/1713/
// RAW CODE - https://cses.fi/paste/a9fcbd89a725ffa9ae1544/
#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    cin >> N;
    for(int i = 0, x; i < N; i++){
        cin >> x;
        int cnt = 0;
        for(int i = 1; i * i <= x; i++){
            if(i * i == x) cnt++;
            else if(x % i == 0) cnt+=2;
        }
        cout << cnt << endl;
    }
}
