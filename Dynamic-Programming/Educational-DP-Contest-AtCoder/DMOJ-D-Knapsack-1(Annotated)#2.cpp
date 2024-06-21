// SOLUTION 2: 2 Row Flip DP ARRAY (2 by W)
// Educational DP Contest AtCoder D - Knapsack 1 (DMOJ): https://dmoj.ca/problem/dpd
// ANNOTATED CODE - https://dmoj.ca/src/6397539
#include <bits/stdc++.h> // Space Complexity of Approach 1: O(N * W), Time Complexity of Approach 1: O(N * W)
using namespace std; // This method will optimize the space complexity to O(W), but the time complexity remains the same
const int MM = 1e5+2; // bounds of W (knapsack size) will go to 10^5
int N, W; long long dp[2][MM]; // 2 by W dp array because we need two rows: one for current (index 1), one for previous (index 0)
int main(){
    cin >> N >> W;
    for(int i = 1, v, w; i <= N; i++){
        cin >> w >> v; // item i has weight w with value v
        for(int j = 1; j <= W; j++){  // perform the same dp we have done in approach 1 (going left to right, there are W columns)
                                      // note that column 0 is just 0 from our base case, so we set j to 1 (but for the row the number of items is always changing)
                                      // we could set it to dp[1][j] as the previous and dp[2][j] as the current and let row 0 be the original base case, but that's unnecessary
            dp[1][j] = (w > j) ? dp[0][j] : max(dp[0][j], v + dp[0][j-w]);  // condition to check if we can put the weight into the knapsack (we don't want to access negative indexes with j - w)
        }
        for(int k = 1; k <= W; k++){ // "flip" array means we set the current to previous, loop through each of the columns / values we set
            dp[0][k] = dp[1][k]; // the current value is now considered the previous value, so that the next time we loop we can perform this operation again
        }
    }
    cout << dp[1][W]; // note that you could also print out dp[0][W] because that is also storing the current optimal solution for N items with knapsack weight W (line 18)
}
