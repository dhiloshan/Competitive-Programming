// Round 440 Div 2. B. Maximum of Maximums of Minimums (Codeforces): https://codeforces.com/contest/872/problem/B
// RAW CODE
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
        for(int i = 0; i < N; i++) st[i][0] = a[i];
        for(int k = 1; k <= log2(N); k++) {
            for (int i = 0; i < N - (1 << k) + 1; i++) {
                st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
            }
        }
        int lft = 0, lft2 = N-1, ans = -INF;
        while(lft < lft2){
            int rit = lft2-1, rit2 = N-1; 
            int k1 = log2(rit-lft+1), k2 = log2(rit2-lft2+1);
            int mi1 = min(st[lft][k1], st[rit-(1<<k1)+1][k1]), mi2 = min(st[lft2][k2], st[rit2-(1<<k2)+1][k2]), final = max(mi1, mi2);
            ans = max(ans, final);
            lft2--;
        }
        cout << ans << endl;
    }
}
