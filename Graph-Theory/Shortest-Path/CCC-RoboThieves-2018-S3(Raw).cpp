// CCC '18 S3 - RoboThieves (DMOJ): https://dmoj.ca/problem/ccc18s3
// RAW CODE - https://dmoj.ca/src/6846379
#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
typedef pair<int, int> pi;
int N, M, dir[4][2]={{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; char g[MM][MM]; bool vis[MM][MM]; pi st; vector<pi> cam;
int dis[MM][MM]; priority_queue<array<int, 3>> q;
void push(int r, int c, int d){
    if(g[r][c] != 'W' && !vis[r][c] && dis[r][c] > d) {
            q.push({-d, r, c}); dis[r][c] = d;
    }
}
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> g[i][j];
            if(g[i][j] == 'S') st = {i, j};
            if(g[i][j] == 'C') cam.push_back({i, j});
        }
    }
    for(auto e: cam){
        for(int k=0; k<4; k++){
            int r = e.first, c = e.second;
            while(g[r][c] != 'W'){
                if(g[r][c]=='.' || g[r][c]=='S') vis[r][c] = 1;
                r += dir[k][0]; c += dir[k][1];
            }
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    if(!vis[st.first][st.second]) { q.push({0, st.first, st.second});  dis[st.first][st.second] = 0;}
    while(!q.empty()){
        auto [d, r, c] = q.top(); q.pop();  d=-d;
        if(d > dis[r][c]) continue;
        if(g[r][c] == '.' || g[r][c] == 'S'){
            for(int k=0; k<4; k++)
                push(r + dir[k][0], c + dir[k][1], dis[r][c]+1);
        }else if(g[r][c] == 'L') push(r, c-1, dis[r][c]);
        else if(g[r][c] == 'R') push(r, c+1, dis[r][c]);
        else if(g[r][c] == 'U') push(r-1, c, dis[r][c]);
        else if(g[r][c] == 'D') push(r+1, c, dis[r][c]);
    }
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if(g[i][j] == '.') cout << (dis[i][j]==0x3f3f3f3f? -1: dis[i][j]) << "\n";
}
