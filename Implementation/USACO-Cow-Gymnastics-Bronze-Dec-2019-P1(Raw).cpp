// USACO 2019 December Contest, Bronze Problem 1. Cow Gymnastics(USACO) - https://usaco.org/index.php?page=viewproblem2&cpid=963
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 22;
int K, N, rnk[MM][MM], sum;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ifstream cin("gymnastics.in");
    // ofstream cout("gymnastics.out");
    cin >> K >> N;
    for(int i = 1; i <= K; i++){
        for(int j = 1, x; j <= N; j++){
            cin >> x;
            rnk[i][x] = j;
        }
    }
    for(int i = 1; i < N; i++){
        for(int j = i+1; j <= N; j++){
            int ri = 0, rj = 0;
            for(int k = 1; k <= K; k++){
                if(rnk[k][i] < rnk[k][j]) ri++;
                else rj++;
            }
            if(ri == K || rj == K) sum++;
        }
    }
    cout << sum << endl;
}
