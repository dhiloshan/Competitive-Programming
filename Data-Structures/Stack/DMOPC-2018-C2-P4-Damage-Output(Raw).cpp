// DMOPC '18 Contest 2 P4 - Damage Output (DMOJ): https://dmoj.ca/problem/dmopc18c2p4
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 6e5+3;
string s; int cnt = 0; stack<char> stk;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    for(char c : s){
        if(!stk.empty() && c == ')' && stk.top() == '(') stk.pop();
        else stk.push(c);
    }
    if(stk.empty()) cout << "YES" << endl;
    else if(stk.size() >= 3 || stk.size() == 1) cout << "NO" << endl;
    else{
        char tp = stk.top(); stk.pop();
        char bt = stk.top(); stk.pop();
        if((bt == ')' && tp == ')') || (bt == '(' && tp == '(')) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
