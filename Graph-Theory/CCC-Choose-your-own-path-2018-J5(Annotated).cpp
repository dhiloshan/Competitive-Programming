// CCC '18 J5 - Choose your own path (DMOJ): https://dmoj.ca/problem/ccc18j5
// ANNOTATED CODE - https://dmoj.ca/src/6777009
/* BFS Template
 Perform BFS on the graph
 The graph must be connected for it to output 'Y' => check each cell of the vis array and if one is false print 'F'
 For the minimum distance, push all endpoints (where page i has Mi = 0) into an endpoints vector
 Iterate through the min distance (dis[endpoints[i]]) for each number in endpoints vector and update a int minimum variable if minimum > dis[endpoints[i]]
 */
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+3;
int N, dis[MM]; bool vis[MM]; vector<int> adj[MM], endpoints;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1, m; i <= N; i++){ // step 1: build adjacency list
        cin >> m; // m is the number of out-edges for page/node i
        if(m == 0) endpoints.push_back(i); // store all "ending pages" of the book into a vector
        for(int j = 1, x; j <= m; j++){ // note that everything is 1-indexed
            cin >> x;
            adj[i].push_back(x); // directed graph, so edges are unidirectional
        }
    }

    // step 2: perform bfs
    queue<int> q;
    vis[1] = true; dis[1] = 1; q.push(1); // note that we set the initial distance to 1 because initially we read page 1, which has a cost of 1
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(!vis[nxt]){
                q.push(nxt);
                vis[nxt] = true; dis[nxt] = dis[cur] + 1;
            }
        }
    }

    // step 3: output
    // step 3.1: if all pages can be visited
    bool reachable = true;
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            reachable = false;
            break;
        }
    }

    // step 3.2: find the minimum distance to an "ending page"
    int mi = N;
    for(int ending : endpoints){
        if(vis[ending]){ // if it is possible to reach that page (remember there is no guarantee we can reach an ending page, that's why we output Y or N)
            mi = min(mi, dis[ending]);
        }
    }

    // step 3.3: printing results to console
    cout << (reachable? 'Y' : 'N') << endl;
    cout << mi << endl;
}
