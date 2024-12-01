// VM7WC '16 #3 Silver Can Shahir even get there?! (DMOJ): https://dmoj.ca/problem/vmss7wc16c3p2
// RAW CODE - https://dmoj.ca/src/6779091
#include <bits/stdc++.h>
using namespace std;
const int MM = 2003;
int N, M, A, B; bool vis[MM]; vector<int> adj[MM];
void dfs(int root){
    for(int nxt : adj[root]){
        if(!vis[nxt]){
            vis[nxt] = true;
            dfs(nxt);
        }
    }
}
int main(){
    cin >> N >> M >> A >> B;
    for(int i = 1, u, v; i <= M; i++){
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    vis[A] = true; dfs(A);
    cout << (vis[B]? "GO SHAHIR!" : "NO SHAHIR!") << endl;
}
