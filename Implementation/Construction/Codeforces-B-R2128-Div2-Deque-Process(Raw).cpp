// B. Deque Process (Codeforces): https://codeforces.com/contest/2128/problem/b
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int T;
void solve(){
    int N; cin >> N;
    deque<int> p;
    for(int i = 0; i < N; i++){
        int x; cin >> x; p.push_back(x);
    }
    string good;
    if(p[0] < p[N-1]) {
        good += 'R'; p.pop_back();
    }
    else{
        good += 'L'; p.pop_front();
    }
    bool makeLess = true;
    while(!p.empty()){
        if(p.size() == 1){
            good += "L"; break;
        }
        int lft = p.front(), rit = p.back();
        if(makeLess){
            if(lft > rit){
                good += "LR";
            }
            else{
                good += "RL";
            }
        }
        else{
            if(lft > rit){
                good += "RL";
            }
            else{
                good += "LR";
            }
        }
        p.pop_front(); p.pop_back();
        makeLess = !makeLess;
    }
    cout << good << endl;
}
int main(){
    for(cin >> T; T--;) solve();
}
