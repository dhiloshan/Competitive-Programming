// CSES Problem Set Message Route (CSES): https://cses.fi/problemset/task/1667
// RAW CODE - https://cses.fi/paste/12790f3cc8f650adade947/
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
        for(int nxt : adj[cur]){
            if(!vis[nxt]){
                q.push(nxt);
                p[nxt] = cur; vis[nxt] = true; dis[nxt] = dis[cur] + 1;
            }
        }
    }
    if(!vis[N]){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << dis[N]+1 << endl;
        int cur = N;
        vector<int> order; order.push_back(N);
        while(cur != 1){
            cur = p[cur];
            order.push_back(cur);
        }
        for(int i = order.size()-1; i >= 0; i--){
            cout << order[i] << " \n"[i==0];
        }
    }
}
