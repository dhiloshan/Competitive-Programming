// CCC '23 S2 - Symmetric Mountains (DMOJ):
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 5003;
int N, a[MM], ans[MM], dp[MM][MM];
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    ans[1] = 0;
    for(int len = 2; len <= N; len++){
        int mi = 1e9;
        for(int i = 1; i <= N-len+1; i++){
            int j = i+len-1;
            dp[i][j] = dp[i+1][j-1] + abs(a[j]-a[i]);
            mi = min(mi, dp[i][j]);
        }
        ans[len] = mi;
    }
    for(int i = 1; i <= N; i++){
        cout << ans[i] << " \n"[i==N];
    }
}


/*
 dp look up table
 dp[len m][start at pos idx]
 interval dp

 base case: dp[1][idx] = 0
 dp[m][idx] = dp[m-1][idx+1] + abs(a[idx]-a[idx+m-1])

 asymmetric value starting from idx of length m

 */
