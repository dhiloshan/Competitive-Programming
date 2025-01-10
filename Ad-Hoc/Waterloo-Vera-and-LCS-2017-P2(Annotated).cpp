// Waterloo 2017 Winter B - Vera and LCS (DMOJ): https://dmoj.ca/problem/waterloo2017wb
// ANNOTATED CODE - https://dmoj.ca/src/6875738
#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
int N, K, freq[MM]; char a[MM], b[MM];
/*
 we have a LCS problem for string a and b with their LCS being K
 however, we are only given a and K, not b
 the idea is the use the least frequent letter in string a to build string b
 we observe that if the desired LCS (K) is > than N or LCS < min frequency letter, then its literally impossible
 otherwise, all we do is set the positions in a where they equal the min frequent letter to the min frequent letter in array b
 we still need delta (K - min frequency letter) to achieve LCS / K, so while delta > 0, any letter that in array a isn't equal to the min frequent letter just set to b[i]'s value
 do this til delta = 0, then set the rest to min frequent letter
 */
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        freq[(int)a[i]]++; // frequency array for letters a to z using ASCII Value
    }
    // ascii values from 97 (a) to 122 (z) (problem only uses lowercase letters)
    int mi = N; char letter = '0'; // it is guaranteed that we change mi's value and letter's value (make sure you see why try cases)
    for(int i = 97; i <= 122; i++){ // find the min frequent letter for letters a to z
        if(mi > freq[i]){
            mi = freq[i]; letter = (char)i;
        }
    }
    int delta = K - mi; // delta represents the amount of letters left to achieve LCS
    if(K < mi || K > N){ // if string b needs to be bigger than N (problem statement says a and b are length N) or the min frequent letter is greater than the LCS
        cout << "WRONGANSWER" << endl; // it is impossible
        return 0; // quit the program
    }
    for(int i = 0; i < N; i++){ // constructing string b
        if(delta > 0 && a[i] != letter){ // if we need to put more letters to achieve LCS and that letter isnt the minimum frequency letter
            b[i] = a[i]; delta--; //
        }
        else{
            b[i] = letter; // we run this part because either a[i] = min frequency letter or we just fill the rest with min frequency letter
        }
    }
    // print out string b
    for(int i = 0; i < N; i++) cout << b[i];
    cout << endl;
}
