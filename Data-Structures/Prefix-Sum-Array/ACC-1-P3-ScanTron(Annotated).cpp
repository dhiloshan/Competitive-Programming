// Arcadia Computing Contest 1 P3 - ScanTron (DMOJ): https://dmoj.ca/problem/ahscc1p3
// ANNOTATED CODE
// for each i, sum the number of matching positions in the left subarray and right subarray
// optimize using a prefix sum array on the left half and suffix array on the right half
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
typedef long long ll;
string s, t; int N; ll psa[MM], suf[MM];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> s >> t;
    // build psa: psa[i] defines the # of characters from 0 to i in s that match 0 to i in t
    for (int i = 0; i < N-1; i++) {
        if (s[i] == t[i])
            psa[i]++;
        if (i > 0) psa[i] += psa[i-1];
    }
    // build suffix array: suf[i] defines the number of characters from i to the end of s that match with i-1 to the end of t
    for (int i = N-1; i >= 1; i--) {
        if (s[i] == t[i-1])
            suf[i]++;
        suf[i] += suf[i+1];
    }
    int mx = 0;
    for (int i = 0; i < N; i++) { // assume he skipped the ith question
        int score = 0;
        if (i > 0) // check for i > 0 for psa since psa[-1] is invalid
            score += psa[i-1];
        score += suf[i+1];
        mx = max(mx, score);
    }
    cout << mx << endl;
}
