// D1. Magic Powder - 1 (Codeforces): https://codeforces.com/problemset/problem/670/D1
// RAW CODE
// Naive Approach #2 (Can transition to binary search from here)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e6+3;
int N, K, a[MM], b[MM], q[MM];
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];
    int ans = 0, req = 0; 
    while (true) {
        for (int i = 1; i <= N; i++) {
            if (b[i] >= a[i]) b[i] -= a[i];
            else {
                req += (a[i] - b[i]);
                b[i] = 0;
            }
        }
        if (req <= K) {
            K -= req; ans++;
        }
        else break;
        req = 0;
    }
    cout << ans << endl;
}
