// DMOPC '14 Contest 2 P5 - Sawmill Scheme (DMOJ): https://dmoj.ca/problem/dmopc14c2p5
// RAW CODE - https://dmoj.ca/src/6933218
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, M; double dp[MM]; vector<int> adj[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dp[1] = 1.0;
    for(int i = 1; i <= N; i++){
        if(adj[i].empty()) cout << fixed << setprecision(9) << dp[i] << endl;
        else for(int nxt : adj[i]) dp[nxt] += dp[i] / (double)adj[i].size();
    }
}
