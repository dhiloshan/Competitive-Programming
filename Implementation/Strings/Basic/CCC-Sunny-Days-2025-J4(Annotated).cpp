// CCC '25 J4 - Sunny Days (DMOJ): https://dmoj.ca/problem/ccc25j4 - https://dmoj.ca/problem/ccc25j4
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef pair<int, int> pi;
int N, mx; string s; vector<pi> rng;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; s.resize(N);
    bool flag = false; // clever bool to check for new range
    for(int i = 0; i < N; i++){
        cin >> s[i];
        if(s[i] == 'S'){
            if(!flag){
                rng.emplace_back(i, i); flag = true;
            }
        }
        else{ // 'P'
            flag = false;
            if(!rng.empty() && (i > 0 && s[i-1] == 'S')) rng.back().second = i-1;
        }
    }
    if(flag) rng.back().second = N-1;
    for(int i = 0; i < rng.size(); i++){
        auto [l, r] = rng[i];
        int lft = r-l+2, rit = lft; // we add 2 instead of 1 because we can change at most one character on the left or right of the range
        if(i > 0 && rng[i-1].second + 2 == l){ // if there is another range on the LEFT side that is one letter P away from our range
            lft += rng[i-1].second - rng[i-1].first + 1;
        }
        if(i < rng.size()-1 && rng[i+1].first - 2 == r){ // same thing but for the RIGHT side
            rit += rng[i+1].second - rng[i+1].first + 1;
        }
        mx = max(mx, max(lft, rit));
    }
    // CAREFUL of edge cases (problem statement): Unfortunately, the data is incorrect for exactly ONE day, but Jeremy doesn't know which day this is.
    if(mx > N) cout << N-1 << endl; // what if the whole string is S? then one of them has to be P. we do mx > N because in line 27 we add by 2 assuming there is at least 1 P. so mx will be N+1. if one of the character is P, answer is N-1;
    else if(mx == 0) cout << 1 << endl; // what if the whole string is P? one of the characters must be S, so it is not 0, it is 1
    else cout << mx << endl; // combination of P's and S's
}
