// CCC '25 J4 - Sunny Days (DMOJ): https://dmoj.ca/problem/ccc25j4
// RAW CODE - https://dmoj.ca/src/7074827
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef pair<int, int> pi;
int N, mx; string s; vector<pi> rng;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; s.resize(N);
    bool flag = false;
    for(int i = 0; i < N; i++){
        cin >> s[i];
        if(s[i] == 'S'){
            if(!flag){
                rng.emplace_back(i, i); flag = true;
            }
        }
        else{
            flag = false;
            if(!rng.empty() && (i > 0 && s[i-1] == 'S')) rng.back().second = i-1;
        }
    }
    if(flag) rng.back().second = N-1;
    for(int i = 0; i < rng.size(); i++){
        auto [l, r] = rng[i];
        int lft = r-l+2, rit = lft;
        if(i > 0 && rng[i-1].second + 2 == l){
            lft += rng[i-1].second - rng[i-1].first + 1;
        }
        if(i < rng.size()-1 && rng[i+1].first - 2 == r){
            rit += rng[i+1].second - rng[i+1].first + 1;
        }
        mx = max(mx, max(lft, rit));
    }
    if(mx > N) cout << N-1 << endl;
    else if(mx == 0) cout << 1 << endl;
    else cout << mx << endl;
}
