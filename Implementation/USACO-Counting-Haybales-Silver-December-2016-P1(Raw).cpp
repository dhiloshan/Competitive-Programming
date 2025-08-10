// USACO 2016 December Contest, Silver Problem 1. Counting Haybales (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=666
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+3;
int N, Q, a[MM];
int main(){
    ifstream cin("haybales.in");
    ofstream cout("haybales.out");
    cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N);
    for(int i = 0, l, r; i < Q; i++){
        cin >> l >> r;
        cout << upper_bound(a, a+N, r) - lower_bound(a, a+N, l) << endl;
    }
}

