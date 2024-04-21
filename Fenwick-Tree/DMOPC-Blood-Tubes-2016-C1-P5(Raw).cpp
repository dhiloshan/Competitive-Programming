// RAW Code - https://dmoj.ca/src/6356403
// Blood Tubes '16 Contest 1 Problem 5 (DMOPC) - https://dmoj.ca/problem/dmopc16c1p5
#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+3;
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
int N; ll bit[MM], ans;
void update(int pos, int val){
    for(int i = pos; i < MM; i+=(i&-i)) bit[i] += val;
}
ll query(int pos){
    ll ans = 0;
    for(int i = pos; i > 0; i-=(i&-i)) ans += bit[i];
    return ans;
}
int main(){
    cin >> N;
    for(int i = 0, x; i < N; i++){
        cin >> x;
        int lft = query(x), rit = i - lft;
        ans += min(lft, rit); update(x, 1);
    }
    cout << ans << endl;
}
