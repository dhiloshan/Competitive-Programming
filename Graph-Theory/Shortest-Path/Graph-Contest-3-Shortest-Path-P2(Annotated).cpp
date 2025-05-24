// Graph Contest 3 P2 - Shortest Path (DMOJ)
// ANNOTATED CODE (bellman-ford): O(VE)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3;
struct Edge { int u, v, w; }; // easy way to define an edge
int N, M, dis[MM]; vector<Edge> edges;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0, a, b, c; i < M; i++){
        cin >> a >> b >> c;
        edges.push_back({a, b, c}); // a corresponds to u, b ... v, c ... w
        // could also create an Edge object if that helps you visualize easier
    }
    memset(dis, 0x3f, sizeof(dis)); dis[1] = 0;
    for(int i = 1; i < N; i++){ // loop N-1 times
        for(auto [u, v, w] : edges){ // relax all edges (M times)
            // prior path min dist: dis[v]
            // new path: dis[u] + w
            dis[v] = min(dis[v], dis[u] + w);
        }
    }
    // don't need to check for cycle since shortest path is guaranteed
    /* still will provide the code for it: idea is if you have to update again, then there has to be a cycle (V-1 edges is max length for simple path). the only way an update can happen is if there is something better than a 0 or positive cycle: negative
    for(auto [u, v, w] : edges){
        if(dis[v]>dis[u]+w){ // negative cycle exists
            cout << -1 << endl;
            return 0;
        }
    }
     */
    cout << dis[N] << endl;
}
