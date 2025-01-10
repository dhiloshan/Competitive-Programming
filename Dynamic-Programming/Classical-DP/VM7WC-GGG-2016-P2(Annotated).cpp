// VM7WC '16 #2 Gold - GGG (DMOJ): https://dmoj.ca/problem/vmss7wc16c2p3
// ANNOTATED CODE - https://dmoj.ca/src/6875700
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, M, pos[MM]; vector<int> lis;
/*
 context: LCS = longest common subsequence, LIS - longest increasing subsequence, both require DP so even if i don't mention it you should know how these two problems require dp
 we can't do LCS with dp because N <= 10^6 => fails time and space complexity
 however, notice the following (best to use paper):
 idx     1    2    3    4    5    6
 A       7    8    12   3    6    19
 B       5    7    12   9    8    6
 b_in_a  _    1     3   _    2    5
 b in a is just where b[i] is in array a and give me its index (_ means there is no number b[i] in array a)
 best to draw it out with arrows coming from numbers in B to numbers in A
 you'll notice that you could turn this into a LIS problem => O(NlogN) time
 */
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1, x; i <= N; i++){
        cin >> x; pos[x] = i; // pos is the frequency array for element in array a
    }
    cin >> M;
    for(int i = 1, x; i <= M; i++){
        cin >> x; x = pos[x]; // x is just b_in_a[i]
        if(x == 0) continue; // global int arrays by default are initialized to 0, so if pos[x] = 0, that means there is no such number b[i] in array a, so don't do LIS and skip this iteration
        // we are doing LIS dp as we take input
        if(lis.empty() || x > lis.back()){ // the lis array will be empty at first so check that
            lis.push_back(x);
        }
        else{
            *lower_bound(lis.begin(), lis.end(), x) = x; // first number >= x in lis array will now be x
        }
    }
    cout << lis.size() << endl; // property of the LIS array is that its size is the size of the actual LIS, but the numbers inside LIS AREN'T the LIS itself
}
