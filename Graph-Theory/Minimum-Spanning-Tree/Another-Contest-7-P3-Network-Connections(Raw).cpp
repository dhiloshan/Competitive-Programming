// Another Contest 7 Problem 3 - Network Connections (DMOJ): https://dmoj.ca/problem/acc7p3
// RAW CODE - https://dmoj.ca/src/7133637
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MM = 1e5+3;
int p[MM], rnk[MM], f[MM], N, M; bool nxt[MM]; vector<pii> krusk; ll cost;
int fd(int u){ return u == p[u]? u : p[u]=fd(p[u]); }
void unite(int u, int v){
    int s1 = fd(u), s2 = fd(v);
    if(rnk[s1]>rnk[s2]){p[s2]=s1;rnk[s1]+=rnk[s2];}
    else{p[s1]=s2;rnk[s2]+=rnk[s1];}
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1, fi; i <= N; ++i) { cin >> fi; f[i]=fi; p[i]=i; rnk[i]=1; }
    for(int i = 0, a, b; i < M; ++i){
        cin >> a >> b; unite(a, b);
        if(b==a+1) nxt[a]=true;
    }
    for(int i = 1; i < N; ++i){
        if(!nxt[i]) krusk.push_back({f[i+1]-f[i], {i, i+1}});
    }
    sort(krusk.begin(), krusk.end());
    for(auto [fc, p] : krusk){
        auto [a, b] = p;
        if(fd(a) != fd(b)){ unite(a, b); cost+=fc; }
    }
    cout << cost << endl;
}
