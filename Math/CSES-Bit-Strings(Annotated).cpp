// CSES Problem Set Bit Strings (CSES): https://cses.fi/problemset/task/1617
// ANNOTATED CODE - https://cses.fi/paste/1db20b307ce6a25fc1b2a0/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int N;
int main(){
    cin >> N;
    long long ans = 1; // ensure it's long long
    for(int i = 1; i <= N; i++){
        ans = (ans * 2) % MOD; // multiplication MOD
    }
    cout << ans << endl; // you can use binary exponentiation to optimize to log time 
}
