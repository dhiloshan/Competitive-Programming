// Educational DP Contest AtCoder M - Candies (DMOJ): https://dmoj.ca/problem/dpm
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+3;
const int MOD = 1e9+7;
int N, K, dp[101][MM], a[101], psa[101][MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> a[i];
    dp[0][0] = 1;
    for(int i = 0; i <= K; i++) psa[0][i] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= K; j++){
            dp[i][j] = psa[i-1][j];
            if(j-a[i]-1 >= 0) dp[i][j] = (psa[i-1][j] - psa[i-1][j-a[i]-1] + MOD) % MOD;
            psa[i][j] = dp[i][j];
            if(j > 0) psa[i][j] = (psa[i][j-1] + dp[i][j]) % MOD;
        }
    }
    cout << dp[N][K] << endl;
}
