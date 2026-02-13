// CSES Subordinates (CSES): https://cses.fi/problemset/task/1674
// RAW CODE (for each node, calculate sum of subtree sizes)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e5+3;
int N, val[MM]; vector<int> adj[MM], rev[MM];
void dfs(int u) {
    if (rev[u].size() == 0) {
        return;
    }
    for (int nxt : rev[u]) {
        dfs(nxt);
        val[u] += (val[nxt] + 1);
    }
}
int main() {
    cin >> N;
    for (int i = 1, x; i <= N-1; i++) {
        cin >> x;
        adj[i+1].push_back(x);
        rev[x].push_back(i+1);
    }
    dfs(1);
    for (int i = 1; i <= N; i++) {
        cout << val[i] << " ";
    }
    cout << endl;
}
