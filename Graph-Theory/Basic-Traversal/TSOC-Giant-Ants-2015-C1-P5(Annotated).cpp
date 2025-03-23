// TSOC '15 Contest 1 #5 - Giant Ants (DMOJ): https://dmoj.ca/problem/tsoc15c1p5
// ANNOTATED CODE - https://dmoj.ca/src/7077368
#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int N, M, W, ant[MM], dis[MM]; vector<int> adj[MM]; bool vis[MM]; queue<int> q;
int main(){
    cin >> N >> M;
    for(int i = 0, x, y; i < M; i++){
        cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    cin >> W;
    for(int i = 0, x; i < W; i++){
        cin >> x;
        q.push(x); ant[x]=0; vis[x]=1; // multi-source bfs
    }
    while(!q.empty()){ // bfs for ants
        int cur = q.front(); q.pop(); 
        for(int nxt : adj[cur]){
            if(!vis[nxt]){
                q.push(nxt); ant[nxt] = ant[cur] + 4; vis[nxt] = true; // ant speed is slower; add by 4
            }
        }
    }
    memset(vis, false, sizeof(vis));
    q.push(1); dis[1] = 0; vis[1] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt: adj[cur]){
            if(!vis[nxt] && dis[cur] + 1 < ant[nxt]){ // smart check to see if the car can go to the node
                dis[nxt] = dis[cur] + 1; vis[nxt] = true; q.push(nxt);
            }
        }
    }
    if(vis[N]) cout << dis[N] << endl; // check if the car can even reach node N
    else cout << "sacrifice bobhob314" << endl;
}
