// CCC '07 J5 - Keep on Truckin' (DMOJ) - https://dmoj.ca/problem/ccc07j5
// ANNOTATED CODE - https://dmoj.ca/src/6410349
#include <bits/stdc++.h> // DP State - Let dp[i] represent the number of ways to reach a motel at point a[i]
using namespace std; // DP Transition - for base case, we know there is only one way to reach "origin" (point 0), 1 path
const int MM = 80;   // loop left to right, check the distance between every two motels (points i and j)
typedef long long ll; // if it is more than A and less than B, add the number of ways you can reach motel i (left) to motel j (right)
                      // as you have dp[i] more ways to reach motel j => if(dif >= A && dif <= B) dp[j] += dp[i]
long long A, B, N; vector<int> a = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000}; // Original points the motel is located at (more can be added)
int main(){
    cin >> A >> B >> N;
    for(int i = 1, x; i <= N; i++){ // if there are extra motels to add
        cin >> x; a.push_back(x); // add this point into the vector
    }
    sort(begin(a), end(a)); // sort the points in ascending order, so we have a "number line" if you will
    vector<ll> dp(a.size()); // treat dp vector like an array
    dp[0] = 1; // BASE CASE: there is only one way to start at the beginning / point 0
    for(int i = 0; i < a.size(); i++){ // left to right search
        for(int j = i+1; j < a.size(); j++){ // O(N^2) time complexity, checking every single pair to see if it satisfies range [A, B]
            if(a[j] - a[i] >= A && a[j] - a[i] <= B){ // if the distance from motel i to j is more or equal to the minimum (A) but less or equal to the maximum (B)
                dp[j] += dp[i]; // to reach motel j, there are now dp[i] more ways to reach it
            }
        }
    }
    cout << dp.back() << endl; // dp.back() is the solution for the last index / motel, which is the answer the problem is asking for
}
