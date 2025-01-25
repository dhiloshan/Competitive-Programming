// Disjoint Set Test (DMOJ): https://dmoj.ca/problem/ds2
// ANNOTATED CODE - https://dmoj.ca/src/6917234
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef pair<int, int> pi; // Kruskal algorithm using disjoint set union (max optimizations)
int N, M, p[MM], rnk[MM]; vector<int> edges; // p[i] = parent; rnk[i] = rank; edges denotes all of the edges #'s for the MST
int fd(int u) { // find node u's parent + path compression optimization
    return u == p[u]? u : p[u] = fd(p[u]); // recursively go up until you find node u's parent
    // (path compression) all of the nodes in the recursive path should now have a new parent: the crux of the connected component => faster query time to find parent
}
void unite(int u, int v){ // union node u and node v + union by rank optimization
    int s1 = fd(u), s2 = fd(v); // the two sets
    // we are merging the smaller tree with the bigger tree (rnk represents size of component)

    if(rnk[s1] < rnk[s2]) { p[s1] = s2; rnk[s2] += rnk[s1]; }
    else { p[s2] = s1; rnk[s1] += rnk[s2]; }
    // whichever component is bigger set the new parent of the smaller set to the bigger set's parent
    // and update the rank of the bigger set to add the size of the smaller set
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); // for some reason saved a lot of time on my DMOJ submission so I'm going to use I/O fast input/output constantly
    cin >> N >> M;
    for(int i = 1; i <= N; i++) { p[i] = i; rnk[i] = 1; } // initialization: all nodes point to themselves and have a rank of 1 (N sets of size/rank 1)
    for(int i = 1, u, v; i <= M; i++){
        cin >> u >> v; // in the question, edge i has weight i, so do kruskal as you're taking input
        int fu = fd(u), fv = fd(v); // the two sets
        if(fu != fv){ // if they don't have the same parent (different sets)
            unite(fu, fv);
            edges.emplace_back(i); // since we had to use the edge for the MST push it into the edges final answer
        }
        if(edges.size() == N-1) break; // once the graph has N-1 edges it is a tree and thus our MST, so break
    }
    if(edges.size() != N-1) cout << "Disconnected Graph\n"; // that means there is at least one node that isn't connected
    else for(int c : edges) cout << c << '\n';
}
