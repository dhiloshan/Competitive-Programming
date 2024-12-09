// USACO 2020 December Contest, Bronze Problem 1. Do You Know Your ABCs? (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=1059
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
int a[7], total, A, B, C;
// the logic is we can guarantee that the smallest two numbers is A and B, but C may not be the third smallest number as it could be A+B
// to find C, just subtract the total (has to be the biggest number since all numbers are POSITIVE) from A and B
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // don't need to include input and output files; they will provide input from terminal
    for(int i = 0; i < 7; i++){
        cin >> a[i];
    }
    sort(a, a+7); // make the list in ascending order
    total = a[6], A = a[0], B = a[1], C = total - A - B;
    cout << A << " " << B  << " " << C << endl;
}
