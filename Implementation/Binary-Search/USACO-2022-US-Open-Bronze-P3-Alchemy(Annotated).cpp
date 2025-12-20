// USACO 2022 US Open, Bronze Problem 3. Alchemy (DMOJ): https://dmoj.ca/problem/usaco22openb3
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 102;
int N, K, a[MM]; vector<int> rev[MM];
bool isValid(int am) {
    int req[N+1]; memset(req, 0,  sizeof(req));
    req[N] = am;
    for (int i = N; i >= 1; i--) {
        if (req[i] > 1e7) return false; // prevent integer overflow
        if (a[i] >= req[i])
            continue;
        // if you need to make more of metal i
        int rem = req[i] - a[i];
        if (rev[i].size() == 0) // no recipes to create metal i
            return false;
        for (int nxt : rev[i]) { // propogate values
            req[nxt] += rem;
        }
    }
    return true;
}
int main() {
    cin >> N;
    for (int i=1; i <= N; i++) cin >> a[i];
    cin >> K;
    for (int i = 1, u, m; i <= K; i++) {
        cin >> u >> m;
        for (int j = 1, v; j <= m; j++) {
            cin >> v;
            rev[u].push_back(v);
        }
    }
    // isValid(x) is true when you can supply x of metal N's
    // T T T F F .. <- find last true
    int lo = 0, hi = 1e7;
    while (hi - lo > 1) {
        int mid = lo + (hi - lo) / 2;
        if (isValid(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << endl;
}
