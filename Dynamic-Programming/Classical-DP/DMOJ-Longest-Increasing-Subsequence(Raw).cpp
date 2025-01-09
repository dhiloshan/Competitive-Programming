// Longest Increasing Subsequence (DMOJ): https://dmoj.ca/problem/lis
// RAW CODE - https://dmoj.ca/src/6872375
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, a[MM], dp[MM]; vector<int> lis;
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    dp[1] = 1; lis.push_back(a[1]);
    for(int i = 2; i <= N; i++){
        int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        if(idx == lis.size()) lis.push_back(a[i]);
        else lis[idx] = a[i];
        dp[i] = idx+1;
    }
    cout << *max_element(dp+1, dp+N+1) << endl;
}
