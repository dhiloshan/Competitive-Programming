// MNYC '17: Hurontario
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+3;
const int MOD = 1e9+7;
const int SEED = 1e5+7;
string a, b; ll hshA[MM], hshB[MM], pw[MM];
ll subHash(ll hsh[], int L, int R){
    return (hsh[R]-hsh[L-1]*pw[R-L+1]%MOD+MOD)%MOD;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    pw[0] = 1;
    // hash arrays are 1 indexed
    for(int i = 1; i <= a.size(); i++) hshA[i] = (hshA[i-1] * SEED % MOD + a[i-1]) % MOD;
    for(int i = 1; i <= b.size(); i++) hshB[i] = (hshB[i-1] * SEED % MOD + b[i-1]) % MOD;
    for(int i = 1; i <= max(a.size(), b.size()); i++) pw[i] = pw[i-1] * SEED % MOD;

    for(int len = min(a.size(), b.size()); len >= 0; len--){ // optimize substring comparison in O(1) time using string hashes
        ll hash1 = subHash(hshA, a.size()-len+1, a.size());
        ll hash2 = subHash(hshB, 1, len);
        if(hash1 == hash2){ // check if the two hashes are the same <-> check if the two strings are the same
            cout << a << b.substr(len) << endl; // starting from index len til the end
            return 0;
        }
    }

    cout << a << b << endl;
}
