// USACO 2020 January Contest, Bronze Problem 1. Word Processor (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=987
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
int N, K; vector<string> words;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream cin("word.in");
    ofstream cout("word.out");
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        string cur; cin >> cur;
        words.push_back(cur);
    }
    int cnt = K - words[0].size();
    cout << words[0];
    for(auto it = words.begin()+1; it != words.end(); it++){
        string cur = *it;
        if(cnt >= cur.size()){
            cnt -= cur.size();
            cout << " " << cur;
        }
        else{
            cnt = K - cur.size();
            cout << endl << cur;
        }
    }
}
