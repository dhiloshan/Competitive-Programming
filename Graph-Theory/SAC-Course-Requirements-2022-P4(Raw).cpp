// SAC '22 Code Challenge 5 Junior P4 - Course Requirements (SAC): https://dmoj.ca/problem/sac22cc5jp4
// RAW CODE - https://dmoj.ca/src/6779027
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
int N, in[MM]; vector<int> adj[MM], topo; queue<int> q;
int main(){
    cin >> N;
    for(int i = 1, c; i <= N; i++){
        cin >> c;
        in[i] = c;
        if(c == 0){
            q.push(i);
            topo.push_back(i);
        }
        for(int j = 1, x; j <= c; j++){
            cin >> x;
            adj[x].push_back(i);
        }
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(--in[nxt] == 0){
                q.push(nxt);
                topo.push_back(nxt);
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << topo[i] << " \n"[i==N-1];
    }
}
