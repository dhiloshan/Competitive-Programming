// A. Cycles (Codeforces): https://codeforces.com/contest/232/problem/A
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 102;
int N, K, p, a[MM][MM];
inline int C(int n, int k) {
    ll ans = 1;
    for (int i = 0; i < k; i++) ans *= (n-i);
    int demon = 1;
    for (int i = 2; i <= k; i++) demon *= i;
    return ans / demon;
}
void findMinP() {
    // binary search min k
    // p choose 3 < k -> T T T T ... T F F F
    // find last true
    int lo = 3, hi = 100; // lo is lower bound, hi is upper bound
    while (lo + 1 != hi) {
        int m = lo + (hi - lo) / 2;
        if (C(m, 3) <= K) lo = m;
        else hi = m;
    }
    p = lo;
}
int main() {
    cin >> K;
    findMinP();
    // fill in complete graph with p vertices
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) {
            if (i != j)
                a[i][j] = 1;
        }
    }
    // add additional node attachments
    int rem = K - C(p, 3);
    int nodeCur = p;
    while (rem > 0) {
        nodeCur++;
        // u choose 2 < rem. binary search for u
        // for the sake of practicing binary search i will write it out again (but u should just replace findMinP)
        int lo = 2, hi = p; // # of nodes to attach itself to
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (C(mid, 2) <= rem) lo = mid;
            else hi = mid;
        }
        int u = lo;
        for (int i = 1; i <= u; i++) { // u vertices
            a[i][nodeCur] = 1; a[nodeCur][i] = 1;
        }
        rem -= C(u, 2);
    }
    // output
    cout << nodeCur << endl;
    for (int i = 1; i <= nodeCur; i++) {
        for (int j = 1; j <= nodeCur; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }

}

