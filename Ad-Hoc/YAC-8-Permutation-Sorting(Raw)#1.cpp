// SOLUTION #1: generate up to N intervals and then merge them O(NlogN)
// Yet Another Contest 8 P1 - Permutation Sorting (DMOJ): https://dmoj.ca/problem/yac8p1
// RAW CODE - https://dmoj.ca/src/6737549
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e6+2;
int N, a[MM], idx[MM], ans; vector<pi> rng;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        idx[a[i]] = i;
    }
    for(int i = 1; i <= N; i++){
        if(a[i] != i) {
            int mi = min(i, idx[i]), mx = max(i, idx[i]);
            rng.emplace_back(mi, mx);
        }
    }
    if(!rng.empty()){
        sort(rng.begin(), rng.end());
        int L = rng[0].first, R = rng[0].second;
        for(auto it = rng.begin()+1; it != rng.end(); ++it){
            auto [l, r] = *it;
            if(l <= R) {
                R = max(r, R);
            }
            else {
                ans += (R - L + 1);
                L = l;
                R = r;
            }
        }
        ans += (R - L + 1);
    }
    cout << ans << endl;
}
