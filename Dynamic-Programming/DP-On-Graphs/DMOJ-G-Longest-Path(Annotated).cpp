// Educational DP Contest AtCoder G - Longest Path (DMOJ): https://dmoj.ca/problem/dpg
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, M, in[MM], dp[MM]; vector<int> adj[MM], rev[MM]; vector<int> order;
int main(){
    cin >> N >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v; adj[u].push_back(v); rev[v].push_back(u);
        in[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(in[i] == 0){
            q.push(i);
            dp[i] = 0; // base case for starting vertices
        }
    }
    // topo sort to generate the right order
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(--in[nxt] == 0){
                q.push(nxt); order.push_back(nxt);
            }
        }
    }
    int mx = 0;
    for(int node : order) {
        int curMx = 0;
        for(int opt : rev[node]){
            curMx = max(curMx, dp[opt] + 1);
        }
        dp[node] = curMx;
        mx = max(mx, curMx);
    }
    cout << mx << endl;
}
