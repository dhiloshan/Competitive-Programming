// CCC '21 S2 - Modern Art (DMOJ): https://dmoj.ca/problem/ccc21s2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 5e6+2;
int N, M, K; char c; bool col[MM], row[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> M >> N >> K;
    for(int i = 0, cur; i < K; i++){
        cin >> c >> cur;
        if(c == 'R') row[cur] = !row[cur];
        else col[cur] = !col[cur];
    }
    int ans = 0;
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++)
            if(!(row[i] == col[j]))
                ans++;
                
    cout << ans << endl;
}
