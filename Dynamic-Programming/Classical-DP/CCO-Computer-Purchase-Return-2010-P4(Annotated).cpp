// CCO '10 P4 - Computer Purchase Return (DMOJ): https://dmoj.ca/problem/cco10p4
// ANNOTATED CODE - https://dmoj.ca/src/6900904
#include <bits/stdc++.h>
using namespace std;
const int MM = 3003;
typedef pair<int, int> pi;
int T, N, B, dp[6][MM]; vector<pi> items[6];
/* grouped knapsack problem - the idea is we have T types of items (in this case up to 5)
and we have to choose exactly one from each type such that we maximize the value and the cost is under B (this may not even be possible btw)
 this is just regular knapsack but we have to set the cells to negative infinity first.
 why? dp[t][i] may not even use all t items is the reason why, because we have to use ALL of the items 1 to t
 dp[t][i] = maximum value yielded from a budget of i dollars while using ALL t items
 unlike regular knapsack, this knapsack problem's answer could be -1 because we can't choose such items to fit this plan
 the base case is that all cells in row 0 is 0: dp[0][i] = 0 for all i from 0 to B (look at dp state to see why)
 but dp[1][0], dp[2][0] isn't 0. why? because we aren't using any items since the budget is 0, which goes against our dp state because we have to use all T items, so it is negative inf
 the rest will be explained in the code
 */
int main(){
    cin >> T >> N;
    for(int i = 1, c, v, t; i <= N; i++){
        cin >> c >> v >> t;
        items[t].emplace_back(c, v); // items[t] has all of the items of type t
    }
    cin >> B;
    memset(dp, -0x3f, sizeof(dp)); // initialize to negative infinity
    for(int i = 0; i <= B; i++) dp[0][i] = 0; // BASE CASE: if we have no items, then the maximal value is 0
    for(int t = 1; t <= T; t++){ // for each type of item from 1 to t
        for(auto [c, v] : items[t]){ // for each item
            for(int i = c; i <= B; i++){ // we START from cost c because if we start from c-1 or c-2 or even lower like 1, we can't afford to USE item t, which GOES AGAINST OUR DP STATE BECAUSE we have to use ALL t itmes
                dp[t][i] = max(dp[t][i], dp[t-1][i-c] + v); // dp transition
                // VERY IMPORTANT!!!: either way we have to TAKE the current item (because going BACK TO OUR DP STATE, we have to use all T items)
                // EITHER, we don't take this item of type t, because we already have taken another item OF type t in the past => dp[t][i] (in some past iteration of type t item)
                // OR, we take item of type t NOW, and as a result, we only consider items 1 to t-1
            }
        }
    }
    int ans = -1; // again, it might not be even possible to construct such plan
    ans = max(ans, dp[T][B]); // there is either a solution for all T items and with a maximum budget of B, or it's just going to be -1
    cout << ans << endl;
}
