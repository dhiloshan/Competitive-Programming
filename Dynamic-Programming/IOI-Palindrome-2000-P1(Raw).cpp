// IOI '00 P1 - Palindrome (DMOJ): https://dmoj.ca/problem/ioi00p1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 5e3+3;
int N; string s;
int dp[3][MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> s;
    int curRow = 1;
    for(int i = 1; i < s.size(); i++){
        for(int j = 0; j < s.size()-i; j++){
            int l = j, r = l + i;
            int prevRow1 = (curRow + 2) % 3, prevRow2 = (curRow + 1) % 3;
            if(s[l] == s[r]){
                dp[curRow][l] = dp[prevRow2][l+1];
            }
            else {
                int matchFirst = dp[prevRow1][l + 1] + 1;
                int matchLast = dp[prevRow1][l] + 1;
                dp[curRow][l] = min(matchFirst, matchLast);
            }
        }
        curRow = (curRow + 1) % 3;
    }
    int finalRow = ((s.size() % 3) + 2) % 3;
    cout << dp[finalRow][0] << endl;
}
