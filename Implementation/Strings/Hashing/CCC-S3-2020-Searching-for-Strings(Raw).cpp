// CCC '20 S3 - Searching for Strings (DMOJ): https://dmoj.ca/problem/ccc20s3
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5, base = 131, base2 = 10007, mod = 1e9+7;
typedef long long ll;
ll hsh[MM], pw[MM], hsh2[MM], pw2[MM]; string s, t; unordered_set<ll> st;

ll getSubHash(int l, int r){
    ll v1 = (hsh[r] - hsh[l-1]*pw[r-l+1]%mod + mod)%mod;
    ll v2 = (hsh2[r] - hsh2[l-1]*pw2[r-l+1]%mod + mod)%mod;
    return (v1 << 31) | v2;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;  vector<int> fs(26), ft(26);
    int n = s.size(), m = t.size();
    for(char c : s) fs[c - 'a']++;
    pw[0] = 1; pw2[0] = 1;
    
    for(int i=1; i<=m; i++) {
        pw[i] = pw[i-1] * base % mod;
        hsh[i] = (hsh[i-1] * base + t[i-1])%mod;
        pw2[i] = pw2[i-1] * base2 % mod;
        hsh2[i] = (hsh2[i-1] * base2 + t[i-1])%mod;
    }
    
    for(int i=1; i<=m; i++) {
        ft[t[i-1] - 'a']++;
        if(i > n) ft[t[i-n-1] - 'a']--;
        if(fs == ft) {
            st.insert(getSubHash(i-n+1, i));
        }
    }
    
    cout << st.size() << endl;
}
