// CCC '15 S3 - Gates (DMOJ): https://dmoj.ca/problem/ccc15s3
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
const int mod = (int)1e9+7;
const int base = (int)1e8+7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mi;
typedef set<int> si;
typedef queue<int> qi;
#define f first
#define s second
#define MP(x, y) make_pair(x, y);
#define PB(x) push_back(x);
#define MEM(arr, x) memset(arr, x, sizeof(arr));
#define sorte(vect) sort(vect.begin(), vect.end())
#define sortE(vect) sort(vect.begin(), vect.end(), greater<int>())
#define F0R(x) for(int i = 0; i < x; i++)
#define F1R(x) for(int i = 1; i <= x; i++)
int G, P; si gate;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> G >> P;

    for(int i = 1; i <= G; i++) gate.insert(i);

    for(int i = 1, g; i <= P; i++){
        cin >> g;
        auto it = gate.upper_bound(g);

        if(it == gate.begin()){
            cout << i-1 << endl;
            return 0;
        }
        it--;
        gate.erase(it);
    }

    cout << P << endl;
}
