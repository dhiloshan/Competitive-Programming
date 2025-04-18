// Arcadia Computing Contest 2 P4 - Choose Your Own Adventure! (DMOJ): https://dmoj.ca/problem/ahscc2p4
// RAW CODE - https://dmoj.ca/src/7122198
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
typedef pair<int, int> pi;
int N, M, out[MM]; queue<int> rem; vector<int> adj[MM];
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
        if(++u <= N+M){
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
        else{
            int count = 0;
            if(a-1 != 1) { adj[a].push_back(a-1); count++; }
            if(a+1 <= N+M) { adj[a].push_back(a+1); count++; }
            if(count < 2 && a-2 != 1) { adj[a].push_back(a-2); count++; }
            if(count < 2 && a+2 <= N+M) { adj[a].push_back(a+2); count++; }
            rem.pop();
        }
    }
    return true;
}
int main(){
    cin >> N >> M;
    gen_choice(1);
    gen_rem();
    if(!gen_end(N) || (N==1&&M==1)) cout << -1 << endl;
    else{
        for(int i = 1; i <= N; i++){
            for(int j = 0; j < adj[i].size(); j++){
                cout << adj[i][j] << " \n"[j==adj[i].size()-1];
            }
        }
    }
}
