// RAW CODE - https://dmoj.ca/src/6342254
// CCC '05 S5 - Pinball Ranking (DMOJ) - https://dmoj.ca/problem/ccc05s5
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
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
int N, a[MM], idx; ll bit[MM], inv; map<int, int> mp;
void update(int pos, int val){
    for(int i = pos; i < MM; i+=(i&-i)) bit[i] += val;
}
ll query(int pos){
    ll sum = 0;
    for(int i = pos; i > 0; i -= (i&-i)) sum += bit[i];
    return sum;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i]; mp[a[i]] = 0;
    }
    for(auto& e : mp) e.second = ++idx;
    for(int i = 1; i <= N; i++){
        inv += i - query(mp[a[i]]);
        update(mp[a[i]], 1);
    }
    cout << fixed << setprecision(8) << (double)inv / N << endl;
}
