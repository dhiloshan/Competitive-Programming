// Wesley's Anger Contest 6 Problem 3 Difference Sorting (DMOJ): https://dmoj.ca/problem/wac6p3
// ANNOTATED CODE - https://dmoj.ca/src/6926229
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
typedef long long ll;
int N; ll a[MM], sorted[MM];
/*
 note #1: it doesn't matter the number of operations, just swap any two number with a difference <= K
 note #2: we can use a sorted array to see where the current number i should be at
 note #3: we should use a prefix maximum array to keep track of the current max (you'll see why)
 a: [1 6 5 3 2 10] => [1 6 6 6 6 10]
 sorted:              [1 2 3 5 6 10]
 we start at i = 1, where sorted[i] = a[i], so nothing needs to be swapped
 for i = 2, notice how a[i] > sorted[i]. this GUARANTEES (also looking at it visually) that there is some # in the subarray
 from 1 to i in original array a that needs to be taken out of this subarray. in this case, it is 6
 another way to look at this is as connected components. sorted[j] only equals a[2] when j = 5, so look at the subarray
 from i = 2 to i = 5 as a "connected component". each neighbour, like from i = 3 to i = 4 in the sorted array, as an edge in a graph. in this case,
 the edge from i = 3 to i = 4 is just sorted[4] - sorted[3] = 2. we calculate the maximum edge in the connected component
 as max(sorted[i+1] - sorted[i], sorted[i+2] - sorted[i+1], ..., sorted[j] - sorted[j-1])
 notice we only viewed this as a connected component ONCE a[i] > sorted[i]. can we use this to make our implementation easier?
 yes, in fact. we can use if statement to only take the maximum of a single edge if a[i] > sorted[i]. if so, ans = max(current max, sorted[i+1] - sorted[i])
 because once sorted[i] = a[i], we know the connected component "stops" (in the case above it stops when i = 5), so we don't have to do anything
 only when the array a element is bigger than the element that should actually be in there (sorted[i]) should you check the edge
 */
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i]; sorted[i] = a[i];
        a[i] = max(a[i-1], a[i]); // prefix maximum array
    }
    sort(sorted+1, sorted+N+1);
    ll ans = 0; // minimum K to allow someone to sort the array just by swapping any two numbers where their absolute difference <= K
    for(int i = 1; i <= N; i++){
        // if the prefix max is greater than the expected value at position i, there must be a number in subarray 1 to i in array a to take out
        if(a[i] > sorted[i]) // if yes, there is a number in the subarray 1 to i that shouldn't be there
            ans = max(ans, sorted[i+1] - sorted[i]); // check the weight of the "edge" from the connected component and update the max
    }
    cout << ans << endl;
}
