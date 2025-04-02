// Multiple of K (Olympiads): https://dmoj.ca/problem/oly19practice19
// RAW CODE - https://dmoj.ca/src/6458546
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, K, psa[MM], rem[MM], ans=-1;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    cin >> psa[1]; psa[1] %= K;
    for(int i = 2, x; i <= N; i++){
        cin >> x; psa[i] = (psa[i-1] + x) % K;
    }
    fill(rem, rem+MM, -1);
    rem[0] = 0;
    for(int i = 1; i <= N; i++){
        if(rem[psa[i]] != -1)
            ans = max(ans, i - rem[psa[i]]);
        else
            rem[psa[i]] = i;
    }
    cout << ans << endl;
}
