// CCC '09 S5 - Wireless (DMOJ): https://dmoj.ca/problem/ccc09s5
// ANNOTATED CODE - https://dmoj.ca/src/6900968
#include <bits/stdc++.h>
using namespace std;
int N, M, K, dif[1002][30002], ans, num;
// difference array problem: although it is on a 2D grid, we apply the transformations row for row because we are dealing with circles
// so this is technically just 1D diff array
// prerequisite: knowledge of circles (extra includes parabolas, maybe hyperbolas and ellipses): AOPS Intro and Intermediate Algebra
// formula: for a circle centered at (h, k) with radius r, the points ON the edges of the circle is (x-h)^2 + (y-k)^2 = r^2
// idea: for row i, we find the left (min) and right (max) integer columns that are within or on the circle and apply diff array there. repeat for all rows in the circle
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N >> K;
    for(int i = 1, x, y, r, b; i <= K; i++){ // circle i is centered at (x, y) with radius r. they have a value of b
        cin >> x >> y >> r >> b; // note that y is horizontal and x is vertical in this case
        for(int j = max(1, x-r); j <= min(N, x+r); j++){ // from the bottom row, going to the top row in the circle
            // we do max and min because the circle can go out of the confined space we are given of N rows and M columns
            int d = sqrt(r*r - (x-j) * (x-j)); // circle formula => y +or- d = ?, there are two solutions, - is for min, + is for max
            dif[j][max(1, y-d)] += b; // once again do max and min (look two lines above)
            dif[j][min(M, y+d)+1] -= b; // remember to add 1 (like for all 1D diff array transformations)
        }
    }
    // step 2: apply the 1D diff updates to yield the actual values
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dif[i][j] += dif[i][j-1]; // applying 1D transformations ROW BY ROW (again not 2D diff array because doing 2D rectangular updates on a circle makes no sense)
            // you can check if each value is the maximum like below, it's quite efficient because you don't need a separate loop to check
            if(dif[i][j] > ans){
                ans = dif[i][j];
                num = 1; // draw your attention here
            }
            else if(dif[i][j] == ans) num++;
        }
    }
    cout << ans << endl << num << endl;
}
