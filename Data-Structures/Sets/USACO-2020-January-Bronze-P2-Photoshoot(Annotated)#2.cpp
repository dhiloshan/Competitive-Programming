// USACO 2020 January Bronze P2 - Photoshoot (DMOJ): https://dmoj.ca/problem/usaco20janb2
// ANNOTATED CODE O(N) Math derived clever approach
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e3+2;
int N, b[MM];
// ax where x is odd can be expressed as Cx + a1 for some constant Cx
// ax where x is even can be expressed as Dx - a1
/*
 From b, you get a[x] = b[x-1] - a[x-1] for all x
 You can express all a[x] as some sum and differences of b-values plus a1 (or minus a1)
 In DMOJ's example:
 a1 = a1
 a2 = 4 - a1
 a3 = 2 + a1
 a4 = 5 - a1
 a5 = 1 + a1
 You need to NOTICE THIS RECURSIVE IDEA.
 a2 can be written as a constant plus or minus a1
 a3 can be written as a constant plus or minus a2, which is a constant plus or minus a1
 ...
 so on
 Now all a[x] values is either Cx + a1 (for odd by observation) or Dx - a1 (for even by observation)

 We have a series of equations that hold true
 4 - a1
 5 - a1
Case 1: One of these values are equal to 1
The # that is equal to 1 is the smallest expression, which is minimal Dx
 -----
 0 + a1
 1 + a1
 2 + a1
Case 2: One of these values are equal to 1
The # that is equal to 1 is the smallest expression, which is minimal Cx

Now, you have 2 a1 solutions.
First start with the smaller a1 solution (lexicographically minimal).
Generate a from indices 2 to n using b of 1 to n-1.
For each number generated (make sure to push a1), check if it is within 1 to n inclusive. if not, stop and try the other a1 solution.
If yes, push into unordered set and also into another vector a to maintain order
Once finished generating a, if the size of the unordered set is N, then you have N unique numbers within 1 to N. print array a.
Else, try the second a1 solution. According to DMOJ problem statement, this is guaranteed to work, as a permutation is guaranteed.
 */
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++) cin >> b[i];
    // base case
    int oddMi = 0; // 0 + a1
    int evenMi = b[1]; // b1 - a1
    int constantCur = b[1];
    for (int x = 3; x <= N; x++) {
        constantCur = b[x-1] - constantCur;
        if (x % 2 == 1)
            oddMi = min(oddMi, constantCur);
        else
            evenMi = min(evenMi, constantCur);
    }
    // 2 possible cases for a1: based on oddMi and evenMi
    int a1OddSolution = 1 - oddMi; // Cx + a1 = 1 (min) => 1 - Cx
    int a1EvenSolution = evenMi - 1; // Dx - a1 = 1 =>  Dx - 1


    vector<int> a1Solutions = {a1OddSolution, a1EvenSolution};
    sort(a1Solutions.begin(), a1Solutions.end()); // start with the smaller a1 solution to make it LEXICOGRAPHICALLY MINIMAL

    for (int a1 : a1Solutions) {
        unordered_set<int> st; st.insert(a1);
        vector<int> a; a.push_back(a1);
        int cur = b[1]-a1;
        if (cur < 1 || cur > N) break;
        st.insert(cur); a.push_back(cur);
        for (int i = 2; i <= N-1; i++) {
            int num = b[i] - cur;
            if (num < 1 || num > N) break;
            else {
                a.push_back(num); st.insert(num);
                cur = num;
            }
        }
        if (st.size() == N) {
            for (int i : a)
                cout << i << " ";
            cout << endl;
        }
    }
}
