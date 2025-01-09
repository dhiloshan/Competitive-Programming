// Longest Common Subsequence (DMOJ): https://dmoj.ca/problem/lcs
// ANNOTATED CODE - https://dmoj.ca/src/6872229
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+3;
int N, M, a[MM], b[MM], dp[MM][MM]; // LCS of two arrays
/* there are only two cases: the characters match or they don't
 if they do, then we have another COMMON character so far for an array a[idx 1 to i] and array b[idx 1 to j]
 so we need we have to add one (we have ONE common character) to some previous subproblem
 what is that subproblem? well just don't include the current character, which is located at idx i-1 and j-1 => dp[i-1][j-1] + 1
 -
 else, if they don't match, then we have two subcases:
 take out the current character in array a or in array b
 the first subcase is located at dp[i-1][j], and the second is at dp[i][j-1]
 (we don't add one because the characters don't match)
 */
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int i = 1; i <= M; i++) cin >> b[i];
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1; // if the numbers match, then add one to the subproblem
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // then the numbers don't match, we have two subcases, take out the number from the first array or second
        }
    }
    cout << dp[N][M] << endl; // the answer we desire is the LCS for array a from 1 to N and array b from 1 to M
}
