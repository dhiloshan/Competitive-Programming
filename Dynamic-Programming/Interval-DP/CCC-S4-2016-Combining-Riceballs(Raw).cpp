// CCC '16 S4 - Combining Riceballs (DMOJ): https://dmoj.ca/problem/ccc16s4
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 403;
const int mod = (int)1e9+7;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, pi> pii;
int N, psa[MM], ans; bool dp[MM][MM];
int sum(int l, int r) { return psa[r] - psa[l-1]; }
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> psa[i]; ans = max(ans, psa[i]);
        psa[i] += psa[i-1]; dp[i][i] = 1;
    }
    for (int len = 2; len <= N; len++) {
        for (int l = 1, r = l + len - 1; r <= N; l++, r++) {
            for (int p = l, q = r; p < q; ) {
                if (dp[l][p] && dp[q][r] && (dp[p+1][q-1] || p+1 == q) && sum(l, p) == sum(q, r)) {
                    dp[l][r] = true; break;
                }
                if (sum(l, p) < sum(q, r)) p++;
                else q--;
            }
            if (dp[l][r]) ans = max(ans, sum(l, r));
        }
    }
    cout << ans << endl;
}
