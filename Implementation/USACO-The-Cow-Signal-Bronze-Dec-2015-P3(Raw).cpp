// USACO 2016 December Contest, Bronze Problem 3. The Cow-Signal (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=665
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
int N, M, K; char a[10][10];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ifstream cin("cowsignal.in");
    // ofstream cout("cowsignal.out");
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int k1 = 0; k1 < K; k1++){
            for(int j = 0; j < M; j++){
                for(int k2 = 0; k2 < K; k2++){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}
