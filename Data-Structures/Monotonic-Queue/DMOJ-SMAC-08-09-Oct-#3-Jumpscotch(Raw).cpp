// SMAC 08/09 (Oct) #3 - Jumpscotch (DMOJ): https://dmoj.ca/problem/smac08c1p3
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+3;
int N, K, a[MM], dp[MM]; deque<int> q;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K; K++; 
    for (int i = 1; i <= N; i++) cin >> a[i];
    dp[1] = a[1]; q.push_back(1);
    for(int i = 2; i <= N; i++){
        if(!q.empty() && q.front() <= i - K) q.pop_front();
        dp[i] = dp[q.front()] + a[i];
        while(!q.empty() && dp[q.back()] >= dp[i]) q.pop_back();
        q.push_back(i);
    }
    cout << dp[N] << endl;
}
