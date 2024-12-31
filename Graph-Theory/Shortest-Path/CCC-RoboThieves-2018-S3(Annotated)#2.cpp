// SOLUTION 2: 0-1 BFS O(V + E) - modified Dijkstra for a graph with edges weighing 0 or 1
// CCC '18 S3 - RoboThieves (DMOJ): https://dmoj.ca/problem/ccc18s3
// ANNOTATED CODE - https://dmoj.ca/src/6847057
#include <bits/stdc++.h>
using namespace std;
const int MM = 102;
typedef pair<int, int> pi;
typedef pair<int, pi> pii; // (weight, node) => (weight, r, c) for a grid
int N, M, dis[MM][MM]; bool vis[MM][MM]; char g[MM][MM]; vector<pi> cam; deque<pii> q; pi st;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void push(int w, int s, int r, int c){ // push function to update distance and check validity
    // let s represent the state (weight) of the edge, either being 0 or 1
    if(g[r][c] != 'W' && !vis[r][c] && dis[r][c] > w){ // if the cell is not a wall cell, can't be seen by a camera, and there is a better path (dis[r][c] is the OLD cost, w is the new cost during 0-1 bfs)
        // state is either 0 or 1, where 0 gets more priority
        if(s == 0) q.push_front({w, {r, c}}); // pushing it to the front because it is the cheaper edge
        else q.push_back({w, {r, c}}); // process it later
        dis[r][c] = w; // mark the new, cheaper cost
    }
}
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> g[i][j];
            if(g[i][j] == 'S'){ st.first = i; st.second = j; g[i][j] = '.'; } // treat start cell like an empty cell
            else if(g[i][j] == 'C'){ cam.emplace_back(i, j); vis[i][j] = true; } // if cell (i, j) is "visited", it means it can be seen by a camera
        }
    }
    // preprocess cameras
    for(auto [r, c] : cam){
        for(int k = 0; k < 4; k++){
            int nr = r + d[k][0], nc = c + d[k][1]; // new coordinates according to transformation from array d
            while(nr > 1 && nr < N && nc > 1 && nc < M && g[nr][nc] != 'W'){ // if the cell is in bounds and isn't a wall cell (we don't do nr >= 1) because when nr = 1 or when nc = 1, it is a wall guaranteed according to the problem statement
                if(g[nr][nc] == '.') vis[nr][nc] = true; // only if the cell is empty we mark it vis (cameras can't see conveyors according to problem statement)
                nr += d[k][0]; nc += d[k][1]; // apply transformation
            }
        }
    }
    memset(dis, 0x3f, sizeof(dis)); // initialize distance array to infinity
    if(!vis[st.first][st.second]){
        dis[st.first][st.second] = 0; q.push_front({0, {st.first, st.second}}); // from start node to (r, c) it costs w at the time it was pushed into the queue
    }
    // 0-1 bfs (pretty similar to dijkstra)
    while(!q.empty()){
        auto [w, pos]  = q.front(); q.pop_front();
        int r = pos.first, c = pos.second;
        if(w > dis[r][c]) continue; // outdated distance is ignored, at the time we pushed this distance, source node to (r, c) with cost w was the best choice AT THAT POINT IN TIME, not now
        if(g[r][c] == '.')
            for(int k = 0; k < 4; k++) // for each possible direction
                push(dis[r][c] + 1, 1, r + d[k][0], c + d[k][1]); // it is an empty cell so it costs 1 to get from (r, c) to ("nr", "nc") [or neighbouring cell]
        else if(g[r][c] == 'L') push(dis[r][c], 0, r, c-1); // notice we push dis[r][c] instead of dis[r][c] + 1
        else if(g[r][c] == 'R') push(dis[r][c], 0, r, c+1); // that's because conveyors cost 0, and they automatically move you to a specified cell according to its direction
        else if(g[r][c] == 'U') push(dis[r][c], 0, r-1, c); // ALSO, we are doing 0 instead of 1 for s, because it is a conveyor cell, so it costs 0 to get from (r, c) to its adjacent cell
        else if(g[r][c] == 'D') push(dis[r][c], 0, r+1, c);
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(g[i][j] == '.' && !(i == st.first && j == st.second)) cout << (dis[i][j]==0x3f3f3f3f? -1 : dis[i][j]) << endl;
            // if node isn't start node, is empty, and can't be seen by a camera (checking if dis[i][j] is "INF"), print out its min distance
            // we don't check vis[i][j] because although an empty cell may not be seen by a camera, it may not be able to be visited entirely due to a wall
            // 0x3f3f3f3f is 0x3f in all four bytes of int to represent infinity (memset fills in 0x3f, byte by byte)
        }
    }
}
