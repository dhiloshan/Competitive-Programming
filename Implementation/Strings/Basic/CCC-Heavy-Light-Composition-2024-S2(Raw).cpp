// CCC '24 S2 - Heavy-Light Composition (DMOJ): https://dmoj.ca/problem/ccc24s2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 150;
int N, L;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> L;
    for(int i = 1; i <= N; i++){
        string s; cin >> s;
        int freq[MM]; memset(freq, 0, sizeof(freq));
        for(char c : s) { freq[c]++; }
        bool val[MM]; memset(val, false, MM);
        for(int i = 97; i <= 122; i++){
            if(freq[i] > 1) val[i] = true;
        }
        bool flag = true; bool cur = !val[s[0]];
        for(int i = 1; i < s.size(); i++){
            if(val[s[i]] != cur){
                flag = false; break;
            }
            cur = !cur;
        }
        cout << (flag? 'T' : 'F') << endl;
    }
}
