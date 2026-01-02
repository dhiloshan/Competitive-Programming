// C. Another Problem on Strings (Codeforces): https://codeforces.com/problemset/problem/165/C
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
typedef long long ll;
int K, psa[MM]; string s; ll ans;
int main() {
    cin >> K >> s;
    for (int i = 1; i <= s.length(); i++) {
        if (s[i-1] == '1') {
            psa[i]++;
        }
        psa[i] += psa[i-1]; // build psa
    }
    // psa[r] - psa[l-1] is the # of 1's in a range. psa is used to optimize queries
    for (int i = 1; i <= s.length(); i++) {
        /*
        for (int j = i; j <= s.length(); j++) { linear search costs O(N). naive soln
        }
        */
        // find lower bound
        int lo = i-1, hi = s.length()+1;
        while (hi - lo > 1) {
            int mi = lo + (hi - lo) / 2;
            int numOfOnes = psa[mi] - psa[i-1];
            if (numOfOnes >= K) hi = mi;
            else lo = mi;
        }
        int lb = hi;
        if (hi != s.length()+1) { // find upper bound
            lo = i-1; hi = s.length()+1;
            while (hi - lo > 1) {
                int mi = lo + (hi - lo) / 2;
                int numOfOnes = psa[mi] - psa[i-1];
                if (numOfOnes > K) hi = mi;
                else lo = mi;
            }
            int ub = hi;
            ans += ub - lb;
        }


    }
    cout << ans << endl;
}
