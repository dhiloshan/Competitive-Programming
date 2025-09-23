// THICC '17 P5 - Smarties (DMOJ): https://dmoj.ca/problem/thicc17p5
// RAW CODE (exactly like diverse arrays AC3P1 problem)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+3;
int N, K, f[MM]; ll cnt;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> f[i];
    unordered_map<int, int> mp;
    for(int i = 1, j = 1; j <= N; j++){
        mp[f[j]]++;
        while(mp.size() >= K && i <= j){
            cnt += (N-j+1);
            mp[f[i]]--; if(mp[f[i]] == 0) mp.erase(f[i]);
            i++;
        }
    }
    cout << cnt << endl;
}
