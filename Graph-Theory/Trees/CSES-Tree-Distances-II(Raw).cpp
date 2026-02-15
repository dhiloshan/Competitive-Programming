// Tree Distances II (CSES): https://cses.fi/problemset/task/1133
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 3e6+8;
ll N, ans[MM], sz[MM]; vector<int> adj[MM];
void dfs1(int cur, int par, ll dep) {
    ans[1] += dep;
    sz[cur] = 1;
    for (int nxt : adj[cur]) {
        if (nxt != par) {
            dfs1(nxt, cur, dep+1);
            sz[cur] += sz[nxt];
        }
    }
}
void dfs2(int cur, int par) {
    for (int nxt : adj[cur]) {
        if (nxt != par) {
            ans[nxt] = ans[cur] + N - 2 * sz[nxt];
            dfs2(nxt, cur);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 1, a, b; i < N; i++) {
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs1(1, 1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " \n"[i==N];
    }
}
