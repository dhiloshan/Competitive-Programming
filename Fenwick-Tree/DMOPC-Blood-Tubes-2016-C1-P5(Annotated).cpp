// ANNOTATED CODE - https://dmoj.ca/src/6317252
// Blood Tubes '16 Contest 1 Problem 5 (DMOPC) - https://dmoj.ca/problem/dmopc16c1p5
// classical inversion counting question using fenwick's tree
// we're taking advantage of the fact we know the frequency of a subarray of integers, overall logic is quite easy
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5e5+3;
typedef long long ll;
int N; ll bit[MM], sum;
void update(int pos, int val){ // update all bit cells that have the frequency of x
    for(int i=pos; i<=N; i+=i&-i) bit[i] += val;
}
ll query(int pos){ // number of integers between 1 and x in the array
    ll cur = 0;
    for(int i=pos; i>0; i-=i&-i) cur += bit[i];
    return cur;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1, x; i <= N; i++){
        cin >> x; // tube x
        int lft = query(x), rit = i - 1 - lft; // lft considers if we put the tube from the left, rit does the opposite
                                               // rit = total - number of integers from 1 to x = remaining integers (-1 is for the fact we start at i = 1 and do the queries) )
        sum += min(lft, rit); update(x, 1);    // min(lft, rit) says does it cost less to put the tube from the left or right
                                               // take input and add 1 frequency for that number
    }
    cout << sum << endl;
}
