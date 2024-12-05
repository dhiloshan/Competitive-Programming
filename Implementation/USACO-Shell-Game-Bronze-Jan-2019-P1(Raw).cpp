// USACO 2019 January Contest, Bronze Problem 1. Shell Game (USACO) - https://usaco.org/index.php?page=viewproblem2&cpid=783
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 103;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
int N, mx; bool lis[4]; vector<pii> swp;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ifstream cin("shell.in");
    // ofstream cout("shell.out");
    cin >> N;
    for(int i = 0, x, y, z; i < N; i++){
        cin >> x >> y >> z;
        swp.push_back({{x,y}, z});
    }
    for(int i = 1; i <= 3; i++){
        int cnt = 0;
        memset(lis, false, 4); lis[i] = true;
        for(int j = 0; j < N; j++){
            int a = swp[j].first.first, b = swp[j].first.second, g = swp[j].second;
            swap(lis[a], lis[b]);
            if(lis[g]) cnt++;
        }
        mx = max(mx, cnt);
    }
    cout << mx << endl;
}
