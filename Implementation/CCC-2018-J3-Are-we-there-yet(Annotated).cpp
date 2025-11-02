// CCC '18 J3 - Are we there yet? (DMOJ): https://dmoj.ca/problem/ccc18j3
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5], psa[5];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 4; i++){
        cin >> a[i]; psa[i] = psa[i-1] + a[i];
    }
    for(int i = 0; i <= 4; i++){
        // left half
        for(int j = 0; j < i; j++){
            cout << psa[i] - psa[j] << " ";
        }
        // right half
        for(int k = i; k <= 4; k++){
            cout << psa[k] - psa[i] << " ";
        }
        cout << endl;
    }
}
