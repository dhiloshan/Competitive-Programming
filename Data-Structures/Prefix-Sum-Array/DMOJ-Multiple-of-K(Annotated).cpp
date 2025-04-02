// Multiple of K (Olympiads): https://dmoj.ca/problem/oly19practice19
// ANNOTATED CODE - similar to leetcode 560 (# of subarrays whose sum is K), can we chop off some prefix to get a multiple of K
// but realize that it seems qutie unnecessary to check every single multiple of K (wishful thinking is an effective tool)
// instead, use mod. if there is some array from 1 to R, can we chop off a prefix from 1 to L such that the reminder of 1 to L's sum is the same as the reminder of 1 to R's sum
// to maximize the length, we note the first occurance of this reminder, using rem[] (default is -1)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, K, psa[MM], rem[MM], ans=-1;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    cin >> psa[1]; psa[1] %= K;
    for(int i = 2, x; i <= N; i++){
        cin >> x; psa[i] = (psa[i-1] + x) % K; // psa stores mod values, we don't need the actual ones
    }
    fill(rem, rem+MM, -1); // default value
    rem[0] = 0; // base case
    for(int i = 1; i <= N; i++){
        if(rem[psa[i]] != -1)
            ans = max(ans, i - rem[psa[i]]);
        else
            rem[psa[i]] = i;
    }
    cout << ans << endl;
}
