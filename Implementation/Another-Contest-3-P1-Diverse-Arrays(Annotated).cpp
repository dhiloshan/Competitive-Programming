// Another Contest 3 Problem 1 - Diverse Arrays (DMOJ): https://dmoj.ca/problem/acc3p1
// ANNOTATED CODE - https://dmoj.ca/src/6894609
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, K, a[MM], cnt[MM], s; long long ans;
// sliding window approach (but the window isn't a fixed size) - once we have a window with at least K different numbers,
// count the number of arrays ending from R to ending from N (N - R + 1): this is the number of diverse arrays starting from index L, so increment L by one
// just do this until R reaches N+1
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    // cnt is the frequency array, cnt[i] tells us the number of times the element i appears in array a so far
    for(int l = 1, r = 1; r <= N; r++){
        if(++cnt[a[r]] == 1){ // increases cnt[a[r]], then check
            s++; // s represents the number of elements in our "window" CURRENTLY
        }
        while(s >= K){
            ans += N - r + 1; // this tells us the number of diverse arrays only from index L
            if(--cnt[a[l]] == 0){ // decreases cnt[a[l]] FIRST, then checks
                s--;
            }
            l++; // increment L because we counted the number of diverse arrays starting from this number already
        }
    }
    cout << ans << endl; // # of diverse arrays
}
