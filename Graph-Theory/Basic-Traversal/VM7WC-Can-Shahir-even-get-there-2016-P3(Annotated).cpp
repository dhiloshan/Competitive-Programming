// VM7WC '16 #3 Silver Can Shahir even get there?! (DMOJ): https://dmoj.ca/problem/vmss7wc16c3p2
// ANNOTATED CODE - https://dmoj.ca/src/6779104
// WAY 1 (this version): use dfs; WAY 2: use BFS (i made some submissions on DMOJ with that solution but I'm not going to formally put it into Github)
#include <bits/stdc++.h>
using namespace std;
const int MM = 2003;
int N, M, A, B; bool vis[MM]; vector<int> adj[MM];
void dfs(int root){ // go through every possible path that it can go, starting from the root node
    for(int nxt : adj[root]){ // for each of its neighbours
        if(!vis[nxt]){ // we need this if we want the function to eventually stop and not go on forever meaninglessly
            vis[nxt] = true;
            dfs(nxt); // instead of pushing it into a queue for BFS, just call the recursive function
        }
    }
}
int main(){
    cin >> N >> M >> A >> B;
    for(int i = 1, u, v; i <= M; i++){
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u); // two-way roads
    }
    vis[A] = true; dfs(A); // first mark root node (Shahir's house) visited [because you are starting there]; then call dfs on that "root" node
    cout << (vis[B]? "GO SHAHIR!" : "NO SHAHIR!") << endl; // condensed if logic
}
