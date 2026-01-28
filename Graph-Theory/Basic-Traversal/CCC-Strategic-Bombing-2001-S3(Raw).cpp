// CCC '01 S3 - Strategic Bombing (DMOJ): https://dmoj.ca/problem/ccc01s3
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
unordered_map<char, vector<char> > adj; vector<string> edges;
unordered_set<char> vis;
char n1, n2;
void dfs(char c) {
    vis.insert(c);
    for (char nxt : adj[c]) {
        if (vis.find(nxt) == vis.end() && !((nxt == n2 && c == n1) || (nxt == n1 && c == n2))) {
            dfs(nxt);
        }
    }
}
int main() {
    string s;
    cin >> s;
    while (s != "**") {
        edges.push_back(s);
        adj[s[0]].push_back(s[1]);
        adj[s[1]].push_back(s[0]);
        cin >> s;
    }
    int cnt = 0;
    for (string e : edges) {
        n1 = e[0]; n2 = e[1];
        dfs('A');
        if (vis.find('B') == vis.end()) {
            cout << e << endl;
            cnt++;
        }
        vis = {};
    }
    cout << "There are " << cnt << " disconnecting roads." << endl;
}
