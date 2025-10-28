// ICPC NAQ 2016 G - Inverse Factorial (DMOJ): https://dmoj.ca/problem/naq16g
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 1503;
string N;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    if(N.size() <= 7){
        int Ncur = stoi(N);
        if(Ncur == 1)
            cout << 1 << endl;
        else{
            for(int i = 2; i <= 10; i++){
                Ncur /= i;
                if(Ncur == 1)
                    cout << i << endl;
            }
        }
    }
    else{
        int n = 10; double logFactor = 0;
        for(int i = 1; i <= 10; i++)
            logFactor += log10(i);
        while(floor(logFactor)+1 < N.size()){
            n++;
            logFactor += log10(n);
        }
        cout << n << endl;
    }
}
