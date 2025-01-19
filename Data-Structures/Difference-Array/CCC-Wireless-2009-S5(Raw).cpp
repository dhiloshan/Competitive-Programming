// CCC '09 S5 - Wireless (DMOJ): https://dmoj.ca/problem/ccc09s5
// RAW CODE - https://dmoj.ca/src/6900914
#include <bits/stdc++.h>
using namespace std;
int N, M, K, dif[1002][30002], ans, num;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N >> K;
    for(int i = 1, x, y, r, b; i <= K; i++){
        cin >> x >> y >> r >> b;
        for(int j = max(1, x-r); j <= min(N, x+r); j++){
            int d = sqrt(r*r - (x-j) * (x-j));
            dif[j][max(1, y-d)] += b;
            dif[j][min(M, y+d)+1] -= b;
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dif[i][j] += dif[i][j-1];
            if(dif[i][j] > ans){
                ans = dif[i][j]; num = 1;
            }
            else if(dif[i][j] == ans) num++;
        }
    }
    cout << ans << endl << num << endl;
}
