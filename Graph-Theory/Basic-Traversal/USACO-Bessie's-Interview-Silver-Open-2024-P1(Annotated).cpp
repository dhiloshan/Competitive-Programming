// USACO 2024 Open Silver P1 - Bessie's Interview (DMOJ): https://dmoj.ca/problem/usaco24opens1
// ANNOTATED CODE - https://dmoj.ca/src/6946623
#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+5; // NOTE the use of the new data structures used to represent the graph and arrays because array bounds are too small
typedef long long ll; // remember to use long long, the t[i] values will accumulate
int N, K, t[MM]; // idea: use priority queue to greedily find bessie's interview time, then figure out how you got to that interview time by starting from the beginning again, by building a graph, then running bfs to see which nodes from 1 to K (farmers, starting nodes) you can visit
unordered_map<ll, vector<ll>> adj; // t[i] <= 10^9; so we can't use vector<ll> adj[MM] since arrays go up to 10^6-10^7, just use unordered map/hash map
priority_queue<ll, vector<ll>, greater<ll>> q; // sorts in ascending order to find the interview time for bessie (minimized)
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> t[i];
    for(int i = 1; i <= K; i++) q.push(t[i]); // push the starting nodes
    // build the graph
    for(int i = K+1; i <= N; i++){ // for cows K+1 to N find their interview times
        ll time = q.top(); q.pop(); // this indicates that the farmer is available (after time minutes)
        q.push(time + t[i]);
        adj[time+t[i]].push_back(time);
    }
    ll time = q.top(); // the top is the time of bessie's interview
    cout << time << endl;
    queue<ll> q2; unordered_set<ll> vis; // make a new queue and a vis data structure (just use unordered set because array is too small)
    // run bfs
    q2.push(time); vis.insert(time);
    while(!q2.empty()){
        auto cur = q2.front(); q2.pop();
        for(auto nxt : adj[cur]){
            if(!vis.count(nxt)) { // if the node is not visited
                q2.push(nxt); vis.insert(nxt);
            }
        }
    }
    for(int i = 1; i <= K; i++) cout << vis.count(t[i]); // the ith farmer can interview Bessie if and only if there is a path from t[i] to Bessie's start time in the graph
    cout << endl;
}
