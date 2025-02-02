// Arcadia Computing Contest 1 P4 - Cyclic Sorting (DMOJ): https://dmoj.ca/problem/ahscc1p4
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
int N, Q, a[MM]; unordered_set<int> st;
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) {
        int pre = (i - 1 + N) % N; // we use mod to wrap around the array, for ex. if i == 0, pre would correspond to N-1
        if(a[pre] > a[i]) st.insert(i); // if this is an inversion push the index into the set
    }
    for(int i = 1, p, x; i <= Q; i++) {
        cin >> p >> x; p--; // we want 0 index (to make it work with mod)
        if(a[(p-1+N) % N] > a[p]) st.erase(p); // initially erase it if we see an inversion
        if(a[p] > a[(p+1) % N]) st.erase((p+1)%N); // note the use of inversion
        a[p] = x; // set the new value
        if(a[(p-1+N) % N] > a[p]) st.insert(p); // if there is an inversion push the index back in
        if(a[p] > a[(p+1) % N]) st.insert((p+1)%N);
        if(st.size() > 1) cout << -1 << endl; // if there is more than one inversion, no amount of cyclic shifts will work
        else {
            if(st.empty()) cout << 0 << endl; // if there is no inversion, print 0
            else {
                int v = *st.begin(); // this is the index of the inversion (0-indexed, not 1-indexed, this is because our answer is the NUMBER of cyclic shifts, so we want 0-indexed)
                cout << min(v, N - v) << endl; // either do cyclic shifts from the left, or the right
            }
        }
    }
}
