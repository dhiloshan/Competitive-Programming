// CSES Problem Set Message Route (CSES): https://cses.fi/problemset/task/1667
// ANNOTATED CODE -  https://cses.fi/paste/0d72773f14c733aeade9cf/
// https://usaco.guide/gold/unweighted-shortest-paths?lang=cpp
// regular minimum distance bfs question; however, we need to find the path of this shortest path
// just use backtracking by storing the parent node of node i during bfs
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, M, p[MM], dis[MM]; bool vis[MM]; vector<int> adj[MM];
int main(){
    cin >> N >> M;
    for(int i = 1, u, v; i <= M; i++){
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    queue<int> q;
    vis[1] = true; dis[1] = 0; q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){ // for each neighbour of node i
            if(!vis[nxt]){
                q.push(nxt);
                p[nxt] = cur; vis[nxt] = true; dis[nxt] = dis[cur] + 1;
                // when BFS reaches the node, it is guaranteed it has traversed the minimum number of edges
                // because we exhaustively checked all neighbours for each node (and each edge is the same value so every edge is the same cost)
                // p[i] defines the parent of node i, such that the minimum distance is guaranteed from source node (1) to node i (current node)
            }
        }
    }
    if(!vis[N]){ // if you can't visit node N
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << dis[N]+1 << endl; // # of nodes in the path = min distance (in terms of edges) + 1
        int cur = N;
        vector<int> order; order.push_back(N); // start from dest node, backtrack til you reach starting node
        while(cur != 1){
            cur = p[cur];
            order.push_back(cur);
        } // order matters, so don't sort it, go from right to left
        for(int i = order.size()-1; i >= 0; i--){
            cout << order[i] << " \n"[i==0];
        }
    }
}
