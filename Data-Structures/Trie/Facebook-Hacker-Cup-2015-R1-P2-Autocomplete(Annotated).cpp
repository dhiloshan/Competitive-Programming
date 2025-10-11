// Facebook Hacker Cup '15 Round 1 P2 - Autocomplete (DMOJ): https://dmoj.ca/problem/fhc15c1p2
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 6e5+3;
int T;
class node {
public:
    unordered_map<char, node*> child; // just like an adjacency list, nodes store all of its neighbours and point to it
};
void freeData(node* u){ // frees nodes to avoid MLE
    for(auto e : u->child){
        freeData(e.second);
    }
    delete u; // dont use free() -> malloc, use delete
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N; cin >> N;
        node* root = new node(); // pointer to a variable with type node
        // int* random = new int(); random is a pointer to itself, an integer
        int cnt = 0;
        for(int i = 1; i <= N; i++){
            string s; cin >> s;
            // start from base case
            node* cur = root;
            int curCnt = 0; bool flag = false;  // flag dictates if we started to go to a new path (word is bigger than the longest common prefix)
            for(int j = 1; j <= s.size(); j++){ // iterate through the string
                char c = s[j-1]; // make it 0-indexed
                if(!(cur->child.count(c))){ // if this new character does not exist as one of the current node's neighbours 
                    if(!flag){ // if we haven't already deviated to a new path
                        curCnt = j; flag = true; 
                    }
                    cur->child[c] = new node(); // add a new node since there are no neighbours
                }
                cur = cur->child[c]; // continue going down the tree
            }
            if(!flag) curCnt = s.size(); // edge case: the entire word is in the trie, so add the entire string's size
            cnt += curCnt;
        }
        printf("Case #%d: %d\n", i, cnt);
        freeData(root); // remember to recursively free the data starting from root to avoid MLE
    }
}
