// CCC '25 S2 - Cryptogram Cracking Club (DMOJ): https://dmoj.ca/problem/ccc25s2
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
typedef long long ll; // best to maintain a queue for all operations executed on the string
string s; queue<pair<char, ll> > q; ll C, total; // ensure to use long long when necessary
int main(){
    cin >> s >> C;
    int wi = 0; // naming convention: wi represents any index, starts with the letter w for while loop
    while(wi < s.size()){ // iterate through the string
        if(97 <= int(s[wi]) && int(s[wi]) <= 122){ // if this character is lowercase
            char cur = s[wi]; ll num = 0; wi++; // ensure to add one to the index
            while(48 <= int(s[wi]) && int(s[wi]) <= 57){ // if this character is a number from 0 to 9
                num = (num * 10 + (s[wi] - '0')); // s[wi] - '0' yields the numerical value of a number
                // line 15 avoids the need to use a string and convert it into a long long using stoll()
                wi++; // ensure to add one to the index
            }
            q.push({cur, num}); total += num; // total represents the number of letters in the base string
        }
    }
    C %= total; // mod C by the total
    while(!q.empty()){ // go through the queue. better to use this than a for loop
        auto [letter, len] = q.front(); q.pop();
        C -= len;
        if(C < 0){ // if the length is negative then the answer must be the current character
            cout << letter << endl;
            return 0; // guaranteed to print the answer in the while loop. when we do, return 0
        }
    }
}
