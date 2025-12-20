// CCOQR '16 - Stupendous Bowties (DMOJ): https://dmoj.ca/problem/ccoqr16p1
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+3;
typedef pair<int, int> pi;
int N; vector<pi> p; map<int, vector<int> > mpX, mpY;
int BS(const map<int, vector<int>>& mp, const int c, const int desired) {
    map<int, vector<int>>::const_iterator it = mp.find(c);
    const vector<int> space = it->second;
    int lo = -1, hi = static_cast<int>(space.size());
    while (hi - lo > 1) {
        int mi = lo + (hi - lo) / 2;
        if (desired < space[mi]) hi = mi;
        else lo = mi;
    }
    return lo;
}
int main() {
    cin >> N;
    for (int i = 1, x, y; i <= N; i++) {
        cin >> x >> y; p.emplace_back(x, y);
        mpX[x].push_back(y); mpY[y].push_back(x);
    }
    // sort all vectors to prepare for binary search (mono increasing func)
    for (map<int, vector<int>>::iterator it = mpX.begin(); it != mpX.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
    for (map<int, vector<int>>::iterator it = mpY.begin(); it != mpY.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
    long long ans = 0;
    // process each point
    for (vector<pi>::iterator coor = p.begin(); coor != p.end(); coor++) { // vector is a whole container, iterator is like a pointer
        int x = coor->first, y = coor->second;
        int xIdx = BS(mpX, x, y), yIdx = BS(mpY, y, x);
        int lft = xIdx, rit = mpX[x].size() - xIdx - 1;
        int top = yIdx, btm = mpY[y].size() - yIdx - 1;
        ans += 2LL * lft * rit * top * btm;
    }
    cout << ans << endl;
}
