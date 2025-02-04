// WC '15 Contest 1 S3 - Contest Sites (DMOJ): https://dmoj.ca/problem/wc15c1s3
// ANNOTATED CODE - https://dmoj.ca/src/6946231
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef long long ll;
typedef pair<int, int> pi;
int N, M, K, ppl[MM]; ll dis1[MM], dis2[MM], ans; vector<pi> adj[MM], order1, order2, movetonode1;
void dijk(int s, ll dis[]){ // dijkstra algorithm given start node s and a dist array; pass by reference for dist array
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
        adj[v].emplace_back(u, w); // reverse the edges because we do dijkstra from dest nodes
    }
    dijk(1, dis1); dijk(2, dis2); // run dijk in reverse from dest nodes 1 and 2
    for(int i = 2; i <= N; i++) {
        if(ppl[i] > 0){ // if there is 0 people we don't need to do anything (very important to include this line i lost 6 / 30 points for this)
            if(dis2[i] == 1e18 && dis1[i] == 1e18){ cout << -1 << endl; return 0; } // then you can't travel to either the dest nodes
            else if(dis1[i] == 1e18) order1.emplace_back(dis2[i], i); // if so then you HAVE to take node 2
            else if(dis1[i] <= dis2[i]) { ans += (ll)dis1[i] * ppl[i]; ppl[i] = 0; } // then lets go through node 1
            else order2.emplace_back(dis2[i]-dis1[i],  i); // these nodes we don't have to go to node 2 but if we can let's do it, this is greedy, the one with the best cost save (the distance to node 2 is SIGNIFICANTLY less than dist to node 1) should be the ones we consider first
        }
    }
    sort(order2.begin(), order2.end());
    for(auto [d2, i] : order1) { // we HAVE to go to node 1 as it is impossible to reach node 2
        if (ppl[i] > K) { // then there isn't enough spots to hold the contest at node 2
            cout << -1 << endl;
            return 0;
        }
        ans += (ll) ppl[i] * d2; // for each person, they travel a distance of d2
        K -= ppl[i];
    }
    for(auto [g, u] : order2){ // greedy approach, while possible, use node 2, but start with the nodes with the most cost save
        int d1 = dis1[u], d2 = dis2[u];
        if(K > 0){ // first see if you can go to building two (note it may not be the best option)
            int n = min(ppl[u], K); // there may be 4 spots left (K) for node 2, but there are 6 people at node u (ppl[u]), so we can only accommodate 4 ppl
            K -= n; ans += (ll)d2 * n;
            ppl[u] -= n;
        }
        if(ppl[u] > 0){ // if you still have ppl left move the rest of them from node u to node 1
            ans += (ll)d1 * ppl[u];
            ppl[u] = 0;
        }
    }
    cout << ans << endl;
}
