// CCC '22 S3 - Good Samples (DMOJ): https://dmoj.ca/problem/ccc22s3
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
ll N, M, K; int a[MM]; deque<int> q;
int main(){
    cin >> N >> M >> K;
    if(K < N || K > (1+M)*M/2 + (N-M)*M) {
        cout << -1 << endl;
        return 0;
    }
    a[1] = 1;  
    K -= N;
    q.push_back(1);
    int nxt = 1;
    for(int i = 2; i <= N; i++) {
        if(K >= q.size()) {
            nxt++;
            if(nxt <= M) {
                K -= (nxt - 1);
                q.push_back(nxt);
                a[i] = nxt;
            } else {
                q.push_back(q.front());
                q.pop_front();
                a[i] = q.back();
                K -= M-1;
            }
        } else {
            int x = q[(int)q.size() - 1 - K];
            a[i] = x; K = 0;
            q.push_back(a[i]);
        }
    }
    for(int i=1; i<=N; i++)
        cout << a[i] << " \n"[i==N];
}
