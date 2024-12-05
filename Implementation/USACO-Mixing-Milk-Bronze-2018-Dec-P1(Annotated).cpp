// USACO 2018 December Contest, Bronze Problem 1. Mixing Milk (USACO) - https://usaco.org/index.php?page=viewproblem2&cpid=783
// ANNOTATED CODE
// note there are mathematical optimizations you can make (just simulate til you find the cycle, then the state of 100 steps can be calculated with mod)
#include <bits/stdc++.h>
using namespace std;
int c[4], a[4]; // array c will have constant values, values in array a are changing according to the milk pouring process
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ifstream cin("mixmilk.in");
    // ofstream cout("mixmilk.out");
    /*
     there are two scenarios
     1: bucket a empties itself and pours all milk into bucket b
     2: bucket a does not empty itself since the portion of milk that it poured into bucket b filled its capacity
     when simulating the pouring process, check if bucket a is able to pour all of its milk into bucket b
     check if current amount of bucket a <= total capacity of bucket b - current amount of bucket b
        if so this is scenario 1
        if not this is scenario 2
     */
    for(int i = 1; i <= 3; i++){
        cin >> c[i] >> a[i];
    }
    // start simulation
    for(int i = 1; i <= 100; i++){ // the farmer will repeat this pouring process 100 times
        // let x represent the index of the first bucket and y represent the index of the second bucket
        int x = i%3, y = x+1; // y is guaranteed to be from 1 to 3, when x is 1, y = 2, when x is 2, y is 3, and when x is 0 INITIALLY (then 3), y = is 1
        if(x == 0) x = 3; // x = 1, 2, 0, 1, 2, 0, 1, 2, 0, ...
                          // with this if statement => x = 1, 2, 3, 1, 2, 3, ....
        int rem = c[y] - a[y]; // how much empty space is in the second bucket
        if (a[x] <= rem) {
            a[y] += a[x]; // the first bucket will pour all of its milk into the second bucket
            a[x] = 0; // the first bucket empties itself
        }
        else {
            a[x] -= rem; // whatever amount of milk the first bucket can pour into the second bucket it will do so => that "whatever amount" is rem
            a[y] = c[y]; // the second bucket is now full (which is equal to its capacity)
        }
    }
    for(int i = 1; i <= 3; i++){
        cout << a[i] << endl;
    }
}
