// Dynamic Range Minimum Test (DMOJ): https://dmoj.ca/problem/segtree
// ANNOTATED CODE - https://dmoj.ca/src/7077348
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 262144; // 2 * nearest power of 2 for 100,000 - 1 (very strict memory limit)
struct node { int l, r, v; } seg[MM];
int N, Q, a[MM], x, y; char op;
// key point: where does our answer lie: left child, right child, or both?
void build(int l, int r, int idx){
    seg[idx].l = l; seg[idx].r = r; // initialize node
    if(l == r) { seg[idx].v = a[l]; return; } // if leaf node
    int mid = (l + r)/2; // middle: two ranges - [l, mid] U [mid+1, r]
    build(l, mid, 2*idx); build(mid+1, r, 2*idx+1); // 0-indexed array, so 2*idx is left child
    seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v); // value is minimum of left and right child. push-up
}
void update(int pos, int val, int idx){
    if(seg[idx].l == seg[idx].r){ seg[idx].v = val; return; } // leaf node
    int mid = (seg[idx].l+seg[idx].r)/2; // middle: two ranges - [seg[idx].l, mid] U [mid+1, seg[idx].r]
    if(pos <= mid) update(pos, val, 2*idx); // if the update is required in the left range 
    else update(pos, val, 2*idx+1); // otherwise it has to be in the right range/child
    seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v); // push-up, update all the ancestors
}
int query(int l, int r, int idx){ // range min query [l, r]
    if(seg[idx].l == l && seg[idx].r == r) return seg[idx].v; // leaf node
    int mid = (seg[idx].l+seg[idx].r)/2; // middle
    if(r <= mid) return query(l, r, 2*idx); // if our answer is purely the left child
    if(mid < l) return query(l, r, 2*idx+1); // what about just the right child?
    return min(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1)); // query spans both the left and right child (not fully contained within a single child)
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> a[i];
    build(0, N-1, 1); // 0-indexed, but segment tree starts at idx 1
    for(int i = 1; i <= Q; i++){
        cin >> op >> x >> y;
        if(op == 'M'){ // change a[x] to y
            update(x, y, 1);
        }
        else{ // min range query [x, y]
            cout << query(x, y, 1) << endl;
        }
    }
}
