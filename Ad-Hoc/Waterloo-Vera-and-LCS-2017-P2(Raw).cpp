// Waterloo 2017 Winter B - Vera and LCS (DMOJ): https://dmoj.ca/problem/waterloo2017wb
// RAW CODE - https://dmoj.ca/src/6875741
#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
int N, K, freq[MM]; char a[MM], b[MM];
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        freq[(int)a[i]]++;
    }
    int mi = N; char letter = '0';
    for(int i = 97; i <= 122; i++){
        if(mi > freq[i]){
            mi = freq[i]; letter = (char)i;
        }
    }
    int delta = K - mi;
    if(K < mi || K > N){
        cout << "WRONGANSWER" << endl;
        return 0;
    }
    for(int i = 0; i < N; i++){
        if(delta > 0 && a[i] != letter){
            b[i] = a[i]; delta--;
        }
        else{
            b[i] = letter;
        }
    }
    for(int i = 0; i < N; i++) cout << b[i];
    cout << endl;
}
