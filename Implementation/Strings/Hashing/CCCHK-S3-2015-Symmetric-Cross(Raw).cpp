// CCCHK '15 S3 - Symmetric Cross (DMOJ): https://dmoj.ca/problem/hkccc15s3
// RAW CODE
#include <bits/stdc++.h>
using namespace std;

const int MM = 2005;
const int base = 1e4+7;
const int MOD = 1e9+7;
typedef long long ll;

int R, C, a[MM][MM];
ll u[MM][MM], d[MM][MM], l[MM][MM], rr[MM][MM], pw[MM];
int fr, fc;

ll up(int r, int c, int sz) { 
    return (u[r-sz][c] - u[r][c] * pw[sz] % MOD + MOD) % MOD; 
}
ll down(int r, int c, int sz) { 
    return (d[r+sz][c] - d[r][c] * pw[sz] % MOD + MOD) % MOD; 
}
ll left(int r, int c, int sz) { 
    return (l[r][c-sz] - l[r][c] * pw[sz] % MOD + MOD) % MOD; 
}
ll right(int r, int c, int sz) { 
    return (rr[r][c+sz] - rr[r][c] * pw[sz] % MOD + MOD) % MOD; 
}

bool check(int sz) {
    if (sz == 0) return true;
    for (int i = sz+1; i <= R-sz; i++) {
        for (int j = sz+1; j <= C-sz; j++) {
            --sz;
            if (i+sz > R || i-sz < 1 || j+sz > C || j-sz < 1) continue;
            sz++;
            if (up(i, j, sz) == right(i, j, sz) &&
                right(i, j, sz) == down(i, j, sz) &&
                down(i, j, sz) == left(i, j, sz)) {
                fr = i;
                fc = j;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> a[i][j];
        }
    }

    pw[0] = 1;
    for (int i = 1; i <= max(R, C); i++)
        pw[i] = pw[i-1] * base % MOD;

    for (int r = 1; r <= R; r++)
        for (int c = 1; c <= C; c++)
            rr[r][c] = (rr[r][c-1] * base % MOD + a[r][c]) % MOD;

    for (int r = 1; r <= R; r++)
        for (int c = C; c >= 1; c--)
            l[r][c] = (l[r][c+1] * base % MOD + a[r][c]) % MOD;

    for (int c = 1; c <= C; c++)
        for (int r = 1; r <= R; r++)
            d[r][c] = (d[r-1][c] * base % MOD + a[r][c]) % MOD;

    for (int c = 1; c <= C; c++)
        for (int r = R; r >= 1; r--)
            u[r][c] = (u[r+1][c] * base % MOD + a[r][c]) % MOD;

    int lo = -1, hi = min(R, C);
    while (hi - lo > 1) {
        int mi = lo + (hi - lo) / 2;
        if (check(mi)) lo = mi;
        else hi = mi;
    }

    cout << lo << " " << fr << " " << fc << endl;
}
