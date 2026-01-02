// B. Interesting drink (Codeforces): https://codeforces.com/problemset/problem/706/B/
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+3;
int N, Q, a[MM];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    sort(a+1, a+N+1);
    cin >> Q;
    for (int i = 1, k; i <= Q; i++){
        cin >> k;
        // binary search. the final answer is lo
        int lo = 0, hi = N+1;
        while (hi - lo > 1) {
            int mi = lo + (hi-lo)/2;
            if (a[mi] <= k) lo = mi;
            else hi = mi;
        }
        cout << lo << endl;
    }
}
