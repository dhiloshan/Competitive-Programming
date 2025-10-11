// Facebook Hacker Cup '15 Round 1 P2 - Autocomplete (DMOJ): https://dmoj.ca/problem/fhc15c1p2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
class node {
public:
    unordered_map<char, node*> child;
};
void freeData(node* u){
    for(auto e : u->child){
        freeData(e.second);
    }
    delete u;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N; cin >> N;
        node* root = new node(); 
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            string s; cin >> s;
            node* cur = root;
            int curCnt = 0; bool flag = false;
            for(int j = 1; j <= s.size(); j++){
                char c = s[j-1];
                if(!(cur->child.count(c))){
                    if(!flag){
                        curCnt = j; flag = true;
                    }
                    cur->child[c] = new node();
                }
                cur = cur->child[c];
            }
            if(!flag) curCnt = s.size();
            cnt += curCnt;
        }
        printf("Case #%d: %d\n", i, cnt);
        freeData(root);
    }
}
