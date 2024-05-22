// Maximum Sum (DMOJ) - https://dmoj.ca/problem/dp1p1
// ANNOTATED CODE - https://dmoj.ca/src/6410640
#include <bits/stdc++.h> // DP State - let dp[i] represent the maximum sum that can be obtained from a valid subset from numbers 1 to i
using namespace std; // valid subset refers to a subset with no adjacent neighbours, as mentioned in the question
const int MM = 1e5+3; // This very much resembles the classical knapsack problem: take number i or don't take it
                      // if you don't take it, then it's just the previous optimal solution for numbers 1 to i-1, so dp[i-1]
                      // note that dp[i-1] will be the biggest value you could obtain at that point in time if you didn't take number i
                      // this is because our dp transition will always consider the maximum possible value at each step, and as we include
                      // more elements, the sum can only stay the same or increase, but never decrease
                      // anyways, if we do take number i, then we can't also take number i-1 because i-1 and i are adjacent
                      // so the next best solution is i-2 => dp[i-2], and we are also adding the value from the current cell i, so a[i] => dp[i-2] + a[i]
                      // considering the maximum out of these two choices (we want the maximal, not minimum sum) => dp[i] = max(dp[i-1], dp[i-2] + a[i])
int N, a[MM], dp[MM];
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i]; // Space complexity is just O(N), time complexity is also O(N)
    }
    dp[1] = a[1]; // BASE CASE #1 (we need to consider two base cases because we are accessing i-2, we need two cells prior): with a list of just one number, the maximum sum is just the number itself
    dp[2] = max(a[1], a[2]); // BASE CASE #2: we can pick either or, but not both numbers in the list because they are adjacent, so find the maximum of the two to find the better solution
    for(int i = 3; i <= N; i++){ // starting from number 3 to number N (we already calculated optimal solution for 1 and 2, it won't change)
        dp[i] = max(dp[i-1], dp[i-2] + a[i]); // dp transition: don't take number i (go to previous optimal solution), or take number i (go to cell i-2 bc you can't access i-1 and add the current value a[i])
    }
    cout << dp[N]; // we want the maximal value for the numbers from 1 to N
}
