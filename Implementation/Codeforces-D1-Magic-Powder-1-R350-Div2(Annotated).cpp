// D1. Magic Powder - 1 (Codeforces): https://codeforces.com/problemset/problem/670/D1
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e6+3;
struct e {
    int req, total;
    bool operator<(const e &y) const { // considers whether to put this object before another
        return (total/req) > (y.total/y.req); // bigger quotients go to the bottom of the queue (least priority)
    }
};
int N, K, a[MM], b[MM], q[MM]; priority_queue<e> c;
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];
    for (int i = 1; i <= N; i++) {
        c.push({a[i], b[i]});
        q[b[i]/a[i]]++;
    }
    int cur = c.top().total / c.top().req; // # of cookies currently can be made
    while (c.top().req - c.top().total % c.top().req <= K) { // you can make another of ingredient c.top()
        int qCur = c.top().total / c.top().req;
        int rem = c.top().req - c.top().total % c.top().req;
        K -= rem;
        int nTotal = c.top().total + rem, nReq = c.top().req;
        c.pop(); c.push({nReq, nTotal});
        q[qCur]--; q[qCur+1]++;
        if (q[cur] == 0) cur++;
    }
    cout << cur << endl;
}
