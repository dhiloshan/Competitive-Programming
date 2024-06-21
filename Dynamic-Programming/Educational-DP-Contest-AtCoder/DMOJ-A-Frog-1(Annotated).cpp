// Educational DP Contest AtCoder A - Frog 1 (DMOJ): https://dmoj.ca/problem/dpa
// ANNOTATED CODE - https://dmoj.ca/src/6410510
#include <bits/stdc++.h> // DP State - let dp[i] represent the minimum cost to reach stone i
using namespace std; // DP Transition - base case: dp[1] = 0 (when you are starting at stone 1, there is no cost originally)
                     // otherwise, this is similar to the 0-1 knapsack problem => you take it, or you don't
                     // if you don't take it, you are staying at the same stone, which is just dp[i+1] (let's assume we are calculating the optimal solution for stone i+1 from stone i)
                     // if we do, then like the question says, we need the cost to get to stone i+1 => | h[j] - h[i] | => abs(a[i+1]-a[i])
                     // we want to get to stone i+1, right? in this case, we are calculating how to get there from stone i
                     // now that we know the cost from getting from stone i to i+1, whats the minimum cost to get to stone i?
                     // oh wait! we have calculated the minimum cost to reach stone i (remember the dp state?), it's just dp[i]
                     // so, the cost to get from stone i to i+1 is just minimum cost to get to stone i + cost from stone i to stone i+1 => dp[i] + abs(a[i+1] - a[i])
                     // let's find the minimum of these two choices, taking it, or not taking it: min(dp[i+1], dp[i] + abs(a[i+1] - a[i]))
                     // note: this may look a bit complicated without knowing anything, and later on it will get much more messy, but!
                     // when you break problems to their essence, there isn't too much to it
const int MM = 1e5+3; // bounds of N (1 <= N <= 10^5)
int N, dp[MM], a[MM]; // let the dp array represent the minimum costs and array a represent the height of stone i
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp)); // memset function allows us to fill an array with special values, 0x3f (a really big number)
                                            // we need to set each dp value to "infinity" because they are looking for the minimum
                                            // it's an easier way of doing this: 1) set all dp values to -1,
                                            // 2) base case dp[1] = 0 3) every time we explore a new dp cell and the value of dp[i+1] or dp[i+2]
                                            // is -1, it means we never reached it, so it automatically is abs(a[i+1] - a[i]) + dp[i], so that it has an actual value
                                            // same concept for setting it to infinity, but faster way, we do this for algorithms like Dijkstra too
    dp[1] = 0; // BASE CASE: we are starting at stone 1, so the cost to start is just 0
    for(int i = 1; i <= N; i++){ // looping left to right, starting from stone 1 and ending at stone N
        // from stone i, we are only allowed to go to the next two stones, i+1 and i+2
        // so for every stone i, let's calculate the optimal solution for stones i+1 and i+2, since we can reach it and ask ourselves
        // "can we take it or not take it" => "is it better to stay at stone i or go to stone i+1"
        dp[i+1] = min(dp[i+1], abs(a[i+1] - a[i]) + dp[i]); // either we stay at stone i+1, or go to stone i+1 by adding the cost to get from stone i to stone i+1, and the minimum cost to get to stone i
        dp[i+2] = min(dp[i+2], abs(a[i+2] - a[i]) + dp[i]); // same logic applies to stone i+2
    }
    cout << dp[N] << endl; // we want to find the optimal solution / minimum total cost for stone N
}
