// 2spooky4me (DMOJ): https://dmoj.ca/problem/2spooky4me
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e4+5;
int N, L, S, dif[MM], a[MM], b[MM], c[MM], ans; map<int, int> coor; vector<int> points;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> S;

    points.push_back(1); points.push_back(L+1);

    for(int i = 1; i <= N; i++){
        cin >> a[i] >> b[i] >> c[i];
        points.push_back(a[i]); points.push_back(b[i]+1); // pushing the start and end points of the decorations
    }

    sort(points.begin(), points.end()); // sorting it so we can put virtual ranks

    for(int i = 0; i < points.size(); i++){
        coor[points[i]] = i; // assigning virtual ranks
    }

    for(int i = 1; i <= N; i++){
        dif[coor[a[i]]] += c[i];
        dif[coor[b[i]+1]] -= c[i]; // dif array range updates from L to R using the virtual ranks
    }

    for(int i = 1; i < points.size(); i++){
        dif[i] += dif[i-1]; // update all values after range input updates
    }

    for(int i = 0; i+1 < points.size(); i++){
        if(dif[i] < S){
            ans += (points[i+1] - points[i]); // adding intervals of real values from houses points[i] to points[i+1]-1
        }
    }

    cout << ans << endl;
}
