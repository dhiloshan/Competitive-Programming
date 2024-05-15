// CCC '05 S5 - Pinball Ranking (DMOJ) - https://dmoj.ca/problem/ccc05s5
// RAW CODE - https://dmoj.ca/src/6392246
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
int N, idx, a[MM]; ll bit[MM], inv; map<int, int> mp; // inv refers to total inversion
// idx refers to the rank for coordinate compression, N elements given rank from 1 to N
// mp is a sorted map used for coordinate compression, less efficient but easier to code bc I'm lazy
void update(int pos, int val){ // BIT log N update
    for(int i = pos; i < MM; i+=(i&-i)) bit[i] += val;
}
ll query(int pos){ // BIT log N query
    ll sum = 0;
    for(int i = pos; i > 0; i -=(i&-i)) sum += bit[i];
    return sum;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i]; mp[a[i]] = 0; // put the element in the map
    }
    for(auto& e : mp) e.s = ++idx; // give each element their virtual rank
                                                     // ++idx means add one to index then do e.s = idx
    for(int i = 1; i <= N; i++){
        inv += i - query(mp[a[i]]); // inversion counting formula (for 1 indexed you would do i - 1 - query(mp[a[i]])
                                        // BUT, notice how the question starts at 1 for the algorithm, not 0, so you don't need to subtract 1
        update(mp[a[i]], 1); // update the BIT array which is just a dynamic frequency array
    }
    cout << fixed << setprecision(3) << (double)inv / N << endl; // set precision is the number of zeros after decimal point
}
