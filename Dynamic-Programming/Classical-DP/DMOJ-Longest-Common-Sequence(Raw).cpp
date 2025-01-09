// Longest Common Subsequence (DMOJ): https://dmoj.ca/problem/lcs
// RAW CODE - https://dmoj.ca/src/6872223
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3;
int N, M, a[MM], b[MM], dp[MM][MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int i = 1; i <= M; i++) cin >> b[i];
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[N][M] << endl;
}
