// 743. Network Delay Time
// ANNOTATED CODE
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // pre-process
        vector<pair<int, int>> adj[101];
        for(auto e : times){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }
        // dijkstra
        vector<int> dis(n+1, 1e9); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        dis[k] = 0; pq.push({dis[k], k});
        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();
            if(d > dis[u]) continue;
            for(auto [v, w] : adj[u]){
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w; pq.push({dis[v], v});
                }
            }
        }
        int mx = 0; // max dist to a node
        for(int i = 1; i <= n; i++){
            // cout << i << ": " << dis[i] << endl;
            if(dis[i] == 1e9){
                return -1;
            }
            mx = max(mx, dis[i]);
        }
        return mx;
    }
};
