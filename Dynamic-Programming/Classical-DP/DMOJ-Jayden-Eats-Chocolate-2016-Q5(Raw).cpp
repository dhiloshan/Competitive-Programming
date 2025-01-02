// VM7WC '16 #5 Silver Jayden Eats Chocolate (DMOJ): https://dmoj.ca/problem/vmss7wc16c5p4
// RAW CODE - https://dmoj.ca/src/6786243
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, x, y, z;
int main(){
    cin >> N >> x >> y >> z;
    vector<int> dp(N+1, -1);
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        if(i >= x && dp[i-x] != -1){ 
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        if(i >= y && dp[i-y] != -1){ 
            dp[i] = max(dp[i], dp[i-y] + 1); 
        }
        if(i >= z && dp[i-z] != -1){ 
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }
    cout << dp[N] << endl; 
}
