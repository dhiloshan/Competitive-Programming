// DMOPC '17 Contest 2 P3 - Bad Bunnies (DMOJ): https://dmoj.ca/problem/dmopc17c2p3
// RAW CODE - https://dmoj.ca/src/7043864
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
typedef long long ll;
int N, R, st, ed; ll dis[MM]; bool vis[MM], vis2[MM]; vector<int> adj[MM]; queue<int> q;
bool dfs(int u, int v){
    vis2[u] = true;
    if(u == v){
        return true;
    }
    for(int nxt : adj[u]){
        if(!vis2[nxt]){
            if(dfs(nxt, v)){
                return true;
            }
        }
    }
    vis2[u] = false;
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> R;
    for(int i = 0, a, b; i < N-1; i++){
        cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i = 0, x; i < R; i++){
        cin >> x;
        dis[x] = 0; vis[x] = true; q.push(x);
    }
    cin >> st >> ed;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(!vis[nxt]){
                vis[nxt] = true; dis[nxt] = dis[cur] + 1; q.push(nxt);
            }
        }
    }
    // traverse x to y
    dfs(st, ed);
    ll ans = MM;
    for(int i = 1; i <= N; i++){
        if(vis2[i]){
            ans = min(ans, dis[i]);
        }
    }
    cout << ans << endl;
}
