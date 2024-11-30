// SAC '22 Code Challenge 5 Junior P4 - Course Requirements (SAC): https://dmoj.ca/problem/sac22cc5jp4
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 103;
int N, a[MM][MM], dp[MM][MM];
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = a[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    int mx = 0;
    for(int i = 1; i <= N; i++){
        mx = max(dp[N][i], mx);
    }
    cout << mx << endl;
}
