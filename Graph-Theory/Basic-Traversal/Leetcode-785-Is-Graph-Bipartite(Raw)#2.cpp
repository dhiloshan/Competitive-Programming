// Problem 785. Is Graph Bipartite? (Leetcode) : https://leetcode.com/problems/is-graph-bipartite/
// RAW CODE
// SOLUTION #2: DFS
class Solution {
public:
    bool dfs(int u, bool c, vector<vector<int>>& graph, vector<bool>& col, vector<bool>& vis){ 
        for(int nxt : graph[u]){
            if(!vis[nxt]){
                col[nxt] = !c; vis[nxt] = true;
                if(!dfs(nxt, col[nxt], graph, col, vis)) return false;
            }
            else{
                if(col[nxt] == col[u]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> col(101, false), vis(101, false); 
        for(int i = 0; i < graph.size(); i++){
            if(!vis[i]){
                vis[i] = true;
                if(!dfs(i, false, graph, col, vis)) return false;
            }
        }
        return true;
    }
};
