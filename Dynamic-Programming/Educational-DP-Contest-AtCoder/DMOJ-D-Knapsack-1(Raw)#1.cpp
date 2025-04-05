// Educational DP Contest AtCoder D Knapsack 1 (DMOJ): https://dmoj.ca/problem/dpd
// RAW CODE - https://dmoj.ca/src/6397130
// SOLUTION 1: STANDARD TEMPLATE: 2D DP ARRAY (N by W)
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

/*
 New Problem: Now that you know the highest value you can achieve with these N items and knapsack with size W,
 can you tell me what items you have chose?
 Simple, it's just backtracking
 You always had two choices, you pick item i (dp[i-1][j-w]), or you don't pick item i (dp[i-1][j])
 We can tell if we did pick item i if cell dp[i][j] - v == dp[i-1][j-w]
 We literally just did simple algebra, if you look at the else statement, dp[i][j] = dp[i-1][j-w] + v, now we subtract v from both sides

 Snippet of Code: (assume v[i] tells us the value of item i and w[i] tells us the weight of item i)
 vector<int> ans;
 int i = N, j = W;
 while(i > 0 && j > 0){
    if((dp[i][j] - v[i] == dp[i-1][j-w[i]]) && (j >= w[i])){
        ans.push_back(i); j -= w[i]; i--;
    }
    else i--;
 }
 sort(begin(ans), end(ans));
 cout << "The items I have chosen for your knapsack to get a value of " << dp[N][W] << " are:" << endl;
 for(int k = 0; k <= ans.size()-1; k++){
    cout << k+1 << ") Item " << ans[k] << " with weight " << w[ans[k]] << " and value " << v[ans[k]] << "." << endl;
 }

 Sample Input: (note that the first line takes input for N, W respectively, and then the next N+1 lines take input for item i by WEIGHT FIRST, then value)
 6 6
 2 1
 3 3
 1 5
 5 2
 3 6
 5 10

 Sample Output:
 The items I have chosen for your knapsack to get a value of 15 are:
 1) Item 3 with weight 1 and value 5.
 2) Item 6 with weight 5 and value 10.
*/
