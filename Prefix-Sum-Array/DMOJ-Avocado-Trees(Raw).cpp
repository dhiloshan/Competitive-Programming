// Avocado Trees! (DMOJ): https://dmoj.ca/problem/avocadotrees
// RAW CODE - https://dmoj.ca/src/6454256
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, Q, H, h[MM], v[MM], psa[MM], mx;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q >> H;
    for(int i = 1, a, b; i <= N; i++){
        cin >> a >> b;
        h[i] = a; v[i] = b;
    }

    psa[1] = (h[1] > H)? 0 : v[1];
    for(int i = 2; i <= N; i++){
        psa[i] = (h[i] > H)? psa[i-1] : psa[i-1] + v[i];
    }

    for(int i = 1, l, r; i <= Q; i++){
        cin >> l >> r;
        mx = max(mx, psa[r] - psa[l-1]);
    }
    cout << mx << endl;
}
