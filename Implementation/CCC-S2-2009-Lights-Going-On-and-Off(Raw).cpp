// CCC '09 S2 - Lights Going On and Off (DMOJ): https://dmoj.ca/problem/ccc09s2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 30;
const int mod = (int)1e9+7;
typedef long long ll;
typedef pair<int, char> pi;
int R, L; vector<int> nums;
int main() {
    cin >> R >> L;
    for (int i = 1; i <= R; i++) {
        int num = 0;
        for (int k = L-1, b; k >= 0; k--) {
            cin >> b; num += b<<k;
        }
        nums.push_back(num);
    }
    vector<unordered_set<int> > possible(R);
    possible[0].insert(nums[0]);
    for (int i = 1; i < R; i++) {
        possible[i].insert(nums[i]);
        for (int prev : possible[i-1]) {
            possible[i].insert(nums[i] ^ prev);
        }
    }
    cout << possible[R-1].size() << endl;

}
