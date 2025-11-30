// Curious Robin Hood (LightOJ): https://lightoj.com/problem/curious-robin-hood
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+3;
typedef long long ll;
int T, N, Q, a[MM]; ll bit[MM];
void update(int pos, int val) {
    for (int i = pos; i <= 1e5; i += (i&-i)) {
        bit[i] += val;
    }
}
ll query(int pos) {
    ll sum = 0;
    for (int i = pos; i > 0; i -= (i&-i)) {
        sum += bit[i];
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> Q;
        memset(a, 0, sizeof(a)); memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= N; i++) {
            cin >> a[i]; update(i, a[i]);
        }
        vector<ll> ans;
        for (int i = 1, q; i <= Q; i++) {
            cin >> q;
            if (q == 1) {
                int pos; cin >> pos; pos++;
                update(pos, -a[pos]);
                ans.push_back(a[pos]);
                a[pos] = 0;
            }
            else if (q == 2) {
                int pos, val; cin >> pos >> val; pos++;
                update(pos, val); a[pos] += val;
            }
            else {
                int l, r; cin >> l >> r; l++; r++;
                ans.push_back(query(r) - query(l-1));
            }
        }
        cout << "Case " << t << ":" << endl;
        for (ll e : ans)
            cout << e << endl;
    }
}
