// Bob's Lightbulbs (DMOJ Olympiads): https://dmoj.ca/problem/oly23practice34
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+3;
typedef pair<int, int> pi;
int N, Q, bit[MM]; bool a[MM];
void update(int idx, int delta) {
    for (int i = idx; i <= N; i += (i&(-i))) {
        bit[i] += delta;
    }
}
ll qry(int idx) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll sum = 0;
    for (int i = idx; i > 0; i -= (i&(-i)))
        sum += bit[i];
    return sum;
}
int main() {
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++) {
        string s;
        cin >> s;
        if (s == "TOGGLE") {
            int p; cin >> p;
            int delta = 1;
            if (a[p])
                delta = -1;
            update(p, delta);
            a[p] = !a[p];
        }
        else {
            int l, r; cin >> l >> r;
            if (s == "ON") {
                cout << qry(r) - qry(l-1) << endl;
            }
            else {
                cout << r-l+1 - (qry(r) - qry(l-1)) << endl;
            }
        }
    }
}
