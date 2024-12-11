// CCC '10 J5 - Knight Hop (DMOJ): https://dmoj.ca/problem/ccc10j5
// ANNOTATED CODE - https://dmoj.ca/src/6772221
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int sx, sy, ex, ey, dis[8][8]; bool vis[8][8];
int transf[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}}; // how the knight moves, for ex. moves 2 squares to the right (x-axis) and one square up (y-axis) "mathematical transformation"
struct Coord { // makes life easier; start using struct so you don't need to use .first or .second
    int x, y;
};
int main(){
    cin >> sx >> sy >> ex >> ey; // starting and ending coordinates
    sx--; sy--; ex--; ey--; // we want everything to be 0-indexed

    // BFS traversal: min distance
    queue<Coord> q;
    q.push({sx, sy}); vis[sx][sy] = true; dis[sx][sy] = 0;
    while(!q.empty()){
        Coord cur = q.front(); q.pop();
        for(int i = 0; i < 8; i++){
            int nx = cur.x + transf[i][0], ny = cur.y + transf[i][1];
            if(nx > -1 && nx < 8 && ny > -1 && ny < 8 && !vis[nx][ny]){ // check if in bounds AND if not visited (if it is, loop will run forever [make sure you see why!])
                q.push({nx, ny});
                vis[nx][ny] = true;
                dis[nx][ny] = dis[cur.x][cur.y] + 1;
            }
        }
    }
    cout << dis[ex][ey] << endl; //guaranteed for this cell to be visited, so we don't need ot check if vis[ex][ey]
}
