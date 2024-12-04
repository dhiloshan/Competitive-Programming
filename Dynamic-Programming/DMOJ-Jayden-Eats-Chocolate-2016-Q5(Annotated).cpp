// VM7WC '16 #5 Silver Jayden Eats Chocolate (DMOJ): https://dmoj.ca/problem/vmss7wc16c5p4
// ANNOTATED CODE - https://dmoj.ca/src/6786237
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, x, y, z; // let dp[i] represent the highest number of friends that can receive a piece of chocolate (of size x, y, or z)
// dp[i] = max(dp[i-x], dp[i-y], dp[i-z]) + 1
int main(){
    cin >> N >> x >> y >> z;
    vector<int> dp(N+1, -1);
    dp[0] = 0;
    for(int i = 1; i <= N; i++){ // 3 choices
        if(i >= x && dp[i-x] != -1){ // if dp[i-x] is a valid index where i-x can be split into pieces of chocolate of size x, y, and z with no remainder:
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        if(i >= y && dp[i-y] != -1){ // if dp[i-y] is a ...
            dp[i] = max(dp[i], dp[i-y] + 1); // dp[i] = maximum of current cell (dp[i-x]+1 may be better than dp[i-y]+1) and dp[i-y], which represents the smaller problem of the chocolate with size i-y, +1 for the new friend
        }
        if(i >= z && dp[i-z] != -1){ // if dp[i-z] is a ...
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }
    cout << dp[N] << endl; // our final answer seeks for the maximum number of friends for a chocolate bar with size N
}
