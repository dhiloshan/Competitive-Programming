// TLE '17 Contest 2 P2 - Unlucky Numbers (DMOJ): https://dmoj.ca/problem/tle17c2p2
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, K, psa[MM], a[MM];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i = 1, u; i <= N; i++){
        cin >> u; a[u]++; // psa but for the frequency
    }

    psa[1] = a[1];
    for(int i = 2; i < MM; i++){
        psa[i] = psa[i-1] + a[i]; // psa update 1d
    }

    cin >> K;
    for(int i = 1, f; i <= K; i++){
        cin >> f;
        cout << f - psa[f] << endl; // number of numbers from 1 to f that isn't an unlucky number
    }
}
