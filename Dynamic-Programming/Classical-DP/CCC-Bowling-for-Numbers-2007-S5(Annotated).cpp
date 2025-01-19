// CCC '07 S5 - Bowling for Numbers (DMOJ): https://dmoj.ca/problem/ccc07s5
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 3e4+5;
int n, k, w, t, dp[502][MM], psa[MM]; // psa effectively gives us the sum from L to R, which you should recognize because the player knocks a range of pins (of size W), you need that sum
int main(){
    for(cin >> t; t > 0; t--){ // for each test case
        cin >> n >> k >> w;
        for(int i = 1, x; i <= n; i++){ // just for prefix sum array (static)
            cin >> x; psa[i] = psa[i-1] + x;
        }
        // 2D DP, this is very similar to knapsack problem
        for(int i = 1; i <= k; i++){ // for each bowling ball
            for(int j = 1; j <= n; j++){
                if(j < w) dp[i][j] = psa[j]; // we are using the ith ball to knock down the pins no matter what
                else dp[i][j] = max(dp[i][j-1], psa[j] - psa[j-w] + dp[i-1][j-w]);
                // we do j-1 because we skip the jth pin; the other choice is to hit the range and find the subproblem with i-1 balls with j-w pins
            }
        }
        cout << dp[k][n] << endl;
    }
}
