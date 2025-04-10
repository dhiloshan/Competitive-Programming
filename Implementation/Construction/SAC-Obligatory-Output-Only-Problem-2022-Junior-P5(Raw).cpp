// SAC '22 Code Challenge 4 Junior P5 - Obligatory Output Only Problem (DMOJ): https://dmoj.ca/problem/sac22cc4jp5
// RAW CODE - https://dmoj.ca/src/7109567
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5;
typedef pair<int, int> pi;
int N=MM, M=(N-2)*2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << N << " " << M << endl;
    for(int i = 2; i < N; i++){
        cout << 1 << " " << i << " " << i << endl;
        cout << i << " " << N << " " << 2 * (N-i) << endl;
    }
}
