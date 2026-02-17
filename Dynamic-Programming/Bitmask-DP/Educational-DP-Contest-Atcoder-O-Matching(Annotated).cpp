// Educational DP Contest AtCoder O - Matching (DMOJ): https://dmoj.ca/problem/dpo
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1<<21;
const int mod = (int)1e9+7;
int N, dp[MM], a[21][21];
int fun(int i, int mask){ // mask represents set of 21 women. set -> binary #. each bit is one woman
    if(i == N) return 1;
    if(dp[mask] != -1) return dp[mask]; // at this mask, the smae amount of men would have been used at this point (# of 1 bits rep the ith men)
    int sum = 0;
    for(int j = 0; j < N; j++){ // for each woman
        // if there is a women in the set and man i and woman j are compatible
        if((mask>>j & 1) == 0  && a[i][j] == 1){
            sum = (sum + fun(i+1, mask|1<<j)) % mod; // common formula or format for bitmask dp, especially the mask|1<<j
        }
    }
    return dp[mask] = sum;
}
int main(){
    cin >> N;
    for(int i = 0; i < MM; i++) dp[i] = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    cout << fun(0, 0) << endl;
}
