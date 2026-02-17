// Cheerio Contest 3 P4 - Bit Flips (DMOJ): https://dmoj.ca/problem/cheerio3p4
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1<<30;
const int mod = (int)1e9+7;
typedef long long ll;
typedef pair<int, int> pi;
int N, a[102], psa[30][102], dp[30][102][102]; // interval + bitmask dp
int cnt1(int k, int l, int r){ return psa[k][r] - psa[k][l-1]; } // # of 1's for bit pos k from l to r
int cnt0(int k, int l, int r){ return (r-l+1) - cnt1(k, l, r); } // ... 0's .....
int fun(int k, int l, int r) {
    if (k < 0 || l > r) return 0;
    if (dp[k][l][r] != -1) return dp[k][l][r];
    int ret = 1e9;
    for (int m = l-1; m <= r; m++) { // find the point to split the interval to 0 0 ... 0 1 ... 1
        // we set to l-1 because it may be possible to set the kth bit for #'s from l to r to 1. when m = r, the bit is 0
        ret = min(ret, fun(k-1, l, m) + cnt1(k, l, m)  + fun(k-1, m+1, r) + + cnt0(k, m+1, r));
    } // break the problem down into two intervals. for the left interval, the kth bit will be 0, you also have to enforce non-decreasing values for that interval.
    // for the right interval, the kth bit is 1. so far, for bits 29 to k, it is non decreasing, but for bits k-1 to 0, we need to enforce it.
    // hence, we also call the function on the right interval for bits k-1 to 0
    return dp[k][l][r] = ret;
}
int main() {
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        for (int k = 0; k < 30; k++) {
            psa[k][i] = psa[k][i-1] + (a[i] >> k & 1);
        }
    }
    // 29 is the max amount of bits
    cout << fun(29, 1, N) << endl; // starting from the leftmost bit for range l to r
}
