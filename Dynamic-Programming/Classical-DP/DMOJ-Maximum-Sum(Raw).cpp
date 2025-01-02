// Maximum Sum (DMOJ): https://dmoj.ca/problem/dp1p1
// RAW CODE - https://dmoj.ca/src/6410615
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, a[MM], dp[MM];
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = max(a[1], a[2]);
    for(int i = 3; i <= N; i++){
        dp[i] = max(dp[i-1], dp[i-2] + a[i]);
    }
    cout << dp[N];
}
