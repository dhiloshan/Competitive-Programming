// Coding Spree (DMOJ) - https://dmoj.ca/problem/spree
// ANNOTATED CODE - https://dmoj.ca/src/6415718
#include <bits/stdc++.h>
using namespace std; // template question from 0-1 knapsack problem (refer to knapsack educational dp problem d annotated code number 3 for more details)
const int MM = 1e4+3; // 1 <= T <= 1000 (we are creating a dp array with T cells)
int N, T, dp[MM]; // let dp[i] represent the maximum amount of points achievable with i hours (starting with just one problem, looping to N problems)
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T;
    for(int i = 1, v, h; i <= N; i++){ // starting with just 1 problem, ending with all N problems (solving the smallest possible problem and building it up)
        cin >> v >> h; // (v, h) - value of problem i, number of hours needed to solve problem i
        for(int j = T; j >= h; j--){ // HOWEVER, here we loop right (starting with maximum hours) to left until we reach h, because when j = h, dp[j-h] = dp[h-h] = dp[0]
            dp[j] = max(v + dp[j-h], dp[j]); // either you take it (value of problem i + maximum points with j-h hours) or you don't (just where you are, because that is the optimal solution for j hours and i-1 problems
        }
    }
    cout << dp[T] << endl; // at the end, we want the solution that uses all T hours, like the problem is asking for (look at dp state line 6)
}
