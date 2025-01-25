// DMPG '17 S2 - Anime Conventions (DMOJ): https://dmoj.ca/problem/dmpg17s2
// ANNOTATED CODE - https://dmoj.ca/src/6916434
#include <bits/stdc++.h> // very basic disjoint set
using namespace std;
const int MM = 1e5+5;
int n, q, p[MM]; char op; // p[i] denotes the parent of node i
int fd(int d){ 
    if(d != p[d]) p[d] = fd(p[d]); // when d = p[d] that means we found the crux of the component, so until then keep going up the set recursively
    return p[d]; // return the parent (note we can optimize with path compression)
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) p[i] = i; // every node is the parent of themselves (pointing to themselves)
    for(int i = 1, x, y; i <= q; i++){
        cin >> op >> x >> y;
        if(op == 'A') p[fd(x)] = fd(y);  // node x points to node y now (it's saying node x's parent is now node y's)
        else cout << (fd(x) == fd(y)? 'Y' : 'N') << endl; // if they have the same parent they are a connected component so x can reach y
    }
}
