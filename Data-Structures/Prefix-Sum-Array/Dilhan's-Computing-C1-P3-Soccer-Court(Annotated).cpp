// Dilhan's Computing Contest 1 P3 - Soccer Court (DMOJ): https://dmoj.ca/problem/dcc1p3
// ANNOTATED CODE - https://dmoj.ca/src/7067992
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 402;
int N, M, ans=0; ll psa[2*MM][MM]; // O(N*M^2) with 2D psa and hashmap optimization (even faster with pb_ds hash table)
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> psa[i][j]; psa[i][j] += psa[i][j-1]; // precompute sums row by row
        }
    }
    for(int i = 1; i <= M; i++){
        for(int j = i; j + (j - i + 1) <= M; j++){ // [i, j] [j+1, k]
            int k = j + (j - i + 1); ll lft = 0, rit = 0;
            unordered_map<ll, int> mp; mp[0] = 0; // track to see if some sum occured before
            for(int r = 1; r <= N; r++){
                lft += psa[r][j] - psa[r][i-1]; rit += psa[r][k] - psa[r][j];
                ll dif = rit - lft;
                if(mp.count(dif)){ // right sum + x - left sum + x
                    ans = max(ans, (k - i + 1) * (r - mp[dif])); // not included
                }
                else{
                    mp[dif] = r; 
                }
            }
        }

    }
    cout << ans << endl;
}
