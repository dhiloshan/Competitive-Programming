// Multiple of K (DMOJ): https://dmoj.ca/problem/oly19practice19
// RAW CODE - https://dmoj.ca/src/6458546
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, K, psa[MM], ans=-1; map<int, int> rem;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    cin >> psa[1]; psa[1] %= K;
    for(int i = 2, x; i <= N; i++){
        cin >> x; psa[i] = (psa[i-1] + x) % K;
    }
    rem[0] = 0;
    for(int i = 1; i <= N; i++){
        if(rem.count(psa[i]))
             ans = max(ans, i - rem[psa[i]]);
        else
            rem[psa[i]] = i;
    }
    cout << ans << endl;
}
