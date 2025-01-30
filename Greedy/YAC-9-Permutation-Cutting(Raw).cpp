// Yet Another Contest 9 P1 Permutation Cutting (DMOJ): https://dmoj.ca/problem/yac9p1
// RAW CODE https://dmoj.ca/src/6929344
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
int N, pos[MM], inv[MM], ans = 1;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1, x; i <= N; i++){
        cin >> x; pos[x] = i; 
    }
    for(int i = 1, x; i <= N; i++){
        cin >> x; inv[i] = pos[x];
    }
    int cur = inv[1];
    for(int i = 2; i <= N; i++){
        if(inv[i] != inv[i - 1] + 1) ans++;
        cur = inv[i];
    }
    cout << ans << endl;
}
