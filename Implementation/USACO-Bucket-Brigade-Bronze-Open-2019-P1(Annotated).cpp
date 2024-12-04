// USACO 2019 US Open Contest, Bronze Problem 1. Bucket Brigade (USACO): http://www.usaco.org/index.php?page=viewproblem2&cpid=759
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
int bx, by, lx, ly, rx, ry;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // ifstream cin("buckets.in");
    // ofstream cout("buckets.out");
    // include the above two lines when submitting on usaco.org as the judge requires an output file
    for(int i = 0; i < 10; i++){ // 10 by 10 array
        for(int j = 0; j < 10; j++){
            char c; cin >> c;
            if(c == 'B'){
                bx = i; by = j;
            }
            else if(c == 'L'){
                lx = i; ly = j;
            }
            else if(c == 'R'){
                rx = i; ry = j;
            }
        }
    }
    int min = abs(lx-bx)+abs(ly-by)-1; // if the rock doesn't interrupt the path this is the minimum distance
    if((bx == lx && bx == rx && ((by < ry && ry < ly) || (ly < ry && ry < by))) || (by == ly && by == ry && ((bx < rx && rx < lx) || (lx < rx && rx < bx)))){
        // the if statement checks if the rock is in the way, and the only way it is possible is if both the barn and lake is on the same axis and the rock is in-between those two areas
        min += 2; // if the rock is in the way it will add a cost of 2
    }
    cout << min << endl;
}
