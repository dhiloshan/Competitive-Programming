// Graph Contest 2 P2 - Directed Acyclic Graph (DMOJ): https://dmoj.ca/problem/graph2p2
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1003;
typedef long long ll;
typedef pair<int, int> pi;
int N, vis[MM]; bool a[MM][MM];
void dfs(int u){ // three states: 0 - not visited, 1 - currently visiting (on the path), 2 - fully visited all neighbours of node i
    vis[u] = 1;
    for(int v = 1; v <= N; v++){
        if(a[u][v]){ // for each neighbour
            if(!vis[v]) dfs(v);
            else if(vis[v] == 1){
                cout << "NO" << endl;
                exit(0);
            }
        }
    }
    vis[u] = 2; // node is fully explored
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            bool k; cin >> k;
            a[i][j] = k;
        }
    }
    for(int i = 1; i <= N; i++)
        if(!vis[i]) // may not be rooted at vertex 1
            dfs(i);
    cout << "YES" << endl;
}
