// Square Counting (Olympiads School Only): https://dmoj.ca/problem/oly25practice34
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 3003;
bool holes[MM][MM]; long long dp[MM][MM], H, W, K;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> H >> W >> K;
    for(int i = 1, r, c; i <= K; i++){
        cin >> r >> c; holes[r][c] = true;
    }
    long long sum = 0;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            dp[i][j] = holes[i][j]? 0 : (min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1);
            sum += dp[i][j];
        }
    }
    cout << sum << endl;
}
