// USACO 2020 January Bronze P2 - Photoshoot (DMOJ): https://dmoj.ca/problem/usaco20janb2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e3+2;
int N, b[MM];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++) cin >> b[i];
    for (int a = 1; a <= b[1]-1; a++) {
        unordered_set<int> st; vector<int> nw; 
        st.insert(a); nw.push_back(a);
        int cur = b[1]-a;
        st.insert(cur); nw.push_back(cur);
        for (int j = 2; j <= N-1; j++) {
            cur = b[j] - cur;
            if (cur < 1 || cur > N) 
                break;
            st.insert(cur); nw.push_back(cur);
        }
        if (st.size() == N) { 
            for (int i : nw)
                cout << i << " ";
            cout << endl;
        }
    }
}
