// Round 440 Div 2. B. Maximum of Maximums of Minimums (Codeforces): https://codeforces.com/contest/872/problem/B
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
const int INF = 1e9;
int N, K, a[MM], mx=-INF, mi=INF, st[MM][18];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> a[i]; mx = max(mx, a[i]); mi = min(mi, a[i]);
    }
    if(K == 1) cout << mi << endl;
    else if(K >= 3) cout << mx << endl;
    else{
        // build sparse table
        for(int i = 0; i < N; i++) st[i][0] = a[i]; // base case: k=0,2^0=-1,array_size is each one
        for(int k = 1; k <= log2(N); k++){ // 2^1, 2^2, ... 2^k
            for(int i = 0; i < N-(1<<k)+1; i++){
                st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
            }
        }
        /*
        for(int i = 0; i < N; i++){
            for(int k = 0; k <= log2(N); k++){
                cout << st[i][k] << " \n"[k==floor(log2(N))];
            }
        }
        */
        // [0, N-2] & [N-1, N-1], [0, N-3] & [N-2, N-1], ..., [0, 1] & [2, N-1], [0, 0] & [1, N-1]
        int lft = 0, lft2 = N-1, ans = -INF;
        while(lft < lft2){
            int rit = lft2-1, rit2 = N-1; // [lft, rit] & [lft2 and rit2]
            // query the sparse table
            // find the largest power of 2 that fits => log2(rit-lft+1)
            int k1 = log2(rit-lft+1), k2 = log2(rit2-lft2+1);
            int mi1 = min(st[lft][k1], st[rit-(1<<k1)+1][k1]), mi2 = min(st[lft2][k2], st[rit2-(1<<k2)+1][k2]), final = max(mi1, mi2);
            ans = max(ans, final);
            lft2--;
        }
        cout << ans << endl;
    }
}
