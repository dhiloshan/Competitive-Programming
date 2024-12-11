// CCC '18 J5 - Choose your own path (DMOJ): https://dmoj.ca/problem/ccc18j5
// RAW CODE - https://dmoj.ca/src/6777025
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+3;
int N, dis[MM]; bool vis[MM]; vector<int> adj[MM], endpoints;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1, m; i <= N; i++){
        cin >> m;
        if(m == 0) endpoints.push_back(i);
        for(int j = 1, x; j <= m; j++){
            cin >> x;
            adj[i].push_back(x);
        }
    }

    queue<int> q;
    vis[1] = true; dis[1] = 1; q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(!vis[nxt]){
                q.push(nxt);
                vis[nxt] = true; dis[nxt] = dis[cur] + 1;
            }
        }
    }

    bool reachable = true;
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            reachable = false;
            break;
        }
    }

    int mi = N;
    for(int ending : endpoints){
        if(vis[ending]){
            mi = min(mi, dis[ending]);
        }
    }

    cout << (reachable? 'Y' : 'N') << endl;
    cout << mi << endl;
}
