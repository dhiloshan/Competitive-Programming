// CCC '25 S2 - Cryptogram Cracking Club (DMOJ): https://dmoj.ca/problem/ccc25s2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
typedef long long ll;
string s; queue<pair<char, ll> > q; ll C, total;
int main(){
    cin >> s >> C;
    int wi = 0;
    while(wi < s.size()){
        if(97 <= int(s[wi]) && int(s[wi]) <= 122){
            char cur = s[wi]; ll num = 0; wi++;
            while(48 <= int(s[wi]) && int(s[wi]) <= 57){
                num = (num * 10 + (s[wi] - '0')); wi++;
            }
            q.push({cur, num}); total += num;
        }
    }
    C %= total;
    while(!q.empty()){
        auto [letter, len] = q.front(); q.pop();
        C -= len;
        if(C < 0){
            cout << letter << endl;
            return 0;
        }
    }
}
