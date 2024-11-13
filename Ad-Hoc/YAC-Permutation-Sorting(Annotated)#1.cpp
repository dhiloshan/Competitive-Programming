// SOLUTION #1: generate up to N intervals and then merge them O(NlogN)
// Yet Another Contest 8 P1 - Permutation Sorting (DMOJ): https://dmoj.ca/problem/yac8p1
// ANNOTATED CODE - https://dmoj.ca/src/6737527
// idea is array a[] where, lets say 3, is at index 6, cannot be converted into a valid array of 1, 2, 3, ..., N, unless we sort index 3 to index 6, where 3 represents Px (index it should be at) and 6 represents x
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e6+2;
int N, a[MM], idx[MM], ans; vector<pi> rng, rng2; // rng is short form for range; rng2 represents the merged intervals, if you want to view it delete the // from the rng2 lines
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){ // 1-based indexing
        cin >> a[i];
        idx[a[i]] = i; // array that stores the indexes of the a[] array
    }
    // step 2: iterate through each index of a[] to generate all intervals [x, Px], where Px represents the index it should be at

    for(int i = 1; i <= N; i++){
        if(a[i] != i) {
            int mi = min(i, idx[i]), mx = max(i, idx[i]); // defines the left and right bound of the interval
            rng.emplace_back(mi, mx);
        }
    }

    if(!rng.empty()){
        // step 3: merging interval algorithm
        sort(rng.begin(), rng.end());
        int L = rng[0].first, R = rng[0].second;
        // rng2.emplace_back(L, R);
        for(auto it = rng.begin()+1; it != rng.end(); ++it){
            auto [l, r] = *it;
            if(l <= R) { // merging the two intervals is possible
                // set the right bound of the interval (the left bound is L because we sorted by the first # on line 24)
                R = max(r, R);
            }
            else { // this interval does not intersect
                // append the previous interval, now that we know we have another interval whose bounds do not intersect with the previous one
                // rng2.emplace_back(L, R);
                ans += (R - L + 1); // add the subarray sum to answer
                L = l;
                R = r;
            }
        }
        // guaranteed that your final subarray is not accounted for because of our if-statement logic
        // rng2.emplace_back(L, R);
        ans += (R - L + 1);
    }

    cout << ans << endl;
}
