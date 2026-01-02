// D2. Magic Powder - 2 (Codeforces): https://codeforces.com/problemset/problem/670/D2
// RAW CODE
// Approach #3 (binary search the # of cookies that can be made. if you can't create i cookies, you cannot create i+1, i+2, ..., 2*10^9 cookies either) <- 2*10^9 is max cookies you can make for worst case test case scenario
// Translates to T T T ... T T F F ... find last true value
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e6+3;
int N, K, a[MM], b[MM], q[MM];
bool check(ll req) {
    ll k = K;
    for (int i = 1; i <= N; i++) {
        ll reqCur = (ll)a[i] * req;
        if (b[i] < reqCur)
            k -= (reqCur - b[i]);
        if (k < 0)
            return false;
    }
    return true;
}
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];
    int lo = 0, hi = 2e9+1;
    while (hi - lo > 1) {
        ll mi = lo + (hi - lo) / 2;
        if (check(mi)) lo = mi;
        else hi = mi;
    }
    cout << lo << endl;
}
