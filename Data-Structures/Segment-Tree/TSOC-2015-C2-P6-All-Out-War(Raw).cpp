// TSOC '15 Contest 2 #6 - All-Out War! (DMOJ)
// RAW CODE lazy propagation classic q
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
typedef long long ll;
int N, Q;
ll val[4 * MM], lz[4 * MM], a[MM];
void build(int l, int r, int idx) {
    if (l == r) {
        val[idx] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, 2 * idx);
    build(m + 1, r, 2 * idx + 1);
    val[idx] = min(val[2 * idx], val[2 * idx + 1]);
}

void push_down(int idx) {
    if (lz[idx] != 0) {
        lz[2 * idx] += lz[idx];
        val[2 * idx] -= lz[idx];
    
        lz[2 * idx + 1] += lz[idx];
        val[2 * idx + 1] -= lz[idx];
        
        lz[idx] = 0; 
    }
}

void update(int l, int r, int x, int y, int z, int idx) {
    if (l == x && r == y) {
        val[idx] -= z;
        lz[idx] += z;
        return;
    }
    push_down(idx);
    int m = (l + r) / 2;
    if (y <= m) {
        update(l, m, x, y, z, 2 * idx);
    } else if (x > m) {
        update(m + 1, r, x, y, z, 2 * idx + 1);
    } else {
        update(l, m, x, m, z, 2 * idx);
        update(m + 1, r, m + 1, y, z, 2 * idx + 1);
    }
    val[idx] = min(val[2 * idx], val[2 * idx + 1]);
}

ll query(int l, int r, int x, int y, int idx) {
    if (l == x && r == y) {
        return val[idx];
    }
    push_down(idx);
    int m = (l + r) / 2;
    if (y <= m) return query(l, m, x, y, 2 * idx);
    if (x > m) return query(m + 1, r, x, y, 2 * idx + 1);
    return min(query(l, m, x, m, 2 * idx), query(m + 1, r, m + 1, y, 2 * idx + 1));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
  
    build(1, N, 1);
    
    for (int i = 0; i < Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        update(1, N, a, b, c, 1);
        
        ll range_min = query(1, N, a, b, 1);
        ll total_min = val[1];
        cout << max(0LL, range_min) << " " << max(0LL, total_min) << "\n";
    }
}
