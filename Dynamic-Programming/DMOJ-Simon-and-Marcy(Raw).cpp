// Valentine's Day '15 P2 - Simon and Marcy (DMOJ) - https://dmoj.ca/problem/valday15p2 
// RAW CODE - https://dmoj.ca/src/6400744
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3;
typedef long long ll;
int C, M; ll dp[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> C >> M;
    for(int i = 1, c, p; i <= C; i++){
        cin >> p >> c;
        for(int j = M; j >= c; j--){
            dp[j] = max(dp[j], p + dp[j-c]);
        }
    }
    cout << dp[M] << endl;
}
