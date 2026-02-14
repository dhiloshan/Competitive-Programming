// Tree Distances II (CSES): https://cses.fi/problemset/task/1133
// ANNOTATED CODE (NOT MY CODE, this is usaco guide's code). comments are mine (in a rush to prep for CCC)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
vector<int> graph[200001]; // prefer adj
ll dp[200001], ans[200001]; // key idea: relationship between the current node and the new node when rerooting it. each question will different, and how the ans array is modified will change. dp will not prob
// prefer using sz instead of dp for future use
void dfs1(int node = 1, int parent = 0, ll depth = 0) { // each dfs has a cur node, its parent, and the current depth relative to root (node 1)
    ans[1] += depth; // computes distance total of all node from node 1
    // for each node when the prior line is ran, it is guaranteed the depth provided is correct
    dp[node] = 1; // dp represents subtree size. start with 1 to account for the node itself
    for (int i : graph[node])
        if (i != parent) { // replaces need for vis array (remember its a tree)
            dfs1(i, node, depth + 1); // used to find subtree size of its neighbour
            dp[node] += dp[i]; // for each neighbour add its subtree size here
        }
}

void dfs2(int node = 1, int parent = 0) {
    for (int i : graph[node])
        if (i != parent) {
            ans[i] = ans[node] + n - 2 * dp[i];
            dfs2(i, node);
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1();
    dfs2();
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    return 0;
}
