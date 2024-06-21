// DMOPC '14 Contest 2 P6 - Selective Cutting (DMOJ): https://dmoj.ca/problem/dmopc14c2p6
// RAW CODE - https://dmoj.ca/src/6335065
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef long long ll;
typedef pair<int, int> pi;
#define f first
#define s second
struct qry {
    int l, r, q, id;
    bool operator<(const qry &y) const {return q < y.q;}
};
int N, Q; ll bit[MM], ans[MM]; pi a[MM]; vector<qry> queries;
void update(int pos, int val){
    for(int i = pos; i < MM; i += (i&-i)) bit[i] += val;
}
ll query(int pos){
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
        queries.push_back({l+1, r+1, q, i});
    }
    sort(a+1, a+N+1);
    sort(begin(queries), end(queries));
    int j = 1;
    for(auto& [l, r, q, id] : queries){
        while(a[j].f < q && j <= N){
            update(a[j].s, a[j].f * -1); j++;
        }
        ans[id] = query(r) - query(l-1);
    }
    for(int i = 1; i <= Q; i++){
        cout << ans[i] << endl;
    }
}
