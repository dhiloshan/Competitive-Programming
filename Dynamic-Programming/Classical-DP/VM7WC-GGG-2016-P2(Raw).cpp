// VM7WC '16 #2 Gold - GGG (DMOJ): https://dmoj.ca/problem/vmss7wc16c2p3
// RAW CODE - https://dmoj.ca/src/6875683
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, M, pos[MM]; vector<int> lis;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1, x; i <= N; i++){
        cin >> x; pos[x] = i;
    }
    cin >> M;
    for(int i = 1, x; i <= M; i++){
        cin >> x; x = pos[x];
        if(x == 0) continue;
        if(lis.empty() || x > lis.back()){
            lis.push_back(x);
        }
        else{
            *lower_bound(lis.begin(), lis.end(), x) = x;
        }
    }
    cout << lis.size() << endl;
}
