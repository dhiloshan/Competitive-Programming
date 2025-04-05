// Educational DP Contest AtCoder D Knapsack 1 (DMOJ): https://dmoj.ca/problem/dpd
// RAW CODE - https://dmoj.ca/src/6397530 
// SOLUTION 2: 2 Row Flip DP ARRAY (2 by W)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, W; long long dp[2][MM];
int main(){
    cin >> N >> W;
    for(int i = 1, v, w; i <= N; i++){
        cin >> w >> v;
        for(int j = 1; j <= W; j++){
            dp[1][j] = (w > j) ? dp[0][j] : max(dp[0][j], v + dp[0][j-w]);
        }
        for(int k = 1; k <= W; k++){
            dp[0][k] = dp[1][k];
        }
    }
    cout << dp[1][W];
}
