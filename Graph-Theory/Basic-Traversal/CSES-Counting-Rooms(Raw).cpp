// CSES Problem Set Counting Rooms (CSES): https://cses.fi/problemset/task/1192/
// RAW Code - https://cses.fi/paste/8ae48fbdaf0df2a1adea5f/
#include <bits/stdc++.h>
using namespace std;
const int MM = 1003;
typedef pair<int, int> pi;
int N, M, cnt; bool vis[MM][MM]; char a[MM][MM]; vector<pi> dots;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            if(a[i][j] == '.') dots.emplace_back(i, j);
        }
    }
    for(auto& [i, j] : dots){
        if(!vis[i][j]){
            vis[i][j] = true; cnt++;
            queue<pi> q;
            q.push({i, j});
            while(!q.empty()){
                auto& [ci, cj] = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int ni = ci + d[i][0], nj = cj + d[i][1];
                    if(ni < N && ni > -1 && nj < M && nj > -1 && !vis[ni][nj] && a[ni][nj] == '.'){
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}
