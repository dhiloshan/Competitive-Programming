// CCC '22 S2 - Good Groups (DMOJ): https://dmoj.ca/problem/ccc22s2
// RAW CODE - https://dmoj.ca/src/6929367
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int X, Y, G, ans; string a, b, c; unordered_map<string, vector<string>> ppl; vector<pair<string, string>> x, y;
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> X;
    for(int i = 0; i < X; i++) {
        cin >> a >> b; x.emplace_back(a, b);
    }
    cin >> Y;
    for(int i = 0; i < Y; i++){
        cin >> a >> b; y.emplace_back(a, b);
    }
    cin >> G;
    for(int i = 0; i < G; i++){
        cin >> a >> b >> c;
        ppl[a].push_back(b); ppl[a].push_back(c);
        ppl[b].push_back(a); ppl[b].push_back(c);
        ppl[c].push_back(a); ppl[c].push_back(b);
    }
    for(auto [s1, s2] : x){
        if(ppl[s1][0] != s2 && ppl[s1][1] != s2) ans++;
    }
    for(auto [s1, s2] : y){
        if(ppl[s1][0] == s2 || ppl[s1][1] == s2) ans++;
    }
    cout << ans << endl;
}
