// RTE '16 S3 - School Traversal (DMOJ): https://dmoj.ca/problem/rte16s3
// RAW CODE - https://dmoj.ca/src/7101728
#include <bits/stdc++.h>
using namespace std;
const int MM = 6000, MM2 = 1e6+3;
const int mod = (int)1e9+7;
const int base = (int)1e8+7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
#define f first
#define s second
int N, Q; ll ans[MM2]; vector<pi> adj[MM], qry[MM]; 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0, u, v, w; i < N-1; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    cin >> Q;
    for(int i = 0, u, v; i < Q; i++){
        cin >> u >> v;
        qry[u].push_back({v, i});
    }
    for(int i = 0; i < N; i++){
        queue<int> q; q.push(i);
        bool vis[N+1]; memset(vis, false, N+1); vis[i] = true;
        ll dis[N+1]; memset(dis, 0, N+1); dis[i] = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto [v, w] : adj[cur]){
                if(!vis[v]){
                    dis[v] = dis[cur] + w; q.push(v); vis[v] = true;
                }
            }
        }
        for(auto [v, id] : qry[i]){
            ans[id] = dis[v];
        }
    }
    for(int i = 0; i < Q; i++){
        cout << ans[i] << endl;
    }
}
