// SAC '22 Code Challenge 5 Junior P4 - Course Requirements (SAC): https://dmoj.ca/problem/sac22cc5jp4
// ANNOTATED CODE - https://dmoj.ca/src/6779030
/* Topological sort (that uses BFS)
 Haven't really implemented this in a while, but I'll relate this to 2018 CCC J5 about the endpoints idea
 Find all start points (like we kinda did in J5) by checking if Ci == 0, if so, it's a start point with no pre-requisites, meaning no in-edges
 Perform BFS but every time we visit a neighbour node subtract its in-edge value by 1 and if the in edge value is zero we can push into queue
 This explanation may seem rushed so my tip is to visualize it with a website like graph editor, and think about the idea with start points
 */
 // Note that my raw code is more clean and condensed if you want to check it out
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+3;
int N, in[MM]; vector<int> adj[MM], order; queue<int> q;
int main(){
    cin >> N;
    for(int i = 1, c; i <= N; i++){
        cin >> c; // note everything is 1-indexed
        in[i] = c; // update the # of in-edges for course/node i
        if(c == 0){
            q.push(i); // push all start-points into the queue (we can't guarantee course 1 has no pre-requisites)
            order.push_back(i);
        }
        for(int j = 1, x; j <= c; j++){
            cin >> x;
            adj[x].push_back(i); // note since it is a PREREQUISTE, we reverse the order we create the edge (think about the logic of this)
            // we don't push the edge both ways because it's unidirectional
            // (think about a prerequisite, if course x is a prerequisite for course y, how can course y be a prerequisite for course x?)
        }
    }

    // perform topological sort
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){ // for each neighbouring course/node
            in[nxt]--; // since we visited one of node nxt's pre-requisites, minus the in-edge by 1
            // by our logic, in[i] should not go below 0
            if(in[nxt] == 0){
                q.push(nxt);
                order.push_back(nxt);
            }
        }
    }

    for(int i = 0; i < N-1; i++){
        cout << order[i] << " ";
    }
    cout << order[N-1] << endl;
}
