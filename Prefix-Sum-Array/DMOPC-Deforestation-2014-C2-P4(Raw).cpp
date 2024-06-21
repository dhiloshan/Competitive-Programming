// DMOPC '14 Contest 2 P4 - Deforestation (DMOJ): https://dmoj.ca/problem/dmopc14c2p4
// RAW CODE - https://dmoj.ca/src/6454244
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, Q, a[MM], psa[MM];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    cin >> a[1]; psa[1] = a[1];
    for(int i = 2; i <= N; i++){
        cin >> a[i]; psa[i] = psa[i-1] + a[i];
    }

    cin >> Q;
    for(int i = 1, l, r; i <= Q; i++){
        cin >> l >> r; l++; r++;
        cout << psa[r] - psa[l-1] << endl;
    }
}
