// ANNOTATED VERSION - https://dmoj.ca/src/6335062 (refer to dr. henri lab DMOPC, similar)
// Selective Cutting '14 Contest 2 Problem 6 (DMOPC) - https://dmoj.ca/problem/dmopc14c2p6
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef long long ll;
typedef pair<int, int> pi;
#define f first
#define s second
struct qry {
    int l, r, q, id;
    bool operator<(const qry &y) const {return q < y.q;} // boolean operator to sort by q in ascending order
};
int N, Q; ll bit[MM], ans[MM]; pi a[MM]; vector<qry> queries; // a is for what numbers to make 0, changing them as we read through offline queries
void update(int pos, int val){ // BIT log N update
    for(int i = pos; i < MM; i += (i&-i)) bit[i] += val;
}
ll query(int pos){ // BIT log N query (using long long as this function tends to overflow
    ll sum = 0;
    for(int i = pos; i > 0; i -= (i&-i)) sum += bit[i];
    return sum;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1, x; i <= N; i++){
        cin >> x; update(i, x); a[i] = {x, i};
    }
    cin >> Q;
    for(int i = 1, l, r, q; i <= Q; i++){
        cin >> l >> r >> q;
        queries.push_back({l+1, r+1, q, i}); // numbers l and r are 0-indexed, add 1 to make them 1-indexed
    }
    sort(a+1, a+N+1); // sort a by the first number from index 1 to N
    sort(begin(queries), end(queries)); // sort queries vector according to boolean operator in line 10

    int j = 1; // index used to traverse array called a
    for(auto& [l, r, q, id] : queries){ // convenient to use auto&
        while(a[j].f < q && j <= N){ // while the current value is less than q and j is less than max (last index is N)
            update(a[j].s, a[j].f * -1); j++; // update index a[j].second by subtracting a[j].first
        }
        ans[id] = query(r) - query(l-1); // BIT subarray [L, R] sum query (all numbers less than q are just 0
    }
    for(int i = 1; i <= Q; i++){ // go through the answers for the offline queries and output them
        cout << ans[i] << endl;
    }
}
