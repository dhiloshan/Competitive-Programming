// CSES Problem Set Counting Rooms (CSES): https://cses.fi/problemset/task/1192/
// ANNOTATED Code - https://cses.fi/paste/3c63e1cef9142f6cadea83/
#include <bits/stdc++.h>
using namespace std;
const int MM = 1003;
typedef pair<int, int> pi;
int N, M, cnt; bool vis[MM][MM]; char a[MM][MM]; vector<pi> dots;
// perform BFS on each individual dot, unless it was already visited before
// every time you perform BFS, increment cnt by 1
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // one can move in 4 directions
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            if(a[i][j] == '.') dots.emplace_back(i, j); // stores the location of all of the dots
        }
    }
    for(auto& [i, j] : dots){
        if(!vis[i][j]){ // only performing BFS on new rooms
            vis[i][j] = true; cnt++;
            queue<pi> q;
            q.push({i, j});
            while(!q.empty()){
                auto& [ci, cj] = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int ni = ci + d[i][0], nj = cj + d[i][1];
                    if(ni < N && ni > -1 && nj < M && nj > -1 && !vis[ni][nj] && a[ni][nj] == '.'){ // make sure it is in bounds, not visited, and it is a floor tile not a wall tile
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}
