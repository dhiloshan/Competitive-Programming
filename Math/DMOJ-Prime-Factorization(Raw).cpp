// Prime Factorization (DMOJ): https://dmoj.ca/problem/primefactor
// RAW CODE - https://dmoj.ca/src/6933236
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7+3;
int N, a[MM], prime[MM];
int main(){
    for(int i = 2; i < MM; i++)
        if(prime[i] == 0)
            for(int j = i; j < MM; j+=i)`    
                prime[j] = i;
    cin >> N;
    for(int i = 0, x; i < N; i++){
        cin >> x;
        vector<int> factors;
        while(x > 1){ 
            factors.push_back(prime[x]);
            x /= prime[x];
        }
        for(int i = factors.size()-1; i >= 0; i--){ 
            cout << factors[i] << " \n"[i==0];
        }
    }
}
