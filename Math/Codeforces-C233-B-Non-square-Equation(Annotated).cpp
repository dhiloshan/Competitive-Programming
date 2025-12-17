// B. Non-square Equation (Codeforces): https://codeforces.com/contest/233/problem/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
ll N;
inline int sumD(ll x){
    string s = to_string(x);
    int sum = 0;
    for (char c : s) {
        sum += (c - '0');
    }
    return sum;
}
inline ll quadSolve(ll b) { // positive root; a is 1
    double ans = 0;
    ans = (-b + sqrt(b*b + 4*N))/2;
    if (ans == floor(ans)) { // the value is an integer
        return (ll)ans;
    }
    else {
        return -1;
    }
}
int main() {
    cin >> N;
    int mi = 1e9+7; // minimum x (positive int)
    for (int i = 1; i <= 81; i++) {// s(x) is within 1 to 81
        ll r = quadSolve(i); // 81 possible quadratic equations
        if (r != -1 && sumD(r) == i)
            if (r < mi)
                mi = r;
    }
    if (mi == 1e9+7)
        cout << -1 << endl;
    else
        cout << mi << endl;
}
