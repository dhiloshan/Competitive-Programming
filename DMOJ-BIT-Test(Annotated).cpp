// ANNOTATED CODE  - https://dmoj.ca/src/6317936 
// Binary Indexed Tree Test (DMOJ) - https://dmoj.ca/problem/ds1
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int N, M, a[MM]; ll bit1[MM], freq[MM]; // we are using two different bit arrays
                                        // one for range sum queries (bit1), one for frequency queries
// remember that bit is just an array that supports fast subarray queries and updates
// instead of asking "what is the sum from a[1] to a[i]", we are asking 
// "what is the frequency of 1 to j (how often does numbers 1, 2, ..., j appear in the array)"

void update(int pos, int val, ll bit[]){  // extra argument for which bit array to use
    for(int i = pos; i < MM; i += i&-i){ // as update approaches maximum
        bit[i] += val; // update that cell
    }
    // ex. add 3 to a[5] => 5 = 00101
    // 00101 (5) => 00110 (6) => 01000 (8) => 10000 (16)
    // update cells 5, 6, 8, and 16
}

ll query(int pos, ll bit[]){ 
    ll sum = 0;                         // i & -i refers to 2's last bit, finds the last 1 bit in the binary number
    for(int i = pos; i > 0; i -= i&-i){ // as query approaches 0
        sum += bit[i]; // add the range that bit cell is storing to the sum
    }
    return sum;
    // ex. sum of a[1] to a[11] => 11 = 01011
    // 01011 (11) => 01010 (10) => 01000 (8) => 00000 (0)
    // check bit cells 11, 10, and 8
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> a[i]; 
        update(i, a[i], bit1); // at bit cell i, add the value inputted
        update(a[i], 1, freq); // using frequency array logic, at the cell whose index is the inputted value, add 1 
    }
    for(int i = 1, x, y; i <= M; i++){
        char op; cin >> op >> x;
        if(op == 'C'){
            cin >> y; // x = index / position, y = value
            update(x, y - a[x], bit1); // since you want to change it to a different value, subtract old value from new value
                                       // bit[x] (old value) + (new value - old value) = bit[x] has the new value
            update(a[x], -1, freq);    // minus one frequency to the old value
            update(y, 1, freq);        // add one frequency to the new value
            a[x] = y;                  // change the value in the original array
            // think about:
            // for parameter one (position): what CELL do I want to change
            // for parameter two (index): what do you want to ADD for this cell
           	// for parameter three (different bit array) (usually not there): which functions do I want: bit[], representing psa array for range sum queriesrr
        																						   // or freq[], for the frequency of a subarray of numbers 
        }
        else if(op == 'S'){
            cin >> y; // x = L, y = R
            cout << query(y, bit1) - query(x-1, bit1) << endl; // psa logic => subarray sum = psa[R] - psa[L-1]
        }
        else if(op == 'Q'){
            cout << query(x, freq) << endl; // as mentioned at the top, it's the same logic
                                            // instead of sum of a[1] to a[x], frequency of 1 to x
        }
    }
}
