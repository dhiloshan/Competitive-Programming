// USACO 2016 December Contest, Bronze Problem 3. The Cow-Signal (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=665
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
int N, M, K; char a[10][10];
/* instead of thinking K times bigger in each direction, think about magnifying pixel (i, j) by K times
this is much easier to think about
for each pixel, you want to magnify each pixel on the 2D coordinate plane, so one for the x-coordinate, one for the y-coordinate
first think about magnifying line i in the x-direction only
we look for each pixel on the 1D dimension with one for loop, but within that we print that pixel K times
for magnifying on the 2D plane is the same idea, for the y-direction, have an inner loop that magnifies pixel (i, j) on the y direction K times
*/
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ifstream cin("cowsignal.in");
    // ofstream cout("cowsignal.out");
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < N; i++){ 
        for(int k1 = 0; k1 < K; k1++){
            for(int j = 0; j < M; j++){
                for(int k2 = 0; k2 < K; k2++){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}
