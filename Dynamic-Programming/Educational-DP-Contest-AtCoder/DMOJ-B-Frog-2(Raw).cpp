// Educational DP Contest AtCoder B - Frog 2 (DMOJ): https://dmoj.ca/problem/dpb
// RAW CODE - https://dmoj.ca/src/6410520
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, K, a[MM], dp[MM];
int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for(int i = 1; i <= N; i++){
        for(int k = 1; k <= K; k++){
            dp[i+k] = min(dp[i+k], abs(a[i+k]-a[i]) + dp[i]);
        }
    }
    cout << dp[N] << endl;
}
