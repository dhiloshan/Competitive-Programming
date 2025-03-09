// VM7WC '16 #3 Bronze - Shahir-in-a-Box (DMOJ): https://dmoj.ca/problem/vmss7wc16c3p1
// RAW CODE - https://dmoj.ca/src/6500306
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, x[MM], y[MM];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i = 0, xi, yi; i < N; i++){
        cin >> xi >> yi;
        x[i] = xi; y[i] = yi;
    }
    sort(x, x+N); sort(y, y+N);

    int area = (x[N-1] - x[0]) * (y[N-1] - y[0]);
    cout << area << endl;
}
