// USACO 2020 January Bronze P2 - Photoshoot (DMOJ): https://dmoj.ca/problem/usaco20janb2
// ANNOTATED CODE O(N) Math derived clever approach
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e3+2;
int N, b[MM];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++) cin >> b[i];

    int oddMi = 0;
    int evenMi = b[1];
    int constantCur = b[1];

    for (int x = 3; x <= N; x++) {
        constantCur = b[x-1] - constantCur;
        if (x % 2 == 1)
            oddMi = min(oddMi, constantCur);
        else
            evenMi = min(evenMi, constantCur);
    }

    int a1OddSolution = 1 - oddMi;
    int a1EvenSolution = evenMi - 1;

    vector<int> a1Solutions = {a1OddSolution, a1EvenSolution};
    sort(a1Solutions.begin(), a1Solutions.end());

    for (int a1 : a1Solutions) {
        unordered_set<int> st; st.insert(a1);
        vector<int> a; a.push_back(a1);
        int cur = b[1] - a1;
        if (cur < 1 || cur > N) break;
        st.insert(cur); a.push_back(cur);
        for (int i = 2; i <= N-1; i++) {
            int num = b[i] - cur;
            if (num < 1 || num > N) break;
            a.push_back(num); st.insert(num);
            cur = num;
        }
        if (st.size() == N) {
            for (int i : a)
                cout << i << " ";
            cout << endl;
        }
    }
}
