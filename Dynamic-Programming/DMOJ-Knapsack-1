// SOLUTION 1: STANDARD TEMPLATE: 2D DP ARRAY (N by W)
// RAW CODE - https://dmoj.ca/problem/dpd
// Educational DP Contest AtCoder D Knapsack 1 (DMOJ) - https://dmoj.ca/src/6396236
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, W; long long dp[101][MM];
int main(){
    cin >> N >> W;
    for(int i = 1, w, v; i <= N; i++){
        cin >> w >> v;
        for(int j = 1; j <= W; j++){
            if(j < w){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], v + dp[i-1][j-w]);
            }
        }
    }
    cout << dp[N][W] << endl;
}
