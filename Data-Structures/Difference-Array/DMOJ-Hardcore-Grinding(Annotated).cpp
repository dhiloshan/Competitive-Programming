// Hardcore Grinding (DMOJ Olympiads School Only): https://dmoj.ca/problem/grind
// ANNOTATED CODE (task scheduling problem. min number of machines = max overlap at any given point in time
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e7+3;
int N, dif[MM]; // difference array for 1D range time updates
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0, s, f; i < N; i++){
        cin >> s >> f;
        dif[s]++; dif[f]--; // task starts at s. ends strictly at time f.
    }
    // find the maximum overlap at any given point in time
    int ans = dif[0];
    for(int i = 1; i < MM; i++){
        dif[i] += dif[i-1]; // accumulate past answers (psa)
        ans = max(ans, dif[i]);
    }
    cout << ans << endl;
}
