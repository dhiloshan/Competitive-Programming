// Educational DP Contest AtCoder A - Frog 1 (DMOJ): https://dmoj.ca/problem/dpa
// RAW CODE - https://dmoj.ca/src/6410511
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, dp[MM], a[MM];
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for(int i = 1; i <= N; i++){
        dp[i+1] = min(dp[i+1], abs(a[i+1] - a[i]) + dp[i]);
        dp[i+2] = min(dp[i+2], abs(a[i+2] - a[i]) + dp[i]);
    }
    cout << dp[N] << endl;
}
