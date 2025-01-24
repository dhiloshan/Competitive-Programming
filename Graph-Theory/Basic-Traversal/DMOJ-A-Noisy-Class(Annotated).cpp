// A Noisy Class (DMOJ): https://dmoj.ca/problem/anoisyclass
// ANNOTATED CODE - https://dmoj.ca/src/6915376
#include <bits/stdc++.h> // using topological sort on a directed graph to see if we can quiet down the entire class
using namespace std;
const int MM = 1e4+3;
int N, M, in[MM]; bool vis[MM]; vector<int> adj[MM]; // in is the number of in-edges for node i
int main(){
    cin >> N >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        adj[u].emplace_back(v);
        in[v]++; // remember to add one
    }
    queue<int> q;
    for(int i = 1; i <= N; i++){ // loop that pushes all starting nodes that have no in edges
        if(!in[i]) q.push(i);
    }
    if(q.empty()) {cout << 'N' << endl; return 0;} // if there are no starting nodes its impossible
    // standard bfs
    vis[q.front()] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(!vis[nxt] && !--in[nxt]){ // we minus the in edge by one before checking if it is 0
                vis[nxt] = true; q.push(nxt);
            }
        }
    }
    for(int i = 1; i <= N; i++){ // all in edges must be 0 to show there is a topological ordering to make all students quiet down
        if(in[i]) {cout << 'N' << endl; return 0;} // if it is greater than 0 then print no
    }
    cout << 'Y' << endl;
}
