// USACO 2018 December Contest, Bronze Problem 1. Mixing Milk (USACO) - https://usaco.org/index.php?page=viewproblem2&cpid=783
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
int c[4], a[4]; 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ifstream cin("mixmilk.in");
    // ofstream cout("mixmilk.out");
    for(int i = 1; i <= 3; i++){
        cin >> c[i] >> a[i];
    }
    for(int i = 1; i <= 100; i++){ 
        int x = i%3, y = x+1; 
        if(x == 0) x = 3; 
        int rem = c[y] - a[y]; 
        if (a[x] <= rem) {
            a[y] += a[x]; 
            a[x] = 0;
        }
        else {
            a[x] -= rem; 
            a[y] = c[y];
        }
    }
    for(int i = 1; i <= 3; i++){
        cout << a[i] << endl;
    }
}
