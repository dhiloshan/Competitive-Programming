// Dogs and Cats (DMOJ Olympiads School Only): https://dmoj.ca/problem/oly23practice17
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
const int MOD = 1e9+7;
int N, K, dp[MM];
int main(){
    cin >> N >> K;
    for(int i = 0; i <= K; i++) dp[i] = i+1;
    for(int i = K+1; i <= N; i++){
        dp[i] = (dp[i-1]+dp[i-K-1])%MOD;
    }
    cout << dp[N] << endl;
}
