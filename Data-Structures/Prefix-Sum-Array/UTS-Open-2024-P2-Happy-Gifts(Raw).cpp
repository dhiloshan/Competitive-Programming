// UTS Open '24 P2 - Happy Gifts (DMOJ): https://dmoj.ca/problem/utso24p2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1001;
typedef long long ll;
int N, K; vector<int> p, n;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 1, x; i <= N; i++){
        cin >> x;
        if(x >= 0) p.push_back(x);
        else n.push_back(abs(x));
    }
    sort(p.begin(), p.end(), greater<int>());
    sort(n.begin(), n.end(), greater<int>());
    vector<ll> p_psa(p.size()+1, 0), n_psa(n.size()+1, 0);
    for(int i = 1; i <= p.size(); i++){
        p_psa[i] = p_psa[i-1] + p[i-1];
    }
    for(int i = 1; i <= n.size(); i++){
        n_psa[i] = n_psa[i-1] + n[i-1];
    }
    ll mx = 0;
    for(int pt = 0; pt <= K; pt++){
        int nTotal = (K-pt)/2;
        if(nTotal > n.size() && pt > p.size()) break;
        ll sum = n_psa[min(nTotal, (int)n.size())] + p_psa[min(pt, (int)p.size())];
        mx = max(mx, sum);
    }
    cout << mx << endl;
}
