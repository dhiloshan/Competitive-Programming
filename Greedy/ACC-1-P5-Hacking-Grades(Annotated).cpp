// Arcadia Computing Contest 1 P5 - Hacking Grades (DMOJ): https://dmoj.ca/problem/ahscc1p5
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
const int MOD = 1e9+7;
typedef pair<int, int> pi;
typedef long long ll;
struct e {
    int n, d, idx;
    bool operator<(const e &y) const {
        long double curVal = (long double)(n+1)/(d+1) - (long double)n/d;
        long double newVal = (long double)(y.n+1)/(y.d+1) - (long double)y.n/y.d;
        return curVal < newVal;
    }
};
int N, K, numer[MM], denom[MM]; pi ori[MM]; priority_queue<e> q;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> numer[i];
    for (int i = 1; i <= N; i++) cin >> denom[i];
    for (int i = 1; i <= N; i++) {
        int n = numer[i], d = denom[i];
        ori[i] = {n, d};
        if (n < d) // fraction is not equal to 1
            q.push({n, d, i});
    }
    while (!q.empty() && K > 0) {
        auto [n, d, idx] = q.top(); q.pop();
        ori[idx] = {++n, ++d};
        if (n < d)
            q.push({n, d, idx});
        K--;
    }
    double total = 0;
    for (int i = 1; i <= N; i++) {
        total += (((long double)ori[i].first/ori[i].second)*100);
    }
    printf("%.9f\n", total/N);
}
/*
    maximize the sum of all numbers -> maximize the increase of a number each step locally: greedy
    put all fractions in a set alongside the yield if they apply the transformation. the set is sorted according to this yield
    while K > 0, take out the fraction with the biggest yield, update the value in the vector, and then insert the new fraction with new yield
 */
