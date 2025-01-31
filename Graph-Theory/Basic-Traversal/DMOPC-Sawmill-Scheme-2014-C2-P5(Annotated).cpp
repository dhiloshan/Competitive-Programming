// DMOPC '14 Contest 2 P5 - Sawmill Scheme (DMOJ): https://dmoj.ca/problem/dmopc14c2p5
// ANNOTATED CODE - https://dmoj.ca/src/6933268
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3; // problem requires use of dp on a graph (graph theory + dp)
int N, M; double dp[MM]; vector<int> adj[MM]; // make sure you use double for the dp array (for decimals up to 9 decimal places)
// dp state: dp[i] - probability of reaching node i
// dp transition: for each of node u's neighbours (dp[nxt]), += dp[u] / adj[u].size(), this means add the probability of node u divided by the number of outward edges
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v); // uni-directional edges that point "south"
    }
    dp[1] = 1.0; // crux of the graph is 1 (where we do a bfs-like approach to ensure we visit all nodes according to their topological order)
    for(int i = 1; i <= N; i++){
        if(adj[i].empty()) cout << fixed << setprecision(9) << dp[i] << endl; // if this node is a leaf node (make sure to round to 9 decimal places)
        else for(int nxt : adj[i]) dp[nxt] += dp[i] / (double)adj[i].size(); // travels all neighbours and applies dp transition
    }
}
