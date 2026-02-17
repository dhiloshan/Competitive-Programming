// Cheerio Contest 3 P4 - Bit Flips (DMOJ): https://dmoj.ca/problem/cheerio3p4
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1<<30;
const int mod = (int)1e9+7;
typedef long long ll;
typedef pair<int, int> pi;
int N, a[102], psa[30][102], dp[30][102][102];
int cnt1(int k, int l, int r) { return psa[k][r] - psa[k][l-1]; }
int cnt0(int k, int l, int r) { return (r-l+1) - cnt1(k, l, r); }
int fun(int k, int l, int r) {
    if (k < 0 || l > r) return 0;
    if (dp[k][l][r] != -1) return dp[k][l][r];
    int ret = 1e9;
    for (int m = l-1; m <= r; m++) {
        ret = min(ret, fun(k-1, l, m) + fun(k-1, m+1, r) + cnt1(k, l, m) + cnt0(k, m+1, r));
    }
    return dp[k][l][r] = ret;
}
int main() {
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        for (int k = 0; k < 30; k++) {
            psa[k][i] += psa[k][i-1] + (a[i] >> k & 1);
        }
    }
    cout << fun(29, 1, N) << endl;
}
