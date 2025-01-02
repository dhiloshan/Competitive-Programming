// CCC '07 S4 - Waterpark (DMOJ): https://dmoj.ca/problem/ccc07s4
// ANNOTATED CODE - https://dmoj.ca/src/6786189
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+3;
int N, dp[MM], a, b; vector<int> adj[MM]; // let dp[i] represent the number of ways to reach node i
// the best way to understand this solution is to draw it out and see why I am reversing the edges
/*
Instead of calculating the number of ways to go from node 1 to N
We can reverse the problem: number of ways to come backward to each node, starting from node N to 1
We want to find the number of ways to go from node N to 1
but we can only solve that if we solve the problem for node N-1 to 1
..... we start all the way from node 1, solving each subproblem to the base case: dp[1] = 1
if we go backward, we can count the ways to reach each node by adding up the ways to reach its neighbors.
but in the loop we need to start from 2 and go forwards since we want to start from the smallest problem (except n = 1) and move up
*/
int main(){
    cin >> N >> a >> b;
    while(a != 0 && b != 0){ // the number of edges (M) is not given, only til we reach 0 0 is when the program stops taking input
        adj[b].push_back(a); // reverse the edge to go backwards and solve the sub problem
        cin >> a >> b; 
    }
    dp[1] = 1; // base case: there is one way to reach node 1
    for(int i = 2; i <= N; i++){ // goes through the nodes in a forward fashion
        for(int nxt : adj[i]){ // for each neighbour of node i
            dp[i] += dp[nxt]; // since the neighbour leads to the current node, you are adding the number of ways from the neighbour node to the current node
        }
    }
    cout << dp[N] << endl; // final answer is the number of ways to reach node N
}
