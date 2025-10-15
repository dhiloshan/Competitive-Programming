// USACO 2016 US Open Contest, Silver Problem 2. Diamond Collector (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=643
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 50003;
int N, K, a[MM], bestStartingFrom[MM], bestMx[MM], ans;
int main(){
    ifstream cin("diamond.in");
    ofstream cout("diamond.out");
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> a[i];
    if(N == 0) cout << 0 << endl;
    else if(N == 1) cout << a[1] << endl;
    else{
        sort(a+1, a+N+1); 
        for(int l = 1, r = 1; l <= N; l++){ 
            while(a[r] - a[l] <= K && r <= N) r++; 
            bestStartingFrom[l] = r-l;
        }
        for(int i = N; i >= 1; i--){
            bestMx[i] = max(bestMx[i+1], bestStartingFrom[i]);
        }
        for(int i = 1; i <= N; i++){
            ans = max(ans, bestStartingFrom[i] + bestMx[i+bestStartingFrom[i]]); 
        }
        cout << ans << endl;
    }
}
