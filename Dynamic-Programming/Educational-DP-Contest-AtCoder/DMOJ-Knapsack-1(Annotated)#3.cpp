// SOLUTION 3: 1D DP ARRAY (size W)
// Educational DP Contest AtCoder D Knapsack 1 (DMOJ) - https://dmoj.ca/problem/dpd
// ANNOTATED CODE - https://dmoj.ca/src/6397539
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, W; long long dp[MM]; // we ignore the second dimension for N, where each row is an item
// we instead save space by using a 1D table and modifiying our solution
// Space complexity: O(W)       BUT Time Complexity: O(NW) (remains the same, just iterating and storing slightly differently

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> W;
    for(int i = 1, v, w; i <= N; i++){ // we are STILL going to find the optimal solution for each item, just not storing these optimal solutions for MULTIPLE items, just one at a time
        cin >> w >> v;
        for(int j = W; j >= w; j--) { // we start at the very right, stop at w
                                      // at index w, that is the last point where you can take item i
                                      // if you went to index w-1, it's impossible to take item i with weight w, because you would have -1 space left
                                      // note: just because you end at w for this solution doesn't mean for the previous solutions you could start at w and end at W
                                      // you can't start at w because you are going LEFT to right, you need indexes 0 to w-1, even if it is just dp[i-1][j]
            dp[j] = max(dp[j], v + dp[j-w]); // same exact idea without the second dimension
            // remember, dp[j] represents the optimal solution for items 1 to i-1, it may not look like it but i-1 was the last item before item i which you left off at
            // so either stay with knapsack size j with item i-1 optimal solution, because other than item i you have items 1 to i-1
            // or, you take item i and have j-w space left (and i-1 items left)
            // since you're taking item i, you have to add the value v of item i
        }
    }
    cout << dp[W] << endl; // our array has W cells, the optimal solution is looking for knapsack size W with N items
                           // although you aren't "accessing" index N, that is the last index you left off at in the big for loop
}

// KEY POINT: idea of iterating RIGHT to left instead of LEFT to right to optimize space
// Key observation that you only need the previous row
// Use these insights to guide you in your future dynamic programming challenges, as the ideas are quite similar when you break it down to its smaller components
