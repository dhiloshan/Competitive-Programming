// CCC '03 S4 - Substrings (DMOJ): https://dmoj.ca/problem/ccc03s4
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = (int)5e3+5;
typedef long long ll;
int N;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        vector<string> order;
        string cur(1, s[s.size()-1]);
        for (int i = s.size()-2; i >= 0; i--) {
            order.push_back(cur);
            cur = s[i] + cur;
        }order.push_back(cur);
        sort(order.begin(), order.end());
        int lcp = 0;
        for (int i = 1; i < order.size(); i++) {
            string u = order[i-1], v = order[i];
            int len = 0;
            for (int j = 0; j < min(u.size(), v.size()); j++) {
                if (u[j] == v[j]) len++;
                else break;
            }
            lcp += len;
        }
        cout << ((s.size() * (s.size()+1))/2) - lcp  + 1<< endl;
    }
}
 
