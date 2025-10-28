// EGOI '21 P1 - Zeros (DMOJ): https://dmoj.ca/problem/egoi21p1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1503;
typedef long long ll;
ll A, B;
inline ll cPow(int base, int exp){
    ll cur = 1;
    for(int i = 1; i <= exp; i++)
        cur *= base;
    return cur;
}
inline int cLog(ll num, int base){
    int c = 0;
    while(cPow(base, c) <= num) c++;
    return --c;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;
    int k = cLog(B, 2);
    while(k > 0){
        ll val = cPow(2, k);
        bool rangeContainsMultiple = false;
        ll coef = floor(A/val);
        if((A <= coef*val && coef*val <= B) || (A <= (coef+1)*val && (coef+1)*val <= B))
            rangeContainsMultiple = true;
        if(rangeContainsMultiple)
            break;
        k--;
    }
    int m = cLog(B, 5);
    while(m > 0){
        ll val = cPow(5, m);
        bool rangeContainsMultiple = false;
        ll coef = A/val;
        if((A <= coef*val && coef*val <= B) || (A <= (coef+1)*val && (coef+1)*val <= B))
            rangeContainsMultiple = true;
        if(rangeContainsMultiple)
            break;
        m--;
    }
    cout << min(k, m) << endl;
}
