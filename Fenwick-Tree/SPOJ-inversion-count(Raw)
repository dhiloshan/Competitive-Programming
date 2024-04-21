// RAW CODE (no submission link)
// INVCNT: Inversion Count (SPOJ) - https://www.spoj.com/problems/INVCNT/
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
const int mod = (int)1e9+7;
const int base = (int)1e8+7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mi;
typedef stack<int> si;
typedef queue<int> qi;
#define f first
#define s second
#define PB(x) push_back(x)
#define MEM(arr, x) memset(arr, x, sizeof(arr))
int T;
void update(int pos, int val, vector<ll>& bit){
    for(int i = pos; i < MM; i+=(i&-i)) bit[i] += val;
}
ll query(int pos, vector<ll>& bit){
    ll ans = 0;
    for(int i = pos; i > 0; i-=(i&-i)) ans += bit[i];
    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for(int i = T, N; i > 0; i--){
        cin >> N; vector<ll> bit(MM, 0); ll inv = 0; vector<int> a(MM, 0); map<int, int> mp;
        for(int j = 1; j <= N; j++){
            cin >> a[j]; mp[a[j]] = 0; // set the actual value
        }
        int idx = 0; 
        for(auto&e : mp) e.second = ++idx;
        for(int k = 1; k <= N; k++){
            inv += k - 1 - query(mp[a[k]], bit);
            update(mp[a[k]], 1,bit);
        }
        cout << inv << endl;
    }
}
