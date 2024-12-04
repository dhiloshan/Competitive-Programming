// USACO 2017 December Contest, Bronze Problem 1. Blocked Billboard (USACO) - http://www.usaco.org/index.php?page=viewproblem2&cpid=759
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2003;
int x[7], y[7], sum; bool a[MM][MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // ifstream cin("billboard.in");
    // ofstream cout("billboard.out");
    for(int i = 0; i < 6; i++){
        cin >> x[i] >> y[i]; // better to store the x and y coordinate array than having an explicit nam
        x[i] += 1000; y[i] += 1000; // [-1000, 1000] => [0, 2000]
    }
    sum += ((x[1]-x[0])*(y[1]-y[0]) + (x[3]-x[2])*(y[3]-y[2])); // calculates the area of the two billboards
    for(int i = 0; i < 3; i+=2){ // goes through the first two billboards
        int x1 = x[i], y1 = y[i], x2 = x[i+1], y2 = y[i+1]; // (x1, y1) bottom left corner; (x2, y2) top-right corner
        for(int j = x1; j < x2; j++){ // [x1, x1+1, x1+2, ..., x2) start at x1 inclusive and x2 exclusive
            for(int k = y1; k < y2; k++){ // [y1, y1+1, y1+2, ..., y2) start at y1 inclusive and y2 exclusive
                                        // https://youtu.be/CMhfNfiqkWQ?si=wmGNeWEv1zlVTvRK&t=246
                                        // (1, 2) bottom left, (3, 5) top right
                                        // x: 1, 2; y: 2, 3, 4
                                        // there are 6 choices => 6 u^2 which it is supposed to be, but if we included 3 and 5, then the area would be 12
                a[j][k] = true; // set it to true to represent of the billboard cells
            }
        }
    }
    int x1 = x[4], y1 = y[4], x2 = x[5], y2 = y[5]; // (x1, y1) is the bottom left corner of the truck, (x2, y2) is the top right corner of the truck
    for(int i = x1; i < x2; i++){ // inclusive x1 but exclusive x2
        for(int j = y1; j < y2; j++){ // inclusive y1 but exclusive y2
            if(a[i][j]) sum--; // if this is a billboard cell it is being covered by the truck cell so minus the amount of cells visible by 1
        }
    }
    cout << sum << endl; // number of remaining visible billboard cells
}
