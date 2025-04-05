// RTE '16 S3 - School Traversal (DMOJ): https://dmoj.ca/problem/rte16s3
// ANNOTATED CODE - https://dmoj.ca/src/7101760
// SOLUTION 1: BFS + offline query + store query by ID
// given a weighted tree and Q queries, find the min distance from node a to b
// note that there is only one possible path from node a to b; thus, dijkstra is not needed. instead use bfs
// dijkstra, which is O(E + VlogV), would take too long, BFS is just O(E+V)
// we also note to do bfs before hand, store it, and then use that during queries
// but it takes too much memory for 2D long long array (6000x6000)
// thus, we utilize offline queries and store its id. then we use 1D long long array for each iteration of bfs instead of 2D to save space (vector runs on heap, memory is freed after)
// use another 1D array for the answers and store it there
#include <bits/stdc++.h>
using namespace std;
const int MM = 6000, MM2 = 1e6+3;
const int mod = (int)1e9+7;
const int base = (int)1e8+7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
#define f first
#define s second
int N, Q; ll ans[MM2]; vector<pi> adj[MM], qry[MM]; // qry: [dist to node v from node i, query ID]
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0, u, v, w; i < N-1; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    cin >> Q;
    for(int i = 0, u, v; i < Q; i++){
        cin >> u >> v;
        qry[u].push_back({v, i});
    }
    for(int i = 0; i < N; i++){ // N iterations of BFS
        queue<int> q; q.push(i);
        bool vis[N+1]; memset(vis, false, N+1); vis[i] = true;
        ll dis[N+1]; memset(dis, 0, N+1); dis[i] = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto [v, w] : adj[cur]){
                if(!vis[v]){
                    dis[v] = dis[cur] + w; q.push(v); vis[v] = true; // we add by w, not by 1 (we can use bfs because it is a tree, only one path from a to b)
                }
            }
        }
        for(auto [v, id] : qry[i]){ // for node i, we are queried dist from node i to v, which is dis[v]. store that in the according id slot within the ans array
            ans[id] = dis[v];
        }
    }
    for(int i = 0; i < Q; i++){ // send out the answers in order
        cout << ans[i] << endl;
    }
}
