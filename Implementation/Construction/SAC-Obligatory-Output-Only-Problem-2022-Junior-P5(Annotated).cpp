// SAC '22 Code Challenge 4 Junior P5 - Obligatory Output Only Problem (DMOJ): https://dmoj.ca/problem/sac22cc4jp5
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5; // idea: N will be pushed into the queue N-2 times. Then, each time node N searches for neighbours, it will do so N-2 times. (N-2)(N-2) is way beyond 10^7
typedef pair<int, int> pi;
int N=MM, M=(N-2)*2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << N << " " << M << endl; // queue: [nodes 2, 3, ..., N]. Node 2 will see N, push it to the queue
    for(int i = 2; i < N; i++){ // then node 3 will see node N, and it's dist is guaranteed to be less/shorter to N compared to node 2's dist to node N (line 13) -> 2*(N-2) > 2*(N-3)
        cout << 1 << " " << i << " " << i << endl;
        cout << i << " " << N << " " << 2 * (N-i) << endl; 
    }
}
