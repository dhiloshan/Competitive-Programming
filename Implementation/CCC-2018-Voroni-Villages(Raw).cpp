// CCC '18 S1 - Voronoi Villages (DMOJ): https://dmoj.ca/problem/ccc18s1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N; vector<int> a;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        int x; cin >> x; a.push_back(x);
    }
    sort(a.begin(), a.end());
    double mi = INT_MAX;
    for(int i = 1; i < N-1; i++){
        double cur = (a[i]-a[i-1])/2.0 + (a[i+1]-a[i])/2.0; 
        if(cur < mi) mi = cur;
    }
    printf("%.1f\n", mi);
}
