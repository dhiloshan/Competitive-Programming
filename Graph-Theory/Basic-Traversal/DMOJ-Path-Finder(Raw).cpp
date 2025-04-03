// Path Finder (DMOJ): https://dmoj.ca/problem/pathfind
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
const int mod = (int)1e9+7;
const int base = (int)1e8+7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
#define f first
#define s second
int N, M, K; queue<pi> q;
int d[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
#define hsh(r, c) (1LL*r*base+c)
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    unordered_set<ll> st;
    cin >> N >> M >> K;
    for(int i = 0, a, b; i < K; i++){
        cin >> a >> b;
        if(a == N || b == 1) q.push({a, b});
        else st.insert(hsh(a, b));
    }
    while(!q.empty()){
        auto& [r, c] = q.front(); q.pop();
        for(int i = 0; i < 8; i++){
            int nr = r + d[i][0], nc = c + d[i][1];
            if(st.count(hsh(nr, nc))){
                if(nr == 1 || nc == N){
                    cout << "NO" << endl;
                    return 0;
                }
                q.push({nr, nc});
                st.erase(hsh(nr, nc));
            }
        }
    }
    cout << "YES" << endl;
}
