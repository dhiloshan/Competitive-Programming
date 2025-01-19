// The Cosmic Era P3 - Battle Positions (DMOJ): https://dmoj.ca/problem/seed3
// ANNOTATED CODE - https://dmoj.ca/src/6899418
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int I, N, J, dif[MM], ans;
// template for 1D difference array (range update)
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> I >> N >> J;
    for(int i = 1, l, r, k; i <= J; i++){
        cin >> l >> r >> k;
        dif[l] += k; dif[r+1] -= k; // update points L and R+1 for +K and -K respectively
    }
    // second step of difference array is to iterate and to apply all updates
    // the dif array now holds the increments and decrements for ranges, but not the actual values of the original array yet
    for(int i = 1; i <= I; i++){
        dif[i] += dif[i-1]; // adds the cumulative effect of previous updates to the current index i; converts the updates into the actual values
        if(dif[i] < N) ans++; // if there is not enough troops
    }
    cout << ans << endl;
}
