// SAC '21 Code Challenge P4 (DMOJ): https://dmoj.ca/problem/sac21ccp4
// ANNOTATED CODE - https://dmoj.ca/src/7109580
#include <bits/stdc++.h> // use psa to maintain static range sums when calculating averages
using namespace std;
const int MM = 1e6+3;
int N, Q, a[MM], psa[MM];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    cin >> a[1]; psa[1] = a[1];
    for(int i = 2; i <= N; i++){
        cin >> a[i]; psa[i] = psa[i-1] + a[i];
    }
    for(int i = 1, l, r; i <= Q; i++){
        cin >> l >> r;
        cout << (psa[r] - psa[l-1]) / (r - l + 1) << endl;
    }
}
