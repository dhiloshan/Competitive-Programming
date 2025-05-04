// Problem 785. Is Graph Bipartite? (Leetcode) : https://leetcode.com/problems/is-graph-bipartite/
// ANNOTATED CODE
// SOLUTION #1: BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool col[101], vis[101]; 
        memset(col, false, sizeof(col)); memset(vis, false, sizeof(vis));
        queue<int> q; 
        for(int i = 0; i < graph.size(); i++){ // run BFS for each component
            if(!vis[i]){
                q.push(i); vis[i] = true;
                while(!q.empty()){
                    int cur = q.front(); q.pop();
                    for(int nxt : graph[cur]){
                        if(!vis[nxt]){
                            vis[nxt] = true; q.push(nxt); col[nxt] = !col[cur];
                        }
                        else{
                            if(col[nxt] == col[cur]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
