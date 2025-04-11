// Beta Round 5 C. Longest Regular Bracket Sequence (Codeforces): https://codeforces.com/contest/5/problem/C
// RAW CODE - https://codeforces.com/contest/5/submission/315049980
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
string s; int c[MM], d[MM], mx=0, cnt=0; stack<int> pos;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') { pos.push(i); c[i] = -1; d[i] = -1; }
        else{
            if(pos.empty()){ c[i] = -1; d[i] = -1; }
            else{
                c[i] = pos.top(); pos.pop();
                d[i] = c[i];
                if(d[i]-1 >= 0 && d[d[i]-1] != -1) d[i] = d[d[i]-1];
                if((i-d[i]+1) > mx){ mx = (i-d[i]+1); cnt = 1; }
                else if((i-d[i]+1) == mx) cnt++;
            }
        }
    }
    if(mx == 0) cout << "0 1" << endl;
    else cout << mx << " " << cnt << endl;
}
