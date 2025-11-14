// COCI '16 Contest 6 #3 Turnir (DMOJ): https://dmoj.ca/problem/coci16c6p3
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = (1<<20)+3;
typedef long long ll;
typedef pair<int, int> pi;
struct e {
    int val, idx, rank;
    //  val is the value of the number; idx is the position in the original input array; rank is the location of the number in our new data set. it represents how far up it can go (the answer the question is looking for)
};
int N, ans; vector<e> u; vector<e*> adj[21];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0, x; i < 1<<N; i++){
        cin >> x; u.push_back({x, i, -1});
    }
    sort(u.begin(), u.end(), [](const e &x, const e &y) {
        return x.val < y.val;
    });
    // apply ranks
    int idx = 0;
    for(int i = 0; i < N; i++){
        int curEnd = idx + (1<<i);
        for(auto it = u.begin()+idx; it < u.begin()+curEnd; it++){
            it->rank = N-i;
            adj[it->rank].push_back(&*it);
            idx++;
        }
    }
    u.rbegin()->rank = 0;
    adj[0].push_back(&*u.rbegin());
    // apply merges if adjacent elements on the border are the same
    for(int rnk = 1; rnk <= N; rnk++){
        if(adj[rnk][ (adj[rnk].size())-1 ]->val == adj[rnk-1][0]->val){ // if the last element of the current rank array equals the first element of the lesser rank array
            auto above = adj[rnk-1][0];
            for(int i = adj[rnk].size()-1; i >= 0; i--)
                if(above->val == adj[rnk][i]->val)
                    adj[rnk][i]->rank = above->rank;
        }
    }
    sort(u.begin(), u.end(), [](const e &x, const e &y) {
        return x.idx < y.idx; // restore to original input order
    });
    for(auto it = u.begin(); it != u.end()-1; it++){
        cout << it->rank << " ";
    }
    cout << u.rbegin()->rank << endl; // last element
}
