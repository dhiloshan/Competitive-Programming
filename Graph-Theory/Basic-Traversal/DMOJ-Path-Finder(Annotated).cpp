// Path Finder (DMOJ): https://dmoj.ca/problem/pathfind
// ANNOTATED CODE - https://dmoj.ca/src/7097069
// the idea is to figure out if there is a path from the left column or bottom row to the top row or right column via the blocked nodes
// don't store the graph, instead hash the nodes
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
#define hsh(r, c) (1LL*r*base+c) // hash function for the node
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    unordered_set<ll> st; // stores the blocked nodes
    cin >> N >> M >> K;
    for(int i = 0, a, b; i < K; i++){
        cin >> a >> b;
        if(a == N || b == 1) q.push({a, b}); // multi-source bfs
        else st.insert(hsh(a, b)); // nodes in the middle of the matrix
    }
    while(!q.empty()){
        auto& [r, c] = q.front(); q.pop();
        for(int i = 0; i < 8; i++){ // in all eight directions is considered adjacent 
            int nr = r + d[i][0], nc = c + d[i][1]; // new coordinates
            if(st.count(hsh(nr, nc))){
                if(nr == 1 || nc == N){ // you can hit the top row or right most column
                    cout << "NO" << endl;
                    return 0;
                }
                q.push({nr, nc}); // continue the bfs
                st.erase(hsh(nr, nc)); // if you don't add this it will run in an infinite loop
            }
        }
    }
    cout << "YES" << endl;
}
