// CCO '00 P4 - Packet Routing (DMOJ): https://dmoj.ca/problem/cco00p4
// ANNOTATED CODE - https://dmoj.ca/src/6737495
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+2; // given an undirected tree such that any node a and b have exactly one unique path, find the min distance between a and b given p queries
int N, M, Q; bool vis[MM]; vector<pair<int, int> > adj[MM]; // represented by an adjacency list, stores a pair for weight <neigbhour, weight>
int dfs(int cur, int dst){ // we utilize the fact that there is only a single UNIQUE path from any nodes a to b to our advantage
                           // dijkstra/floyd's is not needed, just a simple dfs algorithm to traverse all nodes
                           // if there were multiple paths from a to b, dfs will not necessarily find the path with minimum cost, just A suitable path
    if(cur == dst) return 0; // base case: if the current node equals the destination node, it means we found a valid path
                             // we are looking at the same node, so it is a cost of 0
    for(auto &[v, w] : adj[cur]) { // for every single neighbour (note it is an undirected graph)
        if (!vis[v]) { // if the node is not visited we have to check if that part of the tree has a valid path starting from cur
            vis[v] = true; // set the node to true before doing dfs
            int cost = dfs(v, dst); // goes from the neighbour node to dest node, if there is a path it will be some non-negative number that represents the cost of the path from v to dst
            if(cost != -1){         // if it is -1, that means at a certain point during recursion, we went out of the for loop in line 12 to  return -1
                                    // since there aren't any neighbours that are unvisited and because that node n (during that point of recursion) is not equal to dst
                                    // please use a basic binary tree example to illustrate this it will make it much more clear
                return w + cost; // return the cost from cur to v
            }
        }
    }
    return -1; // if there is no possible path from cur to dst, return -1
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> Q;
    for(int i = 1, u, v, w; i <= M; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w); // emplace_back is more efficient than push_back
        // push_back creates a temporary copy of the pair because it requires a constructed object
        // push_back({v,w}), where {v,w} is an initializer list that constructs a temporary pair<int, int> object, which is then copied or moved back into the vector
        // to avoid this extra step, we use emplace_back, which directly constructs pair<int, int>{v, w} in place within adj[u]
        // it forwards parameters v and w DIRECTLY to the pair<int, int> constructor, avoiding the temporary object and making insertion more efficient
    }
    for(int i = 0, u, v; i < Q; i++){
        cin >> u >> v;
        for(int i = 0; i < MM; i++) vis[i] = false; // vis[i] represents if node i is visited or not
        vis[u] = true; // mark the root/source node visited before performing dfs
        cout << dfs(u, v) << endl; // u, which represents source, and v, which represents destination => dfs(src, dst)
    }
}
