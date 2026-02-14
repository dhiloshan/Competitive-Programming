// Tree Distances I (CSES): https://cses.fi/problemset/task/1132
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+8;
int N; vector<int> adj[MM];
void bfs(int u, int dis[], bool vis[]) {
    queue<int> q;
    q.push(u);
    vis[u] = true; dis[u] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            if (!vis[nxt]) {
                vis[nxt] = true;
                dis[nxt] = dis[cur] + 1;
                q.push(nxt);
            }
        }
    }
}
int main() {
    cin >> N;
    for (int i = 1, a, b; i < N; i++) {
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    int dis1[MM]; bool vis1[MM]; memset(dis1, 0, sizeof(dis1)); memset(vis1, 0, sizeof(vis1));
    bfs(1, dis1, vis1); 
    int mx = -1, A = 0;
    for (int i = 1; i <= N; i++) {
        if (mx < dis1[i]) {
            mx = dis1[i]; A = i;
        }
    }

    int disA[MM]; bool visA[MM]; memset(disA, 0, sizeof(disA)); memset(visA, 0, sizeof(visA));
    bfs(A, disA, visA);

    int mx2 = -1, B = 0;
    for (int i = 1; i <= N; i++) {
        if (mx2 < disA[i]) {
            mx2 = disA[i]; B = i;
        }
    }

    int disB[MM]; bool visB[MM]; memset(disB, 0, sizeof(disB)); memset(visB, 0, sizeof(visB));
    bfs(B, disB, visB);

    for (int i = 1; i <= N; i++) {
        cout << max(disA[i], disB[i]) << " \n"[i==N];
    }
}
