// A Noisy Class (DMOJ): https://dmoj.ca/problem/anoisyclass
// RAW CODE - https://dmoj.ca/src/6915361
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+3;
int N, M, in[MM]; bool vis[MM]; vector<int> adj[MM];
int main(){
    cin >> N >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        adj[u].emplace_back(v);
        in[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(!in[i]) q.push(i);
    }
    if(q.empty()) {cout << 'N' << endl; return 0;}
    vis[q.front()] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(!vis[nxt] && !--in[nxt]){
                vis[nxt] = true; q.push(nxt);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        if(in[i]) {cout << 'N' << endl; return 0;}
    }
    cout << 'Y' << endl;
}
