// CCC '10 J5 - Knight Hop (CCC): https://dmoj.ca/problem/ccc10j5
// RAW CODE - https://dmoj.ca/src/6772224
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int sx, sy, ex, ey, dis[8][8]; bool vis[8][8];
int transf[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};
struct Coord {
    int x, y;
};
int main(){
    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;
    queue<Coord> q;
    q.push({sx, sy}); vis[sx][sy] = true; dis[sx][sy] = 0;
    while(!q.empty()){
        Coord cur = q.front(); q.pop();
        for(int i = 0; i < 8; i++){
            int nx = cur.x + transf[i][0], ny = cur.y + transf[i][1];
            if(nx > -1 && nx < 8 && ny > -1 && ny < 8 && !vis[nx][ny]){
                q.push({nx, ny});
                vis[nx][ny] = true;
                dis[nx][ny] = dis[cur.x][cur.y] + 1;
            }
        }
    }
    cout << dis[ex][ey] << endl;
}
