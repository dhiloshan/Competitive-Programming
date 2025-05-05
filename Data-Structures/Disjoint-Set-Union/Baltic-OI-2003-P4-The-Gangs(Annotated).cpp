// Baltic OI '03 P4 - The Gangs (DMOJ): https://dmoj.ca/problem/btoi03p4
// ANNOTATED CODE (by ChatGPT o4-mini)
// I wrote the code prior, then I asked GPT to add comments for my future revisions
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3+3;                  // max N <= 2000, but we'll index up to 2*N using this size
int N, M;
int p[MM], rnk[MM];                    // DSU parent and size arrays
vector<int> adj[MM];                   // for enemy→friends links
char op;
// find with path compression
int fd(int u) {
    return u == p[u] ? u : p[u] = fd(p[u]);
}

// union by size (rnk holds component size)
void unite(int u, int v) {
    int s1 = fd(u), s2 = fd(v);
    if (rnk[s1] < rnk[s2]) {
        p[s1] = s2;
        rnk[s2] += rnk[s1];
    } else {
        p[s2] = s1;
        rnk[s1] += rnk[s2];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;                    // read #people and #relations

    // init DSU: 1..N are people, N+1..2N are their "enemy-set reps"
    for (int i = 1; i <= 2*N; i++) {
        p[i] = i;
        rnk[i] = 1;
    }

    // process each operation
    for (int i = 0, a, b; i < M; i++) {
        cin >> op >> a >> b;
        if (op == 'E') {               // E a b: a and b are enemies
            unite(a, b + N);           // link a's friend-group to b's enemy-group
            unite(b, a + N);           // link b's friend-group to a's enemy-group
            adj[b + N].push_back(a);   // record for later: a is in enemy-list of b
            adj[a + N].push_back(b);   // record for later: b is in enemy-list of a
        }
        else {                         // F a b: a and b are friends
            unite(a, b);
        }
    }

    // if two people share the same enemy, they must be friends
    // unite all in each enemy's adjacency list
    for (int i = N+1; i <= 2*N; i++) {
        // WARNING: adj[i].size()-1 can underflow if empty, but kept as original
        for (int j = 0; j < (int32_t)adj[i].size() - 1; j++) {
            unite(adj[i][j], adj[i][j+1]);
        }
    }

    // count distinct friend-groups among original people
    unordered_set<int> st;
    for (int i = 1; i <= N; i++) {
        st.insert(fd(i));             // insert root of each person
    }

    cout << st.size() << endl;       // answer = #gangs
}
