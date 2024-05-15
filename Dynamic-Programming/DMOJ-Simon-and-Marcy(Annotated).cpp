// ANNOTATED CODE - https://dmoj.ca/problem/valday15p2
// Valentine's Day '15 P2 - Simon and Marcy (DMOJ) - https://dmoj.ca/src/6400749
#include <bits/stdc++.h>
using namespace std; // classical knapsack problem in disguise
const int MM = 1e3+3; // C and M maximum (1 <= C, M <= 10^3)
typedef long long ll;
int C, M; ll dp[MM]; // using solution 3, 1D array, to save space
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> C >> M;
    for(int i = 1, c, p; i <= C; i++){ // loop for C items (starting from 1, ending at item C)
        cin >> p >> c; // let ci represent cost of item i and pi represent value of item i
        for(int j = M; j >= c; j--){ // starting from the right (knapsack size M) and ending at the weight of item i (c)
            dp[j] = max(dp[j], p + dp[j-c]); // exact same choices from knapsack 1 problem but different variable names
        }
    }
    cout << dp[M] << endl; // optimal solution for this problem is M, representing knapsack size, or the number of minutes Marceline has to save the princesses
}
