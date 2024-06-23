// Lil' Jami (DMOJ) - https://dmoj.ca/problem/liljami
// RAW CODE - https://dmoj.ca/src/6454264
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, K, Q, a[MM], psa[MM];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for(int i = 0, k; i < K; i++){
        cin >> k; a[k]++;
    }

    psa[0] = a[0];
    for(int i = 1; i < N; i++){
        psa[i] = psa[i-1] + a[i];
    }

    cin >> Q;
    for(int i = 0, l, r; i < Q; i++){
        cin >> l >> r;
        cout << psa[r] - psa[l-1] << endl;
    }
}
