// Beta Round 5 C. Longest Regular Bracket Sequence (Codeforces): https://codeforces.com/contest/5/problem/C
// ANNOTATED CODE - https://codeforces.com/contest/5/submission/315049850
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
string s; int c[MM], d[MM], mx=0, cnt=0; stack<int> pos;
// update c[i], d[i] pos only for closing bracket. c[i] is corresponding open bracket pos (or -1). d[i] is the earliest corresponding open bracket to make it a valid sequence (or -1)
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') { pos.push(i); c[i] = -1; d[i] = -1; } // stack contains all ('s positions
        else{
            if(pos.empty()){ c[i] = -1; d[i] = -1; } // there is no corresponding open bracket
            else{
                c[i] = pos.top(); pos.pop(); // stack logic shows that )'s corresponding bracket is the stack top
                d[i] = c[i]; // this has to be true
                if(d[i]-1 >= 0 && d[d[i]-1] != -1) d[i] = d[d[i]-1]; // if we can find a better answer to the left
                // i-d[i]+1 is the SIZE of the sequence
                if((i-d[i]+1) > mx){ mx = (i-d[i]+1); cnt = 1; }
                else if((i-d[i]+1) == mx) cnt++;
            }
        }
    }
    if(mx == 0) cout << "0 1" << endl; // no valid sequence
    else cout << mx << " " << cnt << endl;
}
