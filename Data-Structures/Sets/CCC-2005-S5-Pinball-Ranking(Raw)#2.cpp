// CCC '05 S5 - Pinball Ranking (DMOJ): https://dmoj.ca/problem/ccc05s5
// RAW CODE
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pi;
typedef long long ll;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int N; ordered_set a; ll total;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1, x; i <= N; i++) {
        cin >> x;
        a.insert({x, i});
        total += (i - a.order_of_key({x, i}));
    }
    printf("%.3Lf\n", total/((long double)N));
}
