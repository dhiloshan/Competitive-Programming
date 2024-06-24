// The Cosmic Era P3 - Battle Positions (DMOJ): https://dmoj.ca/problem/seed3
// RAW CODE - https://dmoj.ca/src/6458558
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int I, N, J, dif[MM], ans;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> I >> N >> J;
    for(int i = 1, l, r, k; i <= J; i++){
        cin >> l >> r >> k;
        dif[l] += k; dif[r+1] -= k;
    }
    for(int i = 1; i <= I; i++){
        dif[i] += dif[i-1];
        if(dif[i] < N) ans++;
    }
    cout << ans << endl;
}
