// Another Contest 3 Problem 1 - Diverse Arrays (DMOJ): https://dmoj.ca/problem/acc3p1
// RAW CODE - https://dmoj.ca/src/6894598
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, K, a[MM], cnt[MM], s; long long ans;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }



    for(int l = 1, r = 1; r <= N; r++){
        if(++cnt[a[r]] == 1){ // increases cnt[a[r]], then check
            s++;
        }

        while(s >= K){
            ans += N - r + 1;
            if(--cnt[a[l]] == 0){ // decreases cnt[a[l]] FIRST, then checks
                s--;
            }
            l++;
        }
    }

    cout << ans << endl;
}
