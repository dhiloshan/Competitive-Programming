// DMOPC '18 Contest 2 P4 - Damage Output (DMOJ): https://dmoj.ca/problem/dmopc18c2p4
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 6e5+3;
int N, mi = MM; ll a[MM], M;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> a[i];
    ll sum = 0;
    for(int l = 1, r = 1; r <= N; r++){
        sum += a[r];
        while(sum >= M){
            mi = min(mi, r-l+1);
            sum -= a[l]; l++;
        }
    }
    if(mi == MM) cout << -1 << endl;
    else cout << mi << endl;
}
