// CCC '24 J5 - Harvest Waterloo (DMOJ): https://dmoj.ca/problem/ccc24j5
// RAW VERSION - https://dmoj.ca/src/6802186
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
const int mod = (int)1e9+7;
const int base = (int)1e8+7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mi;
typedef stack<int> si;
typedef queue<int> qi;
#define f first
#define s second
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define MEM(arr, x) memset(arr, x, sizeof(arr))
#define sorte(vect) sort(vect.begin(), vect.end())
#define sortE(vect) sort(vect.begin(), vect.end(), greater<int>())
#define F0R(x) for(int i = 0; i < x; i++)
#define F1R(x) for(int i = 1; i <= x; i++)
int R, C, A, B, l, m, s;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 

void check(int pumpkin){ // value of a pumpkin
    if(pumpkin == 'L') l++;
    else if(pumpkin == 'M') m++;
    else if(pumpkin == 'S') s++;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    char a[R+5][C+5]; bool vis[R+1000][C+1000];

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }

    cin >> A >> B;
    queue<pi> q; 
    q.push(MP(A, B)); vis[A][B] = true; check(a[A][B]);

    while(!q.empty()){
        int r = q.front().first, c = q.front().second; q.pop();
        for(int i = 0; i < 4; i++){ 
            int nr = r + d[i][0], nc = c + d[i][1]; 
            if(nr > -1 && nc > -1 && nr < R && nc < C && a[nr][nc] != '*' && !vis[nr][nc]){ 
                q.push(MP(nr, nc)); vis[nr][nc] = true;
                check(a[nr][nc]); 
            }
        }
    }
    cout << s + m * 5 + l * 10 << endl;
}
