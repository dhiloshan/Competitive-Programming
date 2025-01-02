// CCC '07 S4 - Waterpark (DMOJ): https://dmoj.ca/problem/ccc07s4
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+3;
int N, dp[MM], a, b; vector<int> adj[MM];
int main(){
    cin >> N >> a >> b;
    while(a != 0 && b != 0){ 
        adj[b].push_back(a); 
        cin >> a >> b;
    }
    dp[1] = 1; 
    for(int i = 2; i <= N; i++){ 
        for(int nxt : adj[i]){ 
            dp[i] += dp[nxt]; 
        }
    }
    cout << dp[N] << endl; 
}
