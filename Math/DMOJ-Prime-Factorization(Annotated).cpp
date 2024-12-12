// Prime Factorization (DMOJ): https://dmoj.ca/problem/primefactor
// ANNOTATED CODE - https://dmoj.ca/src/6804558
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7+3;
int N, a[MM], prime[MM]; // prime[i] denotes the max prime that can divide into i
int main(){
    for(int i = 2; i < MM; i++){ // preprocessing with Sieve of Eratosthenes O(NlogN)
        if(prime[i] == 0){ // if so then this number is prime
            for(int j = i; j < MM; j+=i) prime[j] = i;
        }
    }

    cin >> N;
    for(int i = 0, x; i < N; i++){
        cin >> x;
        vector<int> factors;
        while(x > 1){ // if x is 1, then all prime factors have been found
            factors.push_back(prime[x]);
            x /= prime[x];
        }
        for(int i = factors.size()-1; i >= 0; i--){ // prints in reverse order since we start pushing in the biggest to smallest element, no need to sort it wastes time
            cout << factors[i] << " \n"[i==0];
        }
    }
}
