// Baltic OI '03 P4 - The Gangs (DMOJ): https://dmoj.ca/problem/btoi03p4
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3+3;
int N, M, p[MM], rnk[MM]; vector<int> adj[MM]; char op;
int fd(int u){ return u == p[u]? u : p[u]=fd(p[u]);}
void unite(int u, int v){
    int s1 = fd(u), s2 = fd(v);
    if(rnk[s1]<rnk[s2]){p[s1]=s2;rnk[s2]+=rnk[s1];}
    else{p[s2]=s1;rnk[s1]+=rnk[s2];}
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= 2*N; i++) p[i] = i, rnk[i] = 1;
    for(int i = 0, a, b; i < M; i++){
        cin >> op >> a >> b;
        if(op == 'E'){
            unite(a, b+N); unite(b, a+N);
            adj[b+N].push_back(a); adj[a+N].push_back(b);
        }
        else{
            unite(a, b);
        }
    }
    for(int i = N+1; i <= 2*N; i++)
        for(int j = 0; j < (int32_t)adj[i].size()-1; j++)
            unite(adj[i][j], adj[i][j+1]);

    unordered_set<int> st;
    for(int i = 1; i <= N; i++) st.insert(fd(i));
    cout << st.size() << endl;
}
