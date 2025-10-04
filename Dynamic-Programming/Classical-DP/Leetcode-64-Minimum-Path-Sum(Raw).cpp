// 64. Minimum Path Sum (Leetcode): https://leetcode.com/problems/minimum-path-sum/
// RAW CODE
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[300][300];
        dp[1][1] = grid[0][0];
        int r = grid.size(), c = grid[0].size();
        for(int i = 2; i <= c; i++) dp[1][i] = dp[1][i-1] + grid[0][i-1];
        for(int i = 2; i <= r; i++) dp[i][1] = dp[i-1][1] + grid[i-1][0];
        for(int i = 2; i <= r; i++){
            for(int j = 2; j <= c; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[r][c];
    }
};
