// CCC '23 S1 - Trianglane (DMOJ): https://dmoj.ca/problem/ccc23s1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+3;
int N, a[2][MM], cnt[2][MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
            if(a[i][j]) {
                cnt[i][j] = 3;
                if(j > 1 && a[i][j-1] && a[i][j-2]){
                    cnt[i][j-1] = 1; cnt[i][j] = 2;
                }
                else if(j > 0 && a[i][j-1]){
                    cnt[i][j-1] = 2; cnt[i][j] = 2;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < N; i++){
        if(a[0][i] && a[1][i] && i % 2 == 0){
            cnt[0][i]--; cnt[1][i]--;
        }
        sum += cnt[0][i] + cnt[1][i];
    }
    cout << sum << endl;
}
