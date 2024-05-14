// SOLUTION 3: 1D DP ARRAY (2 by W)
// RAW CODE - https://dmoj.ca/problem/dpd
// Educational DP Contest AtCoder D Knapsack 1 (DMOJ) - https://dmoj.ca/src/6400061
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, W; long long dp[MM];
int main(){
    cin >> N >> W;
    for(int i = 1, v, w; i <= N; i++){
        cin >> w >> v;
        for(int j = W; j >= w; j--){
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[W] << endl;
}
