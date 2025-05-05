// COCI '13 Contest 4 #3 Sumo (DMOJ): https://dmoj.ca/problem/coci13c4p3
// ANNOTATED CODE
/*
we want to check if the graph is bipartite, but instead of running bfs/dfs for every new fight, we do the following:
 we use a DSU and for fight i between fighters a and b, we put a and b+N in the same group and b and a+N in the same group
 "the enemy of your enemy is your friend" common saying in life
 that's exactly the logic we use
 nodes N+1 to 2N are "mirror" nodes, like 1 and 1' (but we say 1+N to represent 1'). but 1' is the enemy of node 1, so if someone fought fighter one, they would be friends with fighter one's enemy
 if at some point both fighters are in the same group, then that's the point where two fighters from the same group must fight each other
 */
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, M, ans, p[2*MM], rnk[2*MM]; bool flag=true;
// dsu operations max optimization
int fd(int u){ return u == p[u]? u : p[u]=fd(p[u]);}
void unite(int u, int v){
    int s1 = fd(u), s2 = fd(v);
    if(rnk[s1] > rnk[s2]){p[s2]=s1;rnk[s1]+=rnk[s2];}
    else{p[s1]=s2; rnk[s2] += rnk[s1];}
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= 2*N; i++){p[i]=i; rnk[i]=1;}
    for(int i = 1, a, b; i <= M; i++){
        cin >> a >> b;
        if(flag){ // if already we don't have two fighters in the same group
            unite(a, b+N); unite(b, a+N); // union the four members
            if(fd(a) == fd(b)) {ans = i; flag = false; } // if they are in the same set then two fighters from the same group are fighting each other, which is bad
        }
    }
    cout << ans << endl;
}
