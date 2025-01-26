// CCO '14 P4 - Where's That Fuel? (DMOJ): https://dmoj.ca/problem/cco14p4
// ANNOTATED CODE - https://dmoj.ca/src/6920400
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3; // greedy problem
typedef pair<int, int> pi;
int N, P, v[MM], c[MM]; vector<pi> temp; queue<pi> order;
/*
 for planet i, if the cost is greater than the value, it is pointless to go there (even if our second priority is to maximize number of planets),
 our MAIN priority is maximize fuel cells / value over everything else
 so sort all eligible planets (their value - cost (this difference must be minimum 0 or greater)) in decreasing order and push them into a queue
 push all of this into a queue
 greedy: go for the best planet with the most value (val - cost), if we can visit that planet (we have enough fuel cells), go there, because over all other planets, that is the best choice currently
 if we can't, push it to the back of the queue because we will try visiting it again once we have more fuel cells
 note that it may be impossible to visit all planets with a margin (val - cost) >= 0, so
 keep track of the number of elements you went through in the queue, if you went through it order.size() times and you haven't visited a new planet once, it means none of the planets in the queue you can visit, so just stop
 */
int main(){
    cin >> N >> P;
    for(int i = 1; i <= N; i++){
        cin >> v[i] >> c[i];
        if(i != P && v[i] - c[i] >= 0) temp.push_back({v[i] - c[i], i}); // v[i] - c[i] is the margin (we want the most bang for our buck), and it is temporary (we only use it for the ordering) til we push it into the queue
    }
    sort(temp.begin(), temp.end(), [](const pi &x, const pi &y) {return x.first > y.first; }); // sort in descending order (custom comparator)
    for(auto [a, b] : temp) order.push({a, b}); // move all elements into the queue
    int sum = v[P], tot = 1; // keep track of number of fuel cells, number of planets visited
    int size = order.size(); bool flag = false; // this is to ensure the while loop doesn't go forever (look at line 16 to see what this does)
    while(!order.empty()){
        auto [val, idx] = order.front(); order.pop();
        if(size == 0){ // if we gone thru the queue order.size() times
            if(flag) {size = order.size(); flag = false;} // if we visited at least one planet reset the variables, we can try again
            else break; // else it is guaranteed we cant visit any other planets so stop here
        }
        if(sum >= c[idx]) { // if we can visit the planet idx
            sum += val; tot++; flag = true; // update, make sure to set flag to true to tell the program (line 31) we were able to visit at least one planet
        }
        else{
            order.push({val, idx}); // else just push it to the back and if the while loop continues to run we will try again
        }
        size--; // make sure to minus the size
    }
    cout << sum << endl << tot << endl; // final answer
}
