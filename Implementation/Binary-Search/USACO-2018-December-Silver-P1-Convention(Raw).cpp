// USACO 2018 December Silver P1 - Convention (DMOJ Olympiads School Only): https://dmoj.ca/problem/usaco18decsilvp1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef long long ll;
int N, M, C, t[MM], dif[MM];
bool check(int cost) {
    int groupsCur = 1, costCur = 0, groupSizeCur = 0;
    for (int i = 1; i <= N; i++) {
        costCur += dif[i]; groupSizeCur++;
        if (costCur > cost || groupSizeCur > C) {
            costCur = 0; groupsCur++; groupSizeCur = 1;
        }
    }
    if (groupsCur > M) return false;
    else return true;
}
int main() {
    cin >> N >> M >> C;
    for (int i = 1; i <= N; i++) cin >> t[i];
    sort(t+1, t+N+1);
    dif[1] = 0; 
    for (int i = 2; i <= N; i++) {
        dif[i] = t[i] - t[i-1];
    } 
    int lo = 0, hi = 1e9; 
    while (hi - lo > 1) {
        int mi = lo + (hi - lo) / 2;
        if (check(mi)) hi = mi;
        else lo = mi;
    }
    cout << hi << endl;
}
