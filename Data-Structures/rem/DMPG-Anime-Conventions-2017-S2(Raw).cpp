// DMPG '17 S2 - Anime Conventions (DMOJ): https://dmoj.ca/problem/dmpg17s2
// RAW CODE - https://dmoj.ca/src/6916420
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int n, q, p[MM]; char op;
int fd(int d){
    if(d != p[d]) p[d] = fd(p[d]);
    return p[d];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1, x, y; i <= q; i++){
        cin >> op >> x >> y;
        if(op == 'A') p[fd(x)] = fd(y);
        else cout << (fd(x) == fd(y)? 'Y' : 'N') << endl;
    }
}
