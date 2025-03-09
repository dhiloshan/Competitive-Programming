/// CCC '25 S1 - Positioning Peter's Paintings (DMOJ): https://dmoj.ca/problem/ccc25s1
// ANNOTATED CODE - https://dmoj.ca/src/7052116
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3; // check only two possibilites
int a, b, x, y;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> x >> y;
    int p1 = 2 * (a + x) + 2 * max(b, y);
    int p2 = 2 * (b + y) + 2 * max(a, x);
    cout << min(p1, p2) << endl;
}
