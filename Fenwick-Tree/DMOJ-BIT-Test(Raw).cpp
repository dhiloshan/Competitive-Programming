// Binary Indexed Tree Test (DMOJ) - https://dmoj.ca/problem/ds1
// RAW CODE - https://dmoj.ca/src/6342254
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int N, M, a[MM]; ll bit1[MM], freq[MM]; 

void update(int pos, int val, ll bit[]){
    for(int i = pos; i < MM; i += i&-i){
        bit[i] += val;
    }
}

ll query(int pos, ll bit[]){
    ll sum = 0;
    for(int i = pos; i > 0; i -= i&-i){
        sum += bit[i];
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        update(i, a[i], bit1); update(a[i], 1, freq);
    }
    for(int i = 1, x, y; i <= M; i++){
        char op; cin >> op >> x;

        if(op == 'C'){
            cin >> y;
            update(x, y - a[x], bit1);
            update(a[x], -1, freq);
            update(y, 1, freq);
            a[x] = y;
        }
        else if(op == 'S'){
            cin >> y;
            cout << query(y, bit1) - query(x-1, bit1) << endl;
        }
        else if(op == 'Q'){
            cout << query(x, freq) << endl;
        }
    }
}
