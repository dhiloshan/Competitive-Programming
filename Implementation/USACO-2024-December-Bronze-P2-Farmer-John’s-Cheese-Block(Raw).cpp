// USACO 2024 December Bronze P2 - Farmer John's Cheese Block (DMOJ Olympiad School Only): https://dmoj.ca/problem/usaco24decb2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int xy[MM][MM], xz[MM][MM], yz[MM][MM];
int N, Q, cnt;
int main() { 
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> Q;
  for(int i = 0, x, y, z; i < Q; i++){
    cin >> x >> y >> z;
    xy[x][y]++; xz[x][z]++; yz[y][z]++;
    if(xy[x][y] == N) cnt++;
    if(xz[x][z] == N) cnt++;
    if(yz[y][z] == N) cnt++;
    
    cout << cnt << endl;
  }
}
