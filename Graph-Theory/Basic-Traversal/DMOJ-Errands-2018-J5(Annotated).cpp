// GlobeX Cup '18 J5 Errands - Course Requirements (DMOJ): https://dmoj.ca/problem/globexcup18j5
// ANNOTATED CODE - https://dmoj.ca/src/6779076
// just run BFS on C, the root node, and for each query check if you can a to C and C to b, if yes print the sum of min distance, if no print its a scam
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, M, Q, C, dis[MM]; bool vis[MM]; vector<int> adj[MM]; queue<int> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> Q >> C;
    for(int i = 1, u, v; i <= M; i++){
        cin >> u >> v; // note everything is 1-indexed
        adj[u].push_back(v); adj[v].push_back(u); // graph has two-way roads
    }
    // perform BFS (this is all just template)
    q.push(C); vis[C] = true; dis[C] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(!vis[nxt]){
                q.push(nxt);
                vis[nxt] = true; dis[nxt] = dis[cur] + 1;
            }
        }
    }
    for(int i = 1, a, b; i <= Q; i++){
        cin >> a >> b;
        cout << ((vis[a] && vis[b])? to_string(dis[a]+dis[b]) : "This is a scam!") << endl;
        // the line above is just very condensed; not good code practice but this is an easy problem
        // it's say if I can get from a to C and from C to b => print out the min distance from a to C + min distance from C to b
        // otherwise, print out this is a scam, indicting it is impossible to find such path
        // we do to_string because this notation requires two outputs of the same type, and since the latter is a string, we have to convert the former from an int to string
    }
}
