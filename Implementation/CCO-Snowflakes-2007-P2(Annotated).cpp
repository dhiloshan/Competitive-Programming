// ANNOTATED CODE - https://dmoj.ca/src/6392195
// Snowflakes '07 P2 (CCO) - https://dmoj.ca/problem/cco07p2
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

string snow_flake(deque<int>& a){ // function to find the smallest lexicographical arrangement of the snowflake's arms (referred to as minimum representation)
    deque<int> ori = a; string min = ""; // duplicating the deque to count the arrangements counter-clock wise (uses different logic)
                                         // min acts as the return value of this function
    for(int e : a) min += to_string(e); // "convert" the deque to a string by appending each value in the deque

    for(int i = 2; i <= 6; i++){ // for 5 times, we are going to count clockwise
        int frt = a.front(); a.pop_front(); // save the front number and remove it
        a.push_back(frt); // add that number to the back

        string cur = "";
        for(int x : a){ // convert this deque into a string
            cur += to_string(x); 
        }

        if(min > cur) min = cur; // if this string is lexicographically smaller than the current minimum, change min to this arrangement
    }
    for(int i = 7; i <= 12; i++){ // for the last 6 combinations, we are going to count counter-clockwise
        int lft = i - 7, j = lft; string cur = ""; // idea is to start in the middle, append the current number and then traverse to the left and append those numbers until you reach the first one
                                                   // then you go to the right of the deque and append that number, and then traverse to the left and append those numbers until you reach the origianl index (middle)
        while(j >= 0){ // this "middle" starts at the very left, and ends at the very right
                       // boundary is very left ( or >= 0)
            cur += to_string(ori[j]); // IMPORTANT LINE - adding the STRING version of the number in the deque to the cur string
            j--; // move to the left by 1 unit
        }
        j = 5; // go to the very right of the deque - index 5 (there are always six arms in the deque / snowflake)
        while(j > lft){ // keep traversing leftwards until you reach index lft (the original starting point)
            cur += to_string(ori[j]);
            j--;
        }
        if(min > cur) min = cur;
    }

    return min; // return this value so that id can be set to this value as the least lexicographical arrangement of snowflake i
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        deque<int> a; // utilizing a deque to modify the left and right side of arm and access indexes
        for(int j = 0, x; j < 6; j++){
            cin >> x; a.push_back(x); // push_back vs push_front | pop_back() vs pop_front()
        }
        string id = snow_flake(a); // id is the return value of deque a (a.k.a the least lexicographical arrangement of the snowflake's arms)
                                      // this is done to easily identify each snowflake, because there is 12 combinations we don't want to check each one
        mp[id]++; 
        if(mp[id] > 1){ // if this id (snowflake) appeared more than once in the map, it must be the same as some other id (snowflake)
            cout << "Twin snowflakes found." << endl; return 0; // thus, twin snowflakes are found, and we can stop the program here
        }
    }
    cout << "No two snowflakes are alike." << endl; // if the entire program ran and we found no twins, then it is for sure there are no alike snowflakes
}
