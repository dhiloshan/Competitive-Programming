// CSES Problem Set Static Range Sum Queries (CSES): https://cses.fi/problemset/task/1646
// RAW Code - https://cses.fi/paste/dc3dc5f934838c19adeaad/
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
int N, Q, a[MM]; long long psa[MM];
int main() {
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    psa[1] = a[1];
    for(int i = 2; i <= N; i++){
        psa[i] = a[i] + psa[i-1];
    }
    for(int i = 1, a, b; i <= Q; i++){
        cin >> a >> b;
        cout << psa[b] - psa[a-1] << endl;
    }
}
