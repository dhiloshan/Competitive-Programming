// SMAC 08/09 (Oct) #3 - Jumpscotch (DMOJ): https://dmoj.ca/problem/smac08c1p3
// ANNOTATED CODE - https://dmoj.ca/src/7316614
/*
 dp[i] = min cost to reach square i
 dp[j] = a[j] + min(dp[j-1], dp[j-2], ... dp[j-K])
 maintain minimum mono queue to output min in O(1). queue takes O(N) overall
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+3;
int N, K, a[MM], dp[MM]; deque<int> q;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K; K++; // K is window size
    for (int i = 1; i <= N; i++) cin >> a[i];
    dp[1] = a[1]; q.push_back(1); // queue stores the index; dp array stores the value
    for(int i = 2; i <= N; i++){
        if(!q.empty() && q.front() <= i - K) q.pop_front();
        dp[i] = dp[q.front()] + a[i];
        while(!q.empty() && dp[q.back()] >= dp[i]) q.pop_back();
        q.push_back(i);
    }
    cout << dp[N] << endl;
}
