// SOLUTION 2: 0-1 BFS O(V + E) - modified Dijkstra for a graph with edges weighing 0 or 1
// CCC '18 S3 - RoboThieves (DMOJ): https://dmoj.ca/problem/ccc18s3
// RAW CODE - https://dmoj.ca/src/6847066
#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
int N, M, dis[MM][MM]; bool vis[MM][MM]; char g[MM][MM]; vector<pi> cam; deque<pii> q; pi st;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void push(int w, int s, int r, int c){
    if(g[r][c] != 'W' && !vis[r][c] && dis[r][c] > w){
        if(s == 0) q.push_front({w, {r, c}});
        else q.push_back({w, {r, c}});
        dis[r][c] = w;
    }
}
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> g[i][j];
            if(g[i][j] == 'S'){ st.first = i; st.second = j; g[i][j] = '.'; }
            else if(g[i][j] == 'C'){ cam.emplace_back(i, j); vis[i][j] = true; }
        }
    }
    for(auto [r, c] : cam){
        for(int k = 0; k < 4; k++){
            int nr = r + d[k][0], nc = c + d[k][1];
            while(nr > 1 && nr < N && nc > 1 && nc < M && g[nr][nc] != 'W'){
                if(g[nr][nc] == '.') vis[nr][nc] = true;
                nr += d[k][0]; nc += d[k][1];
            }
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    if(!vis[st.first][st.second]){
        dis[st.first][st.second] = 0; q.push_front({0, {st.first, st.second}});
    }
    while(!q.empty()){
        auto [w, pos]  = q.front(); q.pop_front();
        int r = pos.first, c = pos.second;
        if(w > dis[r][c]) continue;
        if(g[r][c] == '.')
            for(int k = 0; k < 4; k++)
                push(dis[r][c] + 1, 1, r + d[k][0], c + d[k][1]);
        else if(g[r][c] == 'L') push(dis[r][c], 0, r, c-1);
        else if(g[r][c] == 'R') push(dis[r][c], 0, r, c+1);
        else if(g[r][c] == 'U') push(dis[r][c], 0, r-1, c);
        else if(g[r][c] == 'D') push(dis[r][c], 0, r+1, c);
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(g[i][j] == '.' && !(i == st.first && j == st.second)) cout << (dis[i][j]==0x3f3f3f3f? -1 : dis[i][j]) << endl;
        }
    }
}
