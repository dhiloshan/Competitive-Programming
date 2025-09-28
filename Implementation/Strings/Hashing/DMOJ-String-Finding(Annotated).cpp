// String Finding (DMOJ): https://dmoj.ca/problem/bf4
// ANNOTATED CODE: finding first occurrence of string t in s in O(|S|) linear time
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+3;
const int MOD = 1e9+7;
const int SEED = 1e5+7;
string a, b; ll hashA[MM], hashB, pw[MM];
ll subHash(int L, int R){
    return (hashA[R]-hashA[L-1]*pw[R-L+1]%MOD+MOD)%MOD;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    pw[0] = 1;
    for(int i = 1; i <= a.size(); i++) hashA[i] = (hashA[i-1] * SEED % MOD + a[i-1]) % MOD; // 1-indexed
    for(int j = 0; j < b.size(); j++) hashB = (hashB * SEED % MOD + b[j]) % MOD; // no need for array for the second string
    for(int k = 1; k <= a.size(); k++) pw[k] = pw[k-1] * SEED % MOD;
    for(int i = 1; i <= a.size()-b.size()+1; i++){ // i represents the left index of the sliding window
        ll curHash = subHash(i, i+b.size()-1); // sliding window current hash
        if(curHash == hashB){
            cout << i-1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
