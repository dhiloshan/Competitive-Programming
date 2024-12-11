// CSES Problem Set Static Range Sum Queries (CSES): https://cses.fi/problemset/task/1646
// ANNOTATED Code - https://cses.fi/paste/37084022b370bbd8adead0/
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
int N, Q, a[MM]; long long psa[MM]; // psa template question
// use of long long since a[i] can reach 10^9
int main() {
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> a[i]; // could also put the psa code here but I decided to separate it
    }
    psa[1] = a[1];
    for(int i = 2; i <= N; i++){
        psa[i] = a[i] + psa[i-1];
    }
    for(int i = 1, a, b; i <= Q; i++){
        cin >> a >> b;
        cout << psa[b] - psa[a-1] << endl; // psa formula for range sum L to R
    }
}
