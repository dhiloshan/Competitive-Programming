// USACO 2019 December Contest, Bronze Problem 1. Cow Gymnastics(USACO) - https://usaco.org/index.php?page=viewproblem2&cpid=963
// ANNOTATED CODE
// total time complexity: O(N^2*K) - complete search problem
#include <bits/stdc++.h>
using namespace std;
const int MM = 22;
int K, N, rnk[MM][MM], sum;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ifstream cin("gymnastics.in");
    // ofstream cout("gymnastics.out");
    cin >> K >> N;
    for(int i = 1; i <= K; i++){
        for(int j = 1, x; j <= N; j++){
            cin >> x;
            rnk[i][x] = j; // for the ith practice session, rnk[i][x] denotes for cow x what their ranking is from 1 to j (N)
            // idea is just like a frequency array but in a different context
        }
    }
    for(int i = 1; i < N; i++){
        for(int j = i+1; j <= N; j++){ // O(N^2)
            // for each pair of cows (i, j)
            int ri = 0, rj = 0;
            for(int k = 1; k <= K; k++){ // this block of code loops through all practice sessions in linear time O(K)
                if(rnk[k][i] < rnk[k][j]) ri++;
                else rj++; // guaranteed rnk[k][i] is not equal to rnk[k][j] since rankings are unique
            }
            if(ri == K || rj == K) sum++;
        }
    }
    cout << sum << endl;
}
