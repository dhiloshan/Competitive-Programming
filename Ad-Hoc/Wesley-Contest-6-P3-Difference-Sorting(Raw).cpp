// Wesley's Anger Contest 6 Problem 3 Difference Sorting (DMOJ): https://dmoj.ca/problem/wac6p3
// RAW CODE - https://dmoj.ca/src/6926143
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
typedef long long ll;
int N; ll a[MM], sorted[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i]; sorted[i] = a[i];
        a[i] = max(a[i-1], a[i]);
    }
    sort(sorted+1, sorted+N+1);
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        if(a[i] > sorted[i]) ans = max(ans, sorted[i+1] - sorted[i]);
    }
    cout << ans << endl;
}
