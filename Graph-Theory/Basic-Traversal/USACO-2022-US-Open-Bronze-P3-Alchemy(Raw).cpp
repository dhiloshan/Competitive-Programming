// USACO 2022 US Open, Bronze Problem 3. Alchemy (DMOJ): https://dmoj.ca/problem/usaco22openb3
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 102;
int N, K, a[MM], ans; vector<int> rev[MM];
bool check(int u) {
    if (a[u] > 0) {
        return true;
    }
    else {
        if (rev[u].size() == 0)
            return false;
        for (int nxt : rev[u]) {
            if (!check(nxt)) {
                return false;
            }
            a[nxt]--;
        }
        a[u]++; return true;
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    cin >> K;
    for (int i = 1, u, m; i <= K; i++) {
        cin >> u >> m;
        for (int j = 1, x; j <= m; j++) {
            cin >> x;
            rev[u].push_back(x);
        }
    }
    while (true) {
        if (!check(N)) {
            break;
        }
        a[N]--; ans++;
    }
    cout << ans << endl;
}
