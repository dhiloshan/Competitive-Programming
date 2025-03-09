// USACO 2018 January Contest, Bronze Problem 2. Lifeguards (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=784
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int N, mx; vector<pi> t;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ifstream cin("lifeguards.in");
    // ofstream cout("lifeguards.out");
    cin >> N;
    for(int i = 0, a, b; i < N; i++){
        cin >> a >> b;
        t.emplace_back(a, b);
    }
    sort(t.begin(), t.end());
    for(int i = 0; i < N; i++){
        vector<pi> temp;
        for(int j = 0; j < N; j++){
            if(j != i) temp.push_back(t[j]);
        }
        int cur = 0, L = temp[0].first, R = temp[0].second;
        for(auto it  = temp.begin()+1; it != temp.end(); it++){
            auto& [l, r] = *it;
            if(l < R){ t
                R = max(r, R);
            }
            else{
                cur += (R-L);
                L = l; R = r;
            }
        }
        cur += (R-L);
        mx = max(cur, mx);
    }
    cout << mx << endl;
}
