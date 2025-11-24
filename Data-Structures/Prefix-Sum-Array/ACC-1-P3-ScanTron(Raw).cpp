// Arcadia Computing Contest 1 P3 - ScanTron (DMOJ): https://dmoj.ca/problem/ahscc1p3
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
typedef long long ll;
string s, t; int N; ll psa[MM], suf[MM];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> s >> t;
    for (int i = 0; i < N-1; i++) {
        if (s[i] == t[i])
            psa[i]++;
        if (i > 0) psa[i] += psa[i-1];
    }
    for (int i = N-1; i >= 1; i--) {
        if (s[i] == t[i-1])
            suf[i]++;
        suf[i] += suf[i+1];
    }
    int mx = 0;
    for (int i = 0; i < N; i++) { 
        int score = 0;
        if (i > 0)
            score += psa[i-1];
        score += suf[i+1];
        mx = max(mx, score);
    }
    cout << mx << endl;
}
