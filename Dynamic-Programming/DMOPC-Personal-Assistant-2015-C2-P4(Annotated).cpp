// DMOPC '15 Contest 2 P4 - Personal Assistant (DMOJ): https://dmoj.ca/problem/dmopc15c2p4
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef long long ll;
struct show {
    ll l, r, val;
    bool operator<(const show &y) const { // custom comparator to sort by end times, then start times
        if(r == y.r){ // operator< asks the calling object: should I put the current object before / to the LEFT of the other object y? if it is less than the other object, it will
            return l < y.l;
        }
        return r < y.r;
    }
};
int N; ll dp[MM]; vector<show> shows;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); // needed for this problem's constraints
    cin >> N;
    for(int i = 0; i < N; i++){
        ll s, l, v; cin >> s >> l >> v; // make sure all interval properties are long long
        shows.push_back({s, s+l, v});
    }
    sort(shows.begin(), shows.end()); // sorts according to the bool comparator
    map<ll, int> endTimes; // seperate map for the end times to binary search
    for(int i = 0; i < N; i++){
        auto& [l, r, val] = shows[i];
        endTimes[r] = i;
    }
    dp[0] = shows[0].val; // base case
    for(int i = 1; i < N; i++){
        auto& [l, r, val] = shows[i]; // deconstruct values
        ll dontTake = dp[i-1]; // option one: don't watch show i. best answer is the all the  shows you have currently, other than show i
        ll take = val; // add the current show's value

        auto it = endTimes.upper_bound(l); // find the first show that conflicts with the current show
        if (it != endTimes.begin()) {
            --it; // minus one to find the show that does not conflict
            take += dp[it->second]; // add the dp value of shows 1 to it->second
        }
        dp[i] = max(dontTake, take); // maximum yield from the two options
    }
    cout << dp[N-1] << endl; // 0-indexed: final answer is max value from all of the shows
}
