// Facebook Hacker Cup '15 Round 1 P2 - Autocomplete (DMOJ): https://dmoj.ca/problem/fhc15c1p2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    unordered_map<char, shared_ptr<node> > child;
};
int T, N; string s;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N;
        shared_ptr<node> root = make_shared<node>(); 
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            cin >> s;
            auto cur = root; int tmp = 0;
            for(int i = 0; i < s.size(); i++){
                if(!cur->child.count(s[i])){ 
                    if(!tmp) tmp = i+1; 
                    cur->child[s[i]] = make_shared<node>();
                }
                cur = cur->child[s[i]];
            }
            cnt += tmp == 0? s.size() : tmp;
        }
        printf("Case #%d: %d\n", t, cnt);
    }
}
