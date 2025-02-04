// WC '15 Contest 1 S3 - Contest Sites (DMOJ): https://dmoj.ca/problem/wc15c1s3
// RAW CODE - https://dmoj.ca/src/6946258
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef long long ll;
typedef pair<int, int> pi;
int N, M, K, ppl[MM]; ll dis1[MM], dis2[MM], ans; vector<pi> adj[MM], order1, order2, movetonode1;
void dijk(int s, ll dis[]){
    priority_queue<pi, vector<pi>, greater<> > q;
    fill(dis, dis+MM, 1e18);
    dis[s] = 0; q.push({dis[s], s});
    while(!q.empty()){
        auto [d, u] = q.top(); q.pop();
        if(d > dis[u]) continue;
        for(auto [v, w] : adj[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w; q.push({dis[v], v});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) cin >> ppl[i];
    for(int i = 1, u, v, w; i <= M; i++){
        cin >> u >> v >> w;
        adj[v].emplace_back(u, w);
    }
    dijk(1, dis1); dijk(2, dis2);
    for(int i = 2; i <= N; i++) {
        if(ppl[i] > 0){
            if(dis2[i] == 1e18 && dis1[i] == 1e18){ cout << -1 << endl; return 0; }
            else if(dis1[i] == 1e18) order1.emplace_back(dis2[i], i);
            else if(dis1[i] <= dis2[i]) { ans += (ll)dis1[i] * ppl[i]; ppl[i] = 0; }
            else order2.emplace_back(dis2[i]-dis1[i],  i);
        }
    }
    sort(order2.begin(), order2.end());
    for(auto [d2, i] : order1) {
        if (ppl[i] > K) {
            cout << -1 << endl;
            return 0;
        }
        ans += (ll) ppl[i] * d2;
        K -= ppl[i];
    }
    for(auto [g, u] : order2){
        int d1 = dis1[u], d2 = dis2[u];
        if(K > 0){
            int n = min(ppl[u], K);
            K -= n; ans += (ll)d2 * n;
            ppl[u] -= n;
        }
        if(ppl[u] > 0){
            ans += (ll)d1 * ppl[u];
            ppl[u] = 0;
        }
    }
    cout << ans << endl;
}
