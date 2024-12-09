// USACO 2020 December Contest, Bronze Problem 1. Do You Know Your ABCs? (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=1059
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
int a[7], total, A, B, C;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 7; i++){
        cin >> a[i];
    }
    sort(a, a+7);
    total = a[6], A = a[0], B = a[1], C = total - A - B;
    cout << A << " " << B  << " " << C << endl;
}
