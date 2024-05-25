// Coding Spree (DMOJ) - https://dmoj.ca/problem/spree
// RAW CODE - https://dmoj.ca/src/6415708
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+3;
int N, T, dp[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T;
    for(int i = 1, v, h; i <= N; i++){
        cin >> v >> h;
        for(int j = T; j >= h; j--){
            dp[j] = max(v + dp[j-h], dp[j]);
        }
    }
    cout << dp[T] << endl;
}
