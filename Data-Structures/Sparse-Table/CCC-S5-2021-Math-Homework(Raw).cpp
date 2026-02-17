// CCC '21 S5 - Math Homework (DMOJ): https://dmoj.ca/problem/ccc21s5
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+3, LOG = 20;
int N, M, x[MM], y[MM], z[MM], a[MM], st[LOG+1][MM], dif[17][MM];
int query(int l, int r){
    int k = 31 - __builtin_clz(r - l + 1);
    return gcd(st[k][l], st[k][r-(1<<k)+1]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=M; i++) {
        cin >> x[i] >> y[i] >> z[i];
        dif[z[i]][x[i]]++;  dif[z[i]][y[i]+1]--;
    }
    for(int i=1; i<=N; i++) {
        a[i] = 1;
        for(int k=1; k<=16; k++){
            dif[k][i] += dif[k][i-1];
            if(dif[k][i]) a[i] = lcm(a[i], k);
        }
        st[0][i] = a[i];
    }
    for(int k=1; k<=LOG; k++)
        for(int i=1; i+(1<<k)-1<=N; i++)
            st[k][i] = gcd(st[k-1][i], st[k-1][i+(1<<k-1)]);
    for(int i=1; i<=M; i++){
        if(query(x[i], y[i]) != z[i]) {
            cout << "Impossible\n"; return 0;
        }
    }
    for(int i=1; i<=N; i++) cout << a[i] << " \n"[i==N];
}
