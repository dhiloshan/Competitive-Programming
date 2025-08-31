// USACO 2023 February Contest, Silver Problem 2. Cow-libi (Olympiads School Only): https://dmoj.ca/problem/usaco23febs2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
struct pos { int x, y, t; };
int G, N, ans; vector<pos> g;
bool inno(int x1, int y1, int t1, int x2, int y2, int t2){
    long long dx = 1LL * x2 - x1, dy = 1LL * y2 - y1, dt = llabs(1LL * t2 - t1);
    long long lhs = dx * dx + dy * dy, rhs = dt * dt;
    return lhs > rhs;
}
int main(){
    cin >> G >> N;
    for(int i = 0, x, y, t; i < G; i++){
        cin >> x >> y >> t; g.push_back({x, y, t});
    }
    sort(g.begin(), g.end(), [](const auto& x, const auto &y) {
        return x.t < y.t;
    });
    for(int i = 0; i < N; i++){
        pos cow; cin >> cow.x >> cow.y >> cow.t;
        int idx = lower_bound(g.begin(), g.end(), cow.t, [](const pos &a, int t) -> bool {
            return a.t < t;
        }) - g.begin();
        if((idx == G && inno(cow.x, cow.y, cow. t, g[G-1].x, g[G-1].y, g[G-1].t))
           || (idx == 0 && inno(g[0].x, g[0].y, g[0].t, cow.x, cow.y, cow.t))
           || (g[idx].t == cow.t &&  (cow.x != g[idx].x || cow.y != g[idx].y))
           || (idx != G && idx != 0 && (inno(g[idx-1].x, g[idx-1].y, g[idx-1].t, cow.x, cow.y, cow.t) || inno(cow.x, cow.y, cow.t, g[idx].x, g[idx].y, g[idx].t))))
            ans++;
    }
    cout << ans << endl;
}
