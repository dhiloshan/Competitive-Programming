// COCI '13 Contest 4 #3 Sumo (DMOJ): https://dmoj.ca/problem/coci13c4p3
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, M, ans, p[2*MM], rnk[2*MM]; bool flag = true;
int fd(int u){ return u == p[u] ? u : p[u] = fd(p[u]); }
void unite(int u, int v){
    int s1 = fd(u), s2 = fd(v);
    if(rnk[s1] > rnk[s2]){ p[s2] = s1; rnk[s1] += rnk[s2]; }
    else { p[s1] = s2; rnk[s2] += rnk[s1]; }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= 2*N; i++) p[i] = i, rnk[i] = 1;
    for(int i = 1, a, b; i <= M; i++){
        cin >> a >> b;
        if(flag){
            unite(a, b+N); unite(b, a+N);
            if(fd(a) == fd(b)) ans = i, flag = false;
        }
    }
    cout << ans << endl;
}
