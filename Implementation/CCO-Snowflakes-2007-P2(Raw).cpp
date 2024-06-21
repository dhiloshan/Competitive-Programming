// Snowflakes '07 P2 (CCO): https://dmoj.ca/problem/cco07p2
// RAW CODE - https://dmoj.ca/src/6392195
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+3;
const int mod = (int)1e9+7;
const int base = (int)1e8+7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mi;
typedef stack<int> si;
typedef queue<int> qi;
#define f first
#define s second
#define PB(x) push_back(x)
#define MEM(arr, x) memset(arr, x, sizeof(arr))
int N; map<string, int> mp;

string snow_flake(deque<int>& a){
    deque<int> ori = a; string min = "";
    for(int e : a) min += to_string(e);

    for(int i = 2; i <= 6; i++){
        int frt = a.front(); a.pop_front();
        a.push_back(frt);

        string cur = "";
        for(int x : a){
            cur += to_string(x);
        }

        if(min > cur) min = cur;
    }
    for(int i = 7; i <= 12; i++){
        int lft = i - 7, j = lft; string cur = "";
        while(j >= 0){
            cur += to_string(ori[j]);
            j--;
        }
        j = 5;
        while(j > lft){
            cur += to_string(ori[j]);
            j--;
        }
        if(min > cur) min = cur;
    }

    return min;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        deque<int> a;
        for(int j = 0, x; j < 6; j++){
            cin >> x; a.push_back(x);
        }
        string id = snow_flake(a);
        mp[id]++;
        if(mp[id] > 1){
            cout << "Twin snowflakes found." << endl; return 0;
        }
    }
    cout << "No two snowflakes are alike." << endl;
}
