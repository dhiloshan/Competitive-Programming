// CCC '18 S2 - Sunflowers (DMOJ): https://dmoj.ca/problem/ccc18s2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
typedef long long ll;
int N, a[MM][MM];
bool check(){
    for(int i = 2; i <= N; i++)
        if(a[1][i-1] >= a[1][i])
            return false;

    for(int k = 2; k <= N; k++)
        for(int i = 1; i <= N; i++)
            if(a[k][i-1] >= a[k][i] || a[k-1][i] >= a[k][i])
                return false;

    return true;
}
void rotate(){
    int temp[N+1][N+1], ii = 1;
    for(int c = N; c >= 1; c--){
        int jj = 1;
        for(int r = 1; r <= N; r++){
            temp[ii][jj] = a[r][c];
            jj++;
        }
        ii++;
    }
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            a[i][j] = temp[i][j];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> a[i][j];
        }
    }
    for(int k = 1; k <= 4; k++){
        if(check()){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    cout << a[i][j] << " \n"[j==N];
                }
            }
            return 0;
        }
        rotate();
    }
}
