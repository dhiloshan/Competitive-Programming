// USACO 2024 Open Silver P1 - Bessie's Interview (DMOJ): https://dmoj.ca/problem/usaco24opens1
// RAW CODE - https://dmoj.ca/src/6946534
#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+5;
typedef long long ll;
int N, K, t[MM]; unordered_map<ll, vector<ll>> adj; priority_queue<ll, vector<ll>, greater<ll>> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> t[i];
    for(int i = 1; i <= K; i++) q.push(t[i]);
    for(int i = K+1; i <= N; i++){
        ll time = q.top(); q.pop();
        q.push(time + t[i]); adj[time+t[i]].push_back(time);
    }
    ll time = q.top();
    cout << time << endl;
    queue<ll> q2; unordered_set<ll> vis;
    q2.push(time); vis.insert(time);
    while(!q2.empty()){
        auto cur = q2.front(); q2.pop();
        for(auto nxt : adj[cur]){
            if(!vis.count(nxt)) {
                q2.push(nxt); vis.insert(nxt);
            }
        }
    }
    for(int i = 1; i <= K; i++) cout << vis.count(t[i]);
    cout << endl;
}
