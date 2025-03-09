// USACO 2020 January Contest, Bronze Problem 1. Word Processor (USACO): https://usaco.org/index.php?page=viewproblem2&cpid=987
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
int N, K; vector<string> words; // vector stores all the words, which is easier and smarter than just using getline(cin, string) and having to process each word later
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ifstream cin("word.in");
    // ofstream cout("word.out");
    cin >> N >> K;
    for(int i = 0; i < N; i++){ // there are N words
        string cur; cin >> cur;
        words.push_back(cur);
    }
    int cnt = K - words[0].size(); // cnt shows how many characters are left for a line
    cout << words[0];
    for(auto it = words.begin()+1; it != words.end(); it++){
        string cur = *it; // looping by iterator
        if(cnt >= cur.size()){ // if there is enough space for word i
            cnt -= cur.size();
            cout << " " << cur; // we can be certain that if we put a space before a word and then the word, if the next word is on a new line, then there won't be extra whitespace
        }
        else{ // make a new line for word i
            cnt = K - cur.size();
            cout << endl << cur;
        }
    }
    cout << endl; // At the end of the code you need to print a new line, which is why my initial code that worked on USACO didn't work on DMOJ
}
