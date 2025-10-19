// CCC '21 S1 - Crazy Fencing (DMOJ): https://dmoj.ca/problem/ccc21s1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N; vector<int> a, b;
int main(){
    cin >> N;
    for(int i = 0, x; i <= N; i++){
        cin >> x; a.push_back(x);
    }
    for(int i = 0, x; i < N; i++){
        cin >> x; b.push_back(x);
    }
    double area = 0;
    for(int i = 0; i < N; i++){
        int hl = a[i], hr = a[i+1], w = b[i];
        int bt = min(hl, hr);
        int tp = max(hl, hr) - bt;
        area += (bt * w) + (tp * w) / 2.0;
    }
    printf("%.6f", area);
}
