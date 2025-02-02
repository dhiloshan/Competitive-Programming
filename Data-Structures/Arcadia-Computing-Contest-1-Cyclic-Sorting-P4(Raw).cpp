// Arcadia Computing Contest 1 P4 - Cyclic Sorting (DMOJ): https://dmoj.ca/problem/ahscc1p4
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
int N, Q, a[MM]; unordered_set<int> st;
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) {
        int pre = (i - 1 + N) % N;
        if(a[pre] > a[i]) st.insert(i);
    }
    for(int i = 1, p, x; i <= Q; i++) {
        cin >> p >> x; p--;
        if(a[(p-1+N) % N] > a[p]) st.erase(p);
        if(a[p] > a[(p+1) % N]) st.erase((p+1)%N);
        a[p] = x;
        if(a[(p-1+N) % N] > a[p]) st.insert(p);
        if(a[p] > a[(p+1) % N]) st.insert((p+1)%N);
        if(st.size() > 1) cout << -1 << endl;
        else {
            if(st.empty()) cout << 0 << endl;
            else {
                int v = *st.begin();
                cout << min(v, N - v) << endl;
            }
        }
    }
}
