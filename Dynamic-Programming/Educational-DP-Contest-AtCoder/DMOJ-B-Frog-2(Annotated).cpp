// Educational DP Contest AtCoder B - Frog 2 (DMOJ) - https://dmoj.ca/problem/dpb
// ANNOTATED CODE - https://dmoj.ca/src/6410536
#include <bits/stdc++.h> // DP State - dp[i] represents the minimum cost to reach stone i
using namespace std; // same dp transition and base case as frog 1; however, we can reach the next K stones => just a for loop, no hardcoding (generalization)
const int MM = 1e5+3; // bounds of N go up to 10^5
int N, K, a[MM], dp[MM]; // this time, we have K, which tells us that from stone i, instead of being able to access only the next 2 stones,
                         // we can access the next K stones (bounds of K go up to 100, so it still fits into our time complexity: O(NK)
int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){ // note how we keep it 1-indexed because the problem starts from stone 1
        cin >> a[i]; // space complexity of O(N)
    }
    memset(dp, 0x3f, sizeof(dp)); // set all dp cells to a really big number ("infinity")
    dp[1] = 0; // ALWAYS, when doing dynamic programming problems, start small and think about the base case, the smallest combinations
               // right now, the base case is that we are starting at stone 1, meaning we haven't moved anywhere, so the minimum cost is just 0
    for(int i = 1; i <= N; i++){  // looping left to right, from stone 1 to stone N
        for(int k = 1; k <= K; k++){ // NOW, we can access the next K neighbouring stones
            dp[i+k] = min(dp[i+k], abs(a[i+k]-a[i]) + dp[i]); // generalized dp transition from frog 1, replace 1 or 2 with k
                                                              // either you take it or you don't take it, is it better to go to stone i+k from stone i,
                                                              // or let the optimal solution for stone i+k be the same
        }
    }
    cout << dp[N] << endl; // we want the optimal solution (or minimum total cost) to get to stone N, that is the answer the question wants, not stone N-1, or 5, just N
}
