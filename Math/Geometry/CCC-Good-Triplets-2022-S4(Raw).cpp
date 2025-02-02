// CCC '22 S4 - Good Triplets (DMOJ): https://dmoj.ca/problem/ccc22s4
// RAW CODE - https://dmoj.ca/src/6940651
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
typedef long long ll;
int N, C, a[2*MM], cnt[2*MM]; ll ans;
ll choose2(ll n) { return n*(n-1)/2; }
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    for(int i=0; i<N; i++) {
        cin >> a[i]; a[i+N] = a[i] + C;
        cnt[a[i]]++; cnt[a[i+N]]++;
    }
    sort(a, a+2*N);
    ans = (ll)N*(N-1)*(N-2)/6;
    for(int i=0, j=0; i<N; i++){
        while(j<2*N && 2*(a[j] - a[i]) <= C) j++;
        ans -= choose2(j - i - 1);
    }
    if(C % 2 == 0) {
        for(int i=0; i<C; i++) ans += cnt[i] * choose2(cnt[i+C/2]);
    }
    cout << ans << endl;
}
