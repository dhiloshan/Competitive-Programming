// USACO 2017 December Contest, Bronze Problem 1. Blocked Billboard (USACO) - http://www.usaco.org/index.php?page=viewproblem2&cpid=759
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2003;
int x[7], y[7], sum; bool a[MM][MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // ifstream cin("billboard.in");
    // ofstream cout("billboard.out");
    for(int i = 0; i < 6; i++){
        cin >> x[i] >> y[i];
        x[i] += 1000; y[i] += 1000;
    }
    sum += ((x[1]-x[0])*(y[1]-y[0]) + (x[3]-x[2])*(y[3]-y[2]));
    for(int i = 0; i < 3; i+=2){
        int x1 = x[i], y1 = y[i], x2 = x[i+1], y2 = y[i+1];
        for(int j = x1; j < x2; j++){
            for(int k = y1; k < y2; k++){
                a[j][k] = true;
            }
        }
    }
    int x1 = x[4], y1 = y[4], x2 = x[5], y2 = y[5];
    for(int i = x1; i < x2; i++){
        for(int j = y1; j < y2; j++){
            if(a[i][j]) sum--;
        }
    }
    cout << sum << endl;
}
