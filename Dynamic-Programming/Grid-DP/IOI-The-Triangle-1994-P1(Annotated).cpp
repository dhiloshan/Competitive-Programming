// IOI The Triangle 1994 P1 (SAC): https://dmoj.ca/problem/ioi94p1
// ANNOTATED CODE - https://dmoj.ca/src/6777175
// 2D DP on a grid (2 choices): is it better going left or right (similar to BST)
#include <bits/stdc++.h> // note that space complexity can be optimized to O(N) [my challenge to you]
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
    dp[1][1] = a[1][1]; // base case
    for(int i = 2; i <= N; i++){ // start from row 2: top-bottom approach
        for(int j = 1; j <= i; j++){ // left to right
            dp[i][j] = a[i][j] + max(dp[i-1][j-1], dp[i-1][j]); // is the left cell (dp[i-1][j-1]) or right cell(dp[i-1][j]) better
        }
    }

    int mx = 0; // find the maximum in row N
    for(int i = 1; i <= N; i++){
        mx = max(dp[N][i], mx);
    }
    cout << mx << endl;
}
