// Arcadia Computing Contest 2 P4 - Choose Your Own Adventure! (DMOJ): https://dmoj.ca/problem/ahscc2p4
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
typedef pair<int, int> pi;
int N, M, out[MM]; queue<int> rem; vector<int> adj[MM]; // note the problem describes a segment tree
void gen_choice(int pos){
    int lft = 2 * pos, rit = 2 * pos + 1;
    if(lft <= N) {
        adj[pos].push_back(lft); out[pos]++; gen_choice(lft);
    }
    if(rit <= N) {
        adj[pos].push_back(rit); out[pos]++; gen_choice(rit);
    }
}
void gen_rem(){
    for(int i = 1; i <= N; i++)
        if(out[i] < 2)
            for(int j = 0; j < 2-out[i]; j++)
                rem.push(i);
}
bool gen_end(int u){
    int cnt = 0;
    while(!rem.empty()){
        if(++u <= N+M){ // u is pre-incremented (u+=1 no matter if the if statement is true or not)
            adj[rem.front()].push_back(u);
            rem.pop(); cnt++;
        }
        else break;
    }
    if(cnt < M) return false;
    while(!rem.empty()){
        int a = rem.front(); rem.pop();
        int b = rem.front();
        if(a != b){
            if(a-1 != 1) adj[a].push_back(a-1);
            else adj[a].push_back(a+1);
        }
        else{ // a == b, so push a twice
            int count = 0;
            if(a-1 != 1) { adj[a].push_back(a-1); count++; }
            if(a+1 <= N+M) { adj[a].push_back(a+1); count++; }
            if(count < 2 && a-2 != 1) { adj[a].push_back(a-2); count++; }
            if(count < 2 && a+2 <= N+M) { adj[a].push_back(a+2); count++; }
            // guarantees node a has two out edges
            rem.pop();
        }
    }
    return true;
}
int main(){
    cin >> N >> M;
    gen_choice(1); // rooted at node 1
    gen_rem(); // generate list of nodes with 0 or 1 out edges
    // gen_end(N) => start from node N+1 (++u or ++N at first in the func is N+1) for the end choice nodes via the nodes found in gen_rem()
    if(!gen_end(N) || (N==1&&M==1)) cout << -1 << endl;
    else{ // output the graph
        for(int i = 1; i <= N; i++){
            for(int j = 0; j < adj[i].size(); j++){
                cout << adj[i][j] << " \n"[j==adj[i].size()-1];
            }
        }
    }
}
