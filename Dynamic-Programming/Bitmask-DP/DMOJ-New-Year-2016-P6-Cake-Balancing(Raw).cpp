// New Year's '16 P6 - Cake Balancing (DMOJ): https://dmoj.ca/problem/year2016p6
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1<<10;
const int mod = (int)1e9+7;
typedef long long ll;
typedef pair<int, int> pi;
int L, R, W, dp[MM][MM], sumL[MM], sumR[MM], wl[10], wr[10];
int fun(int maskL, int maskR) {
    if (maskL == 0 && maskR == 0) return 0;
    if (dp[maskL][maskR] != -1) return dp[maskL][maskR];
    int curL = sumL[maskL], curR = sumR[maskR];
    int ret = 1e9;
    for (int sub = maskL; sub > 0; sub = (sub-1) & maskL)
        if (abs((curL - sumL[sub]) - curR) <= W)
            ret = min(ret, 1 + fun(maskL ^ sub, maskR));

    for (int sub = maskR; sub > 0; sub = (sub - 1) & maskR)
        if (abs((curR - sumR[sub]) - curL) <= W)
            ret = min(ret, 1 + fun(maskL, maskR ^ sub));

    return dp[maskL][maskR] = ret;
}
int main() {
    cin >> L >> R >> W;
    for (int i = 0; i < L; i++)  cin >> wl[i];
    for (int i = 0; i < R; i++) cin >> wr[i];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 1 << L; i++)
        for (int j = 0; j < L; j++)
            if (i>>j & 1)
                sumL[i] += wl[j];
    for (int i = 0; i < 1 << R; i++)
        for (int j = 0; j < R; j++)
            if (i>>j & 1)
                sumR[i] += wr[j];
    cout << fun((1<<L)-1, (1<<R)-1) << endl; // bit L to 0 should all be 1 to show that all items are there initially, same for R
}
