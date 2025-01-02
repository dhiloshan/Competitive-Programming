// CCC '07 J5 - Keep on Truckin' (DMOJ): https://dmoj.ca/problem/ccc07j5
// RAW CODE - https://dmoj.ca/src/6409543
#include <bits/stdc++.h>
using namespace std;
const int MM = 80;
typedef long long ll;
long long A, B, N; vector<int> a = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int main(){
    cin >> A >> B >> N;
    for(int i = 1, x; i <= N; i++){
        cin >> x; a.push_back(x);
    }
    sort(begin(a), end(a));
    vector<ll> dp(a.size());
    dp[0] = 1;
    for(int i = 0; i < a.size(); i++){
        for(int j = i+1; j < a.size(); j++){
            if(a[j] - a[i] >= A && a[j] - a[i] <= B){
                dp[j] += dp[i];
            }
        }
    }
    cout << dp.back() << endl;
}
