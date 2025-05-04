// Problem 785. Is Graph Bipartite? (Leetcode) : https://leetcode.com/problems/is-graph-bipartite/
// ANNOTATED CODE
// SOLUTION #1: BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool col[101], vis[101]; // two possible colours for node i since we are checking if it is BIpartite (two seperate sets)
        memset(col, false, sizeof(col)); memset(vis, false, sizeof(vis)); // initialize to false b.c. this is not global var
        queue<int> q; 
        for(int i = 0; i < graph.size(); i++){ // run BFS for each component
            if(!vis[i]){ 
                q.push(i); vis[i] = true;
                while(!q.empty()){
                    int cur = q.front(); q.pop();
                    for(int nxt : graph[cur]){ // two options: you visited this before or you haven't
                        if(!vis[nxt]){ // if you didn't
                            vis[nxt] = true; q.push(nxt); col[nxt] = !col[cur]; // flip the colour; push it for BFS
                        }
                        else{ // make sure the colours aren't the same. if they are, then the graph can't be bipartite because these two nodes, which are supposed to be in two differents sets, are in the same set
                            if(col[nxt] == col[cur]) return false;
                        }
                    }
                }
            }
        }
        return true; // all components are bipartite, so we can return true
    }
};
