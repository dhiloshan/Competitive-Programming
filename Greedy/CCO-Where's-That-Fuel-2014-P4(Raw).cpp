// CCO '14 P4 - Where's That Fuel? (DMOJ): https://dmoj.ca/problem/cco14p4
// RAW CODE - https://dmoj.ca/src/6920369
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
typedef pair<int, int> pi;
int N, P, v[MM], c[MM]; vector<pi> temp; queue<pi> order;
int main(){
    cin >> N >> P;
    for(int i = 1; i <= N; i++){
        cin >> v[i] >> c[i];
        if(i != P && v[i] - c[i] >= 0) temp.push_back({v[i] - c[i], i});
    }
    sort(temp.begin(), temp.end(), [](const pi &x, const pi &y) {return x.first > y.first; });
    for(auto [a, b] : temp) order.push({a, b});
    int sum = v[P], tot = 1, size = order.size(); bool flag = false;
    while(!order.empty()){
        auto [val, idx] = order.front(); order.pop();
        if(size == 0){
            if(flag) {size = order.size(); flag = false;}
            else break;
        }
        if(sum >= c[idx]) {
            sum += val; tot++; flag = true;
        }
        else{
            order.push({val, idx});
        }
        size--;
    }
    cout << sum << endl << tot << endl;
}
