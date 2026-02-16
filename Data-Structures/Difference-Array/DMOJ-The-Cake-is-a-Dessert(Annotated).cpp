// The Cake is a Dessert (DMOJ Olympiad Schools Only): https://dmoj.ca/problem/oly19practice25
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
const int base = 1e4+7;
const int MOD = 1e9+7;
typedef long long ll;
int N, M, K, Q; ll psa[MM][MM], dif[MM][MM];
int main() {
    cin >> N >> M >> K;
    for (int i = 1, a, b, x, y; i <= K; i++) {
        cin >> a >> b >> x >> y;
        dif[a][b]++; dif[x+1][b]--;
        dif[a][y+1]--; dif[x+1][y+1]++;
        // visualize a rectangle and the sum of that rectangle's differences to see why we update the cells shown above
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1]; // propagate the changes. how much icing has been added to this cell?
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + dif[i][j]; // how much icing is from (1, 1) to (i, j)?
        }
    }
    cin >> Q;
    for (int i = 1, a, b, x, y; i <= Q; i++) {
        cin >> a >> b >> x >> y; // some people do a-- and b-- to get rid of the need to do a-1 or b-1 in the final answer. same thing for diff updates
        cout << psa[x][y] - psa[x][b-1] - psa[a-1][y] + psa[a-1][b-1] << endl;
    }
}
