// Disjoint Set Test (DMOJ): https://dmoj.ca/problem/ds2
// RAW CODE - https://dmoj.ca/src/6917112
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef pair<int, int> pi;
int N, M, p[MM], rnk[MM]; vector<int> edges;
int fd(int u) { return u == p[u]? u : p[u] = fd(p[u]); }
void unite(int u, int v){
    int s1 = fd(u), s2 = fd(v);
    if(rnk[s1] < rnk[s2]) { p[s1] = s2; rnk[s2] += rnk[s1]; }
    else { p[s2] = s1; rnk[s1] += rnk[s2]; }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) { p[i] = i; rnk[i] = 1; }
    for(int i = 1, u, v; i <= M; i++){
        cin >> u >> v;
        int fu = fd(u), fv = fd(v);
        if(fu != fv){
            unite(fu, fv);
            edges.emplace_back(i);
        }
        if(edges.size() == N-1) break;
    }
    if(edges.size() != N-1) cout << "Disconnected Graph\n";
    else for(int c : edges) cout << c << '\n';
}
