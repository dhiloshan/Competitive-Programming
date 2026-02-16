// DMPG '15 S5 - Black and White (DMOJ): https://dmoj.ca/problem/dmpg15s5
// RAW CODE (classic dif question. 0-indexed -> 1-indexed. use bool to fit memory constraint. XOR operation represents the flip operation)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+3;
const int base = 1e4+7;
const int MOD = 1e9+7;
typedef long long ll;
int N, K; bool dif[MM][MM];
int main() {
    cin >> N >> K;
    for (int i = 1, x, y, w, h; i <= K; i++) {
        cin >> x >> y >> w >> h; x++; y++;
        dif[x][y] ^= 1; dif[x+w][y] ^= 1;
        dif[x][y+h] ^= 1; dif[x+w][y+h] ^= 1;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dif[i][j] ^= dif[i-1][j] ^ dif[i][j-1] ^ dif[i-1][j-1];
            if (dif[i][j]) ans++;
        }
    }
    cout << ans << endl;
}
