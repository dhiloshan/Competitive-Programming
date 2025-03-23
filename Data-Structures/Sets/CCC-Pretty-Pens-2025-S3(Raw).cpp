// CCC '25 S3 - Pretty Pens (DMOJ): https://dmoj.ca/problem/ccc25s3
// RAW CODE - https://dmoj.ca/src/7077375
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
typedef long long ll;
int N, M, Q, c[MM], p[MM]; multiset<int, greater<int>> col[MM], mx2; multiset<int> mx; ll sum;
inline ll getans() {
    if(mx2.empty() || *mx2.begin() <= *mx.begin()) return sum;
    return sum - *mx.begin() + *mx2.begin();
}
void rem(int x){ 
    mx.erase(mx.find(*col[x].begin())); sum -= *col[x].begin();
    if(col[x].size() > 1) mx2.erase(mx2.find(*next(col[x].begin())));
}
void add(int x){
    mx.insert(*col[x].begin()); sum += *col[x].begin();
    if(col[x].size() > 1) mx2.insert(*next(col[x].begin()));
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++){
        cin >> c[i] >> p[i];
        col[c[i]].insert(p[i]);
    }
    for(int i = 1; i <= M; i++){ 
        mx.insert(*col[i].begin()); sum += *col[i].begin();
        if(col[i].size() > 1) mx2.insert(*next(col[i].begin())); 
    }
    cout << getans() << "\n";
    for(int i = 1, op, k, x; i <= Q; i++){
        cin >> op >> k >> x;
        if(op == 1){
            rem(c[k]); rem(x); col[c[k]].erase(col[c[k]].find(p[k]));
            int old = c[k]; c[k] = x; col[c[k]].insert(p[k]);
            add(old); add(x);
        }
        else{
            rem(c[k]); col[c[k]].erase(col[c[k]].find(p[k]));
            p[k] = x; col[c[k]].insert(p[k]); 
            add(c[k]);
        }
        cout << getans() << "\n";
    }
}
