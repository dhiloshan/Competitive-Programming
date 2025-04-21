// CSES Problem Set Bit Strings (CSES): https://cses.fi/problemset/task/1617
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int N;
int main(){
    cin >> N;
    long long ans = 1;
    for(int i = 1; i <= N; i++){
        ans = (2 * ans) % MOD;
    }
    cout << ans << endl;
}
