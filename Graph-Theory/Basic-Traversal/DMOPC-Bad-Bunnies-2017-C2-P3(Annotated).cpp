// DMOPC '17 Contest 2 P3 - Bad Bunnies (DMOJ): https://dmoj.ca/problem/dmopc17c2p3
// ANNOTATED CODE - https://dmoj.ca/src/7043888
#include <bits/stdc++.h> // idea: multi-source bfs from each of the nodes containing bunnies
using namespace std; // then find the valid path from x to y using dfs, and run a final loop that goes through each node and finds the smallest distance to a bunny
const int MM = 2e5+3;
typedef long long ll;
int N, R, st, ed; ll dis[MM]; bool vis[MM], vis2[MM]; vector<int> adj[MM]; queue<int> q;
bool dfs(int u, int v){ // finds the valid path from x to y
    vis2[u] = true; // mark the current node visited
    if(u == v){ // if the node is the destination node
        return true; // return true for successful
    }
    for(int nxt : adj[u]){ // all neighbours of node u
        if(!vis2[nxt]){
            if(dfs(nxt, v)){ // run dfs on the neighbour
                return true;
            }
        }
    }
    vis2[u] = false; // at this point, we have visited node u's subtree, and it does not lead to node y: mark this node false it has nothing to do with the path from x to y
    return false; // this subtree does not have node y
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> R;
    for(int i = 0, a, b; i < N-1; i++){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a); // bi-directional
    }
    for(int i = 0, x; i < R; i++){
        cin >> x;
        dis[x] = 0; vis[x] = true; q.push(x); // multi-source bfs
    }
    cin >> st >> ed;
    while(!q.empty()){ // standard bfs
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(!vis[nxt]){
                vis[nxt] = true; dis[nxt] = dis[cur] + 1; q.push(nxt);
            }
        }
    }
    // traverse x to y
    dfs(st, ed);
    ll ans = MM; // closest node in this case means min distance, so set initially to the max
    for(int i = 1; i <= N; i++){ // check each node
        if(vis2[i]){ // if the node is on the path from x to y
            ans = min(ans, dis[i]); // mark the min
        }
    }
    cout << ans << endl;
}
