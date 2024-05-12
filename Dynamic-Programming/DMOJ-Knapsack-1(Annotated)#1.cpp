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

/*
 New Problem: Now that you know the highest value you can achieve with these N items and knapsack with size W,
 can you tell me what items you have chose?
 Simple, it's just backtracking
 You always had two choices, you pick item i (dp[i-1][j-w]), or you don't pick item i (dp[i-1][j])
 We can tell if we did pick item i if cell dp[i][j] - v == dp[i-1][j-w]
 We literally just did simple algebra, if you look at the else statement, dp[i][j] = dp[i-1][j-w] + v, now we subtract v from both sides

 // Snippet of Code (assume v[i] tells us the value of item i and w[i] tells us the weight of item i)
 vector<int> ans; // stores all the items by their index (when they came into input)
 int i = N, j = W; // start this algorithm from the bottom right corner, perform a "bottom-up" approach to backtrack
 while(i > 0 && j > 0){ // bounds of our algorithm (dp[1][1] is the smallest by index we can go and need to, dp[0][x] is just 0, same for dp[x][0] => this was defined in our BASE CASE)
    if((dp[i][j] - v[i] == dp[i-1][j-w[i]]) && (j >= w[i])){ // first, check if we have enough space to take item i with knapsack size j
                                                            // if we do, use the equation we created before to see if we even did take item i
        ans.push_back(i);  // if we did take item i, put it into the vector to say we have chose item i to fill up our knapsack with size W using N items
        j -= w[i]; i--; // then, you need to FIRST subtract our current knapsack size with the weight of item i
                        // AFTER, you can subtract i by 1
                        // NOTE: if you did it the other way, you would be subtracting knapsack with size j by the weight of item i-1, not item i
    }
    else i--; // otherwise, go up one row, which is what happens when we DON'T or CAN'T take item i (dp[i][j] = dp[i-1][j], same dp cell but it's i-1)
 }
 sort(begin(ans), end(ans)); // since we are performing a bottom up approach, we are starting with item N and are ending at item 1, so we need to sort it in ascending order
 cout << "The items I have chosen for your knapsack to get a value of " << dp[N][W] << " are:" << endl; // remember, we are checking what items we did for dp[N][W], you could just change 
                                                                                                        // the i and j variables to whatever dimensions you want to solve for what items we chose for dp[i][j]
 for(int k = 0; k <= ans.size()-1; k++){ // starting from index 0 (vector ans is indexed 0) and end at the last index (we minus one because again its 0-indexed, not 1-indexed)                                                        
    cout << k+1 << ") Item " << ans[k] << " with weight " << w[ans[k]] << " and value " << v[ans[k]] << "." << endl; // ans[k] represents index i, we add 1 to k to print it out as 1-indexed, you never say to someone "item 0 is"
 }
 */
