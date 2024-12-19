// VMSS '15 #4 - Frank and Roads (DMOJ): https://dmoj.ca/problem/vmss15c1p4
// ANNOTATED CODE - https://dmoj.ca/src/6819963
#include <bits/stdc++.h>
using namespace std;
const int MM = 2003;
const int INF = 1e9+3;
typedef pair<int, int> pi;
int N, M, G, T, dis[MM]; bool vis[MM]; vector<pi> adj[MM]; vector<int> dest; // dest vector contains all the end nodes we want to check the distance for
int main(){ // template dijkstra, but for each "Food Basics store", check if the distance from the start node to that node is less than T, if so, add 1 to a count variable
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T >> N >> M >> G;
    for(int i = 0, x; i < G; i++){ // push all end nodes
        cin >> x;
        dest.push_back(x);
    }
    for(int i = 0, u, v, w; i < M; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // uni-directional edges
    }
    priority_queue<pi, vector<pi>, greater<pi> > q; // dijkstra implemented with priority queue: O(ElogV)
    fill(dis, dis+MM, INF); // initially all distances to the nodes are infinity
    q.push({0, 0}); dis[0] = 0; // {0, 0} denotes {distance to node x from source node, node x}
    // note that we don't say vis[0] = true because if we did, the while loop would end by continue on the first call
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue; // if the node has been processed before move on
        vis[u] = true; // otherwise just mark it true (processed) and then in the for loop we will process node u
        for(auto& [v, w] : adj[u]){ // iterating through all the neighbours of node u
            // it costs w km to go from node u to node v
            if(dis[v] > dis[u] + w){  // there are two options to go to node v: from node u to node v directly through the edge costing w, or some past path previously computed by Dijkstra
                dis[v] = dis[u] + w; q.push({dis[v], v}); // if node u to node v by edge costing w is better, update it
                // pushing the node v with its updated min distance from the source node puts us one step closer towards finishing the Dijkstra algorithm
            }
        }
    }
    int cnt = 0; // number of nodes Frank can visit
    for(int cur : dest){
        if(dis[cur] <= T) cnt++; // if it is within T km of reach, add 1 to cnt
    }
    cout << cnt << endl;
}
