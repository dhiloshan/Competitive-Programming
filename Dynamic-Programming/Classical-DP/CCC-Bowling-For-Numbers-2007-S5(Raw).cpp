// CCC '07 S5 - Bowling for Numbers (DMOJ): https://dmoj.ca/problem/ccc07s5
// RAW CODE - https://dmoj.ca/src/6899371
#include <bits/stdc++.h>
using namespace std;
const int MM = 3e4+5;
int n, k, w, t, dp[502][MM], psa[MM];
int main(){
    for(cin >> t; t > 0; t--){
        cin >> n >> k >> w;
        for(int i = 1, x; i <= n; i++){
            cin >> x; psa[i] = psa[i-1] + x;
        }
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                if(j < w) dp[i][j] = psa[j];
                else dp[i][j] = max(dp[i][j-1], psa[j] - psa[j-w] + dp[i-1][j-w]);
            }
        }
        cout << dp[k][n] << endl;
    }
}
