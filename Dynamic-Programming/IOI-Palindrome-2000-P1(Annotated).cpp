// IOI '00 P1 - Palindrome (DMOJ): https://dmoj.ca/problem/ioi00p1
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 5e3+3;
int N; string s;
int dp[3][MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> s;
    int curRow = 1; // possible values: [0, 2] since it's mod 3
    // *base case is finished (for substring size 1), which is always 0 since any string of size 1 is a palindrome
    /* Example Scenario: for string size 2, if it is a palindrome, like nn, then it should also be zero
     go back two rows to find the answer for string size 0 (2-2), which is obviously 0, which is the initial value of the dp array from assigning it globally
     */
    for(int i = 1; i < s.size(); i++){ // substring size i+1
        // cout << "Size " << i+1 << ":" << endl;
        for(int j = 0; j < s.size()-i; j++){
            int l = j, r = l + i; // substring (l, r)'s answer is located at dp[curRow][j] or dp[curRow][l]
            int prevRow1 = (curRow + 2) % 3, prevRow2 = (curRow + 1) % 3;
            // int prevRow1 = ((curRow - 1) + 3) % 3, prevRow2 = ((curRow - 2) + 3) % 3;
            if(s[l] == s[r]){ // example string: bx3ab -> (b)x3a(b) = x3a's answer
                dp[curRow][l] = dp[prevRow2][l+1];
                // rewording the logic here
                // the minimum characters I need to insert to substring l to r with size x is the same as the substring starting from l+1 with size x-2
                // it is minus 2 because the front and back character from the original substring
                // start from l+1 because you take out the front character (and the back one, which makes the new substring size x-2)
            }
            else {
                int matchFirst = dp[prevRow1][l + 1] + 1; // match with the first character -> string size decreases by one so use the previous row + move one character rightward
                int matchLast = dp[prevRow1][l] + 1; // match with the last character
                dp[curRow][l] = min(matchFirst, matchLast);
            }
            // cout << dp[curRow][l] << " ";
        }
        curRow = (curRow + 1) % 3; // update the row the program will view for the next iteration
       // cout << endl;
    }
    int finalRow = ((s.size() % 3) + 2) % 3;
    // int finalRow = (((s.size() % 3) - 1) + 3) % 3;
    cout << dp[finalRow][0] << endl;
}
/*
 partial (30%)
 int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> s;
    int dp[N][N];
    memset(dp, 0x3f, N*N); // for understanding purposes I will set all cells to max
    // dp state: dp[i][j] = min # of characters to insert to make "s[i]s[i+1]..s[j]" become a palindrome
    // step 1: base case
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = 0;
        }
    }
    // step 2: dp transition
    for(int d = 1; d < s.size(); d++){ // d-th diagonal (0th diagonal is the base case)
        for(int l = 0; l + d < s.size(); l++){
            int r = l + d; // the current cell is (l, r)
            if(s[l] == s[r]){ // example string: bx3ab
                dp[l][r] = dp[l+1][r-1]; // (b)x3a(b) <- ignore the first and last character because they're the same => x3a's answer (min characters to convert it into a palindrome)
            }
            else{ // example string: Ab3bd
                int matchFirst = dp[l+1][r] + 1; // Ab3bd(A) <- match the first character => b3bd's answer + 1
                int matchLast = dp[l][r-1] + 1; // (d)Ab3bd <- match the last character => Ab3b's answer + 1
                dp[l][r] = min(matchFirst, matchLast);
            }
          //  cout << "Min # of characters to convert " << s.substr(l, d+1) << " into a palindrome: " << dp[l][r] << endl;
        }
    }
    cout << dp[0][s.size()-1] << endl;
     0,1 1,2 2,3 3,4
     0,2 1,3 2,4
*/
