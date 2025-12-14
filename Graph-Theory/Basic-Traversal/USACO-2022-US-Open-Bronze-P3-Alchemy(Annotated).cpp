// USACO 2022 US Open, Bronze Problem 3. Alchemy (DMOJ): https://dmoj.ca/problem/usaco22openb3
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 102;
int N, a[MM], K, ans; vector<int> rev[MM];
bool check(int u) { // true: you have at least 1 of metal u.
    if (a[u] > 0) { // case 1: you already have it
        return true;
    }
    else { // empty, case 2: you need to construct it
        if (rev[u].size() == 0) return false; // if you can't construct it
        vector<int> req;
        for (int nxt : rev[u]) {
            if (!check(nxt)) { // if you can't construct the metal required to make it
                return false;
            }
            a[nxt]--; // remove the metal right away.
            // note: say you remove a[nxt1], but another nxt (nxt2) node is empty, meaning you can't create node u
            // but you already removed a[nxt1]. this is fine because if any nxt (in this case nxt2) is empty
            // then you can't create metal u, so you can't create metal N, so check(N) returns false, so it wouldn't even matter
            // use this as an example: 1->4, 2->4, 3->4. a[4] = {2, 0, 1, 0} (1-indexed)
        }
        a[u]++; // you can construct metal u, so add one
        return true;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    cin >> K;
    for (int i = 1, v, m; i <= K; i++) {
        cin >> v >> m;
        for (int j = 1, u; j <= m; j++) {
            cin >> u; rev[v].push_back(u);
        }
    }
    while (true){
        if (!check(N)) {
            break;
        }
        // you have constructed metal N. so a[N] >= 1
        a[N]--; ans++;
    }
    cout << ans << endl;
}
/*
notes to self: 

IMPORTANT:
-Lesson 1: trace back your code with recursion calls (and use the -> arrows to show what is happening at what step
-Lesson 2: label the return value of each function and the desired result (in this case, check() returns if you have one metal of u to spare)

also,
replace lines 16 to 22 with this:
for (int nxt : rev[u]) {
      if (!check(nxt)) { // if you can't construct the metal required to make it
          return false;
      }
      req.push_back(nxt);
  }
  // to construct metal u, you have to remove one from the required metals
  for (int v : req) {
      a[v]--;
  }
why does this not work?
here is the submission for it: https://dmoj.ca/submission/7487445

short answer is you are checking if a prior metal exists, but don't subtract it til you loop through 
all the metals required to make metal u. 

AI CHATGPT EXPLANATION:
Minimal failing test case for your second version

N = 3
a = [1, 0, 0]    // a[1]=1, a[2]=0, a[3]=0
K = 2

Recipe:
2 ← {1}
3 ← {1, 2}


⸻

What the recipe means
	•	To make 2, you need 1
	•	To make 3, you need both 1 and 2

Correct answer: 0
You only have one 1. You can’t make both.

⸻

What your second version does

Call check(3):

Step 1: loop over ingredients

check(1) → true   // uses a[1]=1 (not consumed yet)
check(2):
    check(1) → true   // SAME unit reused
    a[1]--            // now a[1]=0
    a[2]++            // a[2]=1

Both checks succeeded.

Step 2: subtract ingredients

a[1]--   // a[1] = -1   ❌ reused metal
a[2]--   // a[2] = 0
a[3]++   // a[3] = 1

So your code claims you made metal 3, which is impossible.

⸻

Why the first version blocks this

In the first version:

check(1); a[1]--;
check(2);

	•	First check(1) consumes the only 1
	•	check(2) fails immediately
	•	Correctly returns false

⸻

One sentence summary

Your second version fails because it lets the same metal satisfy multiple ingredient checks before any consumption happens.

That is the concrete reason, with a concrete test case.
*/
