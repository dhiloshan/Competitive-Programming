// SOLUTION 1: STANDARD TEMPLATE: 2D DP ARRAY (N by W)
// ANNOTATED CODE - https://dmoj.ca/problem/dpd
// Knapsack 1 (Educational DP Contest AtCoder D -> DMOJ) - https://dmoj.ca/submission/6396307
#include <bits/stdc++.h> // NOTE: when the comments refer to "optimal solution", it is referring to the "maximum possible sum of the values of items that Taro takes home"
using namespace std; // in other words, it is referring to for the situation where you have i items with knapsack size w, the BEST solution possible is at cell dp[i][w] (known as the dp state)
const int MM = 1e5+2; // maximum knapsack size (1 <= W <= 10^5)
int N, W; long long dp[101][MM]; // but (1 <= N <= 100) in this N by W dp array
int main(){
    cin >> N >> W;
    for(int i = 1, w, v; i <= N; i++){ // going downwards on our "lookup table" (note that index i refers to item i)
        cin >> w >> v; // w - weight of item i, v - value of item i
        for(int j = 1; j <= W; j++){ // going right on our "lookup table" (note that index j refers to the size of our current knapsack)
            // Note: dynamic programming is all about solving multiple problems, and using those subproblems to solve bigger problems
            // we solve the optimal solution for item 1 first with knapsack 1 to W, and then for item 2 we use the optimal solutions from item 1 by looking at our lookup table to solve the bigger problem for item 2
            // this repeats until we solved all problems such that we know the optimal solution for any items 1, 2, ..., k with capacity 1, 2, ..., w
            if(j < w){ // CHOICE 1: we CAN'T take it
                       // if we don't have enough space to put item i with weight w in our knapsack, we can't take it
                       // remember, the more to the right we are on our lookup table, the bigger our "current" knapsack is, meaning j will be bigger
                       // assuming the weight of item i is less than W, there will be some point that we will check condition 2 (line 20 - 22)
                dp[i][j] = dp[i-1][j]; // if we don't take item i, the items left are 1, 2, ..., i-1, so i-1 items
                                       // Plus, we are still considering the same knapsack, which is still size j
                                       // Note that we are solving multiple problems with knapsack sizes of every size from 1 to W
            }
            else{ // CHOICE 2: we CAN take it
                // we are considering two choices, we TAKE it, or we DON'T TAKE it
                // CHOICE 2.1: we DON'T TAKE it
                    // the optimal solution if we don't take is something we already considered before on line 17, it's just dp[i-1][j]
                    // this is because we are still considering the same knapsack size j, and the items other than i, which so far is just 1, 2, ..., i-1
                // CHOICE 2.2: we DO TAKE it
                    // if we do take it, obviously we're adding the value of item i, but to what?
                    // first off, what's the remaining capacity of the current knapsack now that we chose item i
                    // our current knapsack is weight j, and the item we want to take into our knapsack has a weight of w
                    // so the remaining knapsack size is j - w
                        // note! you might be thinking, "why can't we pick knapsack size j - w - 1, or j - w - 2
                        // we could (assuming it isn't negative), but it's not the OPTIMAL solution
                        // guaranteed we can assume the knapsack with size j - w has the same or better solution than the knapsack with size j - w - 1
                        // there's more space and when you are going through the lookup table on the right, it's always increasing in value, there's no "inversion" (refer to inversion counting with fenwick's tree)
                    // back on topic, what items are we considering?
                    // same thing, now that we have picked item i, the items we have taken so far that is UPDATED in our lookup table is items 1 to i-1
                        // if we don't do row i-1 and do row i, it's the same row we are on right now, and there is a chance that cell ALREADY taken in item i
                    // so, we are adding value v, to the optimal solution with a knapsack size of j - w that considered items 1 to i-1 => v + dp[i - 1][j - w]
                // summing up everything, we want to see if it is better/more optimal/more valuable to choose item or not to choose item i:
                dp[i][j] = max(dp[i-1][j], v + dp[i-1][j-w]); // we are using the max function to compare the two choices to see which one is "higher in value"
            }
        }
    }
    // we have now solved N * W problems, where if we wanted the optimal solution for items 1 to i with knapsack capacity w, it would be dp[i][w]
    cout << dp[N][W] << endl; // the problem is asking to consider all N items with a knapsack size W
}
