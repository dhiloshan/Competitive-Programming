// CCC '15 S2 - Jerseys (DMOJ): https://dmoj.ca/problem/ccc15s2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 3003;
const int mod = (int)1e9+7;
typedef long long ll;
typedef pair<int, char> pi;
int J, A; unordered_map<int, char> have;
int main() {
    cin >> J >> A;
    for (int i = 1; i <= J; i++) {
        char c; cin >> c;
        have[i] = c;
    }
    int total = 0;
    for (int i = 1; i <= A; i++) {
        char c; int n; cin >> c >> n;
        if (have.find(n) != have.end()) { // the jersey exists
            char cur = have[n];
            if ((c == 'S' && (cur == 'S' || cur == 'M' || cur == 'L'))
                || (c == 'M' && (cur == 'M' || cur == 'L'))
                || (c == 'L' && cur == 'L')) {
                total++; have.erase(n);
            }
        }
    }
    cout << total << endl;
}
