// Graph Contest 3 P2 - Shortest Path (DMOJ)
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3;
struct Edge { int u, v, w; };
int N, M, dis[MM]; vector<Edge> edges;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0, a, b, c; i < M; i++){
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    memset(dis, 0x3f, sizeof(dis)); dis[1] = 0;
    for(int i = 1; i < N; i++){
        for(auto [u, v, w] : edges){
            dis[v] = min(dis[v], dis[u] + w);
        }
    }
    cout << dis[N] << endl;
}
