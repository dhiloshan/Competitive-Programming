// CCC '22 S3 - Good Samples (DMOJ): https://dmoj.ca/problem/ccc22s3
// ANNOTATED CODE - https://dmoj.ca/src/6899205
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
ll N, M, K; int a[MM]; deque<int> q;
int main(){
    cin >> N >> M >> K;
    if(K < N || K > (1+M)*M/2 + (N-M)*M) { // M(M+1)/2 considers the pitches from 1 to M, and then (N-M)*M considers the remaining (N-M) spaces, make sure you see why.
        cout << -1 << endl; // then we can't construct such sequence
        return 0;
    }
    a[1] = 1;  // start the sequence with 1
    K -= N; // all subarrays with size 1 we take off from K
    q.push_back(1); // deque for the sliding window
    int nxt = 1; // the next element to append
    for(int i = 2; i <= N; i++) {
        if(K >= q.size()) { // we check the size of the queue BEFORE we insert the element, which is why we don't do K >= q.size() - 1; remember we aren't checking subarrays with size one because we did K - N which considered all N subarrays of size 1
            nxt++; // move to the next pitch
            if(nxt <= M) {
                K -= (nxt - 1); // pushing this new element yields nxt - 1 good subarrays, make sure you see why.
                q.push_back(nxt); // push this number in our sliding window
                a[i] = nxt; // add it to the sequence
            } else { // if this number is not in the range of pitches [1, M]
                q.push_back(q.front()); // reuse the first element
                q.pop_front(); // pop that element to continue the cycle and to not reuse the same element consecutively in sequence a
                a[i] = q.back(); // put that reused element in the sequence
                K -= M-1; // this is just K - (nxt-1) but nxt is just M (literally, nxt = M+1 yes. but we can't use the # M+1, we can only use M, so that's why M = nxt, so nxt -1 = M -1)
            }
        } else { // if K is smaller than the window size, we need to carefully select an element to first make K equal to 0, and then this block will run multiple times to append the same element over and over (you'll see why below)
            int x = q[(int)q.size() - 1 - K]; // at first, we calculate the element to make K to 0 with this index
            a[i] = x; K = 0;
            q.push_back(a[i]); // push this reused element to the back of the queue
            // REALLY IMPORTANT: after we run this block once, it will run every time in the for loop til i reaches N, because 0 <= some positive integer
            // q[q.size() - 1 - K] = q[q.size() - 1 - 0] = q[q.size()-1] = q.back() => so in the second iteration we are just reusing this reused element and putting it in the sequence
        }
    }
    for(int i=1; i<=N; i++)
        cout << a[i] << " \n"[i==N];
}
