// Longest Increasing Subsequence (DMOJ): https://dmoj.ca/problem/lis
// ANNOTATED CODE -https://dmoj.ca/src/6872401
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, a[MM], dp[MM]; vector<int> lis; // temporary lis vector that stores the smallest possible ending values for increasing subsequences of different lengths
// stores the length of the LIS for the current i; however, I decided to implement it with the dp array to understand LIS better
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    dp[1] = 1; lis.push_back(a[1]); // base case: dp[1] = 1
    for(int i = 2; i <= N; i++){
        int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin(); // index where the value needs to be replaced by a[i]
        if(idx == lis.size()) lis.push_back(a[i]); // note that lower_bound returns lis.end() if a[i] > lis.back(), so lis.end() - lis.begin() = N
                                                   // if so then push a[i] to the back because it makes the subsequence increasing
        else lis[idx] = a[i]; // otherwise replace that index in the temporary lis with a[i]
        dp[i] = idx+1; // we add one because accessing indexes is 0-indexed
    }
    cout << *max_element(dp+1, dp+N+1) << endl; // max_element finds the max element in an array and returns an iterator, very convenient
}
