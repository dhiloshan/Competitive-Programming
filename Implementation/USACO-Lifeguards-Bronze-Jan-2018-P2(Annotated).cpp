// USACO 2018 January Contest, Bronze Problem 2. Lifeguards (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=784
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int N, mx; vector<pi> t;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ifstream cin("lifeguards.in");
    // ofstream cout("lifeguards.out");
    // run N scenarios where you fire the ith lifeguard, find the coverage without that lifeguard, and the final answer is the maximum of all coverages
    cin >> N;
    for(int i = 0, a, b; i < N; i++){
        cin >> a >> b;
        t.emplace_back(a, b);
    }
    sort(t.begin(), t.end());
    for(int i = 0; i < N; i++){ // try each individual scenario
        vector<pi> temp;
        for(int j = 0; j < N; j++){ // copy all the contents from the time shifts array to the temp array, EXCEPT for the ith lifeguard we are excluding
            if(j != i) temp.push_back(t[j]); // push all lifeguard's intervals except the ith lifeguard's
        }
        // merging interval algorithm
        int cur = 0, L = temp[0].first, R = temp[0].second;
        for(auto it  = temp.begin()+1; it != temp.end(); it++){
            auto& [l, r] = *it;
            /*
             there are two scenarios
             1: the intervals intersect
                the end of the first interval > the start of the second interval
                if they intersect, merge it
                change R to be the max of r and R, to see which one is the rightmost, to get the most coverage
                we know L is the leftmost number since we sorted it in ascending order, so L (let's say index i) is guaranteed to be <= l (index i+1)
             2: the intervals don't intersect
                the end of the first interval <= the start of the second interval
                (its <= because at the end of the first interval is when the lifeguard QUITS, they need a new lifeguard at that exact point)
                in that case, add the distance from L to R into cur
                then change L to l and R to r to have the new interval to compare the future intervals to
             */
            if(l < R){ // they intersect (don't use <= because at point R the lifeguard with shift [L,R] will stop, and the lifeguard [l, r] will come and start at point l, so there is only one lifeguard at point R
                R = max(r, R);
            }
            else{
                cur += (R-L);
                L = l; R = r;
            }
        }
        cur += (R-L);
        mx = max(cur, mx);
    }
    cout << mx << endl;
}
