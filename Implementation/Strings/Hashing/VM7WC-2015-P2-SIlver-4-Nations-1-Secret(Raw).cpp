// VM7WC '15 #2 Silver - 4 Nations, 1 Secret (DMOJ): https://dmoj.ca/problem/vmss7wc15c2p2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 25002, SEED = 1e5+7, MOD = 1e9+7;
int N, ans, ans_st, st; string s; ll pre[MM], suf[MM], pw[MM];
ll preHash(int L, int R) { return (pre[R] - pre[L-1] * pw[R-L+1] % MOD + MOD) % MOD; }
ll sufHash(int L, int R){ return (suf[L] - suf[R+1] * pw[R-L+1] % MOD + MOD) % MOD; }
bool check(int len) {
    for(int i = len; i <= N; i++){
        if(preHash(i-len+1, i) == sufHash(i-len+1, i)) {
            st = i - len + 1; return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> s; pw[0] = 1;
    for(int i = 1; i <= N; i++){
        pw[i] = pw[i-1] * SEED % MOD;
        pre[i] = (pre[i-1] * SEED % MOD + s[i-1]) % MOD;
    }
    for(int i = N; i >= 1; i--){
        suf[i] = (suf[i+1] * SEED % MOD + s[i-1]) % MOD;
    }
    vector<int> len[2];
    for(int i = 1; i <= N; i++)
        len[i % 2].push_back(i);
    for(int k = 0; k < 2; k++){
        int lo = 0, hi = (int)len[k].size() - 1, best = -1, pos = -1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(check(len[k][mid])){
                best = len[k][mid]; lo = mid + 1; pos = st;
            }
            else
                hi = mid - 1;
        }
        if(best > ans) {
            ans = best; ans_st = pos;
        }
    }
    cout << s.substr(ans_st-1, ans) << endl << ans << endl;
}
