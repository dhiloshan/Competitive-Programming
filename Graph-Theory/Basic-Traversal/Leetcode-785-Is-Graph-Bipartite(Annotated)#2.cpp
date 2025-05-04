// Problem 785. Is Graph Bipartite? (Leetcode) : https://leetcode.com/problems/is-graph-bipartite/
// ANNOTATED CODE
// SOLUTION #2: DFS
class Solution {
public:
    bool dfs(int u, bool c, vector<vector<int>>& graph, vector<bool>& col, vector<bool>& vis){ // make sure to pass by reference
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
        /*
        currently, I struggle with DFS, but I like to think about this problem like this:
        to verify a graph is bipartite (assume connected), it should be able to pass 2 different tests:
        1) (BFS) start from any random node and colour it white. then, colour all of its neighbours black. after, for each of its neighbours, colour it white and so on...
        2) (DFS) start from a random vertex and colour it white. now colour any one of its neighbours black, then colour any one of the neighbour's neighbours white, and so on.... When you reach a dead end, you reached the bottom, so now go back a step and see if that node has any more neighbours to colour the opposite colour.
        honestly, it's better to visualize this than reading my explaination, but this shows how verifying if a graph is bipartite using DFS works.
        */
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
// PERFORMANCE NOTE: after passing the graph by reference and changing col and vis arrays to vectors, I got from 40 ms to 0ms!
