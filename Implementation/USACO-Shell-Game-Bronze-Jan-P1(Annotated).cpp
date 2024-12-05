// USACO 2019 January Contest, Bronze Problem 1. Shell Game (USACO) - https://usaco.org/index.php?page=viewproblem2&cpid=783
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 103;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
int N, mx; bool lis[4]; vector<pii> swp; // lis[1] to lis[3] represents the "state" of the ith shell (if true then the rock is under that shell only
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream cin("shell.in");
    ofstream cout("shell.out");
    cin >> N;
    for(int i = 0, x, y, z; i < N; i++){
        cin >> x >> y >> z;
        swp.push_back({{x,y}, z});
    }
    // simulate each scenario
    for(int i = 1; i <= 3; i++){
        // let i represent the shell the rock is initially under
        int cnt = 0; // current score for the ith simulation
        memset(lis, false, 4); lis[i] = true; // all values are false except for the ith cell we are simulating that has the rock
        for(int j = 0; j < N; j++){
            int a = swp[j].first.first, b = swp[j].first.second, g = swp[j].second;
            swap(lis[a], lis[b]); // swap the two shells
            if(lis[g]) cnt++;
        }
        mx = max(mx, cnt); // update the maximum if this situation is where Bessie makes more correct guesses
    }
    cout << mx << endl; // the best of Bessie's scores
}
