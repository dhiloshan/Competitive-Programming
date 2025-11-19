// CCC '20 S1 - Surmising a Sprinter's Speed (DMOJ): https://dmoj.ca/problem/ccc20s1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int N; vector<pi> v;
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N;
  for(int i = 0; i < N; i++){
    int t, p; cin >> t >> p;
    v.push_back({t, p});
  }
  sort(v.begin(), v.end());
  double mx = 0;
  for(int i = 1; i < N; i++){
    mx = max(mx, (double)abs(v[i].second - v[i-1].second) / (v[i].first - v[i-1].first));
  }
  printf("%.5f\n", mx);
}
