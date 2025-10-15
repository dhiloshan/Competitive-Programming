// USACO 2016 US Open Contest, Silver Problem 2. Diamond Collector (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=643
// ANNOTATED CODE
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
    // base cases
    if(N == 0) cout << 0 << endl;
    else if(N == 1) cout << a[1] << endl;
    else{
        sort(a+1, a+N+1); // step 1: sort in ascending order
        // two pointer to find largest subarray satisfying the constraint
        for(int l = 1, r = 1; l <= N; l++){ // incrementing l instead of r for two pointer
            while(a[r] - a[l] <= K && r <= N) r++; // make sure r <= N
            bestStartingFrom[l] = r-l;
        }
        for(int i = N; i >= 1; i--){ // suffix max array
            bestMx[i] = max(bestMx[i+1], bestStartingFrom[i]);
        }
        for(int i = 1; i <= N; i++){
            ans = max(ans, bestStartingFrom[i] + bestMx[i+bestStartingFrom[i]]); // consider right side as new problem
        }
        cout << ans << endl;
    }
}
