// CCC '15 S4 - Convex Hull (DMOJ): https://dmoj.ca/problem/ccc15s4
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
const int MM2 = 202;
const int INF = 1e9;
struct Edge {
    int v, t, h; // variables within this object
    bool operator<(const Edge &y) const { // should I put my current object BEFORE this other object? (easiest way to explain how operator< works)
        if(y.t == t) return y.h < h;
        return y.t > t; // ensures its ascending order
        // only put the current object before if it is SMALLER than the other one: 7 (y object) 5 (current object), 8 1, 9 3 are all random examples of this

    }
};
int K, N, M, A, B, dis[MM][MM2]; vector<Edge> adj[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> K >> N >> M;
    for(int i = 0, a, b, t, h; i < M; i++){
        cin >> a >> b >> t >> h;
        adj[a].push_back({b, t, h}); adj[b].push_back({a, t, h});
    }
    cin >> A >> B;
    priority_queue<Edge> pq;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= K; j++){
            dis[i][j] = INF;
        }
    } dis[A][K] = 0; pq.push({A, 0, K});
    while(!pq.empty()){
        auto [u, ct, ch] = pq.top(); pq.pop();
        if(ct > dis[u][ch]) continue;
        if(u == B) {cout << dis[u][ch] << endl; return 0;}
        for(auto [v, w, h] : adj[u]) {
            if(ch - h > 0 && dis[u][ch] + w < dis[v][ch-h]){
                dis[v][ch-h] = dis[u][ch] + w; pq.push({v, dis[v][ch-h], ch-h});
            }
        }
    }
    cout << -1 << endl;
}
