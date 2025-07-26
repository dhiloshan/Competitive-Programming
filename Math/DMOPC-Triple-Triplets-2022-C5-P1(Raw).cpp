// DMOPC '22 Contest 5 P1 - Triple Triplets (DMOJ): https://dmoj.ca/problem/dmopc22c5p1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int N; cin >> N;
    ll ans = 0;
    for(int t = 0; t*2 <= N; t++){
        ll ones = N - 2LL*t;
        ll triples = (ones*(ones-1)/2) * t;
        ans = max(ans, triples);
    }
    cout << ans << endl;
}
