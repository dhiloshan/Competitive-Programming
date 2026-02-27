// CCC '26 S2 - Beams of Light (DMOJ): https://dmoj.ca/problem/ccc26s2
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
int L, N, Q;
int main() {
    cin >> N >> L >> Q;
    vector<int> dif(N+2, 0); // define the difference array

    // take input; static range updates
    for (int i = 1, p, s; i <= L; i++) {
        cin >> p >> s;
        dif[max(1, p-s)]++; dif[min(N, p+s)+1]--;
    }

    // compute prefix sums from left to right
    for (int i = 1; i <= N; i++) {
        dif[i] += dif[i-1];
    }

    // answer the queries
    for (int i = 1, q; i <= Q; i++) {
        cin >> q;
        if (dif[q] >= 1)
            cout << 'Y' << endl;
        else
            cout << 'N' << endl;
    }
}
