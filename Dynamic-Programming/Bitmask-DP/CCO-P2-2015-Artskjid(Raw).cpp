// CCO '15 P2 - Artskjid (DMOJ): https://dmoj.ca/problem/cco15p2
// RAW CODE (make sure to add another dimension to the dp array to account for which node you are at. seems like most bitmask dp questions use a similar template. also very important to set ans to -1e9, as it MAY be impossible to go from node u to v)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1<<18;
const int mod = (int)1e9+7;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, pi> pii;
int N, M, dp[18][MM]; vector<pi> adj[MM];
int fun(int u, int mask) {
    if (u == N-1) return 0;
    if (dp[u][mask] != -1) return dp[u][mask];
    int ans = -1e9;
    for (auto [v, w] : adj[u]) {
        if (((mask>>v)&1) == 0) {
            int res = fun(v, mask|(1<<v));
            if (res != -1e9)
                ans = max(ans, res + w);
        }
    }
    return dp[u][mask] = ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < 18; i++)
        for (int j = 0; j < MM; j++)
            dp[i][j] = -1;

    for (int i = 1, a, b, c; i <= M; i++) {
        cin >> a >> b >> c; adj[a].emplace_back(b, c);
    }
    cout << fun(0, 1) << endl;
}
