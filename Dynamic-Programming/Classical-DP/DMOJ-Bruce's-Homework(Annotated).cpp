// Bruce's Homework (DMOJ Olympiads School Only): https://dmoj.ca/problem/olyhwk
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4;
int N, T, M, t[105], extra; double dp[MM], v[105];
int main(){
    cin >> N >> M >> T;
    fill(dp, dp+MM, 0); fill(v, v+N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> t[i];
    }
    for(int i = 1, a; i <= M; i++){
        cin >> a; if(a==0) extra++;
        for(int j = 1, p; j <= a; j++){
            cin >> p; v[p] += (1.0/a); // satisfaction of problem i increases by bi/ai
        }
    }
    // converted to knapsack problem
    for(int i = 1; i <= N; i++){ // problem/item i
        for(int w = T; w >= t[i]; w--){ // total_time/knapsack_size w
            dp[w] = fmax(dp[w], v[i]+dp[w-t[i]]);
        }
    }
    printf("%.2f", dp[T] + extra);
}
