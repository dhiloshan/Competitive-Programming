// CCC '24 S4 - Painting Roads (DMOJ): https://dmoj.ca/problem/ccc24s4
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 3e5+8;
int N, M; vector<tuple<int, char, int> > adj[MM]; bool vis[MM]; char c[MM];
void dfs(int cur, int depth) {
    vis[cur] = true;
    for (auto& [nxt, val, i] : adj[cur]) {
        if (!vis[nxt]){
            if (depth % 2 == 0) val = 'R';
            else val = 'B';
            if (c[i] == '-') c[i] = val;
            dfs(nxt, depth+1);
        }
    }
}
void dfsC(int cur, bool visC[]) {
    visC[cur] = true;
    for (auto& [nxt, val, i] : adj[cur]) {
        if (!visC[nxt]) {
            dfsC(nxt, visC);
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) c[i] = '-'; // initial
    for (int i = 1, a, b; i <= M; i++) {
        cin >> a >> b;
        adj[a].push_back({b, 'G', i}); adj[b].push_back({a, 'G', i});
    }
    vector<int> start;
    bool check[MM]; memset(check, 0, sizeof(check));
    for (int i = 1; i <= N; i++) {
        if (!check[i]) {
            dfsC(i, check);
            start.push_back(i);
        }
    }
    for (int i : start) {
        dfs(i, 0); 
    }
    for (int i = 1; i <= M; i++) {
        if (c[i] == '-') c[i] = 'G';
        cout << c[i];
    }
    cout << endl;

}
