// CCO '10 P4 - Computer Purchase Return (DMOJ): https://dmoj.ca/problem/cco10p4
// RAW CODE - https://dmoj.ca/src/6900869
#include <bits/stdc++.h>
using namespace std;
const int MM = 3003;
typedef pair<int, int> pi;
int T, N, B, dp[6][MM]; vector<pi> items[6];
int main(){
    cin >> T >> N;
    for(int i = 1, c, v, t; i <= N; i++){
        cin >> c >> v >> t;
        items[t].emplace_back(c, v);
    }
    cin >> B;
    memset(dp, -0x3f, sizeof(dp));
    for(int i = 0; i <= B; i++) dp[0][i] = 0;
    for(int t = 1; t <= T; t++){
        for(auto [c, v] : items[t]){
            for(int i = c; i <= B; i++){
                dp[t][i] = max(dp[t][i], dp[t-1][i-c] + v);
            }
        }
    }
    int ans = -1;
    ans = max(ans, dp[T][B]);
    cout << ans << endl;
}
