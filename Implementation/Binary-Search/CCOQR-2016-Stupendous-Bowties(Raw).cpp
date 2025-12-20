// CCOQR '16 - Stupendous Bowties (DMOJ): https://dmoj.ca/problem/ccoqr16p1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+3;
typedef pair<int, int> pi;
int N; vector<pi> p; map<int, vector<int>> px, py;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        p.push_back({x, y}); px[x].push_back(y); py[y].push_back(x);
    }
    for (auto& e : px) sort(e.second.begin(), e.second.end());
    for (auto& e : py) sort(e.second.begin(), e.second.end());
    ll ans = 0;
    for (auto [x, y] : p) {
        int hIdx = lower_bound(px[x].begin(), px[x].end(), y) - px[x].begin();
        int vIdx = lower_bound(py[y].begin(), py[y].end(), x) - py[y].begin();
        int lft = hIdx, rit = px[x].size() - hIdx - 1;
        int btm = vIdx, top = py[y].size() - vIdx - 1;
        ans += 2LL * lft * rit * top * btm;
    }
    cout << ans << endl;
}
