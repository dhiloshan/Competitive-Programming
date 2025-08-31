// USACO 2023 February Contest, Silver Problem 2. Cow-libi (Olympiads School Only): https://dmoj.ca/problem/usaco23febs2
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
struct pos { int x, y, t; };
int G, N, ans; vector<pos> g;
bool inno(int x1, int y1, int t1, int x2, int y2, int t2){ // derived from euclidean distance to check if it is impossible for a cow to travel from grazing i to i+1
    long long dx = 1LL * x2 - x1, dy = 1LL * y2 - y1, dt = llabs(1LL * t2 - t1); // multiply with 1LL to turn one part into long long which casts the entire thing into long long
    long long lhs = dx * dx + dy * dy, rhs = dt * dt;  // long long arithmetic since dx, dy, and dt are long long
    return lhs > rhs; // don't use pow as it turns its arguments to doubles and returns a double
}
int main(){
    cin >> G >> N;
    for(int i = 0, x, y, t; i < G; i++){ // for each grazing
        cin >> x >> y >> t; g.push_back({x, y, t});
    }
    // sorts grazing based on time in ascending order
    sort(g.begin(), g.end(), [](const auto& x, const auto &y) {
        return x.t < y.t;
    }); // operator< says for two elements x and y, should I put x BEFORE y. it will only do that IF the time of x is less than y
    for(int i = 0; i < N; i++){
        pos cow; cin >> cow.x >> cow.y >> cow.t;
        int idx = lower_bound(g.begin(), g.end(), cow.t, [](const pos &a, int t) -> bool {
            return a.t < t;
        }) - g.begin();
        if((idx == G && inno(cow.x, cow.y, cow. t, g[G-1].x, g[G-1].y, g[G-1].t)) // cow's alibi time is at the end
           || (idx == 0 && inno(g[0].x, g[0].y, g[0].t, cow.x, cow.y, cow.t)) // .... beginning
           || (g[idx].t == cow.t &&  (cow.x != g[idx].x || cow.y != g[idx].y)) // times match but positions are diff
           || (idx != G && idx != 0 && (inno(g[idx-1].x, g[idx-1].y, g[idx-1].t, cow.x, cow.y, cow.t) || inno(cow.x, cow.y, cow.t, g[idx].x, g[idx].y, g[idx].t)))) // .... in between
            ans++;
    }
    cout << ans << endl;
}
