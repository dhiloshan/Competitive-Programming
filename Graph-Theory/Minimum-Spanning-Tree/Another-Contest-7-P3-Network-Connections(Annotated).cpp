// Another Contest 7 Problem 3 - Network Connections (DMOJ): https://dmoj.ca/problem/acc7p3
// ANNOTATED CODE - https://dmoj.ca/src/7133648
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi; // build MST, but instead of checking all edges, we
typedef pair<int, pi> pii; // note that f values are monotonically increasing, so only consider ADJACENT users because it is always better or the same doing route i to i+1, .. to j rather than i to j
const int MM = 1e5+3; // arrays p and rnk are for DSU; nxt is to check if node i is connected to node i+1 (only consider ADJACENT users)
int p[MM], rnk[MM], f[MM], N, M; bool nxt[MM]; vector<pii> krusk; ll cost; // krusk (great name) is for edges to be considered in kruskal; cost is total cost to build MST
int fd(int u){ return u == p[u]? u : p[u]=fd(p[u]); } // path compression optimization
void unite(int u, int v){ // union by rank (size of component) optimization
    int s1 = fd(u), s2 = fd(v);
    if(rnk[s1]>rnk[s2]){p[s2]=s1;rnk[s1]+=rnk[s2];}
    else{p[s1]=s2;rnk[s2]+=rnk[s1];}
}
int main(){ // best way to build MST is 1 to 2 to 3 to 4 to ... N, but if there are edges already done like 1 to 4 prior, then just do 1 to 2 and 2 to 3 and ignore 3 to 4 
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1, fi; i <= N; ++i) { cin >> fi; f[i]=fi; p[i]=i; rnk[i]=1; } // initialize
    for(int i = 0, a, b; i < M; ++i){
        cin >> a >> b; unite(a, b); 
        if(b==a+1) nxt[a]=true; // consider adjacent users only in kruskal algo
    }
    for(int i = 1; i < N; ++i){
        if(!nxt[i]) krusk.push_back({f[i+1]-f[i], {i, i+1}}); // only look at node i+1
    }
    sort(krusk.begin(), krusk.end()); // ascending order
    for(auto [fc, p] : krusk){
        auto [a, b] = p;
        if(fd(a) != fd(b)){ unite(a, b); cost+=fc; } // if they are not connected (diff components), union them, cost is the difference in f val between nodes i and i+1
    }
    cout << cost << endl;
}
